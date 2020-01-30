#pragma once

#include <direct.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <io.h>
//#include <time.h> 
#include <windows.h> 
#define _USE_MATH_DEFINES
//#include <algorithm>
#include <cmath>
#include <cstdlib> /* atoi   */
//#include <chrono>
#include <fstream> /* ifstream class */
#include <iostream>
//#include <map>
#include <msclr/marshal.h>		//.NET string to C-style string
#include <msclr/marshal_cppstd.h> // .NET string to STL string
#include <string>  /* string class   */
#include <sstream> /* istringstream class */
//#include <set>
//#include <tuple>
#include <vector>

#include "Header.h"

#define PI	3.14159265358979324
//座標轉換
#define WGS84_A 6378137.0000
#define WGS84_F 1/298.2572229328697
#define GRS80_A 6378137.0000
#define GRS80_F 1/298.257222101
#define GRS67_A 6378160.0000
#define GRS67_B 6356774.7192
#define GRS67_F 1/298.247167427

//座標系統
#define USGRS67 0
#define USGRS80 1


# define PRECISION 5

#using <System.dll>
namespace Project1 {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;


	PointXYZ XYZtemp;
	vector<PointXYZ> xyzi;
	vector<PointXYZ> xyzM;

	GetID getIDtemp;
	vector<GetID> KML_ID;
	KmlFileXYZ TKMLtemp;
	vector<KmlFileXYZ> KMLAll;//存放讀取全區的kml
	vector<KmlFileXYZ> NewKMLAll;//存放讀取全區的kml
	vector<KmlFileXYZ> KML_GrdXYZ;
	vector<KmlFileXYZ> Point2_XYZ;

	XYZarraytemp TXYZtemp;
	vector<XYZarraytemp> TXYZ;//暫存用
	
	int polygon01 = 0, polygon02 = 0;

	double axx = 6378137.0;
	double bxx = 6356752.314245;
	double lon0 = 121 * M_PI / 180;
	double k0 = 0.9999;
	int dx = 250000;
	double Wgs84toTwd97X01, Wgs84toTwd97Y01;
	double Wgs84toTwd97X02, Wgs84toTwd97Y02;
	double XYZ97to84_x, XYZ97to84_y, XYZ97to84_z;

	char *D_filename;
	char *D_path;
	char D_name[256];
	char build_name[256];
	char build_ID[16];

