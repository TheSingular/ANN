#include "pch.h"
#include "FCLayer.h"
using namespace System;

double inline sigmoid(double x)
{
	return 2 / (1 + Math::Exp(-x)) - 1;
}
double inline sigmoidDerivative(double x)
{
	return  0.5 * (1 - x * x);

}
double inline tanh(double x)
{
	return Math::Tanh(x);
}
double inline tanhDerivative(double x)
{
	return  1 - x * x;
}
double inline relu(double x)
{
	return Math::Max(0.0, x);
}
double inline reluDerivative(double x)
{
	if (x > 0)
		return 1;
	else
		return 0;
}
double inline leakyRelu(double x)
{
	if (x > 0)
		return x;
	else
		return 0.01 * x;
}
double inline leakyReluDerivative(double x)
{
	if (x > 0)
		return 1;
	else
		return 0.01;
}

FCLayer::FCLayer(int numNeurons, FCLayer^ prevLayer, FCLayer^ nextLayer)
{
	this->NumNeurons = numNeurons;
	this->PrevLayer = prevLayer;
	this->NextLayer = nextLayer;
	updateNumInputDim();
	if (this->nextLayer != nullptr)
		this->nextLayer->updateNumInputDim();
}

void FCLayer::resetMomentums()
{
	deltaBias = gcnew array<double>(numNeurons);
	deltaWeights = gcnew array<array<double>^>(numNeurons);
	for (int i = 0; i < numNeurons; i++)
	{
		deltaWeights[i] = gcnew array<double>(numInputDim);
	}
	if (nextLayer != nullptr)
	{
		nextLayer->resetMomentums();
	}
}

//initializes neurons(weights) and bias with random values between -0.5 and 0.5
void FCLayer::initializeNeurons()
{
	//initialize weights and bias
	weights = gcnew array<array<double>^>(numNeurons);
	deltaWeights = gcnew array<array<double>^>(numNeurons);
	bias = gcnew array<double>(numNeurons);
	deltaBias = gcnew array<double>(numNeurons);

	//initialize random seed
	//Random^ randomGenerator = gcnew Random();

	//For each neuron
	for (int i = 0; i < numNeurons; i++)
	{
		//Initialize weightarray for each neuron
		weights[i] = gcnew array<double>(numInputDim);
		deltaWeights[i] = gcnew array<double>(numInputDim);
		for (int j = 0; j < numInputDim; j++)
		{
			//Random weights between -0.5 and 0.5
			weights[i][j] = randomGenerator->NextDouble() - 0.5;
		}
		//Random bias between -0.5 and 0.5
		bias[i] = randomGenerator->NextDouble() - 0.5;
	}
	if (nextLayer != nullptr)
	{
		nextLayer->initializeNeurons();
	}
}
//Updates the number of inputs for each neuron and reconstructs the weights and bias
void FCLayer::updateNumInputDim()
{
	//If there is no previous layer, the input dimension is 2
	if (prevLayer == nullptr)
	{
		numInputDim = 2;
	}
	//If there is a previous layer, the input dimension is the number of neurons in the previous layer
	else
	{
		numInputDim = prevLayer->numNeurons;
	}
	//Reconstruct weights and bias
	initializeNeurons();
}

//Updates the weights and bias of the neurons
//nextDelta is the delta of the next layer minus its inputs and learning rate
//If there's no next layer, nextDelta is precalculated from the output and target (nextDelta = output - target)
void FCLayer::updateWeights(array<double>^ nextDelta, double learningRate, double momentumRate)
{
	if (learningRate == 0)
		learningRate = 0.1;
	array<double>^ prevDelta = gcnew array<double>(numNeurons);

	//If there is no next layer, nextDelta is precalculated from output and target (nextDelta = output - target)
	if (nextLayer == nullptr)
	{
		//For each neuron
		for (int i = 0; i < numNeurons; i++)
		{
			//Calculate delta
			//prevDelta[i] = reluDerivative(outputs[i]) * nextDelta[i];
			//prevDelta[i] = leakyReluDerivative(outputs[i]) * nextDelta[i];
			prevDelta[i] = tanhDerivative(outputs[i]) * nextDelta[i];
			//prevDelta[i] = sigmoidDerivative(outputs[i]) * nextDelta[i];
		}
	}
	//If there is a next layer, nextDelta is calculated from the next layer's delta
	else
	{
		//For each neuron
		for (int j = 0; j < nextLayer->numInputDim; j++)
		{
			//Initialize delta
			prevDelta[j] = 0;
			//For each neuron in the next layer
			for (int k = 0; k < nextLayer->numNeurons; k++)
			{
				//Calculate delta
				prevDelta[j] += nextDelta[k] * nextLayer->weights[k][j];
			}
			//Finalize delta
			//prevDelta[j] *= reluDerivative(outputs[j]);
			//prevDelta[j] *= leakyReluDerivative(outputs[j]);
			prevDelta[j] *= tanhDerivative(outputs[j]);
			//prevDelta[j] *= sigmoidDerivative(outputs[j]);
		}
	}

	//For each neuron
	for (int i = 0; i < numNeurons; i++)
	{

		//Update bias and weights
		deltaBias[i] = (1 - momentumRate) * -1 * prevDelta[i] + momentumRate * deltaBias[i];
		bias[i] += learningRate * deltaBias[i];
		//For each input
		for (int j = 0; j < numInputDim; j++)
		{
			//Update weights
			deltaWeights[i][j] = (1 - momentumRate) * inputs[j] * prevDelta[i] + momentumRate * deltaWeights[i][j];
			weights[i][j] += learningRate * deltaWeights[i][j];
		}
	}
	//Back propagate to previous layer
	if (prevLayer != nullptr)
	{
		prevLayer->updateWeights(prevDelta, learningRate, momentumRate);
	}
}


//Read and store inputs for back propagation later on
array<double>^ FCLayer::predict(array<double>^ inputs)
{
	this->inputs = gcnew array<double>(numInputDim);
	for (int i = 0; i < numInputDim; i++)
	{
		this->inputs[i] = inputs[i];
	}

	outputs = gcnew array<double>(numNeurons);
	for (int i = 0; i < numNeurons; i++)
	{
		outputs[i] = 0;
		for (int j = 0; j < numInputDim; j++)
		{
			outputs[i] += inputs[j] * weights[i][j];
		}
		outputs[i] -= bias[i];
		//outputs[i] = relu(outputs[i]);
		//outputs[i] = leakyRelu(outputs[i]);
		outputs[i] = tanh(outputs[i]);
		//outputs[i] = sigmoid(outputs[i]);
	}

	//Feed forward to next layer if there is one
	if (nextLayer != nullptr)
	{
		return nextLayer->predict(outputs);
	}
	else //If there is no next layer, return the outputs
	{
		return outputs;
	}
}


//Empty destructor (smart pointers)
FCLayer::~FCLayer()
{

}
