#pragma once
ref class FCLayer
{
	public:
		FCLayer(int numNeurons, FCLayer^ prevLayer, FCLayer^ nextLayer);
		void initializeNeurons();
		void updateNumInputDim();
		void readInputs(array<double>^ inputs);
		void calculateOutputs();
		void updateWeights(array<double>^ nextDelta, double learningRate);
		~FCLayer();


		private:
			int numNeurons = 1;
			int numInputDim = 2;
			FCLayer^ prevLayer;
			FCLayer^ nextLayer;
			array<array<double>^>^ weights;
			array<double>^ bias;
			array<double>^ inputs;
			array<double>^ outputs;
};