	int StartKML_ID = 0;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(16, 15);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 42);
			this->button1->TabIndex = 0;
			this->button1->Text = L"輸入LOD 1模型(KML)";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(264, 18);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(60, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"確定";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(17, 78);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(332, 101);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"統一調整高度(平頂)";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label1->Location = System::Drawing::Point(19, 24);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"輸入高度值：";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(12, 60);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(312, 30);
			this->button3->TabIndex = 2;
			this->button3->Text = L"ExportKML";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox1->Location = System::Drawing::Point(148, 18);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(107, 30);
			this->textBox1->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Location = System::Drawing::Point(20, 385);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Size = System::Drawing::Size(329, 158);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"產生屋脊線";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 9));
			this->label4->Location = System::Drawing::Point(208, 90);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 15);
			this->label4->TabIndex = 11;
			this->label4->Text = L"~";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 9));
			this->label6->Location = System::Drawing::Point(20, 90);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(97, 15);
			this->label6->TabIndex = 10;
			this->label6->Text = L"第二組屋脊線";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 9));
			this->label7->Location = System::Drawing::Point(208, 51);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(15, 15);
			this->label7->TabIndex = 9;
			this->label7->Text = L"~";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->textBox6->Location = System::Drawing::Point(131, 81);
			this->textBox6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(68, 27);
			this->textBox6->TabIndex = 8;
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->textBox7->Location = System::Drawing::Point(231, 81);
			this->textBox7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(68, 27);
			this->textBox7->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 9));
			this->label5->Location = System::Drawing::Point(20, 51);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(97, 15);
			this->label5->TabIndex = 6;
			this->label5->Text = L"第一組屋脊線";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 9));
			this->label2->Location = System::Drawing::Point(11, 26);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 15);
			this->label2->TabIndex = 4;
			this->label2->Text = L"輸入要切割屋脊點：";
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button5->Location = System::Drawing::Point(13, 116);
			this->button5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(304, 34);
			this->button5->TabIndex = 3;
			this->button5->Text = L"ExportKML";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->textBox3->Location = System::Drawing::Point(231, 45);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(68, 27);
			this->textBox3->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->textBox2->Location = System::Drawing::Point(131, 45);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(68, 27);
			this->textBox2->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button9);
			this->groupBox3->Controls->Add(this->button8);
			this->groupBox3->Controls->Add(this->button7);
			this->groupBox3->Controls->Add(this->button6);
			this->groupBox3->Controls->Add(this->textBox5);
			this->groupBox3->Controls->Add(this->textBox4);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Location = System::Drawing::Point(19, 191);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Size = System::Drawing::Size(327, 170);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"調整單點高度(斜面)";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(181, 92);
			this->button9->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(137, 32);
			this->button9->TabIndex = 6;
			this->button9->Text = L"刪除";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button8->Location = System::Drawing::Point(213, 55);
			this->button8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(105, 28);
			this->button8->TabIndex = 5;
			this->button8->Text = L"NextPoint";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button7->Location = System::Drawing::Point(24, 129);
			this->button7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(295, 31);
			this->button7->TabIndex = 4;
			this->button7->Text = L"ExportKML";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button6->Location = System::Drawing::Point(24, 92);
			this->button6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(147, 32);
			this->button6->TabIndex = 3;
			this->button6->Text = L"設定";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox5->Location = System::Drawing::Point(105, 55);
			this->textBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(99, 30);
			this->textBox5->TabIndex = 2;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox4->Location = System::Drawing::Point(21, 55);
			this->textBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(75, 30);
			this->textBox4->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(19, 28);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(199, 19);
			this->label3->TabIndex = 0;
			this->label3->Text = L"輸入單點編號與高度：";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(365, 558);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"半自動化-屋頂調整系統";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->Reset();
		openFileDialog1->InitialDirectory = "";
		openFileDialog1->Filter = "(*.kml)|*.KML";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			
			D_filename = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
			String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
			D_path = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));
			String ^CSV_name = System::IO::Path::GetFileNameWithoutExtension(openFileDialog1->FileName);
			char *na = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_name)));

			strcpy(build_ID, na);
			//D_name
			strcpy(D_name, D_path);
			strcat(D_name,"\\");
			strcat(D_name, na);
			strcpy(build_name, D_name);			
			strcat(D_name, "_new.kml");

			KMLAll.clear();
			KML_GrdXYZ.clear();
			KML_ID.clear();
			NewKMLAll.clear();
			StartKML_ID = 0;

			LoadKML(D_filename);//PointToTran//01_ReadMeFile.txt
			char* str;

			if ((int)KMLAll.size()>0)
				str = floatToString(KMLAll[0].z); 
			String ^getZ = gcnew String(str);
			this->textBox1->Text = getZ;
			//FILE *fp = fopen("D:\\程式區\\Project4\\temp\\a.txt","w");
			//for (int i = 0; i < KMLAll.size(); i++)
			//{
			//	fprintf(fp, "%d %d\n", KMLAll[i].Id, KMLAll[i].Qflag);
			//	fprintf(fp, "%lf %lf %lf\n", KMLAll[i].x, KMLAll[i].y, KMLAll[i].z);
			//}			
			//fclose(fp);
			//fp = fopen("D:\\程式區\\Project4\\temp\\b.txt", "w");
			//for (int i = 0; i < KML_ID.size(); i++)
			//{
			//	fprintf(fp, "%d%s\n", KML_ID[i].NO, KML_ID[i].name);
			//}
			//fclose(fp);
			//fp = fopen("D:\\程式區\\Project4\\temp\\c.txt", "w");
			//for (int i = 0; i < KML_GrdXYZ.size(); i++)
			//{
			//	fprintf(fp, "%lf %lf %lf\n", KML_GrdXYZ[i].x, KML_GrdXYZ[i].y, KML_GrdXYZ[i].z);
			//}
			//fclose(fp);

			//ExportKML(filename,name);
			
			SeePointZ();

			MessageBox::Show("完成");

		}

	}
			 char* floatToString(float num)
			 {
				 int whole_part = num;
				 int digit = 0, reminder = 0;
				 int log_value = log10(num), index = log_value;
				 long wt = 0;

				 //String containg result
				 char* str = new char[20];

				 //Initilise stirng to zero
				 memset(str, 0, 20);

				 //Extract the whole part from float num
				 for (int i = 1; i <log_value + 2; i++)
				 {
					 wt = pow(10.0, i);
					 reminder = whole_part % wt;
					 digit = (reminder - digit) / (wt / 10);

					 //Store digit in string
					 str[index--] = digit + 48;//ASCII value of digit = digit + 48
					 if (index == -1)
						 break;
				 }

				 index = log_value + 1;
				 str[index] = '.';

				 float fraction_part = num - whole_part;
				 float tmp1 = fraction_part, tmp = 0;

				 //Extract the fraction part from num
				 for (int i = 1; i <PRECISION; i++)
				 {
					 wt = 10;
					 tmp = tmp1 * wt;
					 digit = tmp;

					 //Store digit in string
					 str[++index] = digit + 48;//ASCII value of digit = digit + 48
					 tmp1 = tmp - digit;
				 }

				 return str;
			 }


			 void LoadKML(char filename[512])
			 {
				 char buf[25000] = { '\0' };
				 char bufNO[512] = { '\0' };
				 FILE *fkml = fopen(filename, "r");				 

				 char Build_NO[80] = "<td>FID</td>";
				 char check_coordinates[80] = "<coordinates>";
				 char check_outerBoundaryIs[80] = "<outerBoundaryIs>";
				 char check_innerBoundaryIs[80] = "<innerBoundaryIs>";
				 char check_LinearRing[80] = "<LinearRing>";

				 char *locNO = { '\0' };
				 char *loc = { '\0' };
				 char *locInner = { '\0' };
				 char *locInner2 = { '\0' };

				 int Qflag = 0;
				 int Kcount = 0;
				 int KMLTemp_count = 0;
				 int ta = 0;
				 int a = 0;
				 
				 
				 while (fgets(buf, 25000, fkml) != NULL) {

					 //字串搜尋 比對
					 locNO = strstr(buf, Build_NO);
					 if (locNO != NULL)
					 {
						 fgets(bufNO, 512, fkml);
						 fgets(bufNO, 512, fkml);

						 strcpy(getIDtemp.name, bufNO);
						 sscanf(bufNO, "			<td>%d</td>", &getIDtemp.NO);
						 KML_ID.push_back(getIDtemp);
					 }

					 //字串搜尋 比對
					 loc = strstr(buf, check_outerBoundaryIs);
					 if (loc != NULL)
					 {
						 fgets(buf, 25000, fkml);
						 fgets(buf, 25000, fkml);
						 fgets(buf, 25000, fkml);
						 //清空空白
						 //string *tmpStr = new string(buf);
						 //tmpStr->erase(tmpStr->begin(), tmpStr->begin() + tmpStr->find_first_not_of("								"));
						 //strcpy_s(buf, sizeof(buf) / sizeof(buf[0]), tmpStr->c_str());

						 //Kcount = AnalysisKMLxyz(buf, getIDtemp.NO);
						 Kcount = AnalysisPolygonxyz(buf, getIDtemp.NO);
						 //KMLTemp_count = KMLTemp_count + 1;

						 Qflag = Qflag + 1;
						 ta = ta + 1;
					 }

					 //字串搜尋 比對
					 locInner = strstr(buf, check_innerBoundaryIs);
					 if (locInner != NULL)
					 {

						 fgets(buf, 25000, fkml);
						 fgets(buf, 25000, fkml);
						 fgets(buf, 25000, fkml);
						 //清空空白
						 //string *tmpStr = new string(buf);
						 //tmpStr->erase(tmpStr->begin(), tmpStr->begin() + tmpStr->find_first_not_of("								"));
						 //strcpy_s(buf, sizeof(buf) / sizeof(buf[0]), tmpStr->c_str());
						 Kcount = AnalysisKMLxyzA(buf, getIDtemp.NO);

						 fgets(buf, 25000, fkml);
						 fgets(buf, 25000, fkml);
						 fgets(buf, 25000, fkml);

						 locInner2 = strstr(buf, check_LinearRing);
						 while (locInner2 != NULL)
						 {
							 fgets(buf, 25000, fkml);
							 fgets(buf, 25000, fkml);
							 //清空空白
							 //string *tmpStr = new string(buf);
							 //tmpStr->erase(tmpStr->begin(), tmpStr->begin() + tmpStr->find_first_not_of("								"));
							 //strcpy_s(buf, sizeof(buf) / sizeof(buf[0]), tmpStr->c_str());
							 Kcount = AnalysisKMLxyzA(buf, getIDtemp.NO);

							 fgets(buf, 25000, fkml);
							 fgets(buf, 25000, fkml);
							 locInner2 = strstr(buf, check_LinearRing);
						 }

					 }

				 }

			 }

			 //分析讀到的<coordinates>下一行中的所有的xyz(Loadkmlarray)
			 int AnalysisPolygonxyz(char buf[25000], int KMLTemp_count)
			 {
				 TXYZ.clear();

				 char *pch01 = NULL;
				 char *context = NULL;
				 char* pSplitStr01 = " "; // 用 "_" 來分割字串
				 char* pSplitStr02 = ","; // 用 "_" 來分割字串
				 int i = 0; int j = 0;
				 bool YZ = false;

				 //讀取第一筆( x,y,z )= pch01
				 //pch01 = strtok(buf, pSplitStr01);
				 pch01 = strtok_s(buf, pSplitStr01, &context);
				 if (pch01 != NULL)
				 {
					 //strcpy(TXYZtemp.xyz, pch01);
					 strcpy_s(TXYZtemp.xyz, sizeof(TXYZtemp.xyz) / sizeof(TXYZtemp.xyz[0]), pch01);
					 TXYZ.push_back(TXYZtemp);
					 i = i + 1;
					 while (pch01 != NULL)
					 {
						 //pch01 = strtok(NULL, pSplitStr01);
						 pch01 = strtok_s(NULL, pSplitStr01, &context);
						 if (pch01 != NULL && strlen(pch01) >1)
						 {
							 //strcpy(TXYZtemp.xyz, pch01);
							 strcpy_s(TXYZtemp.xyz, sizeof(TXYZtemp.xyz) / sizeof(TXYZtemp.xyz[0]), pch01);
							 TXYZ.push_back(TXYZtemp);
							 i = i + 1;
						 }
					 }
				 }

				// KMLtemp.id = KMLTemp_count;
				// KMLtemp.count = i;
				// Kcount.push_back(KMLtemp);

				 for (j = 0; j < (int)TXYZ.size(); j++)
				 {
					 YZ = false;
					 //pch01 = strtok(TXYZ[j].xyz, pSplitStr02);
					 pch01 = strtok_s(TXYZ[j].xyz, pSplitStr02, &context);
					 if (pch01 != NULL)
					 {
						 TKMLtemp.x = atof(pch01);
						 while (pch01 != NULL)
						 {
							 //pch01 = strtok(NULL, pSplitStr02);
							 pch01 = strtok_s(NULL, pSplitStr02, &context);
							 if (pch01 != NULL && strlen(pch01) >1)
							 {
								 if (YZ == false)
								 {
									 TKMLtemp.y = atof(pch01);
									 YZ = !YZ;
								 }
								 else  if (YZ == true)
								 {
									 TKMLtemp.z = atof(pch01);
									 YZ = !YZ;
									 TKMLtemp.Id = j;
									 TKMLtemp.Show = 0;
									 TKMLtemp.Qflag = KMLTemp_count;
									 TKMLtemp.FId = getIDtemp.NO;
									 KMLAll.push_back(TKMLtemp);


								 }
							 }
						 }

					 }

				 }

				 return j;

			 }


			 //分析讀到的<coordinates>下一行中的所有的xyz(Loadkmlarray)
			 int AnalysisKMLxyzA(char buf[25000], int KMLTemp_count)
			 {
				 TXYZ.clear();

				 char *pch01 = NULL;
				 char *context = NULL;
				 char* pSplitStr01 = " "; // 用 "_" 來分割字串
				 char* pSplitStr02 = ","; // 用 "_" 來分割字串
				 int i = 0; int j = 0;
				 bool YZ = false;

				 //讀取第一筆( x,y,z )= pch01
				 //pch01 = strtok(buf, pSplitStr01);
				 pch01 = strtok_s(buf, pSplitStr01, &context);
				 if (pch01 != NULL)
				 {
					 //strcpy(TXYZtemp.xyz, pch01);
					 strcpy_s(TXYZtemp.xyz, sizeof(TXYZtemp.xyz) / sizeof(TXYZtemp.xyz[0]), pch01);
					 TXYZ.push_back(TXYZtemp);
					 i = i + 1;
					 while (pch01 != NULL)
					 {
						 //pch01 = strtok(NULL, pSplitStr01);
						 pch01 = strtok_s(NULL, pSplitStr01, &context);
						 if (pch01 != NULL && strlen(pch01) >1)
						 {
							 //strcpy(TXYZtemp.xyz, pch01);
							 strcpy_s(TXYZtemp.xyz, sizeof(TXYZtemp.xyz) / sizeof(TXYZtemp.xyz[0]), pch01);
							 TXYZ.push_back(TXYZtemp);
							 i = i + 1;
						 }
					 }
				 }

				 for (j = 0; j < (int)TXYZ.size(); j++)
				 {
					 YZ = false;
					 //pch01 = strtok(TXYZ[j].xyz, pSplitStr02);
					 pch01 = strtok_s(TXYZ[j].xyz, pSplitStr02, &context);
					 if (pch01 != NULL)
					 {
						 TKMLtemp.x = atof(pch01);
						 while (pch01 != NULL)
						 {
							 //pch01 = strtok(NULL, pSplitStr02);
							 pch01 = strtok_s(NULL, pSplitStr02, &context);
							 if (pch01 != NULL && strlen(pch01) >1)
							 {
								 if (YZ == false)
								 {
									 TKMLtemp.y = atof(pch01);
									 YZ = !YZ;
								 }
								 else  if (YZ == true)
								 {
									 TKMLtemp.z = atof(pch01);
									 YZ = !YZ;
									 TKMLtemp.Id = j;
									 TKMLtemp.Qflag = KMLTemp_count;
									 TKMLtemp.FId = getIDtemp.NO;
									 KML_GrdXYZ.push_back(TKMLtemp);

								 }
							 }
						 }

					 }

				 }

				 return j;

			 }



			 void ExportKML(char *filename, char *path)
			 {
				 char bufff[256];
				 strcpy(bufff, path);
				 strcat(bufff, "\\NEW.kml");
				 FILE *pw = fopen(bufff, "w");

				 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
				 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
				 fprintf(pw, "<Document>\n");
				 fprintf(pw, "	<name>KML</name>\n");
				 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
				 fprintf(pw, "		<IconStyle>\n");
				 fprintf(pw, "			<color>ff0000ff</color>\n");
				 fprintf(pw, "			<scale>0.5</scale>\n");
				 fprintf(pw, "		<Icon>\n");
				 fprintf(pw, "		<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
				 fprintf(pw, "		</Icon>\n");
				 fprintf(pw, "		</IconStyle>\n");
				 fprintf(pw, "		<LabelStyle>\n");
				 fprintf(pw, "			<color>00000000</color>\n");
				 fprintf(pw, "			<scale>0.1</scale>\n");
				 fprintf(pw, "		</LabelStyle>\n");
				 fprintf(pw, "		<LineStyle>\n");
				 fprintf(pw, "			<color>ff6e6e6e</color>\n");
				 fprintf(pw, "			<width>0.1</width>\n");
				 fprintf(pw, "		</LineStyle>\n");
				 fprintf(pw, "		<PolyStyle>\n");
				 fprintf(pw, "			<color>ff00ff55</color>\n");
				 fprintf(pw, "		</PolyStyle>\n");
				 fprintf(pw, "	</Style>\n");
				 fprintf(pw, "	<StyleMap id=\"PolyStyle001\">\n");
				 fprintf(pw, "		<Pair>\n");
				 fprintf(pw, "			<key>normal</key>\n");
				 fprintf(pw, "			<styleUrl>#PolyStyle000</styleUrl>\n");
				 fprintf(pw, "		</Pair>\n");
				 fprintf(pw, "		<Pair>\n");
				 fprintf(pw, "			<key>highlight</key>\n");
				 fprintf(pw, "			<styleUrl>#PolyStyle00</styleUrl>\n");
				 fprintf(pw, "		</Pair>\n");
				 fprintf(pw, "	</StyleMap>\n");
				 fprintf(pw, "	<Style id=\"PolyStyle000\">\n");
				 fprintf(pw, "		<IconStyle>\n");
				 fprintf(pw, "			<color>ff0000ff</color>\n");
				 fprintf(pw, "			<scale>0.5</scale>\n");
				 fprintf(pw, "		<Icon>\n");
				 fprintf(pw, "		<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
				 fprintf(pw, "		</Icon>\n");
				 fprintf(pw, "		</IconStyle>\n");
				 fprintf(pw, "		<LabelStyle>\n");
				 fprintf(pw, "			<color>00000000</color>\n");
				 fprintf(pw, "			<scale>0</scale>\n");
				 fprintf(pw, "		</LabelStyle>\n");
				 fprintf(pw, "		<LineStyle>\n");
				 fprintf(pw, "			<color>ff6e6e6e</color>\n");
				 fprintf(pw, "			<width>0.1</width>\n");
				 fprintf(pw, "		</LineStyle>\n");
				 fprintf(pw, "		<PolyStyle>\n");
				 fprintf(pw, "			<color>ff00ff55</color>\n");
				 fprintf(pw, "		</PolyStyle>\n");
				 fprintf(pw, "	</Style>\n");
				 fprintf(pw, "	<Folder id=\"KML\">\n");
				 fprintf(pw, "		<name>KML</name>\n");
				 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
				 fprintf(pw, "		<LookAt>\n");
				 fprintf(pw, "			<longitude>%lf</longitude>\n", xyzi[0].x);
				 fprintf(pw, "			<latitude>%lf</latitude>\n", xyzi[0].y);
				 fprintf(pw, "			<altitude>%lf</altitude>\n", xyzi[0].z + 200);
				 fprintf(pw, "			<heading>80</heading>\n");
				 fprintf(pw, "			<tilt>45</tilt>\n");
				 fprintf(pw, "			<range>130</range>\n");
				 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
				 fprintf(pw, "		</LookAt>\n");
				 //ExportLOD1KML

				 int startid = 0;
				 for (int i = 0; i < xyzi.size() - 1; i++)
				 {
					 

					 fprintf(pw, "		<Placemark id=\"ID\">\n");
					 //fprintf(pw, "			<name>ID_%s</name>\n", name2);
					 fprintf(pw, "			<description>\n");
					 fprintf(pw, "			%lf %lf %lf\n", xyzM[i].x, xyzM[i].y, xyzM[i].z);
					 fprintf(pw, "			</description>\n");
					 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
					 fprintf(pw, "			<Point>\n");
					 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
					 fprintf(pw, "							<coordinates>\n");
					 fprintf(pw, "								%lf,%lf,%lf \n", xyzi[i].x, xyzi[i].y, xyzi[i].z);
					 fprintf(pw, "							</coordinates>\n");
					 fprintf(pw, "			</Point>\n");
					 fprintf(pw, "		</Placemark>\n");

				 }

				 fprintf(pw, "	</Folder>\n");
				 fprintf(pw, "</Document>\n");
				 fprintf(pw, "</kml>\n");

				 fclose(pw);
			 }

			 void TWD97ENH_WGS84XYZ(char TorP, double tmx, double tmy, double tmh, double &x, double &y, double &z)
			 {
				 double xlon, ylat, zh;
				 TWD97ENH_TWD97GEO(TorP, tmx, tmy, tmh, xlon, ylat, zh);
				 WGS84GEO_WGS84XYZ(xlon, ylat, zh, x, y, z);

			 }

			 void TWD97ENH_TWD97GEO(char TorP, double tmx, double tmy, double tmh, double &xlon, double &ylat, double &zh)
			 {
				 double lh;//中央子午線
				 if (TorP == 'T'){ lh = 121.0; }
				 if (TorP == 'P'){ lh = 119.0; }

				 //GRS80 Datum
				 double  a = GRS80_A;
				 double  f = GRS80_F;
				 double  c = a / (1 - f);

				 double x = tmx;
				 double y = tmy;

				 //eccentricity
				 double  ex2 = (2 * f - f*f) / ((1 - f)*(1 - f));
				 double  ex4 = ex2*ex2;
				 double  ex6 = ex4*ex2;
				 double  ex8 = ex4*ex4;

				 double e0, f2, f4, f6;
				 e0 = c*(PI / 180)*(1 - 3 * ex2 / 4 + 45 * ex4 / 64 - 175 * ex6 / 256 + 11025 * ex8 / 16384);
				 f2 = (180 / PI)*(3 * ex2 / 8 - 3 * ex4 / 16 + 213 * ex6 / 2048 - 255 * ex8 / 4096);
				 f4 = (180 / PI)*(21 * ex4 / 256 - 21 * ex6 / 256 + 533 * ex8 / 8192);
				 f6 = (180 / PI)*(151 * ex6 / 6144 - 453 * ex8 / 12288);

				 double sigma, sigmr, bf;
				 sigma = (y / 0.9999) / e0;
				 sigmr = sigma*PI / 180;
				 bf = sigma + f2*sin(2 * sigmr) + f4*sin(4 * sigmr) + f6*sin(6 * sigmr);

				 double tan1, tan2, tan4, cos1, cos2, etasq, br;
				 br = bf * PI / 180;
				 tan1 = tan(br);
				 tan2 = tan1*tan1;
				 tan4 = tan2*tan2;

				 cos1 = cos(br);
				 cos2 = cos1*cos1;

				 etasq = ex2*cos2;

				 double nd, nd2, nd4, nd6, nd3, nd5;
				 nd = c / sqrt(1 + etasq);
				 nd2 = nd*nd;
				 nd4 = nd2*nd2;
				 nd6 = nd4*nd2;
				 nd3 = nd2*nd;
				 nd5 = nd4*nd;

				 double dx, dx2, dx4, dx3, dx5, dx6;
				 lh = fabs(lh);
				 dx = (x - 250000) / 0.9999;
				 dx2 = dx*dx;
				 dx4 = dx2*dx2;
				 dx3 = dx2*dx;
				 dx5 = dx4*dx;
				 dx6 = dx3*dx3;

				 double b2, b4, b6, l1, l3, l5;
				 b2 = -tan1*(1 + etasq) / (2 * nd2);
				 b4 = tan1*(5 + 3 * tan2 + 6 * etasq*(1 - tan2)) / (24 * nd4);
				 b6 = -tan1*(61 + 90 * tan2 + 45 * tan4) / (720 * nd6);

				 l1 = 1 / (nd*cos1);
				 l3 = -(1 + 2 * tan2 + etasq) / (6 * nd3*cos1);
				 l5 = (5 + 28 * tan2 + 24 * tan4) / (120 * nd5*cos1);
				 ylat = bf + (180 / PI) * (b2*dx2 + b4*dx4 + b6*dx6);//Output in Degree
				 xlon = lh + (180 / PI) * (l1*dx + l3*dx3 + l5*dx5);//Output in Degree
				 zh = tmh;

				 XYZ97to84_x = xlon;
				 XYZ97to84_y = ylat;
				 XYZ97to84_z = zh;
			 }

			 void WGS84GEO_WGS84XYZ(double xlon, double ylat, double zh, double &x, double &y, double &z)
			 {
				 double  a = WGS84_A;//Semi-Axis
				 double	f = WGS84_F;//Flattening;
				 double  b = a - (a*f);
				 //double  c  = a/(1-f);
				 double e2 = (a*a - b*b) / (a*a);
				 double lat, lon, n;

				 lat = ylat*PI / 180;
				 lon = xlon*PI / 180;
				 n = a / sqrt(1 - e2*sin(lat)*sin(lat));

				 x = (n + zh)*cos(lat)*cos(lon);
				 y = (n + zh)*cos(lat)*sin(lon);
				 z = (n*(1 - e2) + zh)*sin(lat);


			 }



	//統一更改高度//確定
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		
		
		if ((int)KMLAll.size() > 0)
		{
			char *StartID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox1->Text)));
			double SiD = atof(StartID);

			for (int i = 0; i < KMLAll.size(); i++)
			{
				KMLAll[i].z = SiD;
			}
			for (int i = 0; i < KML_GrdXYZ.size(); i++)
			{
				KML_GrdXYZ[i].z = SiD;
			}
			MessageBox::Show("完成");
		}else
			MessageBox::Show("請讀取KML");
		
	}



			 //開啟點雲KML
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

	ExportKML01( D_name);

	MessageBox::Show("完成");

}
		 void ExportKML01( char *path)
		 {
		
			 char buf[64]="a";
			 int Checkcount = 0;

			 //FILE *pw = fopen(path, "w");	 
			 FILE *pw = fopen(D_name, "w");
			 

			 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
			 fprintf(pw, "<Document>\n");
			 fprintf(pw, "	<name>KML_%s</name>\n", buf);
			 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
			 fprintf(pw, "		<IconStyle>\n");

			 fprintf(pw, "			<scale>0.5</scale>\n");
			 fprintf(pw, "		<Icon>\n");
			 fprintf(pw, "		<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
			 fprintf(pw, "		</Icon>\n");
			 fprintf(pw, "		</IconStyle>\n");
			 fprintf(pw, "		<LabelStyle>\n");
			 fprintf(pw, "			<color>00000000</color>\n");
			 fprintf(pw, "			<scale>0</scale>\n");
			 fprintf(pw, "		</LabelStyle>\n");
			 fprintf(pw, "		<LineStyle>\n");
			 fprintf(pw, "			<color>ff6e6e6e</color>\n");
			 fprintf(pw, "			<width>0</width>\n");
			 fprintf(pw, "		</LineStyle>\n");
			 fprintf(pw, "		<PolyStyle>\n");
			 fprintf(pw, "			<color>fff7c6e9</color>\n");
			 fprintf(pw, "		</PolyStyle>\n");
			 fprintf(pw, "	</Style>\n");
			 fprintf(pw, "	<StyleMap id=\"PolyStyle001\">\n");
			 fprintf(pw, "		<Pair>\n");
			 fprintf(pw, "			<key>normal</key>\n");
			 fprintf(pw, "			<styleUrl>#PolyStyle000</styleUrl>\n");
			 fprintf(pw, "		</Pair>\n");
			 fprintf(pw, "		<Pair>\n");
			 fprintf(pw, "			<key>highlight</key>\n");
			 fprintf(pw, "			<styleUrl>#PolyStyle00</styleUrl>\n");
			 fprintf(pw, "		</Pair>\n");
			 fprintf(pw, "	</StyleMap>\n");
			 fprintf(pw, "	<Style id=\"PolyStyle000\">\n");
			 fprintf(pw, "		<IconStyle>\n");

			 fprintf(pw, "			<scale>0.5</scale>\n");
			 fprintf(pw, "		<Icon>\n");
			 fprintf(pw, "		<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
			 fprintf(pw, "		</Icon>\n");
			 fprintf(pw, "		</IconStyle>\n");
			 fprintf(pw, "		<LabelStyle>\n");
			 fprintf(pw, "			<color>00000000</color>\n");
			 fprintf(pw, "			<scale>0</scale>\n");
			 fprintf(pw, "		</LabelStyle>\n");
			 fprintf(pw, "		<LineStyle>\n");
			 fprintf(pw, "			<color>ff6e6e6e</color>\n");
			 fprintf(pw, "			<width>0</width>\n");
			 fprintf(pw, "		</LineStyle>\n");
			 fprintf(pw, "		<PolyStyle>\n");
			 fprintf(pw, "			<color>fff7c6e9</color>\n");
			 fprintf(pw, "		</PolyStyle>\n");
			 fprintf(pw, "	</Style>\n");
			 fprintf(pw, "	<Folder id=\"KML\">\n");
			 fprintf(pw, "		<name>KML_%s</name>\n", buf);
			 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
			 fprintf(pw, "		<LookAt>\n");
			 fprintf(pw, "			<longitude>%lf</longitude>\n", KMLAll[0].x);
			 fprintf(pw, "			<latitude>%lf</latitude>\n", KMLAll[0].y);
			 fprintf(pw, "			<altitude>%lf</altitude>\n", KMLAll[0].z + 100);
			 fprintf(pw, "			<heading>80</heading>\n");
			 fprintf(pw, "			<tilt>45</tilt>\n");
			 fprintf(pw, "			<range>130</range>\n");
			 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
			 fprintf(pw, "		</LookAt>\n");

			 //=================印出KML
			 fprintf(pw, "	<name>KML_%s</name>\n", buf);
			 fprintf(pw, "		<Placemark id=\"ID\">\n");
			 //				 fprintf(pw, "			<name>KML_ID%d</name>\n", KMLAll[i].FId);
			 //fprintf(pw, "			<description>%s</description>\n", filename2);
			 fprintf(pw, "			<description><![CDATA[<html xmlns:fo=\"http://www.w3.org/1999/XSL/Format\" xmlns:msxsl=\"urn:schemas-microsoft-com:xslt\">\n");
			 fprintf(pw, "			<head>\n");
			 fprintf(pw, "			<META http-equiv=\"Content - Type\" content=\"text / html\">\n");
			 fprintf(pw, "			<meta http-equiv=\"content - type\" content=\"text / html; charset = UTF - 8\">\n");
			 fprintf(pw, "			</head>\n");
			 fprintf(pw, "			<body style=\"margin:0px 0px 0px 0px; overflow:auto; background:#FFFFFF; \">\n");
			 fprintf(pw, "			<td>FID</td>\n\n");
			 fprintf(pw, "			<td>%s</td>\n", buf);
			 fprintf(pw, "			</html>]]></description>\n");

			 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
			 fprintf(pw, "			<MultiGeometry>\n");
			 fprintf(pw, "			<Polygon>\n");
			 fprintf(pw, "			<extrude>1</extrude>\n");
			 fprintf(pw, "			<altitudeMode>absolute</altitudeMode>\n");
			 fprintf(pw, "			<outerBoundaryIs>\n");
			 fprintf(pw, "			<LinearRing>\n");
			 fprintf(pw, "					<coordinates>\n");
			 for (int j = 0; j < (int)KMLAll.size(); j++)
			 {
				 fprintf(pw, "%lf,%lf,%lf ", KMLAll[j].x, KMLAll[j].y, KMLAll[j].z);
			 }
			 fprintf(pw, " \n");
			 fprintf(pw, "					</coordinates>\n");
			 fprintf(pw, "			</LinearRing>\n");
			 fprintf(pw, "			</outerBoundaryIs>\n");
			 //KML_GrdXYZ
			 for (int k = 0; k < KML_GrdXYZ.size(); k++)
			 {
				 
					 if (Checkcount == 0)
					 {
						 fprintf(pw, "			<innerBoundaryIs>\n");
						 fprintf(pw, "			<LinearRing>\n");
						 fprintf(pw, "					<coordinates>\n");
						 Checkcount = 1;
					 }

					 fprintf(pw, "%lf,%lf,%lf ", KML_GrdXYZ[k].x, KML_GrdXYZ[k].y, KML_GrdXYZ[k].z);

				 
			 }
			 if (Checkcount == 1)
			 {
				 fprintf(pw, "					</coordinates>\n");
				 fprintf(pw, "			</LinearRing>\n");
				 fprintf(pw, "			</innerBoundaryIs>\n");
				 Checkcount = 0;
			 }
			 fprintf(pw, "			</Polygon>\n");
			 fprintf(pw, "			</MultiGeometry>\n");
			 fprintf(pw, "		</Placemark>\n");


			 //=================印出KML-point
			 int Hid = 0;
			 for (int g = 0; g < (int)KMLAll.size(); g++)
			 {
				 fprintf(pw, "		<Placemark id=\"ID\">\n");
				 fprintf(pw, "			<description>NO:%d\n", Hid);
				 fprintf(pw, "			%lf %lf %lf\n", KMLAll[g].x, KMLAll[g].y, KMLAll[g].z);
				 fprintf(pw, "			</description>\n");
				 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
				 fprintf(pw, "			<Point>\n");
				 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
				 fprintf(pw, "							<coordinates>\n");
				 fprintf(pw, "%lf,%lf,%lf \n",
					 KMLAll[g].x, KMLAll[g].y, KMLAll[g].z);
				 fprintf(pw, "							</coordinates>\n");
				 fprintf(pw, "			</Point>\n");
				 fprintf(pw, "		</Placemark>\n");				

				 Hid = Hid + 1;
			 }

			 //KML_GrdXYZ
			 for (int k = 0; k < KML_GrdXYZ.size(); k++)
			 {

					 fprintf(pw, "		<Placemark id=\"ID\">\n");
					 fprintf(pw, "			<description>\n");
					 fprintf(pw, "			%lf %lf %lf\n", KML_GrdXYZ[k].x, KML_GrdXYZ[k].y, KML_GrdXYZ[k].z);
					 fprintf(pw, "			</description>\n");
					 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
					 fprintf(pw, "			<Point>\n");
					 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
					 fprintf(pw, "							<coordinates>\n");
					 fprintf(pw, "%lf,%lf,%lf ", KML_GrdXYZ[k].x, KML_GrdXYZ[k].y, KML_GrdXYZ[k].z);
					 fprintf(pw, "							</coordinates>\n");
					 fprintf(pw, "			</Point>\n");
					 fprintf(pw, "		</Placemark>\n");

			 }


			 fprintf(pw, "	</Folder>\n");
			 fprintf(pw, "</Document>\n");
			 fprintf(pw, "</kml>\n");
			 fclose(pw);
		 }



private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	

	if (this->textBox2->Text->Length > 0 && this->textBox3->Text->Length > 0)
	{
		

		//FILE *fp = fopen("D:\\程式區\\Project4\\temp\\a.txt","w");
		//for (int i = 0; i < NewKMLAll.size(); i++)
		//{
		//	fprintf(fp, "%d %d ", NewKMLAll[i].Id, NewKMLAll[i].Qflag);
		//	fprintf(fp, "%lf %lf %lf\n", NewKMLAll[i].x, NewKMLAll[i].y, NewKMLAll[i].z);
		//}			
		//fclose(fp);
		MessageBox::Show("完成");
	}else
		MessageBox::Show("請確認資料");

}

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

	MakeData2();

	//FILE *fp = fopen("www.txt", "w");
	//for (int i = 0; i < KMLAll.size(); i++)
	//{
	//	fprintf(fp, "%d %lf %lf %lf\n", i, KMLAll[i].x, KMLAll[i].y, KMLAll[i].z);
	//}
	//fprintf(fp, "======\n");
	//for (int i = 0; i < Point2_XYZ.size(); i++)
	//{
	//	fprintf(fp, "%d %lf %lf %lf\n", i, Point2_XYZ[i].x, Point2_XYZ[i].y, Point2_XYZ[i].z);
	//}
	//fclose(fp);
	
	//ExportKML02(2,D_name);
	ExportKML2polygon(build_name);
	MessageBox::Show("完成");
}
		 void MakeData2()
		 {
			 vector<PointXYZ> Wgs84to970a;
			 vector<PointXYZ> Wgs84to970b;
			 double f97ENHto84X, f97ENHto84Y, f97ENHto84Z;

			 NewKMLAll.clear();
			 Point2_XYZ.clear();
			 polygon01 = 0; polygon02 = 0;

			 char *CutID02 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox2->Text)));
			 int SiD2 = atoi(CutID02);
			 char *CutID03 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox3->Text)));
			 int SiD3 = atoi(CutID03);
			 char *CutID06 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox6->Text)));
			 int SiD6 = atoi(CutID06);
			 char *CutID07 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox7->Text)));
			 int SiD7 = atoi(CutID07);

			 int flag = 0;
			if (SiD2 == 0){ if ((SiD3 > SiD6) || (SiD3 > SiD7)) flag = 1; SiD2 = (int)KMLAll.size()-1; }
			else  if (SiD3 == 0){ if ((SiD2 > SiD6) || (SiD2 > SiD7)) flag = 2;  SiD3 = (int)KMLAll.size() - 1; }
			else  if (SiD6 == 0){ if ((SiD7 > SiD2) || (SiD7 > SiD3)) flag = 3;  SiD6 = (int)KMLAll.size() - 1; }
			else  if (SiD7 == 0){ if ((SiD6 > SiD2) || (SiD6 > SiD3)) flag = 4;  SiD7 = (int)KMLAll.size() - 1; }
			 //當沒有任何ID=0出現~即可正常切屋脊
			 //if (flag== 0)
			 {
				 //這邊任意比大小(SiD2,SiD3) vs (SiD6,SiD7)
				 //假設輸入的第一筆比較大,那就要互換一下位置
				 if (SiD7 < SiD2)
				 {
					 int atemp = 0, btemp = 0;
					 atemp = SiD2; btemp = SiD3;
					 SiD2 = SiD6; SiD3 = SiD7;
					 SiD6 = atemp; SiD7 = btemp;
				 }
				 int i = 0, j = 0;

				 if (SiD2 < SiD3)
				 {
					 i = SiD2; j = SiD3;
				 }
				 else
				 {
					 i = SiD3; j = SiD2;
				 }

				 //這邊先把第一組第一個點之前的存起來
				 for (int k = 0; k <= i; k++)
				 {
					 KMLAll[i].Show = 1;
					 TKMLtemp.x = KMLAll[k].x;
					 TKMLtemp.y = KMLAll[k].y;
					 TKMLtemp.z = KMLAll[k].z;
					 Point2_XYZ.push_back(TKMLtemp);

					 polygon01 = polygon01 + 1;
					 polygon02 = polygon02 + 1;
				 }
				 //這邊先把第一組要算的屋脊點算出來
				 Cal_lonlat_To_twd97(KMLAll[i].x, KMLAll[i].y, 0);
				 double x1 = Wgs84toTwd97X01; double y1 = Wgs84toTwd97Y01;
				 Cal_lonlat_To_twd97(KMLAll[j].x, KMLAll[j].y, 0);
				 double x2 = Wgs84toTwd97X01; double y2 = Wgs84toTwd97Y01;
				 double x = (x2 + x1) / 2;	double y = ((y2 + y1) / 2) + 1.98;
				 TWD97ENH_WGS84XYZ('T', x, y, KMLAll[i].z, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				 TKMLtemp.x = XYZ97to84_x;
				 TKMLtemp.y = XYZ97to84_y;
				 //TKMLtemp.x = (KMLAll[i].x + KMLAll[j].x) / 2;
				 //TKMLtemp.y = (KMLAll[i].y + KMLAll[j].y) / 2;
				 TKMLtemp.z = KMLAll[i].z;
				 Point2_XYZ.push_back(TKMLtemp);
				 polygon02 = polygon02 + 1;
				 TKMLtemp.x = KMLAll[j].x;
				 TKMLtemp.y = KMLAll[j].y;
				 TKMLtemp.z = KMLAll[j].z;
				 Point2_XYZ.push_back(TKMLtemp);
				 polygon02 = polygon02 + 1;
				 ////這邊把第2個點存起來
				 //TKMLtemp.x = KMLAll[j].x;
				 //TKMLtemp.y = KMLAll[j].y;
				 //TKMLtemp.z = KMLAll[j].z;
				 //Point2_XYZ.push_back(TKMLtemp);


				 int p = 0, q = 0;
				 if (SiD6 < SiD7)
				 {
					 p = SiD6; q = SiD7;
				 }
				 else
				 {
					 p = SiD7; q = SiD6;
				 }

				 //這邊先把第二組第一個點之前的存起來
				 for (int k = j + 1; k <= p; k++)
				 {
					 //KMLAll[p].Show = 1;
					 TKMLtemp.x = KMLAll[k].x;
					 TKMLtemp.y = KMLAll[k].y;
					 TKMLtemp.z = KMLAll[k].z;
					 Point2_XYZ.push_back(TKMLtemp);
					 polygon02 = polygon02 + 1;
				 }
				 //這邊先把第二組要算的屋脊點算出來
				 //Cal_lonlat_To_twd97(KMLAll[p].x, KMLAll[p].y, KMLAll[p].z);
				 // x1 = Wgs84toTwd97X01;  y1 = Wgs84toTwd97Y01;
				 //Cal_lonlat_To_twd97(KMLAll[q].x, KMLAll[q].y, KMLAll[q].z);
				 // x2 = Wgs84toTwd97X01;  y2 = Wgs84toTwd97Y01;

				 // x = (x2 + x1) / 2;	y = (y2 + y1) / 2;
				 // TWD97ENH_WGS84XYZ('T', x, y, KMLAll[p].z, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				 // TKMLtemp.x = XYZ97to84_x;
				 // TKMLtemp.y = XYZ97to84_y;
				 Cal_lonlat_To_twd97(KMLAll[p].x, KMLAll[p].y, 0);
				  x1 = Wgs84toTwd97X01;  y1 = Wgs84toTwd97Y01 ;
				 Cal_lonlat_To_twd97(KMLAll[q].x, KMLAll[q].y, 0);
				  x2 = Wgs84toTwd97X01;  y2 = Wgs84toTwd97Y01 ;
				  x = (x2 + x1) / 2;	 y = ((y2 + y1) / 2) + 1.98;
				 TWD97ENH_WGS84XYZ('T', x, y, KMLAll[p].z, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				 TKMLtemp.x = XYZ97to84_x;
				 TKMLtemp.y = XYZ97to84_y;
				 //TKMLtemp.x = (KMLAll[p].x + KMLAll[q].x) / 2;
				 //TKMLtemp.y = (KMLAll[p].y + KMLAll[q].y) / 2;
				 TKMLtemp.z = KMLAll[p].z;
				 Point2_XYZ.push_back(TKMLtemp);

				 TKMLtemp.x = KMLAll[q].x;
				 TKMLtemp.y = KMLAll[q].y;
				 TKMLtemp.z = KMLAll[q].z;
				 Point2_XYZ.push_back(TKMLtemp);


				 //這邊把後面的點存起來
				 for (int k = q + 1; k < (int)KMLAll.size(); k++)
				 {
					 TKMLtemp.x = KMLAll[k].x;
					 TKMLtemp.y = KMLAll[k].y;
					 TKMLtemp.z = KMLAll[k].z;
					 Point2_XYZ.push_back(TKMLtemp);
				 }
			 }
			 
			 Wgs84to970a.clear();
			 Wgs84to970b.clear();


		 }

		 void MakeData()
		 {
			 NewKMLAll.clear();
			 Point2_XYZ.clear();
			 polygon01 = 0; polygon02 = 0;

			 char *CutID02 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox2->Text)));
			 int SiD2 = atoi(CutID02);
			 char *CutID03 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox3->Text)));
			 int SiD3 = atoi(CutID03);
			 char *CutID06 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox6->Text)));
			 int SiD6 = atoi(CutID06);
			 char *CutID07 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox7->Text)));
			 int SiD7 = atoi(CutID07);

			 int i = 0, j = 0;
			 
			 if (SiD2 < SiD3)
			 {	 i = SiD2; j = SiD3; }
			 else
			 {	 i = SiD3; j = SiD2; }

			 //這邊先把第一組第一個點之前的存起來
			 for (int k=0; k <= i; k++)
			 {
				 KMLAll[i].Show = 1;
				 TKMLtemp.x = KMLAll[k].x;
				 TKMLtemp.y = KMLAll[k].y;
				 TKMLtemp.z = KMLAll[k].z;
				 Point2_XYZ.push_back(TKMLtemp);

				 polygon01 = polygon01 + 1;
				 polygon02 = polygon02 + 1;
			 }
			 //這邊先把第一組要算的屋脊點算出來
			 TKMLtemp.x = (KMLAll[i].x + KMLAll[j].x) / 2;
			 TKMLtemp.y = (KMLAll[i].y + KMLAll[j].y) / 2;
			 TKMLtemp.z = KMLAll[i].z;			  
			 Point2_XYZ.push_back(TKMLtemp);
			 polygon02 = polygon02 + 1;
			 TKMLtemp.x = KMLAll[j].x;
			 TKMLtemp.y = KMLAll[j].y;
			 TKMLtemp.z = KMLAll[j].z;
			 Point2_XYZ.push_back(TKMLtemp);
			 polygon02 = polygon02 + 1;
			 ////這邊把第2個點存起來
			 //TKMLtemp.x = KMLAll[j].x;
			 //TKMLtemp.y = KMLAll[j].y;
			 //TKMLtemp.z = KMLAll[j].z;
			 //Point2_XYZ.push_back(TKMLtemp);


			 int p = 0,q = 0;
			 if (SiD6 < SiD7)
			 {	 p = SiD6; q = SiD7;	 }
			 else
			 {	 p = SiD7; q = SiD6;	 }

			 //這邊先把第二組第一個點之前的存起來
			 for (int k = j+1 ; k <= p; k++)
			 {
				 //KMLAll[p].Show = 1;
				 TKMLtemp.x = KMLAll[k].x;
				 TKMLtemp.y = KMLAll[k].y;
				 TKMLtemp.z = KMLAll[k].z;
				 Point2_XYZ.push_back(TKMLtemp);
				 polygon02 = polygon02 + 1;
			 }
			 //這邊先把第二組要算的屋脊點算出來
			 TKMLtemp.x = (KMLAll[p].x + KMLAll[q].x) / 2;
			 TKMLtemp.y = (KMLAll[p].y + KMLAll[q].y) / 2;
			 TKMLtemp.z = KMLAll[p].z;
			 Point2_XYZ.push_back(TKMLtemp);
			 
			 TKMLtemp.x = KMLAll[q].x;
			 TKMLtemp.y = KMLAll[q].y;
			 TKMLtemp.z = KMLAll[q].z;
			 Point2_XYZ.push_back(TKMLtemp);

			
			 //這邊把後面的點存起來
			 for (int k = q + 1; k < (int)KMLAll.size(); k++)
			 {				
				 TKMLtemp.x = KMLAll[k].x;
				 TKMLtemp.y = KMLAll[k].y;
				 TKMLtemp.z = KMLAll[k].z;
				 Point2_XYZ.push_back(TKMLtemp);
			 }


		 }


		 void ExportKML2polygon(char *path)
		 {
			 char buf[64] = "a";
			 int Checkcount = 0;
			 //build_name
			 char NewData01path[256];
			 char NewData02path[256];
			 strcpy(NewData01path, build_name);
			 strcpy(NewData02path, build_name);
			 strcat(NewData01path, "_01.kml");
			 strcat(NewData02path, "_02.kml");
			 //polygon01 = 0; polygon02 = 0;

			 for (int i = 0; i < 2 ; i++)
			 {
				 FILE *pw;
				 if (i == 0)
					 pw = fopen(NewData01path, "w");
				 else
					 pw = fopen(NewData02path, "w");
				 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
				 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
				 fprintf(pw, "<Document>\n");
				 fprintf(pw, "	<name>KML_%s</name>\n", buf);
				 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
				 fprintf(pw, "		<IconStyle>\n");

				 fprintf(pw, "			<scale>0.5</scale>\n");
				 fprintf(pw, "		<Icon>\n");
				 fprintf(pw, "		<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
				 fprintf(pw, "		</Icon>\n");
				 fprintf(pw, "		</IconStyle>\n");
				 fprintf(pw, "		<LabelStyle>\n");
				 fprintf(pw, "			<color>00000000</color>\n");
				 fprintf(pw, "			<scale>0</scale>\n");
				 fprintf(pw, "		</LabelStyle>\n");
				 fprintf(pw, "		<LineStyle>\n");
				 fprintf(pw, "			<color>ff6e6e6e</color>\n");
				 fprintf(pw, "			<width>1</width>\n");
				 fprintf(pw, "		</LineStyle>\n");
				 fprintf(pw, "		<PolyStyle>\n");
				 fprintf(pw, "			<color>fff7c6e9</color>\n");
				 fprintf(pw, "		</PolyStyle>\n");
				 fprintf(pw, "	</Style>\n");
				 fprintf(pw, "	<StyleMap id=\"PolyStyle001\">\n");
				 fprintf(pw, "		<Pair>\n");
				 fprintf(pw, "			<key>normal</key>\n");
				 fprintf(pw, "			<styleUrl>#PolyStyle000</styleUrl>\n");
				 fprintf(pw, "		</Pair>\n");
				 fprintf(pw, "		<Pair>\n");
				 fprintf(pw, "			<key>highlight</key>\n");
				 fprintf(pw, "			<styleUrl>#PolyStyle00</styleUrl>\n");
				 fprintf(pw, "		</Pair>\n");
				 fprintf(pw, "	</StyleMap>\n");
				 fprintf(pw, "	<Style id=\"PolyStyle000\">\n");
				 fprintf(pw, "		<IconStyle>\n");
				 fprintf(pw, "			<scale>0.5</scale>\n");
				 fprintf(pw, "		<Icon>\n");
				 fprintf(pw, "		<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
				 fprintf(pw, "		</Icon>\n");
				 fprintf(pw, "		</IconStyle>\n");
				 fprintf(pw, "		<LabelStyle>\n");
				 fprintf(pw, "			<color>00000000</color>\n");
				 fprintf(pw, "			<scale>0</scale>\n");
				 fprintf(pw, "		</LabelStyle>\n");
				 fprintf(pw, "		<LineStyle>\n");
				 fprintf(pw, "			<color>ff6e6e6e</color>\n");
				 fprintf(pw, "			<width>1</width>\n");
				 fprintf(pw, "		</LineStyle>\n");
				 fprintf(pw, "		<PolyStyle>\n");
				 fprintf(pw, "			<color>fff7c6e9</color>\n");
				 fprintf(pw, "		</PolyStyle>\n");
				 fprintf(pw, "	</Style>\n");
				 fprintf(pw, "	<Folder id=\"KML\">\n");
				 if (i == 0)
					 fprintf(pw, "	<name>KML_%s_01</name>\n", build_ID);
				 else
					 fprintf(pw, "	<name>KML_%s_02</name>\n", build_ID);

				 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
				 fprintf(pw, "		<LookAt>\n");
				 if (i == 0)
				 {
					 fprintf(pw, "			<longitude>%lf</longitude>\n", Point2_XYZ[polygon01].x);
					 fprintf(pw, "			<latitude>%lf</latitude>\n", Point2_XYZ[polygon01].y);
					 fprintf(pw, "			<altitude>%lf</altitude>\n", Point2_XYZ[polygon01].z + 100);
				 }					
				 else
				 {
					 fprintf(pw, "			<longitude>%lf</longitude>\n", Point2_XYZ[polygon02].x);
					 fprintf(pw, "			<latitude>%lf</latitude>\n", Point2_XYZ[polygon02].y);
					 fprintf(pw, "			<altitude>%lf</altitude>\n", Point2_XYZ[polygon02].z + 100);
				 }				
				 fprintf(pw, "			<heading>0</heading>\n");
				 fprintf(pw, "			<tilt>0</tilt>\n");
				 fprintf(pw, "			<range>130</range>\n");
				 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
				 fprintf(pw, "		</LookAt>\n");

				 //=================印出KML
				 if (i == 0)
				 {
					 fprintf(pw, "	<name>KML_%s_01</name>\n", build_ID);
				 }
				 else
				 {
					 fprintf(pw, "	<name>KML_%s_02</name>\n", build_ID);
				 }
				 
				 fprintf(pw, "		<Placemark id=\"ID\">\n");
				 fprintf(pw, "			<description><![CDATA[<html xmlns:fo=\"http://www.w3.org/1999/XSL/Format\" xmlns:msxsl=\"urn:schemas-microsoft-com:xslt\">\n");
				 fprintf(pw, "			<head>\n");
				 fprintf(pw, "			<META http-equiv=\"Content - Type\" content=\"text / html\">\n");
				 fprintf(pw, "			<meta http-equiv=\"content - type\" content=\"text / html; charset = UTF - 8\">\n");
				 fprintf(pw, "			</head>\n");
				 fprintf(pw, "			<body style=\"margin:0px 0px 0px 0px; overflow:auto; background:#FFFFFF; \">\n");
				 fprintf(pw, "			<td>FID</td>\n\n");
				 if (i == 0)
				 {
					 fprintf(pw, "			<td>%s_01</td>\n", build_ID);
				 }
				 else
				 {
					 fprintf(pw, "			<td>%s_02</td>\n", build_ID);
				 }				 
				 fprintf(pw, "			</html>]]></description>\n");

				 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
				 fprintf(pw, "			<MultiGeometry>\n");
				 fprintf(pw, "			<Polygon>\n");
				 fprintf(pw, "			<extrude>1</extrude>\n");
				 fprintf(pw, "			<altitudeMode>absolute</altitudeMode>\n");
				 fprintf(pw, "			<outerBoundaryIs>\n");
				 fprintf(pw, "			<LinearRing>\n");
				 fprintf(pw, "					<coordinates>\n");
				 if (i == 0)
				 {
					 for (int i = 0; i <= polygon01; i++)
					 {
						 fprintf(pw, "%lf,%lf,%lf ", Point2_XYZ[i].x, Point2_XYZ[i].y, Point2_XYZ[i].z);
					 }
					 for (int i = polygon02; i <Point2_XYZ.size(); i++)
					 {
						 fprintf(pw, "%lf,%lf,%lf ", Point2_XYZ[i].x, Point2_XYZ[i].y, Point2_XYZ[i].z);
					 }
					 fprintf(pw, "\n");

				 }
				 else
				 {
					 for (int i = polygon01; i <= polygon02; i++)
					 {
						 fprintf(pw, "%lf,%lf,%lf ", Point2_XYZ[i].x, Point2_XYZ[i].y, Point2_XYZ[i].z);
					 }
					 fprintf(pw, "%lf,%lf,%lf \n", Point2_XYZ[polygon01].x, Point2_XYZ[polygon01].y, Point2_XYZ[polygon01].z);
					
				 }

				 fprintf(pw, "					</coordinates>\n");
				 fprintf(pw, "			</LinearRing>\n");
				 fprintf(pw, "			</outerBoundaryIs>\n");
				 fprintf(pw, "			</Polygon>\n");
				 fprintf(pw, "			</MultiGeometry>\n");
				 fprintf(pw, "		</Placemark>\n");
				 fprintf(pw, "	</Folder>\n");

				 if (i == 0)
				 {
					 int coung = 0;
					 fprintf(pw, "	<name>KML_%s_01</name>\n", build_ID);
					 for (int i = 0; i <= polygon01; i++)
					 {
						 fprintf(pw, "		<Placemark id=\"ID\">\n");
						 fprintf(pw, "			<description>NO:%d\n", coung);
						 fprintf(pw, "			%lf\n%lf\n%lf\n", Point2_XYZ[i].x, Point2_XYZ[i].y, Point2_XYZ[i].z);
						 fprintf(pw, "			</description>\n");
						 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
						 fprintf(pw, "			<Point>\n");
						 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
						 fprintf(pw, "							<coordinates>\n");
						 fprintf(pw, "%lf,%lf,%lf \n",
							 Point2_XYZ[i].x, Point2_XYZ[i].y, Point2_XYZ[i].z);
						 fprintf(pw, "							</coordinates>\n");
						 fprintf(pw, "			</Point>\n");
						 fprintf(pw, "		</Placemark>\n");	
						 coung = coung + 1;
					 }
					 for (int i = polygon02; i <Point2_XYZ.size()-1; i++)
					 {
						 fprintf(pw, "		<Placemark id=\"ID\">\n");
						 fprintf(pw, "			<description>NO:%d\n", coung);
						 fprintf(pw, "			%lf\n%lf\n%lf\n", Point2_XYZ[i].x, Point2_XYZ[i].y, Point2_XYZ[i].z);
						 fprintf(pw, "			</description>\n");
						 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
						 fprintf(pw, "			<Point>\n");
						 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
						 fprintf(pw, "							<coordinates>\n");
						 fprintf(pw, "%lf,%lf,%lf \n",
							 Point2_XYZ[i].x, Point2_XYZ[i].y, Point2_XYZ[i].z);
						 fprintf(pw, "							</coordinates>\n");
						 fprintf(pw, "			</Point>\n");
						 fprintf(pw, "		</Placemark>\n");

						 coung = coung + 1;
						 //fprintf(pw, "%lf,%lf,%lf ", Point2_XYZ[i].x, Point2_XYZ[i].y, Point2_XYZ[i].z);
					 }
					 //fprintf(pw, "\n");

				 }					 
				 else
				 {
					 int coung = 0;
					 fprintf(pw, "	<name>KML_%s_02</name>\n", build_ID);
					 for (int i = polygon01; i <= polygon02; i++)
					 {
						 fprintf(pw, "		<Placemark id=\"ID\">\n");
						 fprintf(pw, "			<description>NO:%d\n", coung);
						 fprintf(pw, "			%lf\n%lf\n%lf\n", Point2_XYZ[i].x, Point2_XYZ[i].y, Point2_XYZ[i].z);
						 fprintf(pw, "			</description>\n");
						 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
						 fprintf(pw, "			<Point>\n");
						 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
						 fprintf(pw, "							<coordinates>\n");
						 fprintf(pw, "%lf,%lf,%lf \n",
							 Point2_XYZ[i].x, Point2_XYZ[i].y, Point2_XYZ[i].z);
						 fprintf(pw, "							</coordinates>\n");
						 fprintf(pw, "			</Point>\n");
						 fprintf(pw, "		</Placemark>\n");
						 coung = coung + 1;
					 }					
					
				 }
					


				 fprintf(pw, "</Document>\n");
				 fprintf(pw, "</kml>\n");
				 fclose(pw);

			 }

		 }
		 
		 void ExportKML02(int Count,char *path)
		 {

			 char buf[64] = "a";
			 int Checkcount = 0;
			 //build_name
			 char NewData01path[256];
			 char NewData02path[256];
			 strcpy(NewData01path, build_name);
			 strcpy(NewData02path, build_name);
			 strcat(NewData01path, "_01.kml");
			 strcat(NewData02path, "_02.kml");

			 for (int i = 0; i < Count; i++)
			 {
				 FILE *pw;
				 if (i == 0)
					 pw = fopen(NewData01path, "w");
				 else
					 pw = fopen(NewData02path, "w");
				 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
				 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
				 fprintf(pw, "<Document>\n");
				 fprintf(pw, "	<name>KML_%s</name>\n", buf);
				 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
				 fprintf(pw, "		<IconStyle>\n");

				 fprintf(pw, "			<scale>0.5</scale>\n");
				 fprintf(pw, "		<Icon>\n");
				 fprintf(pw, "		<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
				 fprintf(pw, "		</Icon>\n");
				 fprintf(pw, "		</IconStyle>\n");
				 fprintf(pw, "		<LabelStyle>\n");
				 fprintf(pw, "			<color>00000000</color>\n");
				 fprintf(pw, "			<scale>0</scale>\n");
				 fprintf(pw, "		</LabelStyle>\n");
				 fprintf(pw, "		<LineStyle>\n");
				 fprintf(pw, "			<color>ff6e6e6e</color>\n");
				 fprintf(pw, "			<width>1</width>\n");
				 fprintf(pw, "		</LineStyle>\n");
				 fprintf(pw, "		<PolyStyle>\n");
				 fprintf(pw, "			<color>fff7c6e9</color>\n");
				 fprintf(pw, "		</PolyStyle>\n");
				 fprintf(pw, "	</Style>\n");
				 fprintf(pw, "	<StyleMap id=\"PolyStyle001\">\n");
				 fprintf(pw, "		<Pair>\n");
				 fprintf(pw, "			<key>normal</key>\n");
				 fprintf(pw, "			<styleUrl>#PolyStyle000</styleUrl>\n");
				 fprintf(pw, "		</Pair>\n");
				 fprintf(pw, "		<Pair>\n");
				 fprintf(pw, "			<key>highlight</key>\n");
				 fprintf(pw, "			<styleUrl>#PolyStyle00</styleUrl>\n");
				 fprintf(pw, "		</Pair>\n");
				 fprintf(pw, "	</StyleMap>\n");
				 fprintf(pw, "	<Style id=\"PolyStyle000\">\n");
				 fprintf(pw, "		<IconStyle>\n");

				 fprintf(pw, "			<scale>0.5</scale>\n");
				 fprintf(pw, "		<Icon>\n");
				 fprintf(pw, "		<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
				 fprintf(pw, "		</Icon>\n");
				 fprintf(pw, "		</IconStyle>\n");
				 fprintf(pw, "		<LabelStyle>\n");
				 fprintf(pw, "			<color>00000000</color>\n");
				 fprintf(pw, "			<scale>0</scale>\n");
				 fprintf(pw, "		</LabelStyle>\n");
				 fprintf(pw, "		<LineStyle>\n");
				 fprintf(pw, "			<color>ff6e6e6e</color>\n");
				 fprintf(pw, "			<width>1</width>\n");
				 fprintf(pw, "		</LineStyle>\n");
				 fprintf(pw, "		<PolyStyle>\n");
				 fprintf(pw, "			<color>fff7c6e9</color>\n");
				 fprintf(pw, "		</PolyStyle>\n");
				 fprintf(pw, "	</Style>\n");
				 fprintf(pw, "	<Folder id=\"KML\">\n");
				 fprintf(pw, "		<name>KML_%s</name>\n", buf);
				 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
				 fprintf(pw, "		<LookAt>\n");
				 fprintf(pw, "			<longitude>%lf</longitude>\n", Point2_XYZ[0].x);
				 fprintf(pw, "			<latitude>%lf</latitude>\n", Point2_XYZ[0].y);
				 fprintf(pw, "			<altitude>%lf</altitude>\n", Point2_XYZ[0].z + 100);
				 fprintf(pw, "			<heading>0</heading>\n");
				 fprintf(pw, "			<tilt>0</tilt>\n");
				 fprintf(pw, "			<range>130</range>\n");
				 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
				 fprintf(pw, "		</LookAt>\n");




				 fclose(pw);

			 }
			 
			 /*
			 FILE *pw = fopen(D_name, "w");


			 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
			 fprintf(pw, "<Document>\n");
			 fprintf(pw, "	<name>KML_%s</name>\n", buf);
			 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
			 fprintf(pw, "		<IconStyle>\n");

			 fprintf(pw, "			<scale>0.5</scale>\n");
			 fprintf(pw, "		<Icon>\n");
			 fprintf(pw, "		<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
			 fprintf(pw, "		</Icon>\n");
			 fprintf(pw, "		</IconStyle>\n");
			 fprintf(pw, "		<LabelStyle>\n");
			 fprintf(pw, "			<color>00000000</color>\n");
			 fprintf(pw, "			<scale>0</scale>\n");
			 fprintf(pw, "		</LabelStyle>\n");
			 fprintf(pw, "		<LineStyle>\n");
			 fprintf(pw, "			<color>ff6e6e6e</color>\n");
			 fprintf(pw, "			<width>1</width>\n");
			 fprintf(pw, "		</LineStyle>\n");
			 fprintf(pw, "		<PolyStyle>\n");
			 fprintf(pw, "			<color>fff7c6e9</color>\n");
			 fprintf(pw, "		</PolyStyle>\n");
			 fprintf(pw, "	</Style>\n");
			 fprintf(pw, "	<StyleMap id=\"PolyStyle001\">\n");
			 fprintf(pw, "		<Pair>\n");
			 fprintf(pw, "			<key>normal</key>\n");
			 fprintf(pw, "			<styleUrl>#PolyStyle000</styleUrl>\n");
			 fprintf(pw, "		</Pair>\n");
			 fprintf(pw, "		<Pair>\n");
			 fprintf(pw, "			<key>highlight</key>\n");
			 fprintf(pw, "			<styleUrl>#PolyStyle00</styleUrl>\n");
			 fprintf(pw, "		</Pair>\n");
			 fprintf(pw, "	</StyleMap>\n");
			 fprintf(pw, "	<Style id=\"PolyStyle000\">\n");
			 fprintf(pw, "		<IconStyle>\n");

			 fprintf(pw, "			<scale>0.5</scale>\n");
			 fprintf(pw, "		<Icon>\n");
			 fprintf(pw, "		<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
			 fprintf(pw, "		</Icon>\n");
			 fprintf(pw, "		</IconStyle>\n");
			 fprintf(pw, "		<LabelStyle>\n");
			 fprintf(pw, "			<color>00000000</color>\n");
			 fprintf(pw, "			<scale>0</scale>\n");
			 fprintf(pw, "		</LabelStyle>\n");
			 fprintf(pw, "		<LineStyle>\n");
			 fprintf(pw, "			<color>ff6e6e6e</color>\n");
			 fprintf(pw, "			<width>1</width>\n");
			 fprintf(pw, "		</LineStyle>\n");
			 fprintf(pw, "		<PolyStyle>\n");
			 fprintf(pw, "			<color>fff7c6e9</color>\n");
			 fprintf(pw, "		</PolyStyle>\n");
			 fprintf(pw, "	</Style>\n");
			 fprintf(pw, "	<Folder id=\"KML\">\n");
			 fprintf(pw, "		<name>KML_%s</name>\n", buf);
			 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
			 fprintf(pw, "		<LookAt>\n");
			 fprintf(pw, "			<longitude>%lf</longitude>\n", NewKMLAll[0].x);
			 fprintf(pw, "			<latitude>%lf</latitude>\n", NewKMLAll[0].y);
			 fprintf(pw, "			<altitude>%lf</altitude>\n", NewKMLAll[0].z + 100);
			 fprintf(pw, "			<heading>80</heading>\n");
			 fprintf(pw, "			<tilt>45</tilt>\n");
			 fprintf(pw, "			<range>130</range>\n");
			 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
			 fprintf(pw, "		</LookAt>\n");
			
			 //=================印出KML
			 fprintf(pw, "	<name>KML_%s_%d</name>\n", buf, NewKMLAll[0].Qflag);
			 fprintf(pw, "		<Placemark id=\"ID\">\n");
			 //				 fprintf(pw, "			<name>KML_ID%d</name>\n", KMLAll[i].FId);
			 //fprintf(pw, "			<description>%s</description>\n", filename2);
			 fprintf(pw, "			<description><![CDATA[<html xmlns:fo=\"http://www.w3.org/1999/XSL/Format\" xmlns:msxsl=\"urn:schemas-microsoft-com:xslt\">\n");
			 fprintf(pw, "			<head>\n");
			 fprintf(pw, "			<META http-equiv=\"Content - Type\" content=\"text / html\">\n");
			 fprintf(pw, "			<meta http-equiv=\"content - type\" content=\"text / html; charset = UTF - 8\">\n");
			 fprintf(pw, "			</head>\n");
			 fprintf(pw, "			<body style=\"margin:0px 0px 0px 0px; overflow:auto; background:#FFFFFF; \">\n");
			 fprintf(pw, "			<td>FID</td>\n\n");
			 fprintf(pw, "			<td>%s</td>\n", buf);
			 fprintf(pw, "			</html>]]></description>\n");

			 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
			 fprintf(pw, "			<MultiGeometry>\n");
			 fprintf(pw, "			<Polygon>\n");
			 fprintf(pw, "			<extrude>1</extrude>\n");
			 fprintf(pw, "			<altitudeMode>absolute</altitudeMode>\n");
			 fprintf(pw, "			<outerBoundaryIs>\n");
			 fprintf(pw, "			<LinearRing>\n");
			 fprintf(pw, "					<coordinates>\n");

			 int C = 0;
			 int NoFid = 0;
			 for (int j = 0; j < (int)NewKMLAll.size()-1; j++)
			 {
				 if (NewKMLAll[j].Show==0)
				 if (NewKMLAll[j].Qflag == 0 && C==0)
				 {
					 fprintf(pw, "%lf,%lf,%lf ", NewKMLAll[j].x, NewKMLAll[j].y, NewKMLAll[j].z);				 
				 }
				 else if (NewKMLAll[j].Qflag == 1 && C == 0)
				 {
					 NoFid = j;
					 fprintf(pw, "\n");
					 fprintf(pw, "					</coordinates>\n");
					 fprintf(pw, "			</LinearRing>\n");
					 fprintf(pw, "			</outerBoundaryIs>\n");
					 fprintf(pw, "			</Polygon>\n");
					 fprintf(pw, "			</MultiGeometry>\n");
					 fprintf(pw, "		</Placemark>\n");

					 //=================印出KML
					 fprintf(pw, "	<name>KML_%s_%d</name>\n", buf, NewKMLAll[j].Qflag);
					 fprintf(pw, "		<Placemark id=\"ID\">\n");
					 //				 fprintf(pw, "			<name>KML_ID%d</name>\n", KMLAll[i].FId);
					 //fprintf(pw, "			<description>%s</description>\n", filename2);
					 fprintf(pw, "			<description><![CDATA[<html xmlns:fo=\"http://www.w3.org/1999/XSL/Format\" xmlns:msxsl=\"urn:schemas-microsoft-com:xslt\">\n");
					 fprintf(pw, "			<head>\n");
					 fprintf(pw, "			<META http-equiv=\"Content - Type\" content=\"text / html\">\n");
					 fprintf(pw, "			<meta http-equiv=\"content - type\" content=\"text / html; charset = UTF - 8\">\n");
					 fprintf(pw, "			</head>\n");
					 fprintf(pw, "			<body style=\"margin:0px 0px 0px 0px; overflow:auto; background:#FFFFFF; \">\n");
					 fprintf(pw, "			<td>FID</td>\n\n");
					 fprintf(pw, "			<td>%s</td>\n", buf);
					 fprintf(pw, "			</html>]]></description>\n");

					 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
					 fprintf(pw, "			<MultiGeometry>\n");
					 fprintf(pw, "			<Polygon>\n");
					 fprintf(pw, "			<extrude>1</extrude>\n");
					 fprintf(pw, "			<altitudeMode>absolute</altitudeMode>\n");
					 fprintf(pw, "			<outerBoundaryIs>\n");
					 fprintf(pw, "			<LinearRing>\n");
					 fprintf(pw, "					<coordinates>\n");
					 fprintf(pw, "%lf,%lf,%lf ", NewKMLAll[j].x, NewKMLAll[j].y, NewKMLAll[j].z);

					 C = 1;
				 }
				 else  if (NewKMLAll[j].Qflag == 1 && C == 1)
				 {
					 fprintf(pw, "%lf,%lf,%lf ", NewKMLAll[j].x, NewKMLAll[j].y, NewKMLAll[j].z);
				 }

			 }
			 fprintf(pw, "%lf,%lf,%lf ", NewKMLAll[NoFid].x, NewKMLAll[NoFid].y, NewKMLAll[NoFid].z);
			 fprintf(pw, "\n");
			 fprintf(pw, "					</coordinates>\n");
			 fprintf(pw, "			</LinearRing>\n");
			 fprintf(pw, "			</outerBoundaryIs>\n");
			 fprintf(pw, "			</Polygon>\n");
			 fprintf(pw, "			</MultiGeometry>\n");
			 fprintf(pw, "		</Placemark>\n");


			 //=================印出KML-point
			 int Hid = 0;		 
			 fprintf(pw, "	<Folder id=\"KML\">\n");
			 for (int g = 0; g < (int)NewKMLAll.size()-1; g++)
			 {
				 if (NewKMLAll[g].Show == 0)
				 {
					 if (NewKMLAll[g].Qflag == NewKMLAll[g + 1].Qflag)
					 {
						 fprintf(pw, "		<Placemark id=\"ID\">\n");
						 fprintf(pw, "			<description>NO:%d\n", Hid);
						 fprintf(pw, "			%lf %lf %lf\n", NewKMLAll[g].x, NewKMLAll[g].y, NewKMLAll[g].z);
						 fprintf(pw, "			</description>\n");
						 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
						 fprintf(pw, "			<Point>\n");
						 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
						 fprintf(pw, "							<coordinates>\n");
						 fprintf(pw, "%lf,%lf,%lf \n",
							 NewKMLAll[g].x, NewKMLAll[g].y, NewKMLAll[g].z);
						 fprintf(pw, "							</coordinates>\n");
						 fprintf(pw, "			</Point>\n");
						 fprintf(pw, "		</Placemark>\n");
					 }


					 Hid = Hid + 1;

					 if (NewKMLAll[g].Qflag != NewKMLAll[g + 1].Qflag)
					 {
						 Hid = 0;
						 fprintf(pw, "	</Folder>\n");
						 fprintf(pw, "	<Folder id=\"KML\">\n");
					 }
				 }
				 
					 
			 }
			 
			 fprintf(pw, "	</Folder>\n");
			 
			 fprintf(pw, "	</Folder>\n");
			 fprintf(pw, "</Document>\n");
			 fprintf(pw, "</kml>\n");
			 fclose(pw);

			 */
		 }

		 //設定單點高度//確定
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	if ((int)KMLAll.size() > 0)
	{
		char *StartID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox4->Text)));
		int SiD = atoi(StartID);
		char *Z_value = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox5->Text)));
		double Z = atof(Z_value);
		
		KMLAll[SiD].z = Z;
		if (SiD == 0)	KMLAll[(int)KMLAll.size()-1].z = Z;

	}
	

}
		 //設定單點高度//exportkml
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	ExportKML01(D_name);

	MessageBox::Show("完成");
}

		 //設定單點高度//NextPoint
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	if ( (int)KMLAll.size() > 0)
	{
		SeePointZ();
	}
}
		 void SeePointZ()
		 {
			 if (StartKML_ID == (int)KMLAll.size())
				 StartKML_ID = 0;

			 char buffer[64];
			 //str4 = floatToString(KMLAll[StartKML_ID].FId);
			 sprintf(buffer, "%d", StartKML_ID);
			 String ^description = gcnew String(buffer);
			 this->textBox4->Text = description;

			 char* str = floatToString(KMLAll[StartKML_ID].z);
			 description = gcnew String(str);
			 this->textBox5->Text = description;

			 StartKML_ID = StartKML_ID + 1;
		 }


