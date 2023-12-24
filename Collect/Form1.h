#pragma once
#include "Process.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ANN.h"
#include "FCLayer.h"
#include "ANNSetup.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ Set_Net;

	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;




	private:
		/// <summary>
		/// User Defined Variables
		/// </summary>
		//int  class_count = 0, numSample = 0;
		const int inputDim = 2;
		//float* Samples, * targets, * Weights, * bias;
		ANN^ ann = gcnew ANN();

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readDataToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ saveDataToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ testingToolStripMenuItem;
	private: System::Windows::Forms::Button^ Reset_Net;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingResetMomentumsToolStripMenuItem;
	private: System::Windows::Forms::Button^ Quick_Set_Net;
	private: System::Windows::Forms::NumericUpDown^ numClasses;
	private: System::Windows::Forms::NumericUpDown^ classNo;



		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Erforderliche Methode für die Designerunterstützung.
		   /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->numClasses = (gcnew System::Windows::Forms::NumericUpDown());
			   this->Reset_Net = (gcnew System::Windows::Forms::Button());
			   this->Quick_Set_Net = (gcnew System::Windows::Forms::Button());
			   this->Set_Net = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->classNo = (gcnew System::Windows::Forms::NumericUpDown());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->readDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->saveDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->trainingResetMomentumsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->testingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->groupBox1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numClasses))->BeginInit();
			   this->groupBox2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classNo))->BeginInit();
			   this->menuStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->pictureBox1->Location = System::Drawing::Point(13, 35);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(802, 578);
			   this->pictureBox1->TabIndex = 0;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			   this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->numClasses);
			   this->groupBox1->Controls->Add(this->Reset_Net);
			   this->groupBox1->Controls->Add(this->Quick_Set_Net);
			   this->groupBox1->Controls->Add(this->Set_Net);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->groupBox1->Location = System::Drawing::Point(869, 50);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(305, 126);
			   this->groupBox1->TabIndex = 1;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Network Architecture";
			   // 
			   // numClasses
			   // 
			   this->numClasses->Location = System::Drawing::Point(10, 21);
			   this->numClasses->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			   this->numClasses->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			   this->numClasses->Name = L"numClasses";
			   this->numClasses->Size = System::Drawing::Size(97, 20);
			   this->numClasses->TabIndex = 12;
			   this->numClasses->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			   // 
			   // Reset_Net
			   // 
			   this->Reset_Net->Location = System::Drawing::Point(183, 13);
			   this->Reset_Net->Name = L"Reset_Net";
			   this->Reset_Net->Size = System::Drawing::Size(116, 42);
			   this->Reset_Net->TabIndex = 3;
			   this->Reset_Net->Text = L"Reset Network\r\n(Clear Everything)";
			   this->Reset_Net->UseVisualStyleBackColor = true;
			   this->Reset_Net->Click += gcnew System::EventHandler(this, &Form1::Reset_Net_Click);
			   // 
			   // Quick_Set_Net
			   // 
			   this->Quick_Set_Net->Location = System::Drawing::Point(10, 61);
			   this->Quick_Set_Net->Name = L"Quick_Set_Net";
			   this->Quick_Set_Net->Size = System::Drawing::Size(156, 59);
			   this->Quick_Set_Net->TabIndex = 2;
			   this->Quick_Set_Net->Text = L"Quick single layer setup";
			   this->Quick_Set_Net->UseVisualStyleBackColor = true;
			   this->Quick_Set_Net->Click += gcnew System::EventHandler(this, &Form1::Quick_Set_Net_Click);
			   // 
			   // Set_Net
			   // 
			   this->Set_Net->Location = System::Drawing::Point(183, 61);
			   this->Set_Net->Name = L"Set_Net";
			   this->Set_Net->Size = System::Drawing::Size(116, 59);
			   this->Set_Net->TabIndex = 2;
			   this->Set_Net->Text = L"Click here to setup the network";
			   this->Set_Net->UseVisualStyleBackColor = true;
			   this->Set_Net->Click += gcnew System::EventHandler(this, &Form1::Set_Net_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(108, 23);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(69, 13);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"Sınıf Sayısı";
			   // 
			   // groupBox2
			   // 
			   this->groupBox2->Controls->Add(this->classNo);
			   this->groupBox2->Controls->Add(this->label2);
			   this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->groupBox2->Location = System::Drawing::Point(879, 191);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Size = System::Drawing::Size(190, 61);
			   this->groupBox2->TabIndex = 2;
			   this->groupBox2->TabStop = false;
			   this->groupBox2->Text = L"Data Collection";
			   // 
			   // classNo
			   // 
			   this->classNo->Location = System::Drawing::Point(6, 19);
			   this->classNo->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			   this->classNo->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			   this->classNo->Name = L"classNo";
			   this->classNo->Size = System::Drawing::Size(86, 20);
			   this->classNo->TabIndex = 13;
			   this->classNo->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(98, 23);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(81, 13);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Örnek Etiketi";
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->fileToolStripMenuItem,
					   this->processToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			   this->menuStrip1->Size = System::Drawing::Size(1283, 24);
			   this->menuStrip1->TabIndex = 4;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // fileToolStripMenuItem
			   // 
			   this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->readDataToolStripMenuItem,
					   this->saveDataToolStripMenuItem
			   });
			   this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 22);
			   this->fileToolStripMenuItem->Text = L"File";
			   // 
			   // readDataToolStripMenuItem
			   // 
			   this->readDataToolStripMenuItem->Name = L"readDataToolStripMenuItem";
			   this->readDataToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			   this->readDataToolStripMenuItem->Text = L"Read_Data";
			   this->readDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::readDataToolStripMenuItem_Click);
			   // 
			   // saveDataToolStripMenuItem
			   // 
			   this->saveDataToolStripMenuItem->Name = L"saveDataToolStripMenuItem";
			   this->saveDataToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			   this->saveDataToolStripMenuItem->Text = L"Save_Data";
			   this->saveDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveDataToolStripMenuItem_Click);
			   // 
			   // processToolStripMenuItem
			   // 
			   this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->trainingToolStripMenuItem,
					   this->trainingResetMomentumsToolStripMenuItem, this->testingToolStripMenuItem
			   });
			   this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			   this->processToolStripMenuItem->Size = System::Drawing::Size(59, 22);
			   this->processToolStripMenuItem->Text = L"Process";
			   // 
			   // trainingToolStripMenuItem
			   // 
			   this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			   this->trainingToolStripMenuItem->Size = System::Drawing::Size(227, 22);
			   this->trainingToolStripMenuItem->Text = L"Training";
			   this->trainingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainingToolStripMenuItem_Click);
			   // 
			   // trainingResetMomentumsToolStripMenuItem
			   // 
			   this->trainingResetMomentumsToolStripMenuItem->Name = L"trainingResetMomentumsToolStripMenuItem";
			   this->trainingResetMomentumsToolStripMenuItem->Size = System::Drawing::Size(227, 22);
			   this->trainingResetMomentumsToolStripMenuItem->Text = L"Training (Reset Momentums)";
			   this->trainingResetMomentumsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainingResetMomentumsToolStripMenuItem_Click);
			   // 
			   // testingToolStripMenuItem
			   // 
			   this->testingToolStripMenuItem->Name = L"testingToolStripMenuItem";
			   this->testingToolStripMenuItem->Size = System::Drawing::Size(227, 22);
			   this->testingToolStripMenuItem->Text = L"Testing";
			   this->testingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testingToolStripMenuItem_Click);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(869, 291);
			   this->textBox1->Multiline = true;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			   this->textBox1->Size = System::Drawing::Size(247, 283);
			   this->textBox1->TabIndex = 5;
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1283, 633);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->groupBox2);
			   this->Controls->Add(this->groupBox1);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"Form1";
			   this->Text = L"ANN - Batuhan ÇİMŞİT - 432923";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numClasses))->EndInit();
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox2->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->classNo))->EndInit();
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
		   void draw_sample(int temp_x, int temp_y, int label) {
			   Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			   switch (label) {
			   case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			   case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			   case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			   case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
			   case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			   case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			   default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			   }//switch
			   pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			   pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		   }//draw_sample
