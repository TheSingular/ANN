#pragma once
#include "FCLayer.h"


using namespace System;
using namespace System::Collections::Generic;
ref class ANN
{
public:
	// Properties

	// read-write
	// 0 for full batch(update once every epoch), 1 for stochastic, n to update every n samples
	property int BatchSize {
		int get() {
			return batchSize;
		}
		void set(int value) {
			value = Math::Max(0, value);
			batchSize = value;
		}
	}
	// read-only
	property int Epochs {
		int get() {
			return epochs;
		}
	}
	// read-write
	property int MaxEpochs {
		int get() {
			return maxEpochs;
		}
		void set(int value) {
			maxEpochs = value;
		}
	}
	// read-only
	property double Error {
		double get() {
			return error;
		}
	}
	// read-write
	property double Threshold {
		double get() {
			return threshold;
		}
		void set(double value) {
			threshold = value;
		}
	}
	// read-only
	property FCLayer^ OutputLayer {
		FCLayer^ get() {
			return outputLayer;
		}
	}
	// read-only
	property FCLayer^ InputLayer {
		FCLayer^ get() {
			return inputLayer;
		}
	}
	// read-write
	property List<FCLayer^>^ HiddenLayers {
		List<FCLayer^>^ get() {
			return hiddenLayers;
		}
		void set(List<FCLayer^>^ value) {
			hiddenLayers = value;
		}
	}

	// Constructor & Destructor
	ANN();
	~ANN();

	// Methods

	//// insert a layer at index, bounded by 0 and hiddenLayers->Count. If index is hiddenLayers->Count, then it will be added to the end of the list
	//void insertLayerAt(int index, int numNeurons);
	//// update a layer at index, bounded by 0 and hiddenLayers->Count -1
	//void updateLayerAt(int index, int numNeurons);
	//// remove a layer at index, bounded by 0 and hiddenLayers->Count -1
	//void removeLayerAt(int index);

	void Train(array<array<double>^>^ input, array<double>^ target);
	array<double>^ predict(array<double>^ input);

	void loadFromFile(String^ filename);
	void saveToFile(String^ filename);
	

private:
	int epochs = 0;
	int maxEpochs = 1000;
	int batchSize = 1;
	double error = 0;
	double threshold = 0.1;
	FCLayer^ inputLayer;
	FCLayer^ outputLayer;
	List<FCLayer^>^ hiddenLayers;
	//Reset everything, remove all layers
	void clearall();
};

