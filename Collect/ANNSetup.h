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
			layers = gcnew List<FCLayer^>();
			FCLayer^ iterator = ann->InputLayer;
			while (iterator != nullptr)
			{
				layers->Add(iterator);
				iterator = iterator->NextLayer;
			}

		}

		property ANN^ Ann {
			ANN^ get() {
				return ann;
			}
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
		System::ComponentModel::Container^ components;


		/// <summary>
		/// User defined variables.
		/// </summary>
		ANN^ ann;
		List<FCLayer^>^ layers;
		int inputDim = 2;
		bool changed = false;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ MaxEpochsInput;
	private: System::Windows::Forms::NumericUpDown^ BatchSizeInput;
	private: System::Windows::Forms::NumericUpDown^ MomentumRateInput;




	private: System::Windows::Forms::NumericUpDown^ LearningRateInput;
	private: System::Windows::Forms::NumericUpDown^ numNeurons;
	private: System::Windows::Forms::NumericUpDown^ numClasses;

	private: System::Windows::Forms::NumericUpDown^ ThresholdInput;





#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->MaxEpochsInput = (gcnew System::Windows::Forms::NumericUpDown());
			   this->BatchSizeInput = (gcnew System::Windows::Forms::NumericUpDown());
			   this->MomentumRateInput = (gcnew System::Windows::Forms::NumericUpDown());
			   this->LearningRateInput = (gcnew System::Windows::Forms::NumericUpDown());
			   this->ThresholdInput = (gcnew System::Windows::Forms::NumericUpDown());
			   this->numNeurons = (gcnew System::Windows::Forms::NumericUpDown());
			   this->numClasses = (gcnew System::Windows::Forms::NumericUpDown());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MaxEpochsInput))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BatchSizeInput))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MomentumRateInput))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LearningRateInput))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ThresholdInput))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numNeurons))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numClasses))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(57, 31);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(232, 31);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Safe Parameters";
			   // 
			   // label2
			   // 
			   this->label2->Location = System::Drawing::Point(20, 72);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(214, 29);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Editing the parameters below will not require network reconstruction.";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(20, 124);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(66, 13);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"Max Epochs";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(23, 206);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(79, 13);
			   this->label4->TabIndex = 3;
			   this->label4->Text = L"Error Threshold";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(20, 167);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(58, 13);
			   this->label5->TabIndex = 3;
			   this->label5->Text = L"Batch Size";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(20, 248);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(74, 13);
			   this->label6->TabIndex = 3;
			   this->label6->Text = L"Learning Rate";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(20, 290);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(82, 13);
			   this->label7->TabIndex = 3;
			   this->label7->Text = L"MomentumRate";
			   // 
			   // MaxEpochsInput
			   // 
			   this->MaxEpochsInput->Location = System::Drawing::Point(23, 144);
			   this->MaxEpochsInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			   this->MaxEpochsInput->Name = L"MaxEpochsInput";
			   this->MaxEpochsInput->Size = System::Drawing::Size(120, 20);
			   this->MaxEpochsInput->TabIndex = 4;
			   this->MaxEpochsInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			   this->MaxEpochsInput->ValueChanged += gcnew System::EventHandler(this, &ANNSetup::MaxEpochsInput_ValueChanged);
			   // 
			   // BatchSizeInput
			   // 
			   this->BatchSizeInput->Location = System::Drawing::Point(23, 183);
			   this->BatchSizeInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			   this->BatchSizeInput->Name = L"BatchSizeInput";
			   this->BatchSizeInput->Size = System::Drawing::Size(120, 20);
			   this->BatchSizeInput->TabIndex = 6;
			   this->BatchSizeInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			   this->BatchSizeInput->ValueChanged += gcnew System::EventHandler(this, &ANNSetup::BatchSizeInput_ValueChanged);
			   // 
			   // MomentumRateInput
			   // 
			   this->MomentumRateInput->DecimalPlaces = 5;
			   this->MomentumRateInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			   this->MomentumRateInput->Location = System::Drawing::Point(23, 306);
			   this->MomentumRateInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			   this->MomentumRateInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, System::Int32::MinValue });
			   this->MomentumRateInput->Name = L"MomentumRateInput";
			   this->MomentumRateInput->Size = System::Drawing::Size(120, 20);
			   this->MomentumRateInput->TabIndex = 8;
			   this->MomentumRateInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 65536 });
			   this->MomentumRateInput->ValueChanged += gcnew System::EventHandler(this, &ANNSetup::MomentumRateInput_ValueChanged);
			   // 
			   // LearningRateInput
			   // 
			   this->LearningRateInput->DecimalPlaces = 5;
			   this->LearningRateInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			   this->LearningRateInput->Location = System::Drawing::Point(23, 267);
			   this->LearningRateInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			   this->LearningRateInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, System::Int32::MinValue });
			   this->LearningRateInput->Name = L"LearningRateInput";
			   this->LearningRateInput->Size = System::Drawing::Size(120, 20);
			   this->LearningRateInput->TabIndex = 9;
			   this->LearningRateInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			   this->LearningRateInput->ValueChanged += gcnew System::EventHandler(this, &ANNSetup::LearningRateInput_ValueChanged);
			   // 
			   // ThresholdInput
			   // 
			   this->ThresholdInput->DecimalPlaces = 5;
			   this->ThresholdInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			   this->ThresholdInput->Location = System::Drawing::Point(23, 225);
			   this->ThresholdInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			   this->ThresholdInput->Name = L"ThresholdInput";
			   this->ThresholdInput->Size = System::Drawing::Size(120, 20);
			   this->ThresholdInput->TabIndex = 10;
			   this->ThresholdInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			   this->ThresholdInput->ValueChanged += gcnew System::EventHandler(this, &ANNSetup::ThresholdInput_ValueChanged);
			   // 
			   // numNeurons
			   // 
			   this->numNeurons->Location = System::Drawing::Point(555, 124);
			   this->numNeurons->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			   this->numNeurons->Name = L"numNeurons";
			   this->numNeurons->Size = System::Drawing::Size(120, 20);
			   this->numNeurons->TabIndex = 11;
			   this->numNeurons->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			   // 
			   // numClasses
			   // 
			   this->numClasses->Location = System::Drawing::Point(555, 436);
			   this->numClasses->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			   this->numClasses->Name = L"numClasses";
			   this->numClasses->Size = System::Drawing::Size(120, 20);
			   this->numClasses->TabIndex = 11;
			   this->numClasses->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			   // 
			   // ANNSetup
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1283, 690);
			   this->Controls->Add(this->numClasses);
			   this->Controls->Add(this->numNeurons);
			   this->Controls->Add(this->ThresholdInput);
			   this->Controls->Add(this->LearningRateInput);
			   this->Controls->Add(this->MomentumRateInput);
			   this->Controls->Add(this->BatchSizeInput);
			   this->Controls->Add(this->MaxEpochsInput);
			   this->Controls->Add(this->label7);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"ANNSetup";
			   this->Text = L"ANNSetup";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MaxEpochsInput))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BatchSizeInput))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MomentumRateInput))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LearningRateInput))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ThresholdInput))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numNeurons))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numClasses))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void MomentumRateInput_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		ann->MomentumRate = (double)MomentumRateInput->Value;
	}
	private: System::Void LearningRateInput_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		ann->LearningRate = (double)LearningRateInput->Value;
	}
	private: System::Void ThresholdInput_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		ann->Threshold = (double)ThresholdInput->Value;
	}
	private: System::Void BatchSizeInput_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		ann->BatchSize = (int)BatchSizeInput->Value;
	}
	private: System::Void MaxEpochsInput_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		ann->MaxEpochs = (int)MaxEpochsInput->Value;
	}
	};
}
