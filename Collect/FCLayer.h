#pragma once
ref class FCLayer
{
	public:
		FCLayer();
		FCLayer(int numNeurons, int numInputs, FCLayer^ prevLayer, FCLayer^ nextLayer);
		void updateNumInputs();
		void updateWeights(double error);
		~FCLayer();


		private:
			int numNeurons;
			int numInputs = 2;
			FCLayer^ prevLayer;
			FCLayer^ nextLayer;
			array<double, 2>^ weights;
			array<double>^ bias;
};