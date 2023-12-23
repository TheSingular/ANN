#pragma once
#include "ANN.h"
#include "FCLayer.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ANNSetup
	/// </summary>
	public ref class ANNSetup : public System::Windows::Forms::Form
	{
	public:
		ANNSetup(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		ANNSetup(ANN^ ann)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->ann = ann;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ANNSetup()
		{
			if (components)
			{
				delete components;
			}

			//Reset weights and biases if structure changed
			if (changed)
			{
				FCLayer^ iterator = ann->InputLayer;
				while (iterator != nullptr)
				{
					iterator->initializeNeurons();
					iterator = iterator->NextLayer;
				}
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


		/// <summary>
		/// User defined variables.
		/// </summary>
		ANN^ ann;
		int inputDim = 2;
		bool changed = false;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// ANNSetup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1958, 1074);
			this->Name = L"ANNSetup";
			this->Text = L"ANNSetup";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
