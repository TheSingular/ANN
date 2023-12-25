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
			if (ann->InputLayer == nullptr)
			{
				//If there is no input layer, disable all buttons but initialize network button and clearall button
				addLayer->Enabled = false;
				editLayer->Enabled = false;
				setNumClass->Enabled = false;
				removeFirstLayer->Enabled = false;
			}
			else if (ann->InputLayer == ann->OutputLayer)
			{
				//If there is only one layer, disable the remove layer button
				removeFirstLayer->Enabled = false;
				editLayer->Enabled = false;
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
	private: System::Windows::Forms::NumericUpDown^ addLayerNumNeuronsBox;


	private: System::Windows::Forms::NumericUpDown^ setNumClassBox;
	private: System::Windows::Forms::Button^ addLayer;
	private: System::Windows::Forms::Button^ removeFirstLayer;



	private: System::Windows::Forms::Button^ setNumClass;



	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::NumericUpDown^ editLayerNumNeuronsBox;
	private: System::Windows::Forms::Button^ editLayer;
	private: System::Windows::Forms::Button^ initializeFirstLayer;
	private: System::Windows::Forms::Button^ resetNetwork;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;




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
			   this->addLayerNumNeuronsBox = (gcnew System::Windows::Forms::NumericUpDown());
			   this->setNumClassBox = (gcnew System::Windows::Forms::NumericUpDown());
			   this->addLayer = (gcnew System::Windows::Forms::Button());
			   this->removeFirstLayer = (gcnew System::Windows::Forms::Button());
			   this->setNumClass = (gcnew System::Windows::Forms::Button());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->editLayerNumNeuronsBox = (gcnew System::Windows::Forms::NumericUpDown());
			   this->editLayer = (gcnew System::Windows::Forms::Button());
			   this->initializeFirstLayer = (gcnew System::Windows::Forms::Button());
			   this->resetNetwork = (gcnew System::Windows::Forms::Button());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->label12 = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MaxEpochsInput))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BatchSizeInput))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MomentumRateInput))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LearningRateInput))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ThresholdInput))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addLayerNumNeuronsBox))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->setNumClassBox))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editLayerNumNeuronsBox))->BeginInit();
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
			   this->label2->Size = System::Drawing::Size(332, 29);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Editing the parameters below will not require network reconstruction.";
			   this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
			   // addLayerNumNeuronsBox
			   // 
			   this->addLayerNumNeuronsBox->Location = System::Drawing::Point(686, 225);
			   this->addLayerNumNeuronsBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			   this->addLayerNumNeuronsBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			   this->addLayerNumNeuronsBox->Name = L"addLayerNumNeuronsBox";
			   this->addLayerNumNeuronsBox->Size = System::Drawing::Size(120, 20);
			   this->addLayerNumNeuronsBox->TabIndex = 11;
			   this->addLayerNumNeuronsBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			   // 
			   // setNumClassBox
			   // 
			   this->setNumClassBox->Location = System::Drawing::Point(686, 455);
			   this->setNumClassBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			   this->setNumClassBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			   this->setNumClassBox->Name = L"setNumClassBox";
			   this->setNumClassBox->Size = System::Drawing::Size(120, 20);
			   this->setNumClassBox->TabIndex = 11;
			   this->setNumClassBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			   // 
			   // addLayer
			   // 
			   this->addLayer->Location = System::Drawing::Point(847, 225);
			   this->addLayer->Name = L"addLayer";
			   this->addLayer->Size = System::Drawing::Size(190, 20);
			   this->addLayer->TabIndex = 12;
			   this->addLayer->Text = L"Add layer before first layer";
			   this->addLayer->UseVisualStyleBackColor = true;
			   this->addLayer->Click += gcnew System::EventHandler(this, &ANNSetup::addLayer_Click);
			   // 
			   // removeFirstLayer
			   // 
			   this->removeFirstLayer->Location = System::Drawing::Point(459, 225);
			   this->removeFirstLayer->Name = L"removeFirstLayer";
			   this->removeFirstLayer->Size = System::Drawing::Size(190, 20);
			   this->removeFirstLayer->TabIndex = 12;
			   this->removeFirstLayer->Text = L"Remove first layer";
			   this->removeFirstLayer->UseVisualStyleBackColor = true;
			   this->removeFirstLayer->Click += gcnew System::EventHandler(this, &ANNSetup::removeFirstLayer_Click);
			   // 
			   // setNumClass
			   // 
			   this->setNumClass->Location = System::Drawing::Point(847, 455);
			   this->setNumClass->Name = L"setNumClass";
			   this->setNumClass->Size = System::Drawing::Size(190, 20);
			   this->setNumClass->TabIndex = 12;
			   this->setNumClass->Text = L"Change number of classes";
			   this->setNumClass->UseVisualStyleBackColor = true;
			   this->setNumClass->Click += gcnew System::EventHandler(this, &ANNSetup::setNumClass_Click);
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label8->Location = System::Drawing::Point(608, 31);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(281, 31);
			   this->label8->TabIndex = 0;
			   this->label8->Text = L"Unsafe Construction";
			   // 
			   // label9
			   // 
			   this->label9->Location = System::Drawing::Point(574, 72);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(364, 45);
			   this->label9->TabIndex = 1;
			   this->label9->Text = L"Warning: Editing the layers below below will require network reconstruction. All "
				   L"previous training will be discarded and the weights will be reinitialized";
			   this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			   // 
			   // editLayerNumNeuronsBox
			   // 
			   this->editLayerNumNeuronsBox->Location = System::Drawing::Point(686, 335);
			   this->editLayerNumNeuronsBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			   this->editLayerNumNeuronsBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			   this->editLayerNumNeuronsBox->Name = L"editLayerNumNeuronsBox";
			   this->editLayerNumNeuronsBox->Size = System::Drawing::Size(120, 20);
			   this->editLayerNumNeuronsBox->TabIndex = 11;
			   this->editLayerNumNeuronsBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			   // 
			   // editLayer
			   // 
			   this->editLayer->Location = System::Drawing::Point(847, 335);
			   this->editLayer->Name = L"editLayer";
			   this->editLayer->Size = System::Drawing::Size(190, 20);
			   this->editLayer->TabIndex = 12;
			   this->editLayer->Text = L"Edit number of neurons for first layer";
			   this->editLayer->UseVisualStyleBackColor = true;
			   this->editLayer->Click += gcnew System::EventHandler(this, &ANNSetup::editLayer_Click);
			   // 
			   // initializeFirstLayer
			   // 
			   this->initializeFirstLayer->Location = System::Drawing::Point(459, 455);
			   this->initializeFirstLayer->Name = L"initializeFirstLayer";
			   this->initializeFirstLayer->Size = System::Drawing::Size(190, 20);
			   this->initializeFirstLayer->TabIndex = 12;
			   this->initializeFirstLayer->Text = L"Initialize network";
			   this->initializeFirstLayer->UseVisualStyleBackColor = true;
			   this->initializeFirstLayer->Click += gcnew System::EventHandler(this, &ANNSetup::initializeFirstLayer_Click);
			   // 
			   // resetNetwork
			   // 
			   this->resetNetwork->Location = System::Drawing::Point(459, 333);
			   this->resetNetwork->Name = L"resetNetwork";
			   this->resetNetwork->Size = System::Drawing::Size(190, 20);
			   this->resetNetwork->TabIndex = 12;
			   this->resetNetwork->Text = L"Reset the network";
			   this->resetNetwork->UseVisualStyleBackColor = true;
			   this->resetNetwork->Click += gcnew System::EventHandler(this, &ANNSetup::resetNetwork_Click);
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Location = System::Drawing::Point(686, 205);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(99, 13);
			   this->label10->TabIndex = 13;
			   this->label10->Text = L"Number of Neurons";
			   // 
			   // label11
			   // 
			   this->label11->AutoSize = true;
			   this->label11->Location = System::Drawing::Point(683, 319);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(99, 13);
			   this->label11->TabIndex = 13;
			   this->label11->Text = L"Number of Neurons";
			   // 
			   // label12
			   // 
			   this->label12->AutoSize = true;
			   this->label12->Location = System::Drawing::Point(686, 439);
			   this->label12->Name = L"label12";
			   this->label12->Size = System::Drawing::Size(95, 13);
			   this->label12->TabIndex = 13;
			   this->label12->Text = L"Number of Classes";
			   // 
			   // ANNSetup
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1283, 690);
			   this->Controls->Add(this->label12);
			   this->Controls->Add(this->label11);
			   this->Controls->Add(this->label10);
			   this->Controls->Add(this->resetNetwork);
			   this->Controls->Add(this->initializeFirstLayer);
			   this->Controls->Add(this->setNumClass);
			   this->Controls->Add(this->removeFirstLayer);
			   this->Controls->Add(this->editLayer);
			   this->Controls->Add(this->addLayer);
			   this->Controls->Add(this->setNumClassBox);
			   this->Controls->Add(this->editLayerNumNeuronsBox);
			   this->Controls->Add(this->addLayerNumNeuronsBox);
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
			   this->Controls->Add(this->label9);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label8);
			   this->Controls->Add(this->label1);
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"ANNSetup";
			   this->Text = L"ANNSetup - Batuhan ÇİMŞİT - 432923";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MaxEpochsInput))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BatchSizeInput))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MomentumRateInput))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LearningRateInput))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ThresholdInput))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addLayerNumNeuronsBox))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->setNumClassBox))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->editLayerNumNeuronsBox))->EndInit();
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
	private: System::Void addLayer_Click(System::Object^ sender, System::EventArgs^ e) {
		//Add layer before first layer
		ann->insertLayerBefore(ann->InputLayer, (int)addLayerNumNeuronsBox->Value);
		changed = true;
		removeFirstLayer->Enabled = true;
	}
	private: System::Void editLayer_Click(System::Object^ sender, System::EventArgs^ e) {
		//Edit number of neurons for first layer
		ann->updateLayer(ann->InputLayer, (int)editLayerNumNeuronsBox->Value);
		changed = true;
	}
	private: System::Void setNumClass_Click(System::Object^ sender, System::EventArgs^ e) {
	//Change number of classes
	ann->updateLayer(ann->OutputLayer, (int)setNumClassBox->Value);
	changed = true;
	}
	private: System::Void initializeFirstLayer_Click(System::Object^ sender, System::EventArgs^ e) {
		//Initialize network
		ann->initializeFirstLayer((int)setNumClassBox->Value);
		changed = true;
		initializeFirstLayer->Enabled = false;
		addLayer->Enabled = true;
		editLayer->Enabled = true;
		setNumClass->Enabled = true;
	}
private: System::Void resetNetwork_Click(System::Object^ sender, System::EventArgs^ e) {
	//Reset the network
	ann->clearall();
	changed = true;
	removeFirstLayer->Enabled = false;
	addLayer->Enabled = false;
	editLayer->Enabled = false;
	setNumClass->Enabled = false;
	initializeFirstLayer->Enabled = true;
}
private: System::Void removeFirstLayer_Click(System::Object^ sender, System::EventArgs^ e) {
	//Remove first layer
	ann->removeLayer(ann->InputLayer);
	changed = true;
	if (ann->InputLayer == ann->OutputLayer)
		removeFirstLayer->Enabled = false;
}
};
}
