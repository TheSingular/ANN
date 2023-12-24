#include "pch.h"
#include "ANN.h"
#include "FCLayer.h"

using namespace System;
using namespace System::IO;

int inline targetOutput(int target, int index)
{
	return target == index ? 1 : -1;
}

int inline targetOutput2Class(int target)
{
	return target == 0 ? 1 : -1;
}

ANN::ANN()
{

}


// insert a layer before the layer specified by next
void ANN::insertLayerBefore(FCLayer^ next, int numNeurons)
{
	if (next == nullptr)
	{
		throw gcnew Exception("Next layer is null");
	}
	if (numNeurons < 1)
	{
		throw gcnew Exception("Number of neurons must be greater than 0");
	}
	FCLayer^ layer = gcnew FCLayer(numNeurons, next->PrevLayer, next);
}
// update a layer's number of neurons
void ANN::updateLayer(FCLayer^ layer, int numNeurons)
{
	if (layer == nullptr)
	{
		throw gcnew Exception("Layer is null");
	}
	if (numNeurons < 1)
	{
		throw gcnew Exception("Number of neurons must be greater than 0");
	}
	layer->NumNeurons = numNeurons;
}

// remove a layer and link the previous layer to the next layer
void ANN::removeLayer(FCLayer^ layer)
{
	if (layer == nullptr)
	{
		throw gcnew Exception("Layer is null");
	}
	if (layer->NextLayer == nullptr)
	{
		throw gcnew Exception("Cannot remove output layer");
	}
	if (layer->PrevLayer != nullptr)
	{
		layer->PrevLayer->NextLayer = layer->NextLayer;
	}
	layer->NextLayer->PrevLayer = layer->PrevLayer;
	layer = nullptr;
}

//Initialize the ANN with a single layer
void ANN::pickNumClass(int numClass)
{
	if (numClass < 2)
	{
		throw gcnew Exception("Number of classes must be greater than 1");
	}
	if (numClass == 2)
	{
		numClass = 1;
	}
	//Clear everything
	clearall();
	//Create input layer
	inputLayer = outputLayer = gcnew FCLayer(numClass, nullptr, nullptr);
	//Set initialized to true
	initialized = true;
}


//Reset everything, remove all layers
void ANN::clearall()
{
	initialized = false;
	batchSize = 1;
	error = 1;
	threshold = 0.1;
	epochs = 0;
	maxEpochs = 10000;
	errorLog = gcnew array<double>(maxEpochs);
	//Smart pointers will delete themselves
	outputLayer = nullptr;
	inputLayer = nullptr;
	input = nullptr;
	rawInput = nullptr;
	target = nullptr;
	mean = gcnew array<double>(2);
	std = gcnew array<double>(2);
}


void ANN::Train()
{
	prepInput();
	//check if input and target exist
	if (input == nullptr || target == nullptr)
	{
		throw gcnew Exception("Input or target array is null");
	}

	//Check if input and target are the same size
	if (input->Length != target->Length)
	{
		throw gcnew Exception("Input and target arrays are not the same size");
	}

	//Check if input is the same size as the input layer
	if (input[0]->Length != inputLayer->NumInputDim)
	{
		throw gcnew Exception("Input array is not the same size as the input dimensions");
	}


	if (BatchSize == 0 || BatchSize > input->Length)
	{
		BatchSize = input->Length;
	}



	epochs = 0;
	errorLog = gcnew array<double>(maxEpochs);
	int batchCounter = 0;
	array<double>^ firstDelta = gcnew array<double>(outputLayer->NumNeurons);

	//Epoch loop (train until max epochs or error is below threshold)
	for (int i = 0; i < maxEpochs && error > threshold; i++)
	{
		//Reset error
		error = 0;
		//Loop through all inputs
		for (int j = 0; j < input->Length; j++)
		{
			array<double>^ output = inputLayer->predict(input[j]);
			batchCounter++;

			//Calculate error
			if (output->Length == 1)
			{
				error += Math::Pow(output[0] - targetOutput2Class(target[j]), 2);
				firstDelta[0] += output[0] - targetOutput2Class(target[j]);
			}
			else
			{
				for (int k = 0; k < output->Length; k++)
				{
					error += Math::Pow(output[k] - targetOutput(target[j], k), 2);
					firstDelta[k] += output[k] - targetOutput(target[j], k);
				}
			}
			error /= output->Length * 2;

			if (batchCounter == batchSize || j == input->Length - 1)
			{
				//Update weights
				outputLayer->updateWeights(firstDelta);
				firstDelta = gcnew array<double>(output->Length);
				batchCounter = 0;
			}
		}
		//Calculate mean error
		error /= input->Length;
		//Add error to error log
		errorLog[epochs] = error;
		//Increase epoch counter
		epochs++;
	}
	error = 1;
}