private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	char *StartID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox4->Text)));
	int SiD = atoi(StartID);	

	KMLAll[SiD].Show = 1;
}

private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}


		 void Cal_lonlat_To_twd97(double lon, double lat, int Mflag)
		 {
			 string TWD97 = "";

			 lon = (lon / 180) * M_PI;
			 lat = (lat / 180) * M_PI;

			 //---------------------------------------------------------
			 double e = Math::Pow((1 - Math::Pow(bxx, 2) / Math::Pow(axx, 2)), 0.5);
			 double e2 = Math::Pow(e, 2) / (1 - Math::Pow(e, 2));
			 double n = (axx - bxx) / (axx + bxx);
			 double nu = axx / Math::Pow((1 - (Math::Pow(e, 2)) * (Math::Pow(Math::Sin(lat), 2))), 0.5);
			 double p = lon - lon0;
			 double A = axx * (1 - n + (5 / 4) * (Math::Pow(n, 2) - Math::Pow(n, 3)) + (81 / 64) * (Math::Pow(n, 4) - Math::Pow(n, 5)));
			 double B = (3 * axx * n / 2.0) * (1 - n + (7 / 8.0)*(Math::Pow(n, 2) - Math::Pow(n, 3)) + (55 / 64.0)*(Math::Pow(n, 4) - Math::Pow(n, 5)));
			 double C = (15 * axx * (Math::Pow(n, 2)) / 16.0)*(1 - n + (3 / 4.0)*(Math::Pow(n, 2) - Math::Pow(n, 3)));
			 double D = (35 * axx * (Math::Pow(n, 3)) / 48.0)*(1 - n + (11 / 16.0)*(Math::Pow(n, 2) - Math::Pow(n, 3)));
			 double E = (315 * axx * (Math::Pow(n, 4)) / 51.0)*(1 - n);

			 double S = A * lat - B * Math::Sin(2 * lat) + C * Math::Sin(4 * lat) - D * Math::Sin(6 * lat) + E * Math::Sin(8 * lat);

			 //計算Y值
			 double K1 = S*k0;
			 double K2 = k0*nu*Math::Sin(2 * lat) / 4.0;
			 double K3 = (k0*nu*Math::Sin(lat)*(Math::Pow(Math::Cos(lat), 3)) / 24.0) * (5 - Math::Pow(Math::Tan(lat), 2) + 9 * e2*Math::Pow((Math::Cos(lat)), 2) + 4 * (Math::Pow(e2, 2))*(Math::Pow(Math::Cos(lat), 4)));
			 double y = K1 + K2*(Math::Pow(p, 2)) + K3*(Math::Pow(p, 4));

			 //計算X值
			 double K4 = k0*nu*Math::Cos(lat);
			 double K5 = (k0*nu*(Math::Pow(Math::Cos(lat), 3)) / 6.0) * (1 - Math::Pow(Math::Tan(lat), 2) + e2*(Math::Pow(Math::Cos(lat), 2)));
			 double x = K4 * p + K5 * (Math::Pow(p, 3)) + dx;

			 if (Mflag == 0){ Wgs84toTwd97X01 = x; Wgs84toTwd97Y01 = y; }
			 else if (Mflag == 1){ Wgs84toTwd97X02 = x; Wgs84toTwd97Y02 = y; }
		 }

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
