#include "pch.h"
#include "FCLayer.h"
#include <memory>
using namespace System;

double inline sigmoid(double x)
{
	return 2 / (1 + exp(-x)) - 1;
}
double inline sigmoidDerivative(double x)
{
	return 0.5 * (1 - x * x);
}

FCLayer::FCLayer(int numNeurons, FCLayer^ prevLayer, FCLayer^ nextLayer)
{
	this->numNeurons = numNeurons;
	this->prevLayer = prevLayer;
	this->nextLayer = nextLayer;
	updateNumInputDim();
}

//initializes neurons(weights) and bias with random values between -0.5 and 0.5
void FCLayer::initializeNeurons()
{
	//initialize weights and bias
	weights = gcnew array<array<double>^>(numNeurons);
	bias = gcnew array<double>(numInputDim);

	//initialize random seed
	Random^ randomGenerator = gcnew Random();

	//For each neuron
	for (int i = 0; i < numNeurons; i++)
	{
		//Initialize weightarray for each neuron
		weights[i] = gcnew array<double>(numInputDim);
		for (int j = 0; j < numInputDim; j++)
		{
			//Random weights between -0.5 and 0.5
			weights[i][j] = randomGenerator->NextDouble() - 0.5;
		}
		//Random bias between -0.5 and 0.5
		bias[i] = randomGenerator->NextDouble() - 0.5;
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
//If there's no next layer, nextDelta is precalculated from the output and target (nextDelta = target - output)
void FCLayer::updateWeights(array<double>^ nextDelta, double learningRate = 0.1)
{
	double learningrate = 0.1;
	array<double>^ prevDelta = gcnew array<double>(numInputDim);

	//If there is no next layer, nextDelta is precalculated from output and target (nextDelta = target - output)
	if (nextLayer == nullptr)
	{
		//
		array<double>^ prevDelta = nextDelta;

		for (int i = 0; i < numNeurons; i++)
		{
			//
			prevDelta[i] *= sigmoidDerivative(outputs[i]) * prevDelta[i];
			//Update bias and weights
			bias[i] += learningRate * prevDelta[i];

			for (int j = 0; j < numInputDim; j++)
			{
				weights[i][j] += learningRate * prevDelta[i] * inputs[j];
			}
		}
	}
	//If there is a next layer, nextDelta is calculated from the next layer's delta
	else
	{
		for (int i = 0; i < numInputDim; i++)
		{
			prevDelta[i] = 0;
			for (int j = 0; j < numNeurons; j++)
			{
				for (int k = 0; k < nextLayer->numNeurons; k++)
				{
					prevDelta[i] += nextDelta[k] * nextLayer->weights[j][k];
				}
				prevDelta[i] *= sigmoidDerivative(outputs[j]);
			}
		}

		for (int i = 0; i < numNeurons; i++)
		{

			//Update bias and weights
			bias[i] += learningRate * prevDelta[i];

			for (int j = 0; j < numInputDim; j++)
			{
				weights[i][j] += learningRate * prevDelta[i] * inputs[j];
			}
		}
	}
	if (prevLayer != nullptr)
	{

		prevLayer->updateWeights(prevDelta, learningRate);
	}
}


//Read and store inputs for back propagation later on
void FCLayer::readInputs(array<double>^ inputs)
{
	this->inputs = gcnew array<double>(numInputDim);
	for (int i = 0; i < numInputDim; i++)
	{
		this->inputs[i] = inputs[i];
	}
	calculateOutputs();
}

//Calculate the outputs of the neurons
void FCLayer::calculateOutputs()
{
	outputs = gcnew array<double>(numNeurons);
	for (int i = 0; i < numNeurons; i++)
	{
		outputs[i] = 0;
		for (int j = 0; j < numInputDim; j++)
		{
			outputs[i] += inputs[j] * weights[i][j];
		}
		outputs[i] = sigmoid(outputs[i]);
	}
	if (nextLayer != nullptr)
		{
			nextLayer->readInputs(outputs);
		}
}
FCLayer::~FCLayer()
{

}