//Predict output based on input, does not train
int ANN::predictRaw(array<double>^ rawTestSample)
{
	//Check if input is the same size as the input layer
	if (rawTestSample->Length != inputLayer->NumInputDim)
	{
		throw gcnew Exception("Input array is not the same size as the input dimensions");
	}
	array<double>^ testSample = gcnew array<double>(rawTestSample->Length);

	for (int i = 0; i < rawTestSample->Length; i++)
	{
		testSample[i] = (rawTestSample[i] - mean[i]) / std[i];
	}
	return predict(testSample);
}

//Predict output based on input, does not train
int ANN::predict(array<double>^ testSample)
{
	return classResult(inputLayer->predict(testSample));
}

int ANN::classResult(array<double>^ output)
{
	int maxIndex = 0;
	if (output->Length == 1)
	{
		return output[0] > 0 ? 0 : 1;
	}
	for (int i = 0; i < output->Length; i++)
	{
		if (output[i] > output[maxIndex])
		{
			maxIndex = i;
		}
	}
	return maxIndex;
}

void ANN::loadFromFile(int^ width, int^ height)
{
	clearall();

	String^ SampleLoc = gcnew String("../Data/Samples.txt");
	String^ WeightLoc = gcnew String("../Data/weights.txt");
	StreamReader^ Samples = gcnew StreamReader(SampleLoc);
	StreamReader^ Weights = gcnew StreamReader(WeightLoc);

	String^ line = Samples->ReadLine();
	array<String^>^ split = line->Split(' ');
	*width = Convert::ToInt32(split[1]);
	*height = Convert::ToInt32(split[2]);
	int numClass = Convert::ToInt32(split[3]);
	int numInputDim = Convert::ToInt32(split[0]);

	pickNumClass(numClass);

	line = Weights->ReadLine();
	int numLayer = Convert::ToInt32(line);
	FCLayer^ iterator;
	for (int i = 0; i < numLayer; i++)
	{
		line = Weights->ReadLine();
		split = line->Split(' ');
		if (i == numLayer - 1)
		{
			iterator = outputLayer;
		}
		else
		{
			iterator = gcnew FCLayer(Convert::ToInt32(split[1]), outputLayer->PrevLayer, outputLayer);
		}

		for (int i = 0; i < iterator->NumNeurons; i++)
		{
			line = Weights->ReadLine();
			split = line->Split(' ');
			for (int j = 0; j < iterator->NumInputDim; j++)
			{
				iterator->Weights[i][j] = Convert::ToDouble(split[j]);
			}
		}
		for (int i = 0; i < iterator->NumNeurons; i++)
		{
			line = Weights->ReadLine();
			split = line->Split(' ');
			iterator->Bias[i] = Convert::ToDouble(split[0]);
		}
		iterator = iterator->NextLayer;
	}
	Weights->Close();

	line = Samples->ReadLine();
	array<double>^ tempInput = gcnew array<double>(numInputDim);
	int tempTarget = 0;
	while (line != nullptr)
	{
		line = Samples->ReadLine();
		split = line->Split(' ');
		for (int i = 0; i < split->Length - 1; i++)
		{
			tempInput[i] = Convert::ToDouble(split[i]);
		}
		tempTarget = Convert::ToInt32(split[split->Length - 1]);
		addSample(tempInput, tempTarget);
	}
	Samples->Close();
}