#pragma endregion
	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (!ann->Initialized)
			MessageBox::Show(L"The Network Architeture should be firtly set up");
		else {
			array<double>^ x = gcnew array<double>(2);
			int temp_x = (System::Convert::ToInt32(e->X));
			int temp_y = (System::Convert::ToInt32(e->Y));
			x[0] = double(temp_x - (pictureBox1->Width / 2));
			x[1] = double((pictureBox1->Height / 2) - temp_y);
			int label;
			int numLabel = Convert::ToInt32(classNo->Value);
			if (numLabel > (ann->OutputLayer->NumNeurons == 1 ? 2 : ann->OutputLayer->NumNeurons))
				MessageBox::Show(L"The class label cannot be greater than the maximum number of classes.");
			else {
				label = numLabel - 1; //Döngüler 0 dan başladığından, label değeri 0 dan başlaması için bir eksiği alınmıştır
				ann->addSample(x, label);
				//if (numSample == 0) { //Dinamik alınan ilk örnek için sadece
				//	numSample = 1;
				//	Samples = new float[numSample * inputDim]; targets = new float[numSample];
				//	for (int i = 0; i < inputDim; i++)
				//		Samples[i] = x[i];
				//	targets[0] = float(label);
				//}
				//else {
				//	numSample++;
				//	Samples = Add_Data(Samples, numSample, x, inputDim);
				//	targets = Add_Labels(targets, numSample, label);
				//}//else
				draw_sample(temp_x, temp_y, label);
				delete[] x;
			}//else of if (Etiket ...
		}//else
	}//pictureMouseClick
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		//Ana eksen doðrularini cizdir
		Pen^ pen = gcnew Pen(Color::Black, 3.0f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
	}
	private: System::Void Set_Net_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			this->Hide();
			ANNSetup^ ann_setup = gcnew ANNSetup(ann);
			ann_setup->ShowDialog();
			this->Show();
			if (ann_setup->DialogResult == System::Windows::Forms::DialogResult::OK)
				MessageBox::Show(L"Network is set up");

			if (ann->Initialized)
				Quick_Set_Net->Enabled = false;
			else
				Quick_Set_Net->Enabled = true;


			Set_Net->Text = L" Network is Ready : \r\n Click to edit layers ";
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}//Set_Net
	private: System::Void readDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		int^ width = gcnew int;
		int^ height = gcnew int;
		try
		{
			ann->loadFromFile(width, height);
			// Veri Kümesini okunacak 

			for (int i = 0; i < ann->RawInput->Length; i++) {
				draw_sample(ann->RawInput[i][0] + *width, *height - ann->RawInput[i][1], ann->Target[i]);
			}
			//draw_sample(temp_x, temp_y, label);
			MessageBox::Show(L"File read successfully");
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}

		Quick_Set_Net->Enabled = false;

	}//Read_Data
	private: System::Void saveDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			ann->saveToFile(pictureBox1->Width, pictureBox1->Height);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}//Save_Data
	private: System::Void testingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//Reset pictureBox
		try {
			pictureBox1->Image = nullptr;
			pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);

			array<double>^ x = gcnew array<double>(inputDim);
			array<double>^ mean = ann->Mean;
			array<double>^ std = ann->Std;
			int num, temp_x, temp_y;
			Bitmap^ surface = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = surface;
			Color c;
			for (int row = 0; row < pictureBox1->Height; row += 2) {
				for (int column = 0; column < pictureBox1->Width; column += 2) {
					x[0] = (double)(column - (pictureBox1->Width / 2));
					x[1] = (double)((pictureBox1->Height / 2) - row);
					//x[0] = (x[0] - mean[0]) / std[0];
					//x[1] = (x[1] - mean[1]) / std[1];
					num = ann->predictRaw(x);
					//MessageBox::Show("merhaba: class :" + System::Convert::ToString(numClass));
					switch (num) {
						//case 0: c = Color::FromArgb(0, 0, 0); break;
						//case 1: c = Color::FromArgb(255, 0, 0); break;
						//case 2: c = Color::FromArgb(0, 255, 0); break;
						//case 3: c = Color::FromArgb(0, 0, 255); break;
						//default: c = Color::FromArgb(0, 255, 255);
					case 0: c = Color::Black; break;
					case 1: c = Color::Red; break;
					case 2: c = Color::Blue; break;
					case 3: c = Color::Green; break;
					case 4: c = Color::Yellow; break;
					case 5: c = Color::Orange; break;
					default: c = Color::YellowGreen;
					}//switch
					surface->SetPixel(column, row, c);
				}//column
				//MessageBox::Show("merhaba2: class :" + System::Convert::ToString(numClass));
			}
			//Samples Draw
			Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			MessageBox::Show(L"Drawing Samples");
			for (int i = 0; i < ann->RawInput->Length; i++) {
				switch (int(ann->Target[i])) {
				case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
				case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
				case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
				case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
				case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
				case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
				default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
				}//switch
				temp_x = int(ann->RawInput[i][0]) + pictureBox1->Width / 2;
				temp_y = pictureBox1->Height / 2 - int(ann->RawInput[i][1]);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}//Testing
	private: System::Void trainingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!ann->Initialized)
			MessageBox::Show(L"The Network Architeture should be firtly set up");
		else
		{
			try {
				MessageBox::Show(L"Training about to start.");
				ann->Train();
				MessageBox::Show(L"Training is completed");
				textBox1->Text = L"";
				textBox1->Text += L"Epochs: " + System::Convert::ToString(ann->Epochs) + L"\r\n";
				textBox1->Text += L"Final Error: " + System::Convert::ToString(ann->ErrorLog[ann->ErrorLog->Length - 1]) + L"\r\n";
				textBox1->Text += L"\r\n" + L"Error Log:" + L"\r\n";
				for (int i = 0; i < ann->ErrorLog->Length; i++)
				{
					textBox1->Text += L"Epoch " + System::Convert::ToString(i) + L" Error: " + System::Convert::ToString(ann->ErrorLog[i]) + L"\r\n";
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
	}
	private: System::Void Reset_Net_Click(System::Object^ sender, System::EventArgs^ e) {
		ann->clearall();
		Set_Net->Text = L"Click here to setup the network";
		Quick_Set_Net->Text = L"Quick single layer setup";
		MessageBox::Show(L"Network is resetted");
		Quick_Set_Net->Enabled = true;

		pictureBox1->Image = nullptr;
		pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
		pictureBox1->Refresh();


	}
	private: System::Void trainingResetMomentumsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!ann->Initialized)
			MessageBox::Show(L"The Network Architeture should be firtly set up");
		else
		{
			try {
				MessageBox::Show(L"Training about to start.");
				ann->InputLayer->resetMomentums();
				ann->Train();
				MessageBox::Show(L"Training is completed");
				textBox1->Text = L"";
				textBox1->Text += L"Epochs: " + System::Convert::ToString(ann->Epochs) + L"\r\n";
				textBox1->Text += L"Final Error: " + System::Convert::ToString(ann->ErrorLog[ann->ErrorLog->Length - 1]) + L"\r\n";
				textBox1->Text += L"\r\n" + L"Error Log:" + L"\r\n";
				for (int i = 0; i < ann->ErrorLog->Length; i++)
				{
					textBox1->Text += L"Epoch " + System::Convert::ToString(i) + L" Error: " + System::Convert::ToString(ann->ErrorLog[i]) + L"\r\n";
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
	}
	private: System::Void Quick_Set_Net_Click(System::Object^ sender, System::EventArgs^ e) {
		// Network is constructed
		try {
			if (!ann->Initialized)
				ann->pickNumClass((int)numClasses->Value);
			else if (ann->InputLayer != ann->OutputLayer)
				throw gcnew Exception(L"Network is multi-layer");
			else
				ann->updateLayer(ann->OutputLayer, Convert::ToInt32((int)numClasses->Value) == 2 ? 1 : Convert::ToInt32((int)numClasses->Value));

			Quick_Set_Net->Text = L"Edit number of classes \r\n (Works only for single layer networks)";
			// Network is initialized

			MessageBox::Show(L"Network is set up");
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	};
}
