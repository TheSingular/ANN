#include "pch.h"
#include "ANN.h"
#include "FCLayer.h"

ANN::ANN()
{

}

//Reset everything, remove all layers
void ANN::clearall()
{
	error = 0;
	threshold = 0.1;
	epochs = 0;
	maxEpochs = 1000;
	//Smart pointers will delete themselves
	outputLayer = nullptr;
	hiddenLayers = nullptr;
}


void ANN::Train(array<array<double>^>^ input, array<double>^ target)
{
	//Check if input and target are the same size
	if (input->Length != target->Length)
	{
		throw gcnew Exception("Input and target arrays are not the same size");
	}

	//Check if input is the same size as the input layer
	if (input[0]->Length != HiddenLayers[0]->NumInputDim)
	{
		throw gcnew Exception("Input array is not the same size as the input dimensions");
	}

	//Check if target is the same size as the output layer
	if (target->Length != outputLayer->NumNeurons)
	{
		throw gcnew Exception("Target array is not the same size as the output layer");
	}

	if (BatchSize == 0 || BatchSize > input->Length)
	{
		BatchSize = input->Length;
	}

	int batchCounter = 0;
	array<double>^ firstDelta = gcnew array<double>(outputLayer->NumNeurons);

	//Epoch loop (train until max epochs or error is below threshold)
	for (int i = 0; i < MaxEpochs && Error > Threshold; i++)
	{
		//Loop through all inputs
		for (int j = 0; j < input->Length; j++)
		{
			array<double>^ output = HiddenLayers[0]->predict(input[j]);
			batchCounter++;

			//Calculate error
			for (int k = 0; k < output->Length; k++)
			{
				error += Math::Pow(output[k] - target[k], 2);
				firstDelta[k] += output[k] - target[k];
			}
			error /= output->Length * 2;

			if (batchCounter == BatchSize || j == input->Length - 1)
			{
				//Update weights
				outputLayer->updateWeights(firstDelta);
				array<double>^ firstDelta = gcnew array<double>(output->Length);
				batchCounter = 0;
			}
		}
		//Increase epoch counter
		epochs++;
	}
}


array<double>^ ANN::predict(array<double>^ input)
{
	//Check if input is the same size as the input layer
	if (input->Length != HiddenLayers[0]->NumInputDim)
	{
		throw gcnew Exception("Input array is not the same size as the input dimensions");
	}

	return HiddenLayers[0]->predict(input);
}

void loadFromFile(String^ filename);
void saveToFile(String^ filename);


//Empty destructor
ANN::~ANN()
{
}