void ANN::saveToFile(int width, int height)
{
	if (rawInput->Length != 0) {
		char** c = new char* [2];

		String^ SampleLoc = gcnew String("../Data/Samples.txt");
		String^ WeightLoc = gcnew String("../Data/weights.txt");
		StreamWriter^ Samples = gcnew StreamWriter(SampleLoc, false);

		Samples->WriteLine("{0} {1} {2} {3}", inputLayer->NumInputDim, width / 2, height / 2, outputLayer->NumNeurons == 1 ? 2 : outputLayer->NumNeurons);
		// Width,  Height, number of Class, data+label
		for (int i = 0; i < input->Length; i++) {
			for (int d = 0; d < input[0]->Length; d++)
				Samples->Write("{0} ", input[i][d]);
			Samples->WriteLine("{0}", target[i]);
		}
		Samples->Close();

		StreamWriter^ Weights = gcnew StreamWriter(WeightLoc, false);
		// #Layer Dimension numClass weights biases

		int labelCount = 0;
		FCLayer^ iterator = inputLayer;
		while (iterator != nullptr)
		{
			labelCount++;
			iterator = iterator->NextLayer;
		}

		Weights->WriteLine("{0}", labelCount);

		iterator = inputLayer;
		while (iterator != nullptr)
		{
			Weights->WriteLine("{0} {1}", iterator->NumInputDim, iterator->NumNeurons);
			for (int i = 0; i < iterator->NumNeurons; i++)
			{
				for (int j = 0; j < iterator->NumInputDim; j++)
				{
					Weights->Write("{0} ", iterator->Weights[i][j]);
				}
				Weights->WriteLine();
			}
			for (int i = 0; i < iterator->NumNeurons; i++)
			{
				Weights->Write("{0} ", iterator->Bias[i]);
			}
			iterator = iterator->NextLayer;
		}
		Weights->Close();
	}
	else throw gcnew Exception("At least one sample should be given");
}

//Adds a single input sample to the input array
void ANN::addSample(array<double>^ input, int target)
{
	

	if (input->Length != inputLayer->NumInputDim)
	{
		throw gcnew Exception("Input array is not the same size as the input dimensions");
	}

	if (target < 0 || target >= (outputLayer->NumNeurons == 1 ? 2 : outputLayer->NumNeurons))
	{
		throw gcnew Exception("Target outside of class constraints");
	}

	if (rawInput == nullptr)
	{
		rawInput = gcnew array<array<double>^>(1);
		this->target = gcnew array<int>(1);
		rawInput[0] = input;
		this->target[0] = target;
	}
	else
	{
		Array::Resize(rawInput, rawInput->Length + 1);
		Array::Resize(this->target, this->target->Length + 1);
		rawInput[rawInput->Length - 1] = input;
		this->target[this->target->Length - 1] = target;
	}
}

void ANN::prepInput()
{
	//randomize input order
	Random^ rand = gcnew Random();
	for (int i = 0; i < rawInput->Length; i++)
	{
		int randIndex = rand->Next(rawInput->Length);
		array<double>^ temp = rawInput[i];
		rawInput[i] = rawInput[randIndex];
		rawInput[randIndex] = temp;
		int temp2 = target[i];
		target[i] = target[randIndex];
		target[randIndex] = temp2;
	}
	//Calculate mean and standard deviation
	for (int i = 0; i < rawInput[0]->Length; i++)
	{
		mean[i] = 0;
		std[i] = 0;
		for (int j = 0; j < rawInput->Length; j++)
		{
			mean[i] += rawInput[j][i];
		}
		mean[i] /= rawInput->Length;
		for (int j = 0; j < rawInput->Length; j++)
		{
			std[i] += Math::Pow(rawInput[j][i] - mean[i], 2);
		}
		std[i] /= rawInput->Length;
		std[i] = Math::Sqrt(std[i]);
	}

	input = gcnew array<array<double>^>(rawInput->Length);
	//Normalize input
	for (int i = 0; i < input->Length; i++)
	{
		input[i] = gcnew array<double>(rawInput[0]->Length);

		for (int j = 0; j < input[0]->Length; j++)
		{
			input[i][j] = (rawInput[i][j] - mean[j]) / std[j];
		}
	}
}


//Empty destructor
ANN::~ANN()
{
}