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
			Array::Resize(errorLog, maxEpochs);
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
	property array<double>^ Mean {
		array<double>^ get() {
			return mean;
		}
	}
	// read-only
	property array<double>^ Std {
		array<double>^ get() {
			return std;
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
	// read-only
	property array<array<double>^>^ RawInput {
		array<array<double>^>^ get() {
			return rawInput;
		}
	}
	// read-only
	property array<int>^ Target {
		array<int>^ get() {
			return target;
		}
	}
	// read-only
	property bool Initialized {
		bool get() {
			return initialized;
		}
	}


	// Constructor & Destructor
	ANN();
	~ANN();

	// Methods

// insert a layer before the layer specified by next
	void insertLayerBefore(FCLayer^ next, int numNeurons);
	// update a layer's number of neurons
	void updateLayer(FCLayer^ layer, int numNeurons);
	// remove a layer and link the previous layer to the next layer
	void removeLayer(FCLayer^ layer);

	void Train();
	int predictRaw(array<double>^ rawTestSample);
	int classResult(array<double>^ output);
	void loadFromFile(int^ width, int^ height);
	void saveToFile(int width, int height);
	void addSample(array<double>^ input, int target);
	void prepInput();
	void pickNumClass(int numClass);


private:
	bool initialized = false;
	int epochs = 0;
	int maxEpochs = 1000;
	array<double>^ errorLog = gcnew array<double>(maxEpochs);
	int batchSize = 1;
	double error = 1;
	double threshold = 0.1;
	array<double>^ mean = gcnew array<double>(2);
	array<double>^ std = gcnew array<double>(2);
	FCLayer^ outputLayer;
	FCLayer^ inputLayer;
	array<array<double>^>^ input;
	array<array<double>^>^ rawInput;
	array<int>^ target;
	//Reset everything, remove all layers
	void clearall();
	int predict(array<double>^ testSample);
};

