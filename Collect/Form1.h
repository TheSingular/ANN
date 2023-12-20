#pragma once
#include "Process.h"
#include <iostream>
#include <fstream>
#include <string>

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
	private: System::Windows::Forms::ComboBox^ ClassCountBox;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ ClassNoBox;

	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// User Defined Variables
		int  class_count = 0, numSample = 0, inputDim = 2;
		float *Samples, *targets, *Weights, *bias;

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

		   /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Set_Net = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ClassCountBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ClassNoBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(20, 54);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1203, 889);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Set_Net);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->ClassCountBox);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox1->Location = System::Drawing::Point(1304, 77);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Size = System::Drawing::Size(300, 154);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Network Architecture";
			// 
			// Set_Net
			// 
			this->Set_Net->Location = System::Drawing::Point(15, 94);
			this->Set_Net->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Set_Net->Name = L"Set_Net";
			this->Set_Net->Size = System::Drawing::Size(196, 51);
			this->Set_Net->TabIndex = 2;
			this->Set_Net->Text = L"Network Setting";
			this->Set_Net->UseVisualStyleBackColor = true;
			this->Set_Net->Click += gcnew System::EventHandler(this, &Form1::Set_Net_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(162, 35);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Sınıf Sayısı";
			// 
			// ClassCountBox
			// 
			this->ClassCountBox->FormattingEnabled = true;
			this->ClassCountBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"2", L"3", L"4", L"5", L"6", L"7" });
			this->ClassCountBox->Location = System::Drawing::Point(15, 31);
			this->ClassCountBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->ClassCountBox->Name = L"ClassCountBox";
			this->ClassCountBox->Size = System::Drawing::Size(121, 28);
			this->ClassCountBox->TabIndex = 0;
			this->ClassCountBox->Text = L"2";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->ClassNoBox);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox2->Location = System::Drawing::Point(1318, 294);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox2->Size = System::Drawing::Size(285, 94);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Data Collection";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(147, 35);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Örnek Etiketi";
			// 
			// ClassNoBox
			// 
			this->ClassNoBox->FormattingEnabled = true;
			this->ClassNoBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9"
			});
			this->ClassNoBox->Location = System::Drawing::Point(10, 31);
			this->ClassNoBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->ClassNoBox->Name = L"ClassNoBox";
			this->ClassNoBox->Size = System::Drawing::Size(110, 28);
			this->ClassNoBox->TabIndex = 0;
			this->ClassNoBox->Text = L"1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1314, 408);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->processToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(2194, 35);
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
			this->fileToolStripMenuItem->Size = System::Drawing::Size(54, 29);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// readDataToolStripMenuItem
			// 
			this->readDataToolStripMenuItem->Name = L"readDataToolStripMenuItem";
			this->readDataToolStripMenuItem->Size = System::Drawing::Size(197, 34);
			this->readDataToolStripMenuItem->Text = L"Read_Data";
			this->readDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::readDataToolStripMenuItem_Click);
			// 
			// saveDataToolStripMenuItem
			// 
			this->saveDataToolStripMenuItem->Name = L"saveDataToolStripMenuItem";
			this->saveDataToolStripMenuItem->Size = System::Drawing::Size(197, 34);
			this->saveDataToolStripMenuItem->Text = L"Save_Data";
			this->saveDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveDataToolStripMenuItem_Click);
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->trainingToolStripMenuItem,
					this->testingToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(88, 29);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(175, 34);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// testingToolStripMenuItem
			// 
			this->testingToolStripMenuItem->Name = L"testingToolStripMenuItem";
			this->testingToolStripMenuItem->Size = System::Drawing::Size(175, 34);
			this->testingToolStripMenuItem->Text = L"Testing";
			this->testingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testingToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1304, 460);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(368, 433);
			this->textBox1->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2194, 974);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
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
			if( class_count == 0)
				MessageBox::Show("The Network Architeture should be firtly set up");
			else {
				float* x= new float[inputDim];
				int temp_x = (System::Convert::ToInt32(e->X));
				int temp_y = (System::Convert::ToInt32(e->Y));
				x[0] = float(temp_x - (pictureBox1->Width / 2));
				x[1] = float(pictureBox1->Height / 2 - temp_y);
				int label;
				int numLabel = Convert::ToInt32(ClassNoBox->Text);
				if (numLabel > class_count)
					MessageBox::Show("The class label cannot be greater than the maximum number of classes.");
				else {
					label = numLabel - 1; //Döngüler 0 dan başladığından, label değeri 0 dan başlaması için bir eksiği alınmıştır
					if (numSample == 0) { //Dinamik alınan ilk örnek için sadece
						numSample = 1;  
						Samples = new float[numSample * inputDim]; targets = new float[numSample];
						for (int i = 0; i < inputDim; i++)
							Samples[i] = x[i];
						targets[0] = float(label);
					}
					else {
						numSample++;
						Samples = Add_Data(Samples, numSample, x, inputDim);
						targets = Add_Labels(targets, numSample, label);
					}//else
					draw_sample(temp_x, temp_y, label);
					label3->Text = "Samples Count: " + System::Convert::ToString(numSample);
					delete [] x;
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
			// Network is constructed
			class_count = Convert::ToInt32(ClassCountBox->Text);
			Weights = new float[class_count * inputDim];
			bias = new float[class_count];
			//initialize weights for single layer
			if (class_count > 2) {
				Weights = init_array_random(class_count * inputDim);
				bias = init_array_random(class_count);
			}
			else {
				int numOutNeuron = 1;
				Weights = init_array_random(inputDim);
				bias = init_array_random(numOutNeuron);
			}
			Set_Net->Text = " Network is Ready : ";
        }//Set_Net
        private: System::Void readDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			char** c = new char *[2];
			// Veri Kümesini okunacak 
			MessageBox::Show("Veri Kümesini Yükleyin");
			c[0] = "../Data/Samples.txt";
			c[1] = "../Data/weights.txt";
			std::ifstream file;
			int num, w, h, Dim, label;
			file.open(c[0]); 
			if (file.is_open()) {
				//MessageBox::Show("Dosya acildi");
				file >> Dim>> w >> h >>num;
				textBox1->Text += "Dimension: "+ Convert::ToString(Dim) + "- Width: "+ Convert::ToString(w)+" - Height: "+ Convert::ToString(h)+ " - Number of Class: "+ Convert::ToString(num) +"\r\n";
				// Set network values
				class_count = num;
				inputDim = Dim;
				Weights = new float[class_count * inputDim];
				bias = new float[class_count];
				numSample = 0;
				float* x = new float[inputDim];
				while (!file.eof())
				{
					if (numSample == 0) { //ilk örnek için sadece
						numSample = 1;
						Samples = new float[inputDim]; targets = new float[numSample];
						for (int i = 0; i < inputDim; i++)
							   file>>Samples[i];
						file >> targets[0];
					}
					else {
						
						for (int i = 0; i < inputDim; i++)
							file >> x[i];
						file >> label;
						if (!file.eof()) {
							numSample++;
							Samples = Add_Data(Samples, numSample, x, inputDim);
							targets = Add_Labels(targets, numSample, label);
						}
					}//else
				} //while
				delete[]x;
				file.close();
				for (int i = 0; i < numSample; i++) {
					draw_sample(Samples[i*inputDim]+w, h-Samples[i*inputDim+1], targets[i]);
					for (int j = 0; j < inputDim; j++)
						textBox1->Text += Convert::ToString(Samples[i * inputDim + j]) + " ";
					textBox1->Text += Convert::ToString(targets[i]) + "\r\n";
				}
				//draw_sample(temp_x, temp_y, label);
				label3->Text = "Samples Count: " + System::Convert::ToString(numSample);
				MessageBox::Show("Dosya basari ile okundu");
			}//file.is_open
			else MessageBox::Show("Dosya acilamadi");
			//Get weights
			int Layer;
			file.open(c[1]);
			if (file.is_open()) {
				file >> Layer >> Dim >> num;
				class_count = num;
				inputDim = Dim;
				Weights = new float[class_count * inputDim];
				bias = new float[class_count];
				textBox1->Text += "Layer: " + Convert::ToString(Layer) + " Dimension: " + Convert::ToString(Dim) + " numClass:" + Convert::ToString(num) + "\r\n";
				while (!file.eof())
				{
					for (int i = 0; i < class_count; i++)
						for (int j = 0; j < inputDim; j++)
							file >> Weights[i * inputDim + j];
					for (int i = 0; i < class_count; i++)
						file >> bias[i];
				}
				file.close();
			}//file.is_open
			delete[]c;
        }//Read_Data
        private: System::Void saveDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (numSample != 0) {
				char** c = new char* [2];
				// Veri Kümesi yazýlacak
				c[0] = "../Data/Samples.txt";
				c[1] = "../Data/weights.txt";
				std::ofstream ofs(c[0]);
				if (!ofs.bad()) {
					// Width,  Height, number of Class, data+label
					ofs <<inputDim<<" "<< pictureBox1->Width / 2 << " " << pictureBox1->Height / 2 <<" "<<class_count<< std::endl;
					for (int i = 0; i < numSample; i++) {
						for (int d = 0; d < inputDim; d++)
							ofs << Samples[i*inputDim+d] << " ";
						ofs << targets[i] << std::endl;
					}
					ofs.close();
				}
				else MessageBox::Show("Samples icin dosya acilamadi");
				std::ofstream file(c[1]);
				if (!file.bad()) {
					// #Layer Dimension numClass weights biases
					file << 1 <<" "<<inputDim << " " << class_count << std::endl;
					for (int k = 0; k < class_count*inputDim; k++) 
							file << Weights[k] << " ";
					file << std::endl;
					for (int k = 0; k < class_count; k++)
						file << bias[k] << " ";
					file.close();
				}
				else MessageBox::Show("Weight icin dosya acilamadi");
				delete[]c;	
			}
			else MessageBox::Show("At least one sample should be given");
        }//Save_Data
	    private: System::Void testingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			float* x = new float[2];
			float* mean = new float[2];
			float* std = new float[2];
			//mean ve std tekrar hesaplanýyor, Aslýnda eðitimde bunlar saklanmalý oradan alýnmalý
			Z_Score_Parameters(Samples, numSample, inputDim, mean, std);
			//MessageBox::Show("mean: "+System::Convert::ToString(mean[0])+ " "+ System::Convert::ToString(mean[1]));
			int num, temp_x, temp_y;
			Bitmap^ surface = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = surface;
			Color c;
			for (int row = 0; row < pictureBox1->Height; row += 2) {
				for (int column = 0; column < pictureBox1->Width; column += 2) {
					x[0] = (float)(column - (pictureBox1->Width / 2));
					x[1] = (float)((pictureBox1->Height / 2) - row);
					x[0] = (x[0] - mean[0]) / std[0];
					x[1] = (x[1] - mean[1]) / std[1];
					num = Test_Forward(x, Weights, bias, class_count, inputDim);
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
			MessageBox::Show("Örnekler cizilecek");
			for (int i = 0; i < numSample; i++) {
				switch (int(targets[i])) {
				case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
				case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
				case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
				case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
				case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
				case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
				default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
				}//switch
				temp_x = int(Samples[i * inputDim]) + pictureBox1->Width / 2;
				temp_y = pictureBox1->Height / 2 - int(Samples[i * inputDim + 1]);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
			}
			delete[] x;
			delete[] mean;
			delete[] std;
	    }//Testing
};
}
