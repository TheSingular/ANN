#pragma once
ref class FCLayer
{
public:
	//Properties

	//read-only
	property int NumInputDim {
		int get() {
			return numInputDim;
		}
	}
	//read-write
	property int NumNeurons {
		int get() {
			return numNeurons;
		}
		void set(int value) {
			numNeurons = value;
			if (nextLayer != nullptr)
				nextLayer->updateNumInputDim();
		}
	}
	//read-write
	property FCLayer^ PrevLayer {
		FCLayer^ get() {
			return prevLayer;
		}
		void set(FCLayer^ value) {

			prevLayer = value;
			//numInputDim is tied to prevLayer's numNeurons
			updateNumInputDim();

			if (prevLayer != nullptr)
				prevLayer->nextLayer = this;
		}
	}
	//read-write
	property FCLayer^ NextLayer {
		FCLayer^ get() {
			return nextLayer;
		}
		void set(FCLayer^ value) {
			nextLayer = value;
			if (nextLayer != nullptr)
			{
				nextLayer->prevLayer = this;
				//nextLayer's numInputDim is tied to numNeurons
				nextLayer->updateNumInputDim();
			}
		}
	}
	//read-write
	property array<array<double>^>^ Weights {
		array<array<double>^>^ get() {
			return weights;
		}
		void set(array<array<double>^>^ value) {
			weights = value;
		}
	}
	//read-write
	property array<double>^ Bias {
		array<double>^ get() {
			return bias;
		}
		void set(array<double>^ value) {
			bias = value;
		}
	}

	//Constructor & Destructor
	FCLayer(int numNeurons, FCLayer^ prevLayer, FCLayer^ nextLayer);
	~FCLayer();

	//Methods
	array<double>^ predict(array<double>^ inputs);
	array<double>^ calculateOutputs();
	void updateWeights(array<double>^ nextDelta);
	void initializeNeurons();

private:
	int numNeurons = 1;
	int numInputDim = 2;
	FCLayer^ prevLayer;
	FCLayer^ nextLayer;
	array<array<double>^>^ weights;
	array<double>^ bias;
	array<double>^ inputs;
	array<double>^ outputs;
	void updateNumInputDim();
};