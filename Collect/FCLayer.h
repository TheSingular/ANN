#pragma once
ref class FCLayer
{
	public:
		FCLayer();
		~FCLayer();


		private:
			int numNeurons;
			int numInputs;
			FCLayer^ prevLayer;
			FCLayer^ nextLayer;
			array<double, 2>^ weights;
			array<double>^ bias;
};

