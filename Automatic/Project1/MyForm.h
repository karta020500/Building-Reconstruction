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



#include "ClassIndex.h"

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

	errno_t err;
	char *Filename01, *Readbpcfile;
	char FilenameTemp[256];
	//===============================================
	XYZarraytemp TXYZtemp;
	vector<XYZarraytemp> TXYZ;//暫存用


	KmlFileXYZ TKMLtemp;
	vector<KmlFileXYZ> KMLAll;//存放讀取全區的kml
	vector<KmlFileXYZ> KMLAll1;//存放讀取全區的kml
	vector<KmlFileXYZ> KML_GrdXYZ;
	vector<KmlFileXYZ> KML_GrdXYZ1;
	vector<KmlFileXYZ> KML_BPCXYZ;
	vector<KmlFileXYZ> KML_BPCXYZTemp;

	GetID getIDtemp;
	vector<GetID> KML_ID;
	


	BPCReport BPCtemp;
	vector<BPCReport> BPCAll;//存放las各tilename的資訊

	BPC2XYZI bpc2xyzi;
	vector<BPC2XYZI> BPC2xyzi;
	BpcTilename bpctemp;
	vector<BpcTilename> readbpctemp;
	BpcTilenameTemp bpcTtemp;
	vector<BpcTilenameTemp> readbpcTtemp;

	KMLcount KMLtemp;
	vector<KMLcount> Kcount;

	GetGrd GRDtemp;
	vector<GetGrd> GRDxyz;
	vector<GetGrd> GRDxyz02;
	
	GetLidra Lidratemp;
	vector<GetLidra> Lidraxyz;

	LidraXYZX LidraXYZXtemp;
	vector<LidraXYZX> LidraXYZXxyz;

	Grdinn Grdt;
	vector<Grdinn> Grdtxyz;
	
	PointXYZa Wgs84to97temp;
	vector<PointXYZa> Wgs84to9701;
	vector<PointXYZa> Wgs84to9702;

	PointToTran tranTemp;
	vector<PointToTran> Tranxyz;

	PointA PointAtemp;
	vector<PointA> PointAxyz;
	//===============================================

	double axx = 6378137.0;
	double bxx = 6356752.314245;
	double lon0 = 121 * M_PI / 180;
	double k0 = 0.9999;
	int dx = 250000;
	double Wgs84toTwd97X01, Wgs84toTwd97Y01;
	double Wgs84toTwd97X02, Wgs84toTwd97Y02;
	double XYZ97to84_x, XYZ97to84_y, XYZ97to84_z;

	char *Wgs84to90_1, *Wgs84to90_2;
	char Tilename02[4][128];

	char ShowIDxyz[128] = { '\0' };
	char D_name[256] = { '\0' };

	double A_minH = 0, A_maxH = 0;
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
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::GroupBox^  groupBox2;



	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button10;


	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  button16;


	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox9;


	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(8, 20);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 29);
			this->button1->TabIndex = 0;
			this->button1->Text = L"開啟KML";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox1->Location = System::Drawing::Point(8, 56);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(140, 25);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"0";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(8, 91);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(240, 41);
			this->button2->TabIndex = 3;
			this->button2->Text = L"分析";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(107, 362);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(385, 175);
			this->tabControl1->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4);
			this->tabPage1->Size = System::Drawing::Size(377, 146);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"航照點雲";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox2->Location = System::Drawing::Point(157, 56);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(140, 25);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"10";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"新細明體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(107, 20);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(91, 29);
			this->button3->TabIndex = 4;
			this->button3->Text = L"開啟點雲";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button23);
			this->tabPage2->Controls->Add(this->button22);
			this->tabPage2->Controls->Add(this->button21);
			this->tabPage2->Controls->Add(this->button12);
			this->tabPage2->Controls->Add(this->button11);
			this->tabPage2->Controls->Add(this->textBox8);
			this->tabPage2->Controls->Add(this->textBox7);
			this->tabPage2->Controls->Add(this->button10);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4);
			this->tabPage2->Size = System::Drawing::Size(377, 146);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"精度分析";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(109, 102);
			this->button23->Margin = System::Windows::Forms::Padding(4);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(89, 26);
			this->button23->TabIndex = 9;
			this->button23->Text = L"LOD 1";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(224, 102);
			this->button22->Margin = System::Windows::Forms::Padding(4);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(119, 26);
			this->button22->TabIndex = 8;
			this->button22->Text = L"分析";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(12, 102);
			this->button21->Margin = System::Windows::Forms::Padding(4);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(85, 26);
			this->button21->TabIndex = 7;
			this->button21->Text = L"點雲資料KML";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(8, 56);
			this->button12->Margin = System::Windows::Forms::Padding(4);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(359, 29);
			this->button12->TabIndex = 4;
			this->button12->Text = L"分析";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(199, 19);
			this->button11->Margin = System::Windows::Forms::Padding(4);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(69, 29);
			this->button11->TabIndex = 3;
			this->button11->Text = L"LOD1";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(276, 20);
			this->textBox8->Margin = System::Windows::Forms::Padding(4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(89, 25);
			this->textBox8->TabIndex = 2;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(85, 20);
			this->textBox7->Margin = System::Windows::Forms::Padding(4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(89, 25);
			this->textBox7->TabIndex = 1;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(8, 20);
			this->button10->Margin = System::Windows::Forms::Padding(4);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(69, 29);
			this->button10->TabIndex = 0;
			this->button10->Text = L"LOD2";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button13);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(377, 146);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"RBMtoKML";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(63, 22);
			this->button13->Margin = System::Windows::Forms::Padding(4);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(224, 30);
			this->button13->TabIndex = 0;
			this->button13->Text = L"LOD2RBMtoKML";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->button20);
			this->tabPage4->Controls->Add(this->textBox10);
			this->tabPage4->Controls->Add(this->textBox9);
			this->tabPage4->Controls->Add(this->button19);
			this->tabPage4->Controls->Add(this->button18);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Margin = System::Windows::Forms::Padding(4);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(377, 146);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"更改模型";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(21, 101);
			this->button20->Margin = System::Windows::Forms::Padding(4);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(212, 35);
			this->button20->TabIndex = 5;
			this->button20->Text = L"button20";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(136, 64);
			this->textBox10->Margin = System::Windows::Forms::Padding(4);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(96, 25);
			this->textBox10->TabIndex = 4;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(21, 64);
			this->textBox9->Margin = System::Windows::Forms::Padding(4);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(93, 25);
			this->textBox9->TabIndex = 3;
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(136, 16);
			this->button19->Margin = System::Windows::Forms::Padding(4);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(109, 28);
			this->button19->TabIndex = 2;
			this->button19->Text = L"點雲";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(21, 16);
			this->button18->Margin = System::Windows::Forms::Padding(4);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(107, 28);
			this->button18->TabIndex = 1;
			this->button18->Text = L"polygon";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button4->Location = System::Drawing::Point(8, 62);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(199, 29);
			this->button4->TabIndex = 6;
			this->button4->Text = L"輸入點雲資料";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Location = System::Drawing::Point(21, 15);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(216, 165);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"光達點雲資料轉換";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label2->Location = System::Drawing::Point(103, 102);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"至";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label1->Location = System::Drawing::Point(15, 102);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 17);
			this->label1->TabIndex = 9;
			this->label1->Text = L"從";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox4->Location = System::Drawing::Point(139, 99);
			this->textBox4->Margin = System::Windows::Forms::Padding(4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(67, 25);
			this->textBox4->TabIndex = 8;
			this->textBox4->Text = L"0";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox3->Location = System::Drawing::Point(39, 99);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(59, 25);
			this->textBox3->TabIndex = 6;
			this->textBox3->Text = L"0";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button6->Font = (gcnew System::Drawing::Font(L"新細明體", 9));
			this->button6->Location = System::Drawing::Point(8, 130);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(199, 28);
			this->button6->TabIndex = 6;
			this->button6->Text = L"執行";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button5->Font = (gcnew System::Drawing::Font(L"新細明體", 9));
			this->button5->Location = System::Drawing::Point(8, 26);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(199, 29);
			this->button5->TabIndex = 7;
			this->button5->Text = L"輸入LOD 1模型(KML)";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button9);
			this->groupBox2->Controls->Add(this->button8);
			this->groupBox2->Controls->Add(this->button7);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Location = System::Drawing::Point(21, 370);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(380, 131);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"光達";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(8, 98);
			this->button9->Margin = System::Windows::Forms::Padding(4);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(100, 29);
			this->button9->TabIndex = 11;
			this->button9->Text = L"分析";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(116, 26);
			this->button8->Margin = System::Windows::Forms::Padding(4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(100, 29);
			this->button8->TabIndex = 10;
			this->button8->Text = L"光達xyz";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(8, 26);
			this->button7->Margin = System::Windows::Forms::Padding(4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(100, 29);
			this->button7->TabIndex = 9;
			this->button7->Text = L"開啟KML";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox6->Location = System::Drawing::Point(157, 62);
			this->textBox6->Margin = System::Windows::Forms::Padding(4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(140, 25);
			this->textBox6->TabIndex = 8;
			this->textBox6->Text = L"0";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox5->Location = System::Drawing::Point(8, 62);
			this->textBox5->Margin = System::Windows::Forms::Padding(4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(140, 25);
			this->textBox5->TabIndex = 7;
			this->textBox5->Text = L"0";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button17);
			this->groupBox3->Controls->Add(this->button16);
			this->groupBox3->Controls->Add(this->button15);
			this->groupBox3->Controls->Add(this->button14);
			this->groupBox3->Location = System::Drawing::Point(248, 15);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4);
			this->groupBox3->Size = System::Drawing::Size(247, 165);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"三角網資料轉換";
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button17->Location = System::Drawing::Point(19, 130);
			this->button17->Margin = System::Windows::Forms::Padding(4);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(220, 28);
			this->button17->TabIndex = 5;
			this->button17->Text = L"執行";
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button16->Location = System::Drawing::Point(19, 62);
			this->button16->Margin = System::Windows::Forms::Padding(4);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(220, 31);
			this->button16->TabIndex = 4;
			this->button16->Text = L"輸入LOD 1模型(KML)";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button15->Location = System::Drawing::Point(19, 95);
			this->button15->Margin = System::Windows::Forms::Padding(4);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(220, 31);
			this->button15->TabIndex = 1;
			this->button15->Text = L"輸入三角網資料";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button14->Location = System::Drawing::Point(19, 26);
			this->button14->Margin = System::Windows::Forms::Padding(4);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(100, 29);
			this->button14->TabIndex = 0;
			this->button14->Text = L"資料前處理";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MediumAquamarine;
			this->ClientSize = System::Drawing::Size(511, 199);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->tabControl1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Automatic Increase the LoD of 3D Building Models";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		openFileDialog1->Reset();
		openFileDialog1->InitialDirectory = "";
		openFileDialog1->Filter = "(*.kml)|*.kml";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{

			Filename01 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));

			TXYZ.clear();
			KMLAll.clear();

			//正常讀取全區LOD1 (KML)
			LoadLod1(Filename01);
			//
			//	FILE *fp1;
			//	err = fopen_s(&fp1, "a1.txt", "w");
			//	for (int i = 0; i < (int)KML_ID.size(); i++)
			//	{
			//		fprintf(fp1, "%d %d %s\n", i, KML_ID[i].NO, KML_ID[i].name);
			//	}
			//	fclose(fp1);
			//////FILE *fp = fopen("a.txt", "w");
			//FILE *fp;
			//err = fopen_s(&fp, "a2.txt", "w");			
			//for (int i = 0; i < (int)KMLAll.size(); i++)
			//{
			//	fprintf(fp, "%d %d %d %lf %lf %lf\n", KMLAll[i].Id, KMLAll[i].Qflag, KMLAll[i].count,KMLAll[i].x, KMLAll[i].y, KMLAll[i].z
			//		
			//	);
			//}
			//fclose(fp);
			//Kcount
			//FILE *fp;
			//err = fopen_s(&fp, "a1.txt", "w");			
			//for (int i = 0; i < (int)Kcount.size(); i++)
			//{
			//	fprintf(fp, "%d %d\n", Kcount[i].id, Kcount[i].count	);
			//}
			//fclose(fp);
			MessageBox::Show("LOAD完成");
		}
	}

	//正常讀取全區LOD1 (KML)
	void LoadLod1(char filename[512])
	{
		
		char buf[25000] = { '\0' };
		//FILE *fkml = fopen(filename, "r");
		FILE *fkml;
		err = fopen_s(&fkml, filename, "r");
		
		char Build_NO[80] = "<td>FID</td>";
		char check_coordinates[80] = "<coordinates>";
		
		char *locNO = { '\0' };
		char *loc = { '\0' };
		
		int Qflag = 0;
		int Kcount = 0;
		int KMLTemp_count = 0;
		//int NumId = 0;
		while (fgets(buf, 25000, fkml) != NULL) {
		    
			//字串搜尋 比對
			locNO = strstr(buf, Build_NO);
			if (locNO != NULL)
			{
				fgets(buf, 25000, fkml);
				fgets(buf, 25000, fkml);
				strcpy(getIDtemp.name,buf);
				sscanf(buf, "<td>%d</td>", &getIDtemp.NO);
				//GetID getIDtemp;
				KML_ID.push_back(getIDtemp);
			}

			//字串搜尋 比對
			loc = strstr(buf, check_coordinates);
			if (loc != NULL)
			{
				fgets(buf, 25000, fkml);
				//清空空白
				string *tmpStr = new string(buf);
				tmpStr->erase(tmpStr->begin(), tmpStr->begin() + tmpStr->find_first_not_of("								"));
				//strcpy(buf, tmpStr->c_str());
				strcpy_s(buf, sizeof(buf) / sizeof(buf[0]), tmpStr->c_str());
				
				
				//std::printf("%s\n", buf);
				Kcount = AnalysisKMLxyz(buf, KMLTemp_count);
				KMLTemp_count = KMLTemp_count + 1;


				Qflag = Qflag + 1;
			}
		}

	}


	//分析讀到的<coordinates>下一行中的所有的xyz(Loadkmlarray)
	int AnalysisKMLxyz(char buf[25000], int KMLTemp_count)
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

		KMLtemp.id = KMLTemp_count;
		KMLtemp.count = i;
		Kcount.push_back(KMLtemp);

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
							KMLAll.push_back(TKMLtemp);


						}
					}
				}

			}

		}

		return j;

	}


private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.lal)|*.LAL";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;
	//String ^CSVname02;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		char *name = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		BPCAll.clear();
		//可正常讀取BPCreport
		LoadBPCreport(name);

		////FILE *fp = fopen("a.txt", "w");
		//FILE *fp;
		//err = fopen_s(&fp, "las.txt", "w");
		//for (int i = 0; i < (int)BPCAll.size(); i++)
		//{			  
		// fprintf(fp, "%.5lf %.5lf %.5lf %.5lf    %7.2lf   %7.2lf   %1.0lf   %1.0lf %lf %s\n",
		//	 BPCAll[i].x1, BPCAll[i].x2, BPCAll[i].y1, BPCAll[i].y2, BPCAll[i].z1, BPCAll[i].z2, BPCAll[i].d1, BPCAll[i].d2, BPCAll[i].d3, BPCAll[i].Tilename
		//	 );
		//}
		//fclose(fp);

		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		Readbpcfile = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));
		strcat(Readbpcfile, "\\");
		//CSV_path = CSV_path + "\\" + "a00.txt";
		//String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		//CSV_path = CSV_path + "\\" + "a1.txt";
		//OutputFilepath = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));
		//LoadBPCreport(name);//可正常讀取BPCreport
		//CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);

		//Readbpcfile = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));
		//strcat(Readbpcfile, "\\");
		//CSV_path = CSV_path + "\\" + "a00.txt";
		//OutputFilepath = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));
		//
		MessageBox::Show("LOAD完成");
	}

}

		 //可正常讀取BPCreport
		 void LoadBPCreport(char *filename)
		 {
			 char buf[1024] = { '\0' };
			 double x1 = 0, x2 = 0, y1 = 0, y2 = 0, z1 = 0, z2 = 0, d1 = 0, d2 = 0, d3 = 0;
			 char Tilename[128] = { '\0' };
			 double f97ENHto84X = 0, f97ENHto84Y = 0, f97ENHto84Z = 0;
			 FILE *f_bpcreport;
			 err = fopen_s(&f_bpcreport, filename, "r");

			 while (fgets(buf, 1024, f_bpcreport) != NULL) {
				 sscanf(buf, "%lf %lf %lf %lf    %lf   %lf   %lf   %lf %lf %s",
					 &BPCtemp.x1, &BPCtemp.x2, &BPCtemp.y1, &BPCtemp.y2,
					 &BPCtemp.z1, &BPCtemp.z2, &BPCtemp.d1, &BPCtemp.d2, &BPCtemp.d3, BPCtemp.Tilename);
				 //坐標轉換97to84(x,y)
				 TWD97ENH_WGS84XYZ('T', BPCtemp.x1, BPCtemp.y1, BPCtemp.z1, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				 BPCtemp.x1 = XYZ97to84_x; BPCtemp.y1 = XYZ97to84_y;
				 TWD97ENH_WGS84XYZ('T', BPCtemp.x2, BPCtemp.y2, BPCtemp.z1, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				 BPCtemp.x2 = XYZ97to84_x; BPCtemp.y2 = XYZ97to84_y;

				 BPCAll.push_back(BPCtemp);
			 }

			 fclose(f_bpcreport);
			 
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


		 //分析polygon在哪個tile
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		if (((int)BPCAll.size() > 0) && ((int)KMLAll.size() > 0))
		{
			readbpcTtemp.clear();
			readbpctemp.clear();

			//FILE *fg = fopen("aa.txt", "w");


			char *StartID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox1->Text)));
			int SiD = atoi(StartID);
			char *EndID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox2->Text)));
			int EiD = atoi(EndID);

			//if (Gbpctemp)	delete Gbpctemp;
			char *name = { '\0' };
			PointA p;
			//Gbpctemp = new BpcTilenameTemp[KML_LoadAll.size()];
			char bpcpath[128] = { '\0' };
			char bpcpathLess[128] = { '\0' };
			char bpcpathKML[128] = { '\0' };
			char bpcpathBase[128] = { '\0' };
			char Lod1KML[128] = { '\0' };
			char tesst[128] = { '\0' };
			int BpcBaseflag = 0;
			double B_x = 0, B_y = 0, B_z = 0;
			int TilenameFlag = 0, GNow = 0, checki = 0;
			//FILE *fp = fopen(OutputFilepath, "w");
			FILE *fkml;
			int GG = 0;
			int StartId = 0;
			int EndId = 0;
			for (int i = 0; i < (int)KMLAll.size(); i++)
			{


				KML_BPCXYZ.clear();
				readbpctemp.clear();
				BpcTilenameTemp bpcTtemp;
				int strcmpCheck = -1, t03 = 0, tFlag = -1;
				p.x = KMLAll[i].x;		p.y = KMLAll[i].y;
				int g = PointInTile(p, i);//Tilename02
				char Tilename01[4][128];
				char Tilename03[4][128];


				//避免下面的判斷再找停一個Qflag時出錯//要記得 要在最後面處理最後一筆
				if (i != KMLAll.size() - 1)
				{
					//if (KML_LoadAll[i].Qflag == KML_LoadAll[i + 1].Qflag)
					{
						for (int u = 0; u < g; u++)
						{
							strcpy(Tilename01[u], Tilename02[u]);
							//fprintf(fp, "%d %s ", g, Tilename01[u]);
						}

						if (strcmpCheck == -1)
						{
							strcpy(Tilename03[0], Tilename01[0]);
							strcmpCheck = 0; t03 = 1;
						}
						int jk = -1;
						for (int u = 0; u < g; u++)
						{
							for (int w = 0; w < t03; w++)
							{
								jk = strcmp(Tilename03[w], Tilename01[u]);
								if (jk != 0)	{ tFlag = u; }
							}
							if (jk == -1)
							{
								strcpy(Tilename03[t03], Tilename01[tFlag]);
								t03 = t03 + 1;
							}
						}

						//for (int w = 0; w < t03; w++)
						//{
						//	fprintf(fp, "g=%d %d %s \n",g,w, Tilename03[w]);	
						//	bpcTtemp.num = g; bpcTtemp.Qflag = KML_LoadAll[i].Qflag;
						//	strcpy(bpcTtemp.Tilename[w], Tilename03[w]);
						//}
						//readbpcTtemp.push_back(bpcTtemp);
						if (g > GG)	GG = g;
					}

					//當處理到同一個Qflg的最後一筆時,開始進行作業
					if (KMLAll[i].Qflag != KMLAll[i + 1].Qflag)
					{
						//Readbpcfile+//
						BPC2xyzi.clear();
						KML_BPCXYZ.clear();
						//BPC2xyzi.clear();

						//if (KML_LoadAll[i].Qflag > 0)
						if (KMLAll[i].Qflag > 0 && (SiD <= KMLAll[i].Qflag  &&  EiD >= KMLAll[i].Qflag))
						{
							//讀取kml_polygon-所屬的BPC-檔案//BPC2xyzi
							for (int bpci = 0; bpci < GG; bpci++)
							{
								strcpy(bpcpath, Readbpcfile);
								strcat(bpcpath, Tilename03[bpci]);
								//fprintf(fp, "%s\n", Tilename03[bpci]);
								//FILE *fbpc = fopen(bpcpath, "r");
								//if (KML_LoadAll[i].Qflag==120)						
								LoadBPCfile(bpcpath);
							}
							

							PointA p;
							for (int s1 = 0; s1 < (int)BPC2xyzi.size(); s1++)
							{
								p.x = BPC2xyzi[s1].x; p.y = BPC2xyzi[s1].y;
								if (PointinPolygonBPC(p, StartId, i))
								{
									TKMLtemp.x = BPC2xyzi[s1].x; TKMLtemp.y = BPC2xyzi[s1].y; TKMLtemp.z = BPC2xyzi[s1].z;
									TKMLtemp.Id = BPC2xyzi[s1].i;
									KML_BPCXYZ.push_back(TKMLtemp);
								}
							}
						}


						

						if ((SiD <= KMLAll[i].Qflag  &&  EiD >= KMLAll[i].Qflag))
						{
							
							//KML_BPCXYZ//KMLpoint
							//判斷資料夾或檔案是否存在access//不存在就建一個mkdir
							char name2[64]; //itoa(KMLAll[i].Qflag, name2, 10);
							itoa(KML_ID[KMLAll[i].Qflag].NO, name2, 10);
							strcpy(bpcpath, Readbpcfile);
							strcat(bpcpath, "result\\");
							if (access(bpcpath, 0))
							{
								mkdir(bpcpath);
							}

							char KMLname[256];
							strcpy(KMLname, bpcpath);
							strcat(KMLname, name2);
							strcat(KMLname, ".kml");

							strcat(bpcpath, name2);
							strcat(bpcpath, "\\");
							if (access(bpcpath, 0))
							{
								mkdir(bpcpath);
							}
							strcat(bpcpath, name2);
							//strcat(bpcpath, "_bpc");
							strcpy(bpcpathLess, bpcpath);
							strcat(bpcpathLess, "_Less.xyz");
							strcpy(bpcpathKML, bpcpath);
							strcat(bpcpathKML, "_kml.kml");
							strcpy(bpcpathBase, bpcpath);
							strcat(bpcpathBase, "_base.txt");
							strcpy(Lod1KML, bpcpath);
							strcat(Lod1KML, "_LOD1.kml");

							strcpy(tesst, bpcpath);
						    strcat(tesst, "New.kml");


							strcat(bpcpath, ".xyz");

							
							//匯出LOD1-KML
							ExportLOD1KML(Lod1KML, StartId, i);				
							

							//if (access(bpcpath, 0))
							if (KMLAll[i].Qflag > 0 && KML_BPCXYZ.size() > 0)
							{



								BpcBaseflag = 0;
								FILE *fbpc = fopen(bpcpath, "w");
								for (int s2 = 0; s2 < (int)KML_BPCXYZ.size(); s2++)
								{
									Cal_lonlat_To_twd97(KML_BPCXYZ[s2].x, KML_BPCXYZ[s2].y, 0);
									if (BpcBaseflag == 0)
									{
										BpcBaseflag = 1;
										B_x = Wgs84toTwd97X01; B_y = Wgs84toTwd97Y01 + 2; B_z = KML_BPCXYZ[s2].z;
										FILE *fbBase = fopen(bpcpathBase, "w");
										fprintf(fbBase, "%lf %lf %lf", B_x, B_y, B_z);
										fclose(fbBase);
									}
									//fprintf(gh, "%lf %lf %lf\n", KML_BPCXYZ[s2].x, KML_BPCXYZ[s2].y, KML_BPCXYZ[s2].z);
									//Cal_lonlat_To_twd97(KML_BPCXYZ[s2].x, KML_BPCXYZ[s2].y, 0);
									fprintf(fbpc, "%lf %lf %lf\n", Wgs84toTwd97X01 - B_x, (Wgs84toTwd97Y01 + 2) - B_y, KML_BPCXYZ[s2].z - B_z);
								}
								fclose(fbpc);
								BpcBaseflag = 0;


								//fclose(gh);
								
								ExportBPCtoKML(bpcpathKML, fkml);
								//ExportNewLOD1_T02(KMLname, StartId, i, tesst, name2, B_z);
								ExportNewLOD1_T03(KMLname, StartId, i, tesst, name2, B_z);
								
							}
							

						}
						//判斷資料夾或檔案是否存在access//不存在就建一個mkdir
						//GG = 0;
						StartId = i + 1;
						
						
					}

				}


			}
			
			//fclose(fp);
			//FILE *fp1 = fopen("./data/aRename.txt", "w");
			//for (int i = 0; i < readbpcTtemp.size(); i++)
			//{	
			//	fprintf(fp, "%d %d %d %s %s\n", i, readbpcTtemp[i].Qflag, readbpcTtemp[i].num, readbpcTtemp[i].Tilename[0], readbpcTtemp[i].Tilename[1]);
			//}
			//fclose(fp);
			
			//fclose(fg);
			MessageBox::Show("done");
		}
		else
		{
			MessageBox::Show("資料讀取不正確，請重新檢查");
		}

	}



			 ////取得KML-所屬的point cloud落在哪一個BPC-tile
			 int PointInTile(PointA p, int id) {
				 int j = 0;
				 for (int i = 0; i < (int)BPCAll.size(); i++)
				 {
					 if (((BPCAll[i].x1 < p.x) && (BPCAll[i].y1 < p.y)) && ((BPCAll[i].x2 > p.x) && (BPCAll[i].y2 > p.y)))
					 {
						 strcpy(Tilename02[j], BPCAll[i].Tilename);

						 //strcpy(bpctemp.Tilename, Readbpcreport[i].Tilename);
						 //readbpctemp.push_back(bpctemp);
						 j = j + 1;
					 }
				 }
				 return j;
			 }

			 void LoadBPCfile(char *filename)
			 {

				 //fprintf(fp, "%s\n", filename);
				 FILE* file = fopen(filename, "rb");
				 double buffer = 0;
				 double buffera = 0;
				 //預備kml檔需要的資料～
				 double f97ENHto84X = 0;
				 double f97ENHto84Y = 0;
				 double f97ENHto84Z = 0;
				 int C = 0;
				 if (file) {
					 /* File was opened successfully. */

					 /* Attempt to read */
					 while (fread(&buffer, 1, sizeof(buffer), file) == 8) {
						 if (C == 0){ bpc2xyzi.x = buffer; C++; }
						 else if (C == 1){ bpc2xyzi.y = buffer; C++; }
						 else if (C == 2){ bpc2xyzi.z = buffer; C++; }
						 else if (C == 3)
						 {
							 bpc2xyzi.i = buffer; C = 0;
							 TWD97ENH_WGS84XYZ('T', bpc2xyzi.x, bpc2xyzi.y, bpc2xyzi.z, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
							 bpc2xyzi.x = XYZ97to84_x; bpc2xyzi.y = XYZ97to84_y; 
							 //這邊Z-8主要是針對bpc點雲過高問題 
							 bpc2xyzi.z = XYZ97to84_z -8;
							 BPC2xyzi.push_back(bpc2xyzi);
						 }
					 }

					 fclose(file);
				 }
				 //char bpcpath[512];
				 //strcpy(bpcpath, Readbpcfile);
				 //strcat(bpcpath, "a.txt");
				 //FILE *fp = fopen(bpcpath, "w");
				 //for (int i = 0; i < BPC2xyzi.size(); i++)
				 //{
				 //	fprintf(fp, "%lf %lf %lf %lf \n", BPC2xyzi[i].x, BPC2xyzi[i].y, BPC2xyzi[i].z, BPC2xyzi[i].i);
				 //}
				 //fclose(fp);
				 //int G = 0;
			 }

			 bool PointinPolygonBPC(PointA p, int i, int Kcount) {
				 int j = 0;
				 bool inside = false;
				 for (j = Kcount - 1; i < Kcount; j = i++)
				 {
					 if (((KMLAll[i].y > p.y) != (KMLAll[j].y > p.y)) && (p.x < (KMLAll[j].x - KMLAll[i].x) * (p.y - KMLAll[i].y) / (KMLAll[j].y - KMLAll[i].y) + KMLAll[i].x)) inside = !inside;
				 }

				 return inside;
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

			 void exportTest(char name[512])
			 {
				 FILE *pw = fopen(name, "w");

				 if (KML_BPCXYZTemp.size() >= 1)
				 {
					 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
					 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
					 fprintf(pw, "<Document>\n");
					 fprintf(pw, "	<name>KML</name>\n");
					 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
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
					 fprintf(pw, "		<name>KML</name>\n");
					 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
					 fprintf(pw, "		<LookAt>\n");
					 fprintf(pw, "			<longitude>%lf</longitude>\n", KML_BPCXYZTemp[0].x);
					 fprintf(pw, "			<latitude>%lf</latitude>\n", KML_BPCXYZTemp[0].y);
					 fprintf(pw, "			<altitude>%lf</altitude>\n", KML_BPCXYZTemp[0].z + 100);
					 fprintf(pw, "			<heading>80</heading>\n");
					 fprintf(pw, "			<tilt>45</tilt>\n");
					 fprintf(pw, "			<range>130</range>\n");
					 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
					 fprintf(pw, "		</LookAt>\n");
					 //ExportLOD1KML
					 //=================印出KML
					 for (int i = 0; i < (int)KML_BPCXYZTemp.size(); i = i + 1)
						 //for (int i = 0; i < 10; i++)
					 {
						 //int d = i %100 ;
						 //if (d == 0)
						 {
							 fprintf(pw, "		<Placemark id=\"ID_%d\">\n", i);
							 fprintf(pw, "			<name>ID_%d</name>\n", i);
							 fprintf(pw, "			<description>\n");
							 fprintf(pw, "			1\n");
							 fprintf(pw, "			</description>\n");
							 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
							 fprintf(pw, "			<Point>\n");
							 fprintf(pw, "					<altitudeMode>relativeToGround</altitudeMode>\n");
							 fprintf(pw, "							<coordinates>\n");
							 fprintf(pw, "								%lf,%lf,%lf \n",
								 KML_BPCXYZTemp[i].x, KML_BPCXYZTemp[i].y, KML_BPCXYZTemp[i].z
								 );
							 fprintf(pw, "\n							</coordinates>\n");
							 fprintf(pw, "			</Point>\n");
							 fprintf(pw, "		</Placemark>\n");
						 }
					 }
					 //=================印出KML

					 fprintf(pw, "	</Folder>\n");
					 fprintf(pw, "</Document>\n");
					 fprintf(pw, "</kml>\n");
				 }
				 
				 fclose(pw);
			 }

			 //匯出LOD1-KML
			 void ExportLOD1KML(char name[512], int i, int j)
			 {

				 FILE *pw = fopen(name, "w");

				 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
				 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
				 fprintf(pw, "<Document>\n");
				 fprintf(pw, "	<name>KML</name>\n");
				 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
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
				 fprintf(pw, "		<name>KML</name>\n");
				 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
				 fprintf(pw, "		<LookAt>\n");
				 fprintf(pw, "			<longitude>%lf</longitude>\n", KMLAll[i].x);
				 fprintf(pw, "			<latitude>%lf</latitude>\n", KMLAll[i].y);
				 fprintf(pw, "			<altitude>%lf</altitude>\n", KMLAll[i].z + 100);
				 fprintf(pw, "			<heading>80</heading>\n");
				 fprintf(pw, "			<tilt>45</tilt>\n");
				 fprintf(pw, "			<range>130</range>\n");
				 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
				 fprintf(pw, "		</LookAt>\n");
				 //ExportLOD1KML
				 //=================印出KML
				 fprintf(pw, "	<name>KML_%d</name>\n", i);
				 fprintf(pw, "		<Placemark id=\"ID\">\n");
				 fprintf(pw, "			<name>KML_ID%d</name>\n", i);
				 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
				 fprintf(pw, "			<Polygon>\n");
				 fprintf(pw, "			<extrude>1</extrude>\n");
				 fprintf(pw, "			<altitudeMode>relativeToGround</altitudeMode>\n");
				 fprintf(pw, "			<outerBoundaryIs>\n");
				 fprintf(pw, "			<LinearRing>\n");
				 fprintf(pw, "					<coordinates>\n");
				 //int j = 0;
				 for (int g = i; g <= j; g++)
				 {

					 fprintf(pw, "%lf,%lf,%lf ", KMLAll[g].x, KMLAll[g].y, KMLAll[g].z);

				 }
				 fprintf(pw, " \n");
				 //fprintf(pw, "%lf,%lf,%lf \n", KMLAll[i].x, KMLAll[i].y, KMLAll[i].z);
				 //fprintf(pw, "%lf,%lf,%lf\n", KML_list[j].x, KML_list[j].y, KML_list[j].z);
				 fprintf(pw, "					</coordinates>\n");
				 fprintf(pw, "			</LinearRing>\n");
				 fprintf(pw, "			</outerBoundaryIs>\n");
				 fprintf(pw, "			</Polygon>\n");
				 fprintf(pw, "		</Placemark>\n");
				 //=================印出KML

				 fprintf(pw, "	</Folder>\n");
				 fprintf(pw, "</Document>\n");
				 fprintf(pw, "</kml>\n");

				 fclose(pw);


			 }

			 void ExportNewLOD1_T02(char filename[256], int i, int j, char filename1[256], char filename2[256], int B_z)
			 {
				 KML_BPCXYZTemp.clear();
				 //KML_BPCXYZ//KMLAll
				 FILE *pw = fopen(filename, "w");

				 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
				 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
				 fprintf(pw, "<Document>\n");
				 fprintf(pw, "	<name>KML_%s</name>\n", filename2);
				 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
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
				 fprintf(pw, "		<name>KML_%s</name>\n", filename2);
				 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
				 fprintf(pw, "		<LookAt>\n");
				 fprintf(pw, "			<longitude>%lf</longitude>\n", KMLAll[i].x);
				 fprintf(pw, "			<latitude>%lf</latitude>\n", KMLAll[i].y);
				 fprintf(pw, "			<altitude>%lf</altitude>\n", KMLAll[i].z + 100);
				 fprintf(pw, "			<heading>80</heading>\n");
				 fprintf(pw, "			<tilt>45</tilt>\n");
				 fprintf(pw, "			<range>130</range>\n");
				 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
				 fprintf(pw, "		</LookAt>\n");
				 //ExportLOD1KML
				 //=================印出KML
				 fprintf(pw, "	<name>KML_%s</name>\n", filename2);
				 fprintf(pw, "		<Placemark id=\"ID\">\n");
//				 fprintf(pw, "			<name>KML_ID%d</name>\n", KMLAll[i].FId);
				 fprintf(pw, "			<description>%s</description>\n", filename2);
				 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");				 
				 fprintf(pw, "			<Polygon>\n");
				 fprintf(pw, "			<extrude>1</extrude>\n");
				 fprintf(pw, "			<altitudeMode>relativeToGround</altitudeMode>\n");
				 fprintf(pw, "			<outerBoundaryIs>\n");
				 fprintf(pw, "			<LinearRing>\n");
				 fprintf(pw, "					<coordinates>\n");
				 //int j = 0;


				 //BpcBaseflag = 1;
				 // B_x = Wgs84toTwd97X01; B_y = Wgs84toTwd97Y01 + 2; B_z = KML_BPCXYZ[s2].z;
				 
				 double x0, y0, x1, y1, dis;
				 double MinH = 999999, MaxH = 0;
				 double avgH;
				 int count = 0;
				 double H;
				 int Checkcount = 0;
				 double Maxh = 0, Mixh = 99999;
				 for (int w = 0; w < (int)KML_BPCXYZ.size(); w++)
				 {
					 if (Maxh < KML_BPCXYZ[w].z)Maxh = KML_BPCXYZ[w].z;
					 if (Mixh > KML_BPCXYZ[w].z)Mixh = KML_BPCXYZ[w].z;
				 }
				 double a01 = 0, a02 = 0, a03 = 0, a04 = 0 , Havg=0;
				 double a05 = 0, a06 = 0, a07 = 0, a08 = 0;
				 int a01c = 0, a02c = 0, a03c = 0, a04c = 0, a05c = 0;
				 int a06c = 0, a07c = 0, a08c = 0, a09c = 0, a010c = 0;
				 double a01H = 0, a02H = 0, a03H = 0, a04H = 0, a05H = 0;
				 double a06H = 0, a07H = 0, a08H = 0, a09H = 0, a010H = 0;
				 Havg = (Maxh - Mixh) / 4;
				 
				 a01 = Mixh; a02 = Mixh + Havg; a03 = Mixh + Havg * 2; a04 = Mixh + Havg *3;
				 
				 //
				 for (int w = 0; w < (int)KML_BPCXYZ.size(); w++)
				 {
					 if (KML_BPCXYZ[w].z >= a01  && KML_BPCXYZ[w].z < a02)
					 {
						 a01c = a01c + 1;	a01H = a01H + KML_BPCXYZ[w].z;
					 }
					 else if (KML_BPCXYZ[w].z >= a02  && KML_BPCXYZ[w].z < a03)
					 {
						 a02c = a02c + 1;	a02H = a02H + KML_BPCXYZ[w].z;
					 }
					 else if (KML_BPCXYZ[w].z >= a03  && KML_BPCXYZ[w].z < a04)
					 {
						 a03c = a03c + 1;	a03H = a03H + KML_BPCXYZ[w].z;
					 }
					 else if (KML_BPCXYZ[w].z >= a04  && KML_BPCXYZ[w].z <= Maxh)
					 {
						 a04c = a04c + 1;	a04H = a04H + KML_BPCXYZ[w].z;
					 }
				 }

				 if (a01c > a02c){
					 if (a01c > a03c)
					 {
						 if (a01c > a04c)
							avgH = a01H / a01c;
					 }						
				 }
				 if (a02c > a01c){
					 if (a02c > a03c)
					 {
						 if (a02c > a04c)
							 avgH = a02H / a02c;
					 }
				 }
				 if (a03c > a01c){
					 if (a03c > a02c)
					 {
						 if (a03c > a04c)
							 avgH = a03H / a03c;
					 }
				 }
				 if (a04c > a01c){
					 if (a04c > a02c)
					 {
						 if (a04c > a03c)
							 avgH = a04H / a04c;
					 }
				 }
				 if (a01c == a02c){ avgH = (a01H + a02H) / (a01c * 2); }
				 else if (a01c == a03c){ avgH = (a01H + a03H) / (a01c * 2); }
				 else if (a01c == a04c){ avgH = (a01H + a04H) / (a01c * 2); }
				 else if (a02c == a03c){ avgH = (a02H + a03H) / (a02c * 2); }
				 else if (a02c == a03c){ avgH = (a02H + a03H) / (a02c * 2); }
				 else if (a03c == a04c){ avgH = (a03H + a04H) / (a03c * 2); }


				 for (int g = i; g <= j; g++)
				 {
					 //count = 0;avgH = 0; 
					 //if (Kcount[KMLAll[g].Qflag].count <= 5)
					 {

						 for (int a = 0; a < (int)KML_BPCXYZTemp.size(); a++)
						 {
							 Cal_lonlat_To_twd97(KML_BPCXYZTemp[a].x, KML_BPCXYZTemp[a].y, 0);
							 x1 = Wgs84toTwd97X01; y1 = Wgs84toTwd97Y01 + 2;

						 }

						fprintf(pw, "%lf,%lf,%lf ", KMLAll[g].x, KMLAll[g].y, avgH);

					 }
				 }
				 fprintf(pw, " \n");
				 //fprintf(pw, "%lf,%lf,%lf \n", KMLAll[i].x, KMLAll[i].y, H);
				 //fprintf(pw, "%lf,%lf,%lf ", KMLAll[i].x, KMLAll[i].y, KMLAll[i].z);
				 

				 //fprintf(pw, "%lf,%lf,%lf\n", KML_list[j].x, KML_list[j].y, KML_list[j].z);
				 fprintf(pw, "					</coordinates>\n");
				 fprintf(pw, "			</LinearRing>\n");
				 fprintf(pw, "			</outerBoundaryIs>\n");
				 fprintf(pw, "			</Polygon>\n");
				 fprintf(pw, "		</Placemark>\n");
				 //=================印出KML

				 fprintf(pw, "	</Folder>\n");
				 fprintf(pw, "</Document>\n");
				 fprintf(pw, "</kml>\n");
				 fclose(pw);
			 }

			 void ExportNewLOD1_T03(char filename[256], int i, int j, char filename1[256], char filename2[256], int B_z)
			 {
				 KML_BPCXYZTemp.clear();
				 //KML_BPCXYZ//KMLAll
				 FILE *pw = fopen(filename, "w");

				 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
				 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
				 fprintf(pw, "<Document>\n");
				 fprintf(pw, "	<name>KML_%s</name>\n", filename2);
				 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
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
				 fprintf(pw, "		<name>KML_%s</name>\n", filename2);
				 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
				 fprintf(pw, "		<LookAt>\n");
				 fprintf(pw, "			<longitude>%lf</longitude>\n", KMLAll[i].x);
				 fprintf(pw, "			<latitude>%lf</latitude>\n", KMLAll[i].y);
				 fprintf(pw, "			<altitude>%lf</altitude>\n", KMLAll[i].z + 100);
				 fprintf(pw, "			<heading>80</heading>\n");
				 fprintf(pw, "			<tilt>45</tilt>\n");
				 fprintf(pw, "			<range>130</range>\n");
				 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
				 fprintf(pw, "		</LookAt>\n");
				 //ExportLOD1KML
				 //=================印出KML
				 fprintf(pw, "	<name>KML_%s</name>\n", filename2);
				 fprintf(pw, "		<Placemark id=\"ID\">\n");
				 //				 fprintf(pw, "			<name>KML_ID%d</name>\n", KMLAll[i].FId);
				 fprintf(pw, "			<description>%s</description>\n", filename2);
				 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
				 fprintf(pw, "			<Polygon>\n");
				 fprintf(pw, "			<extrude>1</extrude>\n");
				 fprintf(pw, "			<altitudeMode>relativeToGround</altitudeMode>\n");
				 fprintf(pw, "			<outerBoundaryIs>\n");
				 fprintf(pw, "			<LinearRing>\n");
				 fprintf(pw, "					<coordinates>\n");
				 //int j = 0;


				 //BpcBaseflag = 1;
				 // B_x = Wgs84toTwd97X01; B_y = Wgs84toTwd97Y01 + 2; B_z = KML_BPCXYZ[s2].z;

				 double x0, y0, x1, y1, dis;
				 double MinH = 999999, MaxH = 0;
				 double avgH;
				 int count = 0;
				 double H;
				 int Checkcount = 0;
				 
				 avgH=GetavgH();

				 for (int g = i; g <= j; g++)
				 {
					 //count = 0;avgH = 0; 
					 //if (Kcount[KMLAll[g].Qflag].count <= 5)
					 {

						 for (int a = 0; a < (int)KML_BPCXYZTemp.size(); a++)
						 {
							 Cal_lonlat_To_twd97(KML_BPCXYZTemp[a].x, KML_BPCXYZTemp[a].y, 0);
							 x1 = Wgs84toTwd97X01; y1 = Wgs84toTwd97Y01 + 2;

						 }

						 fprintf(pw, "%lf,%lf,%lf ", KMLAll[g].x, KMLAll[g].y, avgH);

					 }
				 }
				 fprintf(pw, " \n");
				 //fprintf(pw, "%lf,%lf,%lf \n", KMLAll[i].x, KMLAll[i].y, H);
				 //fprintf(pw, "%lf,%lf,%lf ", KMLAll[i].x, KMLAll[i].y, KMLAll[i].z);


				 //fprintf(pw, "%lf,%lf,%lf\n", KML_list[j].x, KML_list[j].y, KML_list[j].z);
				 fprintf(pw, "					</coordinates>\n");
				 fprintf(pw, "			</LinearRing>\n");
				 fprintf(pw, "			</outerBoundaryIs>\n");
				 fprintf(pw, "			</Polygon>\n");
				 fprintf(pw, "		</Placemark>\n");
				 //=================印出KML

				 fprintf(pw, "	</Folder>\n");
				 fprintf(pw, "</Document>\n");
				 fprintf(pw, "</kml>\n");
				 fclose(pw);
			 }

			 double GetavgH()
			 {
				 double Maxh = 0, Mixh = 99999;
				 double avgH;

				 for (int w = 0; w < (int)KML_BPCXYZ.size(); w++)
				 {
					 if (Maxh < KML_BPCXYZ[w].z)Maxh = KML_BPCXYZ[w].z;
					 if (Mixh > KML_BPCXYZ[w].z)Mixh = KML_BPCXYZ[w].z;
				 }

				
				 double a01 = 0, a02 = 0, a03 = 0, a04 = 0, Havg = 0;
				 double a05 = 0, a06 = 0, a07 = 0, a08 = 0, a09 = 0, a010 = 0;
				 int a01c = 0, a02c = 0, a03c = 0, a04c = 0, a05c = 0;
				 int a06c = 0, a07c = 0, a08c = 0, a09c = 0, a010c = 0;
				 double a01H = 0, a02H = 0, a03H = 0, a04H = 0, a05H = 0;
				 double a06H = 0, a07H = 0, a08H = 0, a09H = 0, a010H = 0;
				 Havg = (Maxh - Mixh) / 10;

				 a01 = Mixh; a02 = Mixh + Havg; a03 = Mixh + Havg * 2; a04 = Mixh + Havg * 3;
				 a05 = Mixh + Havg * 4; a06 = Mixh + Havg * 5; a07 = Mixh + Havg * 6; a08 = Mixh + Havg *7;
				 a09 = Mixh + Havg * 8; a010 = Mixh + Havg * 9;
				 //
				 //for (int w = 0; w < (int)KML_BPCXYZ.size(); w++)
				 //{
					// if (KML_BPCXYZ[w].z >= a01  && KML_BPCXYZ[w].z < a02)					 {
					//	 a01c = a01c + 1;	a01H = a01H + KML_BPCXYZ[w].z;					 }
					// else if (KML_BPCXYZ[w].z >= a02  && KML_BPCXYZ[w].z < a03)					 {
					//	 a02c = a02c + 1;	a02H = a02H + KML_BPCXYZ[w].z;					 }
					// else if (KML_BPCXYZ[w].z >= a03  && KML_BPCXYZ[w].z < a04)					 {
					//	 a03c = a03c + 1;	a03H = a03H + KML_BPCXYZ[w].z;					 }
					// else if (KML_BPCXYZ[w].z >= a04  && KML_BPCXYZ[w].z <= a05)					 {
					//	 a04c = a04c + 1;	a04H = a04H + KML_BPCXYZ[w].z;					 }
					// else if (KML_BPCXYZ[w].z >= a05  && KML_BPCXYZ[w].z <= a06)					 {
					//	 a05c = a05c + 1;	a05H = a05H + KML_BPCXYZ[w].z;					 }
					// else if (KML_BPCXYZ[w].z >= a06  && KML_BPCXYZ[w].z <= a07)					 {
					//	 a06c = a06c + 1;	a06H = a06H + KML_BPCXYZ[w].z;					 }
					// else if (KML_BPCXYZ[w].z >= a07  && KML_BPCXYZ[w].z <= a08)					 {
					//	 a07c = a07c + 1;	a07H = a07H + KML_BPCXYZ[w].z;					 }
					// else if (KML_BPCXYZ[w].z >= a08  && KML_BPCXYZ[w].z <= a09)					 {
					//	 a08c = a08c + 1;	a08H = a08H + KML_BPCXYZ[w].z;					 }
					// else if (KML_BPCXYZ[w].z >= a09  && KML_BPCXYZ[w].z <= Maxh)					 {
					//	 a09c = a09c + 1;	a09H = a09H + KML_BPCXYZ[w].z;					 }
				 //}



				 //if (a01c >= a02c){
					// if (a01c >= a03c)
					//	 if (a01c >= a04c)
					//		 if (a01c >= a05c)
					//			 if (a01c >= a06c)
					//				 if (a01c >= a07c)
					//					 if (a01c >= a08c)
					//						 if (a01c >= a09c)
					//							 avgH = a01H / a01c;
				 //}else
				 //if (a02c >= a01c){
					// if (a02c >= a03c)
					//	 if (a02c >= a04c)
					//		 if (a02c >= a05c)
					//			 if (a02c >= a06c)
					//				 if (a02c >= a07c)
					//					 if (a02c >= a08c)
					//						 if (a02c >= a09c)
					//							 avgH = a02H / a02c;
				 //}
				 //else
				 //if (a03c >= a01c){
					// if (a03c >= a02c)
					//	 if (a03c >= a04c)
					//		 if (a03c >= a05c)
					//			 if (a03c >= a06c)
					//				 if (a03c >= a07c)
					//					 if (a03c >= a08c)
					//						 if (a03c >= a09c)
					//							 avgH = a03H / a03c;
				 //}
				 //else
				 //if (a04c >= a01c){
					// if (a04c >= a02c)
					//	 if (a04c >= a03c)
					//		 if (a04c >= a05c)
					//			 if (a04c >= a06c)
					//				 if (a04c >= a07c)
					//					 if (a04c >= a08c)
					//						 if (a04c >= a09c)
					//							 avgH = a04H / a04c;
				 //}
				 //else
				 //if (a05c >= a01c){
					// if (a05c >= a02c)
					//	 if (a05c >= a03c)
					//		 if (a05c >= a04c)
					//			 if (a05c >= a06c)
					//				 if (a05c >= a07c)
					//					 if (a05c >= a08c)
					//						 if (a05c >= a09c)
					//							 avgH = a05H / a05c;
				 //}
				 //else
				 //if (a05c >= a01c){
					// if (a05c >= a02c)
					//	 if (a05c >= a03c)
					//		 if (a05c >= a04c)
					//			 if (a05c >= a06c)
					//				 if (a05c >= a07c)
					//					 if (a05c >= a08c)
					//						 if (a05c >= a09c)
					//							 avgH = a05H / a05c;
				 //}
				 //else
				 //if (a06c >= a01c){
					// if (a06c >= a02c)
					//	 if (a06c >= a03c)
					//		 if (a06c >= a04c)
					//			 if (a06c >= a05c)
					//				 if (a06c >= a07c)
					//					 if (a06c >= a08c)
					//						 if (a06c >= a09c)
					//							 avgH = a06H / a06c;
				 //}
				 //else
				 //if (a07c >= a01c){
					// if (a07c >= a02c)
					//	 if (a07c >= a03c)
					//		 if (a07c >= a04c)
					//			 if (a07c >= a05c)
					//				 if (a07c >= a06c)
					//					 if (a07c >= a08c)
					//						 if (a07c >= a09c)
					//							 avgH = a07H / a07c;
				 //}
				 //else
				 //if (a08c >= a01c){
					// if (a08c >= a02c)
					//	 if (a08c >= a03c)
					//		 if (a08c >= a04c)
					//			 if (a08c >= a05c)
					//				 if (a08c >= a06c)
					//					 if (a08c >= a07c)
					//						 if (a08c >= a09c)
					//							 avgH = a08H / a08c;
				 //}
				 //else
				 //if (a09c >= a01c){
					// if (a09c >= a02c)
					//	 if (a09c >= a03c)
					//		 if (a09c >= a04c)
					//			 if (a09c >= a05c)
					//				 if (a09c >= a06c)
					//					 if (a09c >= a07c)
					//						 if (a09c >= a08c)
					//							 avgH = a09H / a09c;
				 //}



				 //if (a01c == a02c){ avgH = (a01H + a02H) / (a01c * 2); }				 
				 //else if (a01c == a03c){ avgH = (a01H + a03H) / (a01c * 2); }
				 //else if (a01c == a04c){ avgH = (a01H + a04H) / (a01c * 2); }
				 //else if (a01c == a05c){ avgH = (a01H + a05H) / (a01c * 2); }
				 //else if (a01c == a06c){ avgH = (a01H + a06H) / (a01c * 2); }
				 //else if (a01c == a07c){ avgH = (a01H + a07H) / (a01c * 2); }
				 //else if (a01c == a08c){ avgH = (a01H + a08H) / (a01c * 2); }
				 //else if (a01c == a09c){ avgH = (a01H + a09H) / (a01c * 2); }				 
				 //else if (a02c == a03c){ avgH = (a02H + a03H) / (a02c * 2); }
				 //else if (a02c == a04c){ avgH = (a02H + a04H) / (a02c * 2); }
				 //else if (a02c == a05c){ avgH = (a02H + a05H) / (a02c * 2); }
				 //else if (a02c == a06c){ avgH = (a02H + a06H) / (a02c * 2); }
				 //else if (a02c == a07c){ avgH = (a02H + a07H) / (a02c * 2); }
				 //else if (a02c == a08c){ avgH = (a02H + a08H) / (a02c * 2); }
				 //else if (a02c == a09c){ avgH = (a02H + a09H) / (a02c * 2); }
				 //else if (a03c == a04c){ avgH = (a03H + a04H) / (a03c * 2); }
				 //else if (a03c == a05c){ avgH = (a03H + a05H) / (a03c * 2); }
				 //else if (a03c == a06c){ avgH = (a03H + a06H) / (a03c * 2); }
				 //else if (a03c == a07c){ avgH = (a03H + a07H) / (a03c * 2); }
				 //else if (a03c == a08c){ avgH = (a03H + a08H) / (a03c * 2); }
				 //else if (a03c == a09c){ avgH = (a03H + a09H) / (a03c * 2); }				 
				 //else if (a04c == a05c){ avgH = (a04H + a05H) / (a04c * 2); }
				 //else if (a04c == a06c){ avgH = (a04H + a06H) / (a04c * 2); }
				 //else if (a04c == a07c){ avgH = (a04H + a07H) / (a04c * 2); }
				 //else if (a04c == a08c){ avgH = (a04H + a08H) / (a04c * 2); }
				 //else if (a04c == a09c){ avgH = (a04H + a09H) / (a04c * 2); }
				 //else if (a05c == a06c){ avgH = (a05H + a06H) / (a05c * 2); }
				 //else if (a05c == a07c){ avgH = (a05H + a07H) / (a05c * 2); }
				 //else if (a05c == a08c){ avgH = (a05H + a08H) / (a05c * 2); }
				 //else if (a05c == a09c){ avgH = (a05H + a09H) / (a05c * 2); }
				 //else if (a06c == a07c){ avgH = (a06H + a07H) / (a06c * 2); }
				 //else if (a06c == a08c){ avgH = (a06H + a08H) / (a06c * 2); }
				 //else if (a06c == a09c){ avgH = (a06H + a09H) / (a06c * 2); }
				 //else if (a07c == a08c){ avgH = (a07H + a08H) / (a07c * 2); }
				 //else if (a07c == a09c){ avgH = (a07H + a09H) / (a07c * 2); }
				 //else if (a08c == a09c){ avgH = (a08H + a09H) / (a08c * 2); }

			a01 = Mixh; a02 = Mixh + Havg; a03 = Mixh + Havg * 2; a04 = Mixh + Havg * 3;
			a05 = Mixh + Havg * 4; a06 = Mixh + Havg * 5; a07 = Mixh + Havg * 6; a08 = Mixh + Havg * 7;
			a09 = Mixh + Havg * 8; a010 = Mixh + Havg * 9;
				for (int w = 0; w < (int)KML_BPCXYZ.size(); w++)
				{
				 if (KML_BPCXYZ[w].z >= a01  && KML_BPCXYZ[w].z < a02)					 {
					 a01c = a01c + 1;	a01H = a01H + KML_BPCXYZ[w].z;					 }
				 else if (KML_BPCXYZ[w].z >= a02  && KML_BPCXYZ[w].z < a03)					 {
					 a02c = a02c + 1;	a02H = a02H + KML_BPCXYZ[w].z;					 }
				 else if (KML_BPCXYZ[w].z >= a03  && KML_BPCXYZ[w].z < a04)					 {
					 a03c = a03c + 1;	a03H = a03H + KML_BPCXYZ[w].z;					 }
				 else if (KML_BPCXYZ[w].z >= a04  && KML_BPCXYZ[w].z < a05)					 {
					 a04c = a04c + 1;	a04H = a04H + KML_BPCXYZ[w].z;					 }
				 else if (KML_BPCXYZ[w].z >= a05  && KML_BPCXYZ[w].z < a06)					 {
					 a05c = a05c + 1;	a05H = a05H + KML_BPCXYZ[w].z;					 }
				 else if (KML_BPCXYZ[w].z >= a06  && KML_BPCXYZ[w].z < a07)					 {
					 a06c = a06c + 1;	a06H = a06H + KML_BPCXYZ[w].z;					 }
				 else if (KML_BPCXYZ[w].z >= a07  && KML_BPCXYZ[w].z < a08)					 {
					 a07c = a07c + 1;	a07H = a07H + KML_BPCXYZ[w].z;					 }
				 else if (KML_BPCXYZ[w].z >= a08  && KML_BPCXYZ[w].z < a09)					 {
					 a08c = a08c + 1;	a08H = a08H + KML_BPCXYZ[w].z;					 }
				 else if (KML_BPCXYZ[w].z >= a09  && KML_BPCXYZ[w].z < a010)					 {
					 a09c = a09c + 1;	a09H = a09H + KML_BPCXYZ[w].z;					 }
				 else if (KML_BPCXYZ[w].z >= a09  && KML_BPCXYZ[w].z <= Maxh)					 {
					 a010c = a010c + 1;	a010H = a010H + KML_BPCXYZ[w].z;
				 }
				}
				//FILE *fp = fopen("aaa.txt", "w");
				//fprintf(fp, "%lf %lf \n", Mixh, Maxh);
				//fprintf(fp, "%d %lf \n%d %lf \n%d %lf \n%d %lf \n", a01c, a01H, a02c, a02H, a03c, a03H, a04c, a04H);
				//fprintf(fp, "%d %lf \n%d %lf \n%d %lf \n%d %lf \n", a05c, a05H, a06c, a06H, a07c, a07H, a08c, a08H);
				//fprintf(fp, "%d %lf \n%d %lf \n", a09c, a09H, a010c, a010H);
				//fclose(fp);
				if (a01c >= a02c){
				 if (a01c >= a03c)
					 if (a01c >= a04c)
						 if (a01c >= a05c)
							 if (a01c >= a06c)
								 if (a01c >= a07c)
									 if (a01c >= a08c)
										 if (a01c >= a09c)
											 if (a01c >= a010c)
												avgH = a01H / a01c;
				}
				if (a02c >= a01c){
				 if (a02c >= a03c)
					 if (a02c >= a04c)
						 if (a02c >= a05c)
							 if (a02c >= a06c)
								 if (a02c >= a07c)
									 if (a02c >= a08c)
										 if (a02c >= a09c)
											 if (a02c >= a010c)
											 avgH = a02H / a02c;
				}
				if (a03c >= a01c){
				 if (a03c >= a02c)
					 if (a03c >= a04c)
						 if (a03c >= a05c)
							 if (a03c >= a06c)
								 if (a03c >= a07c)
									 if (a03c >= a08c)
										 if (a03c >= a09c)
											 if (a03c >= a010c)
											 avgH = a03H / a03c;
				}
				if (a04c >= a01c){
				 if (a04c >= a02c)
					 if (a04c >= a03c)
						 if (a04c >= a05c)
							 if (a04c >= a06c)
								 if (a04c >= a07c)
									 if (a04c >= a08c)
										 if (a04c >= a09c)
											 if (a04c >= a010c)
											 avgH = a04H / a04c;
				}
				if (a05c >= a01c){
				 if (a05c >= a02c)
					 if (a05c >= a03c)
						 if (a05c >= a04c)
							 if (a05c >= a06c)
								 if (a05c >= a07c)
									 if (a05c >= a08c)
										 if (a05c >= a09c)
											 if (a05c >= a010c)
											 avgH = a05H / a05c;
				}
				if (a06c >= a01c){
				 if (a06c >= a02c)
					 if (a06c >= a03c)
						 if (a06c >= a04c)
							 if (a06c >= a05c)
								 if (a06c >= a07c)
									 if (a06c >= a08c)
										 if (a06c >= a09c)
											 if (a06c >= a010c)
											 avgH = a06H / a06c;
				}
				if (a07c >= a01c){
				 if (a07c >= a02c)
					 if (a07c >= a03c)
						 if (a07c >= a04c)
							 if (a07c >= a05c)
								 if (a07c >= a06c)
									 if (a07c >= a08c)
										 if (a07c >= a09c)
											 if (a07c >= a010c)
											 avgH = a07H / a07c;
				}
				if (a08c >= a01c){
				 if (a08c >= a02c)
					 if (a08c >= a03c)
						 if (a08c >= a04c)
							 if (a08c >= a05c)
								 if (a08c >= a06c)
									 if (a08c >= a07c)
										 if (a08c >= a09c)
											 if (a08c >= a010c)
											 avgH = a08H / a08c;
				}
				if (a09c >= a01c){
				 if (a09c >= a02c)
					 if (a09c >= a03c)
						 if (a09c >= a04c)
							 if (a09c >= a05c)
								 if (a09c >= a06c)
									 if (a09c >= a07c)
										 if (a09c >= a08c)
											 if (a09c >= a010c)
											 avgH = a09H / a09c;
				}
				if (a010c >= a01c){
					if (a010c >= a02c)
						if (a010c >= a03c)
							if (a010c >= a04c)
								if (a010c >= a05c)
									if (a010c >= a06c)
										if (a010c >= a07c)
											if (a010c >= a08c)
												if (a010c >= a09c)
													avgH = a010H / a010c;
				}



				//if (a01c == a02c){ avgH = (a01H + a02H) / (a01c * 2); }				 
				//else if (a01c == a03c){ avgH = (a01H + a03H) / (a01c * 2); }
				//else if (a01c == a04c){ avgH = (a01H + a04H) / (a01c * 2); }
				//else if (a01c == a05c){ avgH = (a01H + a05H) / (a01c * 2); }
				//else if (a01c == a06c){ avgH = (a01H + a06H) / (a01c * 2); }
				//else if (a01c == a07c){ avgH = (a01H + a07H) / (a01c * 2); }
				//else if (a01c == a08c){ avgH = (a01H + a08H) / (a01c * 2); }
				//else if (a01c == a09c){ avgH = (a01H + a09H) / (a01c * 2); }				 
				//else if (a02c == a03c){ avgH = (a02H + a03H) / (a02c * 2); }
				//else if (a02c == a04c){ avgH = (a02H + a04H) / (a02c * 2); }
				//else if (a02c == a05c){ avgH = (a02H + a05H) / (a02c * 2); }
				//else if (a02c == a06c){ avgH = (a02H + a06H) / (a02c * 2); }
				//else if (a02c == a07c){ avgH = (a02H + a07H) / (a02c * 2); }
				//else if (a02c == a08c){ avgH = (a02H + a08H) / (a02c * 2); }
				//else if (a02c == a09c){ avgH = (a02H + a09H) / (a02c * 2); }
				//else if (a03c == a04c){ avgH = (a03H + a04H) / (a03c * 2); }
				//else if (a03c == a05c){ avgH = (a03H + a05H) / (a03c * 2); }
				//else if (a03c == a06c){ avgH = (a03H + a06H) / (a03c * 2); }
				//else if (a03c == a07c){ avgH = (a03H + a07H) / (a03c * 2); }
				//else if (a03c == a08c){ avgH = (a03H + a08H) / (a03c * 2); }
				//else if (a03c == a09c){ avgH = (a03H + a09H) / (a03c * 2); }				 
				//else if (a04c == a05c){ avgH = (a04H + a05H) / (a04c * 2); }
				//else if (a04c == a06c){ avgH = (a04H + a06H) / (a04c * 2); }
				//else if (a04c == a07c){ avgH = (a04H + a07H) / (a04c * 2); }
				//else if (a04c == a08c){ avgH = (a04H + a08H) / (a04c * 2); }
				//else if (a04c == a09c){ avgH = (a04H + a09H) / (a04c * 2); }
				//else if (a05c == a06c){ avgH = (a05H + a06H) / (a05c * 2); }
				//else if (a05c == a07c){ avgH = (a05H + a07H) / (a05c * 2); }
				//else if (a05c == a08c){ avgH = (a05H + a08H) / (a05c * 2); }
				//else if (a05c == a09c){ avgH = (a05H + a09H) / (a05c * 2); }
				//else if (a06c == a07c){ avgH = (a06H + a07H) / (a06c * 2); }
				//else if (a06c == a08c){ avgH = (a06H + a08H) / (a06c * 2); }
				//else if (a06c == a09c){ avgH = (a06H + a09H) / (a06c * 2); }
				//else if (a07c == a08c){ avgH = (a07H + a08H) / (a07c * 2); }
				//else if (a07c == a09c){ avgH = (a07H + a09H) / (a07c * 2); }
				//else if (a08c == a09c){ avgH = (a08H + a09H) / (a08c * 2); }
				 return avgH;
			 }
			 /*
			 void ExportNewLOD1(char filename[256], int i, int j, char filename1[256], FILE *fg)
			 {
				 //KML_BPCXYZ//KMLAll
				 FILE *pw = fopen(filename, "w");

				 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
				 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
				 fprintf(pw, "<Document>\n");
				 fprintf(pw, "	<name>KML</name>\n");
				 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
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
				 fprintf(pw, "		<name>KML</name>\n");
				 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
				 fprintf(pw, "		<LookAt>\n");
				 fprintf(pw, "			<longitude>%lf</longitude>\n", KMLAll[i].x);
				 fprintf(pw, "			<latitude>%lf</latitude>\n", KMLAll[i].y);
				 fprintf(pw, "			<altitude>%lf</altitude>\n", KMLAll[i].z + 100);
				 fprintf(pw, "			<heading>80</heading>\n");
				 fprintf(pw, "			<tilt>45</tilt>\n");
				 fprintf(pw, "			<range>130</range>\n");
				 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
				 fprintf(pw, "		</LookAt>\n");
				 //ExportLOD1KML
				 //=================印出KML
				 fprintf(pw, "	<name>KML_%d</name>\n", i);
				 fprintf(pw, "		<Placemark id=\"ID\">\n");
				 fprintf(pw, "			<name>KML_ID%d</name>\n", i);
				 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
				 fprintf(pw, "			<Polygon>\n");
				 fprintf(pw, "			<extrude>1</extrude>\n");
				 fprintf(pw, "			<altitudeMode>relativeToGround</altitudeMode>\n");
				 fprintf(pw, "			<outerBoundaryIs>\n");
				 fprintf(pw, "			<LinearRing>\n");
				 fprintf(pw, "					<coordinates>\n");
				 //int j = 0;
				 
				 
					 //BpcBaseflag = 1;
					// B_x = Wgs84toTwd97X01; B_y = Wgs84toTwd97Y01 + 2; B_z = KML_BPCXYZ[s2].z;
				 FILE *fp = fopen(filename1, "w");
				 double x0, y0, x1, y1,dis;
				 double MinH = 999999,MaxH=0;
				 double avgH;
				 int count = 0;
				 double H;
				 for (int g = i; g <= j; g++)
				 {
					 avgH = 0; count = 0;
					 if (Kcount[KMLAll[g].Qflag].count <= 5)
					 {
						 Cal_lonlat_To_twd97(KMLAll[g].x, KMLAll[g].y, 0);
						 x0 = Wgs84toTwd97X01; y0 = Wgs84toTwd97Y01 + 2;
						 for (int a = 0; a < (int)KML_BPCXYZ.size(); a++)
						 {
							  Cal_lonlat_To_twd97(KML_BPCXYZ[a].x, KML_BPCXYZ[a].y, 0);
							  x1 = Wgs84toTwd97X01; y1 = Wgs84toTwd97Y01 + 2;
							  dis=sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
							  //fprintf(fp, "%d %lf\n", g,dis);
							  if (dis <= 0.5)
							  {
								  fprintf(fg, "%d %d %lf\n", g, a, KML_BPCXYZ[a].z);
						 		 avgH = avgH + KML_BPCXYZ[a].z;		count = count + 1;
							  }
						 }
						 avgH = avgH / count;
						 if (avgH > 0)
						 {
							 fprintf(pw, "%lf,%lf,%lf ", KMLAll[g].x, KMLAll[g].y, avgH);							 
						 }else
							 fprintf(pw, "%lf,%lf,%lf ", KMLAll[g].x, KMLAll[g].y, KMLAll[g].z);
							
					 }
					 else
					 {
						 fprintf(pw, "%lf,%lf,%lf ", KMLAll[g].x, KMLAll[g].y, KMLAll[g].z);
					 }
					 //fprintf(pw, "%lf,%lf,%lf ", KMLAll[g].x, KMLAll[g].y, KMLAll[g].z);
					 //Cal_lonlat_To_twd97(KMLAll[g].x, KMLAll[g].y, 0);
					 //x0 = Wgs84toTwd97X01; y0 = Wgs84toTwd97Y01+2;
					 //for (int a = 0; a < (int)KML_BPCXYZ.size(); a++)
					 //{
						// Cal_lonlat_To_twd97(KML_BPCXYZ[a].x, KML_BPCXYZ[a].y, 0);
						// x1 = Wgs84toTwd97X01; y1 = Wgs84toTwd97Y01 + 2;
						// dis=sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
						// //fprintf(fp, "%d %lf\n", g,dis);
						// if (dis <= 0.5)
						// {
						//	 avgH = avgH + KML_BPCXYZ[a].z;		count = count + 1;
						// }
					 //}
					 //avgH = avgH / count;
					 //if (g == i)  H = avgH;
					 //fprintf(pw, "%lf,%lf,%lf ", KMLAll[g].x, KMLAll[g].y, avgH);
					

				 }
				 fprintf(pw, " \n");
				 //fprintf(pw, "%lf,%lf,%lf \n", KMLAll[i].x, KMLAll[i].y, H);
				 //fprintf(pw, "%lf,%lf,%lf ", KMLAll[i].x, KMLAll[i].y, KMLAll[i].z);

				 fclose(fp);

				 //fprintf(pw, "%lf,%lf,%lf\n", KML_list[j].x, KML_list[j].y, KML_list[j].z);
				 fprintf(pw, "					</coordinates>\n");
				 fprintf(pw, "			</LinearRing>\n");
				 fprintf(pw, "			</outerBoundaryIs>\n");
				 fprintf(pw, "			</Polygon>\n");
				 fprintf(pw, "		</Placemark>\n");
				 //=================印出KML

				 fprintf(pw, "	</Folder>\n");
				 fprintf(pw, "</Document>\n");
				 fprintf(pw, "</kml>\n");




				 fclose(pw);
			 }
			 */



			 void ExportBPCtoKML(char name[512], FILE *pw)
			 {

				 pw = fopen(name, "w");

				 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
				 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
				 fprintf(pw, "<Document>\n");
				 fprintf(pw, "	<name>KML</name>\n");
				 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
				 fprintf(pw, "		<LabelStyle>\n");
				 fprintf(pw, "			<color>00000000</color>\n");
				 fprintf(pw, "			<scale>0</scale>\n");
				 fprintf(pw, "		</LabelStyle>\n");
				 fprintf(pw, "		<LineStyle>\n");
				 fprintf(pw, "			<color>ff6e6e6e</color>\n");
				 fprintf(pw, "			<width>0.4</width>\n");
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
				 fprintf(pw, "		<LabelStyle>\n");
				 fprintf(pw, "			<color>00000000</color>\n");
				 fprintf(pw, "			<scale>0</scale>\n");
				 fprintf(pw, "		</LabelStyle>\n");
				 fprintf(pw, "		<LineStyle>\n");
				 fprintf(pw, "			<color>ff6e6e6e</color>\n");
				 fprintf(pw, "			<width>0.4</width>\n");
				 fprintf(pw, "		</LineStyle>\n");
				 fprintf(pw, "		<PolyStyle>\n");
				 fprintf(pw, "			<color>fff7c6e9</color>\n");
				 fprintf(pw, "		</PolyStyle>\n");
				 fprintf(pw, "	</Style>\n");
				 fprintf(pw, "	<Folder id=\"KML\">\n");
				 fprintf(pw, "		<name>KML</name>\n");
				 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
				 fprintf(pw, "		<LookAt>\n");
				 fprintf(pw, "			<longitude>%lf</longitude>\n", KML_BPCXYZ[0].x);
				 fprintf(pw, "			<latitude>%lf</latitude>\n", KML_BPCXYZ[0].y);
				 fprintf(pw, "			<altitude>%lf</altitude>\n", KML_BPCXYZ[0].z);
				 fprintf(pw, "			<heading>10</heading>\n");
				 fprintf(pw, "			<tilt>45</tilt>\n");
				 fprintf(pw, "			<range>130</range>\n");
				 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>");
				 fprintf(pw, "		</LookAt>\n");


				 for (int i = 0; i < (int)KML_BPCXYZ.size(); i = i + 1)
					 //for (int i = 0; i < 10; i++)
				 {
					 //int d = i %100 ;
					 //if (d == 0)
					 {
						 fprintf(pw, "		<Placemark id=\"ID_%d\">\n", i);
						 fprintf(pw, "			<name>ID_%d</name>\n", i);
						 fprintf(pw, "			<description>\n");
						 fprintf(pw, "			1\n");
						 fprintf(pw, "			</description>\n");
						 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
						 fprintf(pw, "			<Point>\n");
						 fprintf(pw, "					<altitudeMode>relativeToGround</altitudeMode>\n");
						 fprintf(pw, "							<coordinates>\n");
						 fprintf(pw, "								%lf,%lf,%lf \n",
							 KML_BPCXYZ[i].x, KML_BPCXYZ[i].y, KML_BPCXYZ[i].z
							 );
						 fprintf(pw, "							</coordinates>\n");
						 fprintf(pw, "			</Point>\n");
						 fprintf(pw, "		</Placemark>\n");
					 }
				 }


				 fprintf(pw, "	</Folder>\n");
				 fprintf(pw, "</Document>\n");
				 fprintf(pw, "</kml>\n");

				 fclose(pw);


			 }







		
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.txt)|*.TXT";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		GRDxyz.clear();


		char *filename = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		char *name = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));

		LoadGrd(filename, name);

		//FILE *fp = fopen("a03.txt", "w");
		//for (int i = 0; i < GRDxyz.size(); i++)
		//{
		//	fprintf(fp, "%lf %lf %lf\n", GRDxyz[i].x, GRDxyz[i].y, GRDxyz[i].z);
		//}
		//
		//fclose(fp);
		MessageBox::Show("LOAD完成");
	}
}

		 void LoadGrd(char *filename, char *name)
		 {
			 FILE *fp = fopen(filename,"r");
			 
			 double f97ENHto84X, f97ENHto84Y, f97ENHto84Z;
			 char buf[128]={'\0'};
			 char bufa[512] = { '\0' };
			 char bufb[512] = { '\0' };
			 char file[256];
			 strcpy(file, name);
			 strcat(file,"\\");
			 int i = 0, j = 1;
			 while (fgets(buf, 128, fp) != NULL) {
				 //GRDtemp; GRDxyz
				 sscanf(buf, "%s", bufa);
				 strcpy(bufb, file);
				 strcat(bufb, bufa);
				 FILE *fpsa = fopen(filename, "r");

				 //fprintf(fpsa, "%s\n", bufb);
				 
				 while (fgets(bufa, 512, fpsa) != NULL) {
					 sscanf(bufa, "%lf %lf %lf", &GRDtemp.x, &GRDtemp.y, &GRDtemp.z);
					 
					//TWD97ENH_WGS84XYZ('T', GRDtemp.x, GRDtemp.y, GRDtemp.z, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				    //GRDtemp.x = XYZ97to84_x; GRDtemp.y = XYZ97to84_y;

					 GRDtemp.id = i; GRDtemp.M = j;
					 i = i + 1;
					 GRDxyz.push_back(GRDtemp);
				 }
				 j = j + 1;
				 fclose(fpsa);
				 fclose(fp);
		 }
		 }

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.kml)|*.kml";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{

		Filename01 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		Readbpcfile = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));
		
		strcat(Readbpcfile, "\\");

		
		TXYZ.clear();
		KMLAll.clear();
		KML_GrdXYZ.clear();

		//正常讀取全區LOD1 (KML)
		LoadLod1a(Filename01);
		
		//FILE *a = fopen("a0aaa.txt", "w");
		//for (int i = 0; i < (int)KMLAll.size(); i++)
		//{
		//	fprintf(a, "%lf %lf %lf\n", KMLAll[i].x, KMLAll[i].y, KMLAll[i].z);
		//}
		//fclose(a);
		//FILE *b = fopen("a0bbb.txt", "w");
		//for (int i = 0; i < (int)Grdtxyz.size(); i++)
		//{

		//		fprintf(b, "%d %d %d %s", i, Grdtxyz[i].i,Grdtxyz[i].Fid, Grdtxyz[i].xyz);

		//}
		//fclose(b);
		//Grdtxyz
		MessageBox::Show("LOAD完成");
	}
}

		 //正常讀取全區LOD1 (KML)
		 void LoadLod1a(char filename[512])
		 {

			 char buf[25000] = { '\0' };
			 //FILE *fkml = fopen(filename, "r");
			 FILE *fkml;
			 err = fopen_s(&fkml, filename, "r");

			// char Build_NO[80] = "<td>FID</td>";
			 char Build_NO[80] = "FID";
			 char check_coordinates[80] = "<coordinates>";
			 char check_coordinates2[80] = "<outerBoundaryIs>";
			 char check_coordinates3[80] = "<innerBoundaryIs>";
			 char check_coordinates4[80] = "<LinearRing>";
			 
			 char *locNO = { '\0' };
			 char *loc = { '\0' };
			 char *locInner = { '\0' };
			 char *locInner2 = { '\0' };
			 char num = {'1'};

			 int Qflag = 0;
			 int Kcount = 0;
			 int KMLTemp_count = 0;
			 int ta = 0;
			 int a = 0;
			 int i = 0;
			 
			 //int NumId = 0;
			 while (fgets(buf, 25000, fkml) != NULL) {

				 //字串搜尋 比對
				 /*locNO = strstr(buf, Build_NO);
				 if (locNO != NULL)
				 {
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 strcpy(getIDtemp.name, buf);
					 sscanf(buf, "<td>%d</td>", &getIDtemp.NO);
					 //GetID getIDtemp;
					 KML_ID.push_back(getIDtemp);
				 }*/

				 //字串搜尋 比對
				 loc = strstr(buf, check_coordinates2);
				 if (loc != NULL)
				 {
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 //清空空白
					 string *tmpStr = new string(buf);
					 tmpStr->erase(tmpStr->begin(), tmpStr->begin() + tmpStr->find_first_not_of("								"));
					 //strcpy(buf, tmpStr->c_str());
					 strcpy_s(buf, sizeof(buf) / sizeof(buf[0]), tmpStr->c_str());

					 //std::printf("%s\n", buf);
					 //strcat(Build_NO, num);
					 strcpy(getIDtemp.name, Build_NO);
					 getIDtemp.NO = i;
					 KML_ID.push_back(getIDtemp);
					 Kcount = AnalysisKMLxyz(buf, getIDtemp.NO);
					 i=i+1;
					 //KMLTemp_count = KMLTemp_count + 1;
					 Qflag = Qflag + 1;
					 ta = ta + 1;
				 }

				 //字串搜尋 比對
				 locInner = strstr(buf, check_coordinates3);
				 if (locInner != NULL)
				 {
					 
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 //清空空白
					 string *tmpStr = new string(buf);
					 tmpStr->erase(tmpStr->begin(), tmpStr->begin() + tmpStr->find_first_not_of("								"));
					 //strcpy(buf, tmpStr->c_str());
					 strcpy_s(buf, sizeof(buf) / sizeof(buf[0]), tmpStr->c_str());
					 Kcount = AnalysisKMLxyzA(buf, getIDtemp.NO);
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);

					 locInner2 = strstr(buf, check_coordinates4);
					 while (locInner2 != NULL)
					 {
						 fgets(buf, 25000, fkml);
						 fgets(buf, 25000, fkml);
						 //清空空白
						 string *tmpStr = new string(buf);
						 tmpStr->erase(tmpStr->begin(), tmpStr->begin() + tmpStr->find_first_not_of("								"));
						 //strcpy(buf, tmpStr->c_str());
						 strcpy_s(buf, sizeof(buf) / sizeof(buf[0]), tmpStr->c_str());
						 //Kcount = AnalysisKMLxyzA(buf, getIDtemp.NO);
						 
						 fgets(buf, 25000, fkml);
						 fgets(buf, 25000, fkml);
						 locInner2 = strstr(buf, check_coordinates4);
					 }

					
				 }
				 
			 }

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
								 //KMLAll.push_back(TKMLtemp);


							 }
						 }
					 }

				 }

			 }

			 return j;

		 }

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

	int StartId = 0;
	int EndId = 0;
	
	if (KMLAll.size() > 0 && GRDxyz.size() > 0)
	{
		char *StartID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox3->Text)));
		int SiD = atoi(StartID);
		char *EndID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox4->Text)));
		int EiD = atoi(EndID);

		char name2[64]; //itoa(KMLAll[i].Qflag, name2, 10);
		char bpcpath[128] = { '\0' };
		char KMLpath[128] = { '\0' };
		char KMLpointpath[128] = { '\0' };
		char KMLname[512];
		FILE *pw;
		
		//FILE *ga = fopen("G:\\程式區備份\\2017_change3 - 0 -data\\data\\DSM_grd\\a.grd", "w");
		//FILE *fp;
		for (int i = 0; i < (int)KMLAll.size()-1; i++)
		{
			KML_BPCXYZ.clear();
			//當處理到同一個Qflg的最後一筆時,開始進行作業
			
			if (KMLAll[i].Qflag != KMLAll[i + 1].Qflag)
			{
				EndId = i;
				
				if (Iinnerbounding(KMLAll[i].Qflag))
				{ 
				if (KMLAll[i].Qflag > 0 && (SiD <= KMLAll[i].Qflag  &&  EiD >= KMLAll[i].Qflag))
				{
					PointA p;
					for (int s1 = 0; s1 < (int)GRDxyz.size(); s1++)
					{
						p.x = GRDxyz[s1].x; p.y = GRDxyz[s1].y;
						if (PointinPolygonGrdA(p, StartId, i))
						{
							TKMLtemp.x = GRDxyz[s1].x; TKMLtemp.y = GRDxyz[s1].y; TKMLtemp.z = GRDxyz[s1].z;
							TKMLtemp.Id = GRDxyz[s1].id;
							KML_BPCXYZ.push_back(TKMLtemp);
							//fprintf(ga, "%lf %lf %lf\n", GRDxyz[s1].x, GRDxyz[s1].y, GRDxyz[s1].z);
						}
					 }
				   }
				}
				
				else if (KMLAll[i].Qflag > 0 && (SiD <= KMLAll[i].Qflag  &&  EiD >= KMLAll[i].Qflag))
				{
					PointA p;
					for (int s1 = 0; s1 < (int)GRDxyz.size(); s1++)
					{
						p.x = GRDxyz[s1].x; p.y = GRDxyz[s1].y;
						if (PointinPolygonGrd(p, StartId, i))
						{
							TKMLtemp.x = GRDxyz[s1].x; TKMLtemp.y = GRDxyz[s1].y; TKMLtemp.z = GRDxyz[s1].z;
							TKMLtemp.Id = GRDxyz[s1].id;
							KML_BPCXYZ.push_back(TKMLtemp);
							//fprintf(ga, "%lf %lf %lf\n", GRDxyz[s1].x, GRDxyz[s1].y, GRDxyz[s1].z);
						}
					 }
				   }
				
				//

				//////KML_BPCXYZ//KMLpoint
				//////判斷資料夾或檔案是否存在access//不存在就建一個mkdir
				//
				if ((SiD <= KMLAll[i].Qflag  &&  EiD >= KMLAll[i].Qflag))
				{
					itoa(KML_ID[KMLAll[i].Qflag].NO, name2, 10);

					strcpy(bpcpath, Readbpcfile);
					strcat(bpcpath, "result\\");					
					if (access(bpcpath, 0))
					{
						mkdir(bpcpath);
					}
					
					strcpy(KMLpath, bpcpath);
					strcpy(KMLpointpath, bpcpath);
					strcat(KMLpath, "KML_");
					strcat(KMLpointpath, "KMLpoint_");
					strcat(KMLpath, name2);
					strcat(KMLpointpath, name2);
					strcpy(ShowIDxyz, bpcpath);
					strcat(ShowIDxyz, "NO_");
					strcat(ShowIDxyz, name2);
					strcat(ShowIDxyz, ".txt");
					strcat(KMLpath, ".kml");
					strcat(KMLpointpath, ".kml");

					strcat(bpcpath, "PC_");
					strcat(bpcpath, name2);
					//strcat(bpcpath, "\\");
					//if (access(bpcpath, 0))
					//{
					//	mkdir(bpcpath);
					//}
					//strcat(bpcpath, name2);


					strcpy(KMLname, bpcpath);
					strcat(KMLname, ".kml");
					strcat(bpcpath, ".txt");

					//fp = fopen(bpcpath, "w");
					//for (int i = 0; i < (int)KML_BPCXYZ.size(); i++)
					//{
					//	fprintf(fp, "%lf %lf %lf\n", KML_BPCXYZ[i].x, KML_BPCXYZ[i].y, KML_BPCXYZ[i].z);
					//}
					//fclose(fp);

					if ((int)KML_BPCXYZ.size() >0)
					{
						ExportBPCtoKMLa(KMLname, pw, name2);
						ExportGRDLOD1_T01(KMLpath, StartId,i,name2);
						ExportGRDLOD1point_T01(KMLpointpath, StartId, i, name2);
						//KMLpath
						//fclose(pw);
					}
				}
				StartId = i + 1;
			}
		}
		//PointA p;
		//for (int s1 = 0; s1 < (int)GRDxyz.size(); s1++)
		//{		

		//	p.x = GRDxyz[s1].x; p.y = GRDxyz[s1].y;
		//	
		//	if (PointinPolygonGrd(p, StartId, (int)KMLAll.size()))
		//	{
		//		TKMLtemp.x = GRDxyz[s1].x; TKMLtemp.y = GRDxyz[s1].y; TKMLtemp.z = GRDxyz[s1].z;
		//		TKMLtemp.Id = GRDxyz[s1].id;
		//		KML_BPCXYZ.push_back(TKMLtemp);
		//	}
		//}

		//

		//
		//for (int a01 = 0; a01 < KML_BPCXYZ.size(); a01++)
		//{
		//	fprintf(ga, "%lf %lf %lf\n", KML_BPCXYZ[a01].x, KML_BPCXYZ[a01].y, KML_BPCXYZ[a01].z);
		//}
		//fclose(ga);

		MessageBox::Show("完成");
	}else
		MessageBox::Show("資料不全");

}

bool Iinnerbounding(int q) {
bool no = false;
  for (int i = 0; i < (int)KML_GrdXYZ.size() - 1; i++)
	if (q == KML_GrdXYZ[i].Qflag)
	{ 
		no = !no;
	}
return no;
}

bool PointinPolygonGrdA(PointA p, int i, int Kcount) {
int j = 0;
int k = 0;
int EndId = 0;
int n = 0;
bool inside = false;
for (j = Kcount - 1; i < Kcount; j = i++)
{
if (((KMLAll[i].y > p.y) != (KMLAll[j].y > p.y)) && (p.x < (KMLAll[j].x - KMLAll[i].x) * (p.y - KMLAll[i].y) / (KMLAll[j].y - KMLAll[i].y) + KMLAll[i].x)) inside = !inside;
}
if (inside) 
{ 
	for (int i = 0; i < (int)KML_GrdXYZ.size() - 1; i++)
	{
		if (KML_GrdXYZ[i].Qflag != KML_GrdXYZ[i + 1].Qflag)
		{
			EndId = i;
for (k = EndId - 1; n < EndId; k = n++)
{
if (((KML_GrdXYZ[n].y > p.y) != (KML_GrdXYZ[k].y > p.y)) && (p.x < (KML_GrdXYZ[k].x - KML_GrdXYZ[n].x) * (p.y - KML_GrdXYZ[n].y) / (KML_GrdXYZ[k].y - KML_GrdXYZ[n].y) + KML_GrdXYZ[n].x));
else inside = !inside;
}
n = i + 1;
}
}
}
return inside;
}
     
		 bool PointinPolygonGrd(PointA p, int i, int Kcount) {
			 int j = 0;
			 bool inside = false;
			 for (j = Kcount - 1; i < Kcount; j = i++)
			 {
				 if (((KMLAll[i].y > p.y) != (KMLAll[j].y > p.y)) && (p.x < (KMLAll[j].x - KMLAll[i].x) * (p.y - KMLAll[i].y) / (KMLAll[j].y - KMLAll[i].y) + KMLAll[i].x)) inside = !inside;
			 }
			 return inside;
		 }
	 
		 void ExportBPCtoKMLa(char name[512], FILE *pw, char name2[64])
		 {
			 pw = fopen(name, "w");

			 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
			 fprintf(pw, "<Document>\n");
			 fprintf(pw, "	<name>KML_%s</name>\n", name2);
			 fprintf(pw, "	<Style id=\"PolyStyle000\">\n");
			 fprintf(pw, "		<IconStyle>\n");			 
			 fprintf(pw, "			<scale>0.5</scale>\n");
			 fprintf(pw, "			<Icon>\n");
			 fprintf(pw, "				<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
			 fprintf(pw, "			</Icon>\n");
			 fprintf(pw, "		</IconStyle>\n");
			 fprintf(pw, "		<LabelStyle>\n");
			 fprintf(pw, "			<color>00000000</color>\n");
			 fprintf(pw, "			<scale>0</scale>\n");
			 fprintf(pw, "		</LabelStyle>\n");
			 fprintf(pw, "		<ListStyle>\n");
			 fprintf(pw, "		</ListStyle>\n");
			 fprintf(pw, "		<LineStyle>\n");
			 fprintf(pw, "			<color>ff6e6e6e</color>\n");
			 fprintf(pw, "			<width>0.4</width>\n");
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

			 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
			 fprintf(pw, "		<IconStyle>\n");
			 fprintf(pw, "			<scale>0.5</scale>\n");
			 fprintf(pw, "			<Icon>\n");
			 fprintf(pw, "				<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
			 fprintf(pw, "			</Icon>\n");
			 fprintf(pw, "		</IconStyle>\n");
			 fprintf(pw, "		<LabelStyle>\n");
			 fprintf(pw, "			<color>00000000</color>\n");
			 fprintf(pw, "			<scale>0</scale>\n");
			 fprintf(pw, "		</LabelStyle>\n");
			 fprintf(pw, "		<ListStyle>\n");
			 fprintf(pw, "		</ListStyle>\n");
			 fprintf(pw, "		<LineStyle>\n");
			 fprintf(pw, "			<color>ff6e6e6e</color>\n");
			 fprintf(pw, "			<width>0.4</width>\n");
			 fprintf(pw, "		</LineStyle>\n");
			 fprintf(pw, "		<PolyStyle>\n");
			 fprintf(pw, "			<color>fff7c6e9</color>\n");
			 fprintf(pw, "		</PolyStyle>\n");
			 fprintf(pw, "	</Style>\n");


			 fprintf(pw, "	<Folder id=\"KML_%s\">\n", name2);
			 fprintf(pw, "		<name>KML_%s</name>\n", name2);
			 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
			 fprintf(pw, "		<LookAt>\n");
			 fprintf(pw, "			<longitude>%lf</longitude>\n", KML_BPCXYZ[0].x);
			 fprintf(pw, "			<latitude>%lf</latitude>\n", KML_BPCXYZ[0].y);
			 fprintf(pw, "			<altitude>%lf</altitude>\n", KML_BPCXYZ[0].z);
			 fprintf(pw, "			<heading>10</heading>\n");
			 fprintf(pw, "			<tilt>45</tilt>\n");
			 fprintf(pw, "			<range>130</range>\n");
			 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>");
			 fprintf(pw, "		</LookAt>\n");


			 for (int i = 0; i < (int)KML_BPCXYZ.size(); i = i + 1)
				 //for (int i = 0; i < 10; i++)
			 {
				 
				 {
					 fprintf(pw, "		<Placemark id=\"ID_%s\">\n", name2);
					 //fprintf(pw, "			<name>ID_%s</name>\n", name2);
					 //fprintf(pw, "			<description>\n%s\n", name2);

					 fprintf(pw, "			<description><![CDATA[<html xmlns:fo=\"http://www.w3.org/1999/XSL/Format\" xmlns:msxsl=\"urn:schemas-microsoft-com:xslt\">\n");
					 fprintf(pw, "			<head>");
					 fprintf(pw, "			<META http-equiv=\"Content - Type\" content=\"text / html\">");
					 fprintf(pw, "			<meta http-equiv=\"content - type\" content=\"text / html; charset = UTF - 8\">");
					 fprintf(pw, "			</head>\n");
					 fprintf(pw, "			<body style=\"margin:0px 0px 0px 0px; overflow:auto; background:#FFFFFF; \">\n");
					 fprintf(pw, "			<td>FID</td>\n\n");
					 fprintf(pw, "			<td>%s</td>\n", name2);					 
					 fprintf(pw, "			%lf %lf %lf\n", KML_BPCXYZ[i].x, KML_BPCXYZ[i].y, KML_BPCXYZ[i].z);
					 fprintf(pw, "			</html>]]></description>\n");
					 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
					 fprintf(pw, "			<Point>\n");
					 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
					 fprintf(pw, "							<coordinates>\n");
					 fprintf(pw, "								%lf,%lf,%lf \n",
						 KML_BPCXYZ[i].x, KML_BPCXYZ[i].y, KML_BPCXYZ[i].z
						 );
					 fprintf(pw, "							</coordinates>\n");
					 fprintf(pw, "			</Point>\n");
					 fprintf(pw, "		</Placemark>\n");
				 }
			 }


			 fprintf(pw, "	</Folder>\n");
			 fprintf(pw, "</Document>\n");
			 fprintf(pw, "</kml>\n");

			 fclose(pw);

			 //pw = fopen(name, "w");

			 //fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			 //fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
			 //fprintf(pw, "<Document>\n");
			 //fprintf(pw, "	<name>KML</name>\n");
			 //fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
			 //fprintf(pw, "		<LabelStyle>\n");
			 //fprintf(pw, "			<color>00000000</color>\n");
			 //fprintf(pw, "			<scale>0</scale>\n");
			 //fprintf(pw, "		</LabelStyle>\n");
			 //fprintf(pw, "		<LineStyle>\n");
			 //fprintf(pw, "			<color>ff6e6e6e</color>\n");
			 //fprintf(pw, "			<width>0.4</width>\n");
			 //fprintf(pw, "		</LineStyle>\n");
			 //fprintf(pw, "		<PolyStyle>\n");
			 //fprintf(pw, "			<color>fff7c6e9</color>\n");
			 //fprintf(pw, "		</PolyStyle>\n");
			 //fprintf(pw, "	</Style>\n");
			 //fprintf(pw, "	<StyleMap id=\"PolyStyle001\">\n");
			 //fprintf(pw, "		<Pair>\n");
			 //fprintf(pw, "			<key>normal</key>\n");
			 //fprintf(pw, "			<styleUrl>#PolyStyle000</styleUrl>\n");
			 //fprintf(pw, "		</Pair>\n");
			 //fprintf(pw, "		<Pair>\n");
			 //fprintf(pw, "			<key>highlight</key>\n");
			 //fprintf(pw, "			<styleUrl>#PolyStyle00</styleUrl>\n");
			 //fprintf(pw, "		</Pair>\n");
			 //fprintf(pw, "	</StyleMap>\n");
			 //fprintf(pw, "	<Style id=\"PolyStyle000\">\n");
			 //fprintf(pw, "		<LabelStyle>\n");
			 //fprintf(pw, "			<color>00000000</color>\n");
			 //fprintf(pw, "			<scale>0</scale>\n");
			 //fprintf(pw, "		</LabelStyle>\n");
			 //fprintf(pw, "		<LineStyle>\n");
			 //fprintf(pw, "			<color>ff6e6e6e</color>\n");
			 //fprintf(pw, "			<width>0.4</width>\n");
			 //fprintf(pw, "		</LineStyle>\n");
			 //fprintf(pw, "		<PolyStyle>\n");
			 //fprintf(pw, "			<color>fff7c6e9</color>\n");
			 //fprintf(pw, "		</PolyStyle>\n");
			 //fprintf(pw, "	</Style>\n");
			 //fprintf(pw, "	<Folder id=\"KML\">\n");
			 //fprintf(pw, "		<name>KML</name>\n");
			 ////fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
			 //fprintf(pw, "		<LookAt>\n");
			 //fprintf(pw, "			<longitude>%lf</longitude>\n", KML_BPCXYZ[0].x);
			 //fprintf(pw, "			<latitude>%lf</latitude>\n", KML_BPCXYZ[0].y);
			 //fprintf(pw, "			<altitude>%lf</altitude>\n", KML_BPCXYZ[0].z);
			 //fprintf(pw, "			<heading>10</heading>\n");
			 //fprintf(pw, "			<tilt>45</tilt>\n");
			 //fprintf(pw, "			<range>130</range>\n");
			 //fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>");
			 //fprintf(pw, "		</LookAt>\n");


			 //for (int i = 0; i < (int)KML_BPCXYZ.size(); i = i + 1)
				// //for (int i = 0; i < 10; i++)
			 //{
				// //int d = i %100 ;
				// //if (d == 0)
				// {
				//	 fprintf(pw, "		<Placemark id=\"ID_%d\">\n", i);
				//	 fprintf(pw, "			<name>ID_%d</name>\n", i);
				//	 fprintf(pw, "			<description>\n");
				//	 fprintf(pw, "			1\n");
				//	 fprintf(pw, "			</description>\n");
				//	 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
				//	 fprintf(pw, "			<Point>\n");
				//	 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
				//	 fprintf(pw, "							<coordinates>\n");
				//	 fprintf(pw, "								%lf,%lf,%lf \n",
				//		 KML_BPCXYZ[i].x, KML_BPCXYZ[i].y, KML_BPCXYZ[i].z
				//		 );
				//	 fprintf(pw, "							</coordinates>\n");
				//	 fprintf(pw, "			</Point>\n");
				//	 fprintf(pw, "		</Placemark>\n");
				// }
			 //}


			 //fprintf(pw, "	</Folder>\n");
			 //fprintf(pw, "</Document>\n");
			 //fprintf(pw, "</kml>\n");

			 //fclose(pw);


		 }

		 void ExportGRDLOD1_T01(char filename[256], int i, int j, char filename2[256])
		 {
			 KML_BPCXYZTemp.clear();
			 //KML_BPCXYZ//KMLAll
			 FILE *pw = fopen(filename, "w");

			 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
			 fprintf(pw, "<Document>\n");
			 fprintf(pw, "	<name>KML_%s</name>\n", filename2);
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
			 fprintf(pw, "		<name>KML_%s</name>\n", filename2);
			 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
			 fprintf(pw, "		<LookAt>\n");
			 fprintf(pw, "			<longitude>%lf</longitude>\n", KMLAll[i].x);
			 fprintf(pw, "			<latitude>%lf</latitude>\n", KMLAll[i].y);
			 fprintf(pw, "			<altitude>%lf</altitude>\n", KMLAll[i].z + 100);
			 fprintf(pw, "			<heading>80</heading>\n");
			 fprintf(pw, "			<tilt>45</tilt>\n");
			 fprintf(pw, "			<range>130</range>\n");
			 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
			 fprintf(pw, "		</LookAt>\n");
			 //ExportLOD1KML
			 
			 
			 //=================印出KML
			 fprintf(pw, "	<name>KML_%s</name>\n", filename2);
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
			 fprintf(pw, "			<td>%s</td>\n", filename2);
			 fprintf(pw, "			</html>]]></description>\n");

			 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
			 fprintf(pw, "			<MultiGeometry>\n");			 
			 fprintf(pw, "			<Polygon>\n");
			 fprintf(pw, "			<extrude>1</extrude>\n");
			 fprintf(pw, "			<altitudeMode>absolute</altitudeMode>\n");
			 fprintf(pw, "			<outerBoundaryIs>\n");
			 fprintf(pw, "			<LinearRing>\n");
			 fprintf(pw, "					<coordinates>\n");
			 //int j = 0;


			 //BpcBaseflag = 1;
			 // B_x = Wgs84toTwd97X01; B_y = Wgs84toTwd97Y01 + 2; B_z = KML_BPCXYZ[s2].z;

			 double x0, y0, x1, y1, dis;
			 double MinH = 999999, MaxH = 0;
			 double avgH;
			 int count = 0;
			 double H;
			 int Checkcount = 0;

			 avgH = GetavgH();

			 for (int g = i; g <= j; g++)
			 {
				fprintf(pw, "%lf,%lf,%lf ", KMLAll[g].x, KMLAll[g].y, avgH);			 
			 }
			 fprintf(pw, " \n");

			 fprintf(pw, "					</coordinates>\n");
			 fprintf(pw, "			</LinearRing>\n");
			 fprintf(pw, "			</outerBoundaryIs>\n");
			 //KML_GrdXYZ
			 for (int k = 0; k < KML_GrdXYZ.size(); k++)
			 {
				 if (KML_ID[KMLAll[j].Qflag].NO == KML_GrdXYZ[k].Qflag)
				 {
					 if (Checkcount == 0)
					 {
						 fprintf(pw, "			<innerBoundaryIs>\n");
						 fprintf(pw, "			<LinearRing>\n");
						 fprintf(pw, "					<coordinates>\n");
						 Checkcount = 1;
					 }
					
					 fprintf(pw, "%lf,%lf,%lf ", KML_GrdXYZ[k].x, KML_GrdXYZ[k].y, avgH);
					
				 }
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
			 //=================印出KML



			 /*
			 //=================印出KML
			 MinH = 999999; MaxH = 0;	
			 count = 0;
			 Checkcount = 0;		
			 avgH = GetavgH();

			 fprintf(pw, "	<name>KML_%s</name>\n", filename2);	 
			
			 FILE *hp = fopen(ShowIDxyz, "w");
			 int Hid = 0;
			 for (int g = i; g < j; g++)
			 {
				 fprintf(pw, "		<Placemark id=\"ID\">\n");
				 fprintf(pw, "			<description>NO:%d\n", Hid);
				 fprintf(pw, "			%lf %lf %lf\n", KMLAll[g].x, KMLAll[g].y, avgH);
				 fprintf(pw, "			</description>\n");
				 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
				 fprintf(pw, "			<Point>\n");
				 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
				 fprintf(pw, "							<coordinates>\n");
				 fprintf(pw, "%lf,%lf,%lf \n",
					 KMLAll[g].x, KMLAll[g].y, avgH);
				 fprintf(pw, "							</coordinates>\n");
				 fprintf(pw, "			</Point>\n");
				 fprintf(pw, "		</Placemark>\n");

				 fprintf(hp, "%d %lf %lf %lf\n", Hid, KMLAll[g].x, KMLAll[g].y, avgH);

				 Hid = Hid + 1;
			 }				 
			 
			 fclose(hp);
			
			 //KML_GrdXYZ
			 for (int k = 0; k < KML_GrdXYZ.size(); k++)
			 {
				 if (KML_ID[KMLAll[j].Qflag].NO == KML_GrdXYZ[k].Qflag)
				 {

					 fprintf(pw, "		<Placemark id=\"ID\">\n");
					 fprintf(pw, "			<description>\n");
					 fprintf(pw, "			%lf %lf %lf\n", KML_GrdXYZ[k].x, KML_GrdXYZ[k].y, avgH);
					 fprintf(pw, "			</description>\n");
					 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
					 fprintf(pw, "			<Point>\n");
					 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
					 fprintf(pw, "							<coordinates>\n");
					 fprintf(pw, "%lf,%lf,%lf ", KML_GrdXYZ[k].x, KML_GrdXYZ[k].y, avgH);
					 fprintf(pw, "							</coordinates>\n");
					 fprintf(pw, "			</Point>\n");
					 fprintf(pw, "		</Placemark>\n");

					 

				 }
			 }
			 //=================印出KML
			 */


			 fprintf(pw, "	</Folder>\n");
			 fprintf(pw, "</Document>\n");
			 fprintf(pw, "</kml>\n");
			 fclose(pw);
		 }

		 void ExportGRDLOD1point_T01(char filename[256], int i, int j, char filename2[256])
		 {
			 KML_BPCXYZTemp.clear();
			 //KML_BPCXYZ//KMLAll
			 FILE *pw = fopen(filename, "w");

			 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
			 fprintf(pw, "<Document>\n");
			 fprintf(pw, "	<name>KML_%s</name>\n", filename2);
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
			 fprintf(pw, "		<name>KML_%s</name>\n", filename2);
			 //fprintf(pw, "		<Snippet maxLines=\"0\"></Snippet>\n");
			 fprintf(pw, "		<LookAt>\n");
			 fprintf(pw, "			<longitude>%lf</longitude>\n", KMLAll[i].x);
			 fprintf(pw, "			<latitude>%lf</latitude>\n", KMLAll[i].y);
			 fprintf(pw, "			<altitude>%lf</altitude>\n", KMLAll[i].z + 100);
			 fprintf(pw, "			<heading>80</heading>\n");
			 fprintf(pw, "			<tilt>45</tilt>\n");
			 fprintf(pw, "			<range>130</range>\n");
			 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
			 fprintf(pw, "		</LookAt>\n");
			 //ExportLOD1KML


			 double x0, y0, x1, y1, dis;
			 double MinH = 999999, MaxH = 0;
			 double avgH;
			 int count = 0;
			 double H;
			 int Checkcount = 0;

			 avgH = GetavgH();




			 //=================印出KML
			 MinH = 999999; MaxH = 0;
			 count = 0;
			 Checkcount = 0;
			 avgH = GetavgH();

			 fprintf(pw, "	<name>KMLpoint_%s</name>\n", filename2);


			 //=================印出KML
			 MinH = 999999; MaxH = 0;
			 count = 0;
			 Checkcount = 0;
			 avgH = GetavgH();

			 fprintf(pw, "	<name>KML_%s</name>\n", filename2);

			
			 int Hid = 0;
			 for (int g = i; g < j; g++)
			 {
				 fprintf(pw, "		<Placemark id=\"ID\">\n");
				 fprintf(pw, "			<description>NO:%d\n", Hid);
				 fprintf(pw, "			%lf %lf %lf\n", KMLAll[g].x, KMLAll[g].y, avgH);
				 fprintf(pw, "			</description>\n");
				 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
				 fprintf(pw, "			<Point>\n");
				 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
				 fprintf(pw, "							<coordinates>\n");
				 fprintf(pw, "%lf,%lf,%lf \n",
					 KMLAll[g].x, KMLAll[g].y, avgH);
				 fprintf(pw, "							</coordinates>\n");
				 fprintf(pw, "			</Point>\n");
				 fprintf(pw, "		</Placemark>\n");

				 

				 Hid = Hid + 1;
			 }

			

			 //KML_GrdXYZ
			 for (int k = 0; k < KML_GrdXYZ.size(); k++)
			 {
				 if (KML_ID[KMLAll[j].Qflag].NO == KML_GrdXYZ[k].Qflag)
				 {

					 fprintf(pw, "		<Placemark id=\"ID\">\n");
					 fprintf(pw, "			<description>\n");
					 fprintf(pw, "			%lf %lf %lf\n", KML_GrdXYZ[k].x, KML_GrdXYZ[k].y, avgH);
					 fprintf(pw, "			</description>\n");
					 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
					 fprintf(pw, "			<Point>\n");
					 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
					 fprintf(pw, "							<coordinates>\n");
					 fprintf(pw, "%lf,%lf,%lf ", KML_GrdXYZ[k].x, KML_GrdXYZ[k].y, avgH);
					 fprintf(pw, "							</coordinates>\n");
					 fprintf(pw, "			</Point>\n");
					 fprintf(pw, "		</Placemark>\n");



				 }
			 }
			 //=================印出KML



			 fprintf(pw, "	</Folder>\n");
			 fprintf(pw, "</Document>\n");
			 fprintf(pw, "</kml>\n");
			 fclose(pw);
		 }

private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.kml)|*.kml";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{

		Filename01 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		Readbpcfile = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));
		
		strcat(Readbpcfile, "\\");
		//strcpy(FilenameTemp, Readbpcfile);

		TXYZ.clear();
		KMLAll.clear();
		KML_GrdXYZ.clear();

		//正常讀取全區LOD1 (KML)
		LoadLod1a(Filename01);
		//FILE *a = fopen("a0aaa.txt", "w");
		//for (int i = 0; i < (int)KMLAll.size(); i++)
		//{
		//	fprintf(a, "%d %d %lf %lf %lf\n", i, KMLAll[i].Qflag, KMLAll[i].x, KMLAll[i].y, KMLAll[i].z);
		//}
		//fclose(a);

		MessageBox::Show("LOAD完成");
	}
}

private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.txt)|*.TXT";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		
		Lidraxyz.clear();
		LidraXYZXxyz.clear();
		char *filename = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		char *name = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));

		LoadLidra(filename, name);

		MessageBox::Show("LOAD完成");
	}

}

		 void LoadLidra(char *filename, char *name)
		 {
			 FILE *fp = fopen(filename, "r");

			 double f97ENHto84X, f97ENHto84Y, f97ENHto84Z;
			 char buf[128] = { '\0' };
			 char bufa[128] = { '\0' };
			 char bufb[512] = { '\0' };
			 char file[256] = { '\0' };;

			 int i = 0, j = 1;

			// double x0 = 0, y0 = 0;
			// double x1 = 999999, y1 = 9999999;
			// // LidraXYZXtemp; // LidraXYZXxyz;
			// double xL, yL, xR, yR;

			// FILE *f = fopen("G:\\程式區備份\\2017_change3 - 0 -data\\data\\光達\\a.txt", "w");

			// while (fgets(buf, 128, fp) != NULL) {
			//	 sscanf(buf, "%s", bufa);
			//	 double x0 = 0, y0 = 0;
			//	 double x1 = 999999, y1 = 9999999;
			//	 double ax, ay, az, av;
			//	 strcpy(file, name);
			//	 strcat(file, "\\");
			//	 strcat(file, bufa);
			//	 //file[sizeof(file)] = '\0';
			//	 //fprintf(f, "%s%s", buf, file);
			//	 FILE *fpsa = fopen(file, "r");
			//	 while (fgets(bufb, 128, fpsa) != NULL) {
			//		 //fprintf(f, "%s %s\n", buf, file);
			//		 sscanf(bufb, "%lf %lf %lf %lf", &ax, &ay, &az, &av);
			//		 if (x0 < ax) x0 = ax;
			//		 if (y0 < ay) y0 = ay;
			//		 if (x1 > ax) x1 = ax;
			//		 if (y1 > ay) y1 = ay;
			//	 }
			//	 fclose(fpsa);

			//	  TWD97ENH_WGS84XYZ('T', x1, y0, 0, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
			//	  x1 = XYZ97to84_x; y0 = XYZ97to84_y;
			//	  TWD97ENH_WGS84XYZ('T', x0, y1, 0, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
			//	  x0 = XYZ97to84_x; y1 = XYZ97to84_y;

			//	  fprintf(f, "%lf %lf %lf %lf %s\n", x1, y0, x0, y1, bufa);
			// 
			//}
			// fclose(f);
			// fclose(fp);

			 while (fgets(buf, 128, fp) != NULL) {
				 sscanf(buf, "%lf %lf %lf %lf %s", &LidraXYZXtemp.xLup, &LidraXYZXtemp.yLup, &LidraXYZXtemp.xRdown, &LidraXYZXtemp.yRdown, &LidraXYZXtemp.name);
				 LidraXYZXxyz.push_back(LidraXYZXtemp);
			 }
			 fclose(fp);


		 }



private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	if (KMLAll.size() > 0 && LidraXYZXxyz.size() > 0)
	{

		//==========================過濾光達資料==================================
		//依續讀取每一筆資料
			//121.558881 25.030751 121.566783 25.025304 4542.xyz
			//121.558906 25.036168 121.566808 25.030721 4543.xyz
			//121.558930 25.041585 121.566833 25.036138 4544.xyz
			//121.566808 25.030721 121.574710 25.025274 4642.xyz
			//121.566833 25.036138 121.574735 25.030691 4643.xyz
			//121.566858 25.041554 121.574761 25.036107 4644.xyz
		//開啟第一筆4542.xyz
		//讀取第一筆中的第一行x y z v資料,然後丟入KML判斷(應該要重頭跑到尾)
		//char name2[64]; //itoa(KMLAll[i].Qflag, name2, 10);
		char bpcpath[128] = { '\0' };
		char KMLpath[128] = { '\0' };
		char KMLname[512];
		char KMLname2[512];
		FILE *pw;
		int StartId = 0;
		int GG = 0;
		PointA p;
		//FILE *fp = fopen("G:\\程式區備份\\2017_change3 - 0 -data\\data\\光達\\a03.txt","w");

		for (int i = 0; i < (int)LidraXYZXxyz.size(); i++)
		{
			Lidraxyz.clear();

			strcpy(KMLname, Readbpcfile);
			strcat(KMLname, LidraXYZXxyz[i].name);
			strcat(KMLname, "LOD 2.kml");
			strcpy(KMLname2, Readbpcfile);
			strcat(KMLname2, "New_");
			strcat(KMLname2, LidraXYZXxyz[i].name);
			FILE *fg = fopen(KMLname2, "w");

			LoadLidrafileTemp(KMLname, KMLname2 , fg);
						
			StartId = i + 1;

			fclose(fg);
		}
		MessageBox::Show("完成");
	}
	else
		MessageBox::Show("確認檔案是否正確");

	//==========================過濾光達資料==================================

	/*
	if (KMLAll.size() > 0 && LidraXYZXxyz.size() > 0)
	{
		readbpcTtemp.clear();
		readbpctemp.clear();

		char *StartID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox5->Text)));
		int SiD = atoi(StartID);
		char *EndID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox6->Text)));
		int EiD = atoi(EndID);

		//char name2[64]; //itoa(KMLAll[i].Qflag, name2, 10);
		char bpcpath[128] = { '\0' };
		char KMLpath[128] = { '\0' };
		char KMLname[512];
		FILE *pw;
		int StartId = 0;
		int GG = 0;
		PointA p;
		//FILE *fp = fopen("G:\\程式區備份\\2017_change3 - 0 -data\\data\\光達\\a03.txt","w");
		for (int i = 0; i < (int)KMLAll.size(); i++)
		{
			int strcmpCheck = -1, t03 = 0, tFlag = -1;
			p.x = KMLAll[i].x;		p.y = KMLAll[i].y;
			int g = PointInLidra(p, i);//Tilename02
			//int g =0;//Tilename02
			char Tilename01[4][128];
			char Tilename03[4][128];


			//避免下面的判斷再找停一個Qflag時出錯//要記得 要在最後面處理最後一筆
			if (i != KMLAll.size() - 1)
			{
				if ((SiD <= KMLAll[i].Qflag  &&  EiD >= KMLAll[i].Qflag))
				{
					readbpcTtemp.clear();

					for (int u = 0; u < g; u++)
					{
						strcpy(Tilename01[u], Tilename02[u]);
						//fprintf(fp, "%d %s ", g, Tilename01[u]);
					}

					if (strcmpCheck == -1)
					{
						strcpy(Tilename03[0], Tilename01[0]);
						strcmpCheck = 0; t03 = 1;
					}
					int jk = -1;
					for (int u = 0; u < g; u++)
					{
						for (int w = 0; w < t03; w++)
						{
							jk = strcmp(Tilename03[w], Tilename01[u]);
							if (jk != 0)	{ tFlag = u; }
						}
						if (jk == -1)
						{
							strcpy(Tilename03[t03], Tilename01[tFlag]);
							t03 = t03 + 1;
						}
					}

					for (int w = 0; w < t03; w++)
					{
						//fprintf(fp, "g=%d %d %s \n",  g, w, Tilename03[w]);
						bpcTtemp.num = g;
						strcpy(bpcTtemp.Tilename[w], Tilename03[w]);
					}
					readbpcTtemp.push_back(bpcTtemp);
					if (g > GG)	GG = g;
					//========================================================================



					if (KMLAll[i].Qflag != KMLAll[i + 1].Qflag)
					{
						//	//Readbpcfile+//
						BPC2xyzi.clear();
						KML_BPCXYZ.clear();


						////	//讀取kml_polygon-所屬的BPC-檔案//BPC2xyzi
							for (int bpci = 0; bpci < GG; bpci++)
							{
								strcpy(bpcpath, Readbpcfile);
								strcat(bpcpath, Tilename03[bpci]);
						
								LoadLidrafile(bpcpath, StartId,i);
							}


						////	//=================================================
							char name2[64]; //itoa(KMLAll[i].Qflag, name2, 10);
							itoa(KML_ID[KMLAll[i].Qflag].NO, name2, 10);

							strcpy(bpcpath, Readbpcfile);
							strcat(bpcpath, "result\\");
							if (access(bpcpath, 0))
							{
								mkdir(bpcpath);
							}

							strcpy(KMLpath, bpcpath);
							strcat(KMLpath, name2);
							strcat(KMLpath, ".kml");
						//	
							FILE *hp = fopen(KMLpath, "w");


						//	//ExportBPCtoKMLa(KMLpath, hp);

						//	ExportGRDLOD1_T01(KMLpath, StartId, i, name2);

						//	//for (int h = 0; h < KML_BPCXYZ.size(); h++)
						//	//{

						//	//	fprintf(hp, "%lf %lf %lf\n", KML_BPCXYZ[h].x, KML_BPCXYZ[h].y, KML_BPCXYZ[h].z);
						//	//}
							fclose(hp);
						////KML_BPCXYZ


						////=================================================

						StartId = i + 1;
					}

				}

				

					
			

					////當處理到同一個Qflg的最後一筆時,開始進行作業
					//if (KMLAll[i].Qflag != KMLAll[i + 1].Qflag)
					//{
					//	//Readbpcfile+//
					//	BPC2xyzi.clear();
					//	KML_BPCXYZ.clear();

					//	//讀取kml_polygon-所屬的BPC-檔案//BPC2xyzi
					//	for (int bpci = 0; bpci < GG; bpci++)
					//	{
					//		strcpy(bpcpath, Readbpcfile);
					//		strcat(bpcpath, Tilename03[bpci]);
					//		//fprintf(fp, "%s\n", Tilename03[bpci]);
					//		//FILE *fbpc = fopen(bpcpath, "r");

					//		//fclose(fbpc);
					//		//if (KML_LoadAll[i].Qflag==120)						
					//		LoadLidrafile(bpcpath, StartId,i);
					//	}


					//	//=================================================
					//	char name2[64]; //itoa(KMLAll[i].Qflag, name2, 10);
					//	itoa(KML_ID[KMLAll[i].Qflag].NO, name2, 10);

					//	strcpy(bpcpath, Readbpcfile);
					//	strcat(bpcpath, "result\\");
					//	if (access(bpcpath, 0))
					//	{
					//		mkdir(bpcpath);
					//	}

					//	strcpy(KMLpath, bpcpath);
					//	strcat(KMLpath, name2);
					//	strcat(KMLpath, ".txt");

					//	FILE *hp = fopen(KMLpath, "w");
					//	for (int h = 0; h < KML_BPCXYZ.size(); h++)
					//	{

					//		fprintf(hp, "%lf %lf %lf\n", KML_BPCXYZ[h].x, KML_BPCXYZ[h].y, KML_BPCXYZ[h].z);
					//	}
					//	fclose(hp);
						//KML_BPCXYZ


						//=================================================
						
						//StartId = i + 1;

					//}
			}
			
		}

		
		//for (int i = 0; i < readbpcTtemp.size(); i++)
		//{
		//	fprintf(fp1, "%d %d %s %s\n", i, readbpcTtemp[i].num, readbpcTtemp[i].Tilename[0], readbpcTtemp[i].Tilename[1]);
		//}
		//fclose(fp1);
		//fclose(fp);


		MessageBox::Show("完成");
	}else
		MessageBox::Show("確認檔案是否正確");
	
	
	
}


		 ////取得KML-所屬的point cloud落在哪一個BPC-tile
		 int PointInLidra(PointA p, int id) {
			 int j = 0;
			 for (int i = 0; i < (int)LidraXYZXxyz.size(); i++)
			 {
				 //if (((BPCAll[i].x1 < p.x) && (BPCAll[i].y1 < p.y)) && ((BPCAll[i].x2 > p.x) && (BPCAll[i].y2 > p.y)))
				 if (((LidraXYZXxyz[i].xLup < p.x) && (LidraXYZXxyz[i].yRdown < p.y)) && ((LidraXYZXxyz[i].xRdown > p.x) && (LidraXYZXxyz[i].yLup > p.y)))
				 {
					 strcpy(Tilename02[j], LidraXYZXxyz[i].name);
					 j = j + 1;
				 }
			 }
			 return j;
			 */
		 }

		 //過濾光達資料
		 void LoadLidrafileTemp(char KMLname[512], char KMLname2[512], FILE *fg)
		 {
			 double f97ENHto84X, f97ENHto84Y, f97ENHto84Z;
			 double ax, ay, az, av;
			 char buf[128];
			 FILE *fpsa = fopen(KMLname, "r");
			 PointA p;
			 int Startid = 0;
			 int R = 0;
			 while (fgets(buf, 128, fpsa) != NULL) {
				 R = 0;
				 sscanf(buf, "%lf %lf %lf %lf", &ax, &ay, &az, &av);
				 TWD97ENH_WGS84XYZ('T', ax, ay, az, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				 p.x = XYZ97to84_x; p.y = XYZ97to84_y;
				 p.z = az;	
				 for (int i = 0; (i < (int)KMLAll.size())&& (R==0); i++)
				 {
					 if (i != KMLAll.size() - 1)
					 {
						 if (KMLAll[i].Qflag != KMLAll[i + 1].Qflag)
						 {
							 if (PointinPolygonBPC(p, Startid, i))
							 {
								 fprintf(fg, "%lf %lf %lf %lf\n", ax, ay, az, av);
								 R = 1;
							 }
							 Startid = i + 1;
						 }
					 }
				 }
				 //fprintf(fg, "%lf %lf %lf %lf\n", p.x, p.y, az, av);			 
			 }
			 fclose(fpsa);
		 }
		 //過濾光達資料


		 void LoadLidrafile(char *filename,int i,int j)
		 {
			 double f97ENHto84X, f97ENHto84Y, f97ENHto84Z;
			 double ax, ay, az, av;
			 char buf[128];
			 FILE *fpsa = fopen(filename, "r");
			 PointA p;
			 while (fgets(buf, 128, fpsa) != NULL) {

				 sscanf(buf, "%lf %lf %lf %lf", &ax, &ay, &az, &av);
				 TWD97ENH_WGS84XYZ('T', ax, ay, az, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				 p.x = XYZ97to84_x; p.y = XYZ97to84_y;
				 p.z = az;
				 if (PointinPolygonBPC(p, i, j))
				 {
					 TKMLtemp.x = p.x; TKMLtemp.y = p.y; TKMLtemp.z = p.z;
					 TKMLtemp.Id = i;
					 KML_BPCXYZ.push_back(TKMLtemp);
				 }
			 }
			 fclose(fpsa);
		 }

		

private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.txt)|*.Txt";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		Wgs84to90_1 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		this->textBox7->Text = openFileDialog1->FileName;
	}
}


private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.txt)|*.Txt";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		char *D_filename = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		//String ^CSV_name = System::IO::Path::GetFileNameWithoutExtension(openFileDialog1->FileName);
		//char *na = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_name)));

		char *D_path = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));
		strcpy(D_name, D_path);
		strcat(D_name, "\\");
		strcat(D_name, "精度分析.txt");

		Wgs84to90_2 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		this->textBox8->Text = openFileDialog1->FileName;
	}
}


private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {

	vector<PointXYZa> Wgs84to970a;
	vector<PointXYZa> Wgs84to970b;

	char *Wgs8401 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox7->Text)));
	char *Wgs8402 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox8->Text)));

	FILE *fp01, *fp02;
	fp01 = fopen(Wgs8401, "r");
	fp02 = fopen(Wgs8402, "r");
	char buf[512];
	char buf2[512];
	double X, Y, Z;
	int d1, d2;
	while (fgets(buf, 512, fp01) != NULL) {
		sscanf(buf, "%d %lf %lf %lf",&d1 , &X, &Y, &Z);
		Cal_lonlat_To_twd97(X, Y, 0);
		Wgs84to97temp.x = Wgs84toTwd97X01; Wgs84to97temp.y = Wgs84toTwd97Y01 ; Wgs84to97temp.z = Z;
		Wgs84to970a.push_back(Wgs84to97temp);
	}
	while (fgets(buf2, 512, fp02) != NULL) {
		sscanf(buf2, "%d %lf %lf %lf", &d2, &X, &Y, &Z);
		Cal_lonlat_To_twd97(X, Y, 1);
		Wgs84to97temp.x = Wgs84toTwd97X02; Wgs84to97temp.y = Wgs84toTwd97Y02; Wgs84to97temp.z = Z;
		Wgs84to970b.push_back(Wgs84to97temp);
	}
	fclose(fp01); fclose(fp02);

	FILE *fp = fopen(D_name, "w");
	double avgXY = 0, avgZ = 0;
	int kg = 0;
	for (int i = 0; i < (int)Wgs84to970a.size(); i++)
	{
		double disXY = LENXY(Wgs84to970a[i].x, Wgs84to970a[i].y, Wgs84to970b[i].x, Wgs84to970b[i].y);
		double disZ = LENZ(Wgs84to970a[i].z, Wgs84to970b[i].z);
		fprintf(fp, "平面距離:%lf，高程距離:%lf\n", disXY, disZ);
		avgXY = avgXY + disXY; avgZ = avgZ + disZ;
		kg = kg + 1;
	}
	avgZ = avgZ / (int)Wgs84to970a.size();
	fprintf(fp, "\n平均平面精度:%lf，平均高程精度:%lf\n", avgXY / (int)Wgs84to970a.size(), avgZ);
	
	double Xz01 = 0;
	for (int i = 0; i < (int)Wgs84to970a.size(); i++)
	{
		double disZ = (LENZ(Wgs84to970a[i].z, Wgs84to970b[i].z) - avgZ) ;
		Xz01 = Xz01+ disZ*disZ;
	}
	Xz01 = Xz01 / ((int)Wgs84to970a.size()-1);
	Xz01 = sqrt(Xz01);
	fprintf(fp, "差值標準差:%lf\n", Xz01);

	double Xz = 0;
	for (int i = 0; i < (int)Wgs84to970a.size(); i++)
	{
		double sum = LENZ(Wgs84to970a[i].z, Wgs84to970b[i].z);
		sum = sum*sum;
		Xz = Xz + sum;
	}
	Xz = Xz / (int)Wgs84to970a.size();
	Xz = sqrt(Xz);

	fprintf(fp, "RMSE:%lf", Xz);
	Wgs84to970b.clear();
	Wgs84to970a.clear();

	fclose(fp);
	MessageBox::Show("轉換完成");
}

		 double LENXY(double x1, double y1, double x2, double y2)
		 {
			 return sqrt((abs(x1 - x2)* abs(x1 - x2)) + (abs(y1 - y2)* abs(y1 - y2)));
		 }
		 double LENZ(double z1, double z2)
		 {
			 return ((z1 - z2));
		 }


private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {

	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.rbm)|*.RBM";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		GRDxyz.clear();
		
		char *filename = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		char *name = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));

		//LOD 2-> RBM to KML
		RBMtoKML(filename, name);


		//做出100公尺的網格
		//MakeTile();

		MessageBox::Show("完成");
	}
}
		 //LOD 2-> RBM to KML
		 void	 RBMtoKML(char filename[256], char name[256])
		 {//GRDtemp
			 FILE *fp = fopen(filename, "r");			
			 char buf[256]; char buf01[4096];
			 char bufa[1024]; char bufb[1024];
			 char EndWord[80] = "END";
			 char *loc = { '\0' };
			 int p, q, r;
			 int count = 0;	
			 double f97ENHto84X = 0, f97ENHto84Y = 0, f97ENHto84Z = 0;
			 while (fgets(buf, 256, fp) != NULL) {
				 		

				 //字串搜尋 比對
				 loc = strstr(buf, EndWord);
				 if (loc == NULL)
				 {
					 sscanf(buf, "%d %d %d", &p, &q, &r);
					 for (int i = 0; i < q; i++)
					 {
						 fgets(buf01, 4096, fp);
						 //fprintf(fpa, "%s", buf);
						 sscanf(buf01, "       %lf       %lf %d            %lf", &GRDtemp.x, &GRDtemp.y, &r, &GRDtemp.z);
						 TWD97ENH_WGS84XYZ('T', GRDtemp.x, GRDtemp.y, GRDtemp.z, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
						 GRDtemp.x = XYZ97to84_x; GRDtemp.y = XYZ97to84_y;

						 GRDtemp.M = p; GRDtemp.id = count;		count = count + 1;
						 GRDxyz.push_back(GRDtemp);

					 }
				 }
				 
			 }
			 fclose(fp);

			 strcpy(bufa, name);
			 strcpy(bufb, name);
			 strcat(bufa,"\\LOD 2.kml");
			 strcat(bufb, "\\A\\");
		
			 fp = fopen(bufa, "w");
			 ExportRBMtoKML(bufa, bufb);
			 //for (int k = 0; k < GRDxyz.size(); k++)
			 //{
				// fprintf(fp, "%d %d %lf %lf %lf\n", GRDxyz[k].id, GRDxyz[k].M, GRDxyz[k].x, GRDxyz[k].y, GRDxyz[k].z);
			 //}
			 //fclose(fp);
		 }
		 //LOD 2-> RBM to KML
		 void ExportRBMtoKML(char name[1024], char nameb[1024])
		 {
			 FILE *pw = fopen(name, "w");

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
			 fprintf(pw, "			<longitude>%lf</longitude>\n", GRDxyz[0].x);
			 fprintf(pw, "			<latitude>%lf</latitude>\n", GRDxyz[0].y);
			 fprintf(pw, "			<altitude>%lf</altitude>\n", GRDxyz[0].z + 200);
			 fprintf(pw, "			<heading>80</heading>\n");
			 fprintf(pw, "			<tilt>45</tilt>\n");
			 fprintf(pw, "			<range>130</range>\n");
			 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
			 fprintf(pw, "		</LookAt>\n");
			 //ExportLOD1KML
			 char buf[256];
			 char name3[64];
			 int startid = 0;
			 FILE *bp;// = fopen(nameb, "w");
			 int A = 0;
			 int B = 0;
			 //itoa(GRDxyz[0].M, name3, 10);
			 //strcpy(buf, nameb);
			 //strcat(buf, "NO_");
			 //strcat(buf, name3);
			 //strcat(buf, ".txt");
			 //bp = fopen(buf, "w");

			 for (int i = 0; i < GRDxyz.size()-1; i++)
			 {
				
				 //當處理到同一個Qflg的最後一筆時,開始進行作業
				 if (GRDxyz[i].M != GRDxyz[i + 1].M)
				 {
					 
					 itoa(GRDxyz[i].M, name3, 10);
					 strcpy(buf, nameb);
					 strcat(buf, "NO_");
					 strcat(buf, name3);
					 strcat(buf, ".txt");

					 bp = fopen(buf, "w");


					 ////=================印出KML
					 fprintf(pw, "	<name>KML_%d</name>\n", GRDxyz[i].M);
					 fprintf(pw, "		<Placemark id=\"ID\">\n");
					 fprintf(pw, "			<name>KML_ID%d</name>\n", GRDxyz[i].M);
					 fprintf(pw, "			<description>NO:%d\n", GRDxyz[i].M);
					 fprintf(pw, "			</description>\n");
					 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
					 fprintf(pw, "			<Polygon>\n");
					 fprintf(pw, "			<extrude>1</extrude>\n");
					 fprintf(pw, "			<altitudeMode>absolute</altitudeMode>\n");
					 fprintf(pw, "			<outerBoundaryIs>\n");
					 fprintf(pw, "			<LinearRing>\n");
					 fprintf(pw, "					<coordinates>\n");
					 fprintf(pw, "									");
					
					 int A = 0;
					 for (; startid < i; startid++)
					 {
						
						 fprintf(pw, "%lf,%lf,%lf ", GRDxyz[startid].x, GRDxyz[startid].y, GRDxyz[startid].z);

						 fprintf(bp, "%d %lf %lf %lf\n", A, GRDxyz[startid].x, GRDxyz[startid].y, GRDxyz[startid].z);
						 A = A + 1;
					 }
					 startid = i+1;
					 fprintf(pw, "%lf,%lf,%lf ", GRDxyz[i].x, GRDxyz[i].y, GRDxyz[i].z);
					 fprintf(pw, " \n");
					 fprintf(pw, "					</coordinates>\n");
					 fprintf(pw, "			</LinearRing>\n");
					 fprintf(pw, "			</outerBoundaryIs>\n");
					 fprintf(pw, "			</Polygon>\n");
					 fprintf(pw, "		</Placemark>\n");
					 //=================印出KML

					
					 A = 0;
					
					 B = 0;
					

					 
					 //A = A + 1;

					 fclose(bp);

				 }
				 else
				 {
					 fprintf(pw, "		<Placemark id=\"ID\">\n");
					 //fprintf(pw, "			<name>ID_%s</name>\n", name2);
					 fprintf(pw, "			<description>NO:%d\n",B);
					 fprintf(pw, "			%lf %lf %lf\n", GRDxyz[i].x, GRDxyz[i].y, GRDxyz[i].z);
					 fprintf(pw, "			</description>\n");
					 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
					 fprintf(pw, "			<Point>\n");
					 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
					 fprintf(pw, "							<coordinates>\n");
					 fprintf(pw, "								%lf,%lf,%lf \n",
						 GRDxyz[i].x, GRDxyz[i].y, GRDxyz[i].z
						 );
					 fprintf(pw, "							</coordinates>\n");
					 fprintf(pw, "			</Point>\n");
					 fprintf(pw, "		</Placemark>\n");

					
					 B = B + 1;
					
				 }
				

				 

				/* strcpy(buf, name2);
				 strcat(buf, "NO_.txt");
				 bp = fopen(buf,"w");
				 fprintf(bp, "%d %lf %lf %lf\n", GRDxyz[i].M, GRDxyz[i].x, GRDxyz[i].y, GRDxyz[i].z);
				 */
				 
			 }			 

			 fprintf(pw, "	</Folder>\n");
			 fprintf(pw, "</Document>\n");
			 fprintf(pw, "</kml>\n");
			 //
			 fclose(pw);	
			 
		 }

		 
		 //LOD 2-> RBM to KML


		 //做出100公尺的網格
		 void MakeTile()
		 {
			 double X = 121.557606;
			 double Y = 25.041392;

			 Cal_lonlat_To_twd97(X, Y,0);	 			 
			 X = Wgs84toTwd97X01;  Y = Wgs84toTwd97Y01 + 2;

			 double X2 = 121.575443;
			 double Y2 = 25.040788;
			 Cal_lonlat_To_twd97(X2, Y2, 0);
			 X2 = Wgs84toTwd97X01;  Y2 = Wgs84toTwd97Y01 + 2;
			 
			 ExportLine(X, Y,X2,Y2);
		 }

		 //做出100公尺的網格
		 void ExportLine(double X, double Y, double X2, double Y2)
		 {
			 FILE *pw = fopen("A.kml", "w");
			 double x1, y1, x2, y2, x3, y3, x4, y4;
			 double f97ENHto84X = 0, f97ENHto84Y = 0, f97ENHto84Z = 0;
			 double Lx = 100, Ly = 100;
			 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
			 fprintf(pw, "<Document>\n");
			 fprintf(pw, "	<name>KML</name>\n");
			 fprintf(pw, "	<Style id=\"PolyStyle000\">\n");
			 fprintf(pw, "		<IconStyle>\n");
			 fprintf(pw, "			<scale>5</scale>\n");
			 fprintf(pw, "			<Icon>\n");
			 fprintf(pw, "				<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
			 fprintf(pw, "			</Icon>\n");
			 fprintf(pw, "		</IconStyle>\n");
			 fprintf(pw, "		<LabelStyle>\n");
			 fprintf(pw, "			<color>00000000</color>\n");
			 fprintf(pw, "			<scale>0</scale>\n");
			 fprintf(pw, "		</LabelStyle>\n");
			 fprintf(pw, "		<ListStyle>\n");
			 fprintf(pw, "		</ListStyle>\n");
			 fprintf(pw, "		<LineStyle>\n");
			 fprintf(pw, "			<color>ff0000ff</color>\n");
			 fprintf(pw, "			<width>5</width>\n");
			 fprintf(pw, "		</LineStyle>\n");
			 fprintf(pw, "		<PolyStyle>\n");
			 fprintf(pw, "			<color>ff0000ff</color>\n");
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

			 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
			 fprintf(pw, "		<IconStyle>\n");
			 fprintf(pw, "			<scale>5</scale>\n");
			 fprintf(pw, "			<Icon>\n");
			 fprintf(pw, "				<href>http://maps.google.com/mapfiles/kml/shapes/shaded_dot.png</href>\n");
			 fprintf(pw, "			</Icon>\n");
			 fprintf(pw, "		</IconStyle>\n");			
			 fprintf(pw, "		<LineStyle>\n");
			 fprintf(pw, "			<color>ff0000ff</color>\n");
			 fprintf(pw, "			<width>5</width>\n");
			 fprintf(pw, "		</LineStyle>\n");
			 fprintf(pw, "	</Style>\n");

			 fprintf(pw, "	<Folder id=\"KML\">\n");
			 fprintf(pw, "		<name>KML</name>\n" );
			
			 double Rx = X, Ry = Y;
			 x1 = X, y1 = Y;
			 x4 = X2; y4 = Y2;

			 double nx1, nx2, ny1, ny2;
			 TWD97ENH_WGS84XYZ('T', x1, y1, 0, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
			 nx1 = XYZ97to84_x; ny1 = XYZ97to84_y;
			 TWD97ENH_WGS84XYZ('T', x4, y4, 0, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
			 nx2 = XYZ97to84_x; ny2 = XYZ97to84_y;

			 for (int i = 0; i < 18; i = i + 1)
			 {

				 
			 	 fprintf(pw, "		<Placemark id=\"ID\">\n");
			 	 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
			 	 fprintf(pw, "			<LineString>\n");
			 	 fprintf(pw, "							<coordinates>\n");
			 	 fprintf(pw, "								%lf,%lf,0 %lf,%lf,0 \n",
			 		 nx1, ny1, nx2, ny2
			 		 );
			 	 fprintf(pw, "							</coordinates>\n");
			 	 fprintf(pw, "			</LineString>\n");
			 	 fprintf(pw, "		</Placemark>\n");
			 	 
			 	 //Rx = Rx + 100;
				 		  
				 y1 = y1 - 100; y4 = y4 - 100;

				 TWD97ENH_WGS84XYZ('T', x1, y1, 0, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				  ny1 = XYZ97to84_y;

				 TWD97ENH_WGS84XYZ('T', x4, y4, 0, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				  ny2 = XYZ97to84_y;
			 	 
			 }
			 Rx = X, Ry = Y;
			 
			 x1 = X; y1 = Y;
			 x4 = X; y4 = Y -1800;
			 TWD97ENH_WGS84XYZ('T', x1, y1, 0, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
			 
			 nx1 = XYZ97to84_x; ny1 = XYZ97to84_y;
			 TWD97ENH_WGS84XYZ('T', x4, y4, 0, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
			 nx2 = XYZ97to84_x; ny2 = XYZ97to84_y;

			 for (int i = 0; i < 18; i = i + 1)
			 {

				 fprintf(pw, "		<Placemark id=\"ID\">\n");
				 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
				 fprintf(pw, "			<LineString>\n");
				 fprintf(pw, "							<coordinates>\n");
				 fprintf(pw, "								%lf,%lf,0 %lf,%lf,0 \n",
					 nx1, ny1, nx1, ny2
					 );
				 fprintf(pw, "							</coordinates>\n");
				 fprintf(pw, "			</LineString>\n");
				 fprintf(pw, "		</Placemark>\n");

				 //Rx = Rx + 100;

				 x1 = x1 + 100; x4 = x1;


				 TWD97ENH_WGS84XYZ('T', x1, y1, 0, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				 nx1 = XYZ97to84_x;
				 ny1 = XYZ97to84_y;

				 TWD97ENH_WGS84XYZ('T', x4, y4, 0, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
				 ny2 = XYZ97to84_y;

			 }



			 fprintf(pw, "	</Folder>\n");
			 fprintf(pw, "</Document>\n");
			 fprintf(pw, "</kml>\n");

			 fclose(pw);

			 

		 }


		 //GRDto3tran
		 //讀取各grd,分成2個三角形(0.5),然後取重心
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.txt)|*.TXT";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		GRDxyz.clear();


		char *filename = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		char *name = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));

		LoadTran(filename, name);


		MessageBox::Show("LOAD完成");
	}
}

		 void LoadTran(char *filename, char *name)
		 {
			// tranTemp
			//Tranxyz
			 FILE *fp = fopen(filename, "r");
			 double x, y, z;			 
			 char buf[128] = { '\0' };
			 char bufa[512] = { '\0' };
			 char bufb[512] = { '\0' };
			 char bufc[512] = { '\0' };


			 char file[256]; char filea[256]; char fileb[256];
			 strcpy(file, name);
			 strcat(file, "\\");
			 strcpy(filea, file);
			 strcat(filea, "01_");
			 int i = 0, j = 1;
			 double f97ENHto84X = 0, f97ENHto84Y = 0, f97ENHto84Z = 0;
			 double X,Y,Z;
			 while (fgets(buf, 128, fp) != NULL) {
				 //GRDtemp; GRDxyz
				 sscanf(buf, "%s", bufa);
				 strcpy(bufb, file);
				 strcat(bufb, bufa);
				 FILE *fpsa = fopen(bufb, "r");

				 strcpy(bufc, filea);
				 strcat(bufc, bufa);
				 FILE *fpsb = fopen(bufc, "w");
				 strcpy(fileb, bufc);
				 strcat(fileb, ".kml");
				 //fprintf(fps, "%s\n", bufb);
				// GetGrd GRDtemp;
				// vector<GetGrd> GRDxyz;
				 while (fgets(bufa, 128, fpsa) != NULL) {
					 sscanf(bufa, "%lf %lf %lf", &x, &y, &z);					 
					 tranTemp.x1 = x - 0.5;		tranTemp.y1 = y + 0.5;		tranTemp.z1 = z;
					 //TWD97ENH_WGS84XYZ('T', tranTemp.x1, tranTemp.y1, tranTemp.z1, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
					 //tranTemp.x1 = XYZ97to84_x; tranTemp.y1 = XYZ97to84_y;

					 tranTemp.x2 = x + 0.5;		tranTemp.y2 = y + 0.5;		tranTemp.z2 = z;
					 //TWD97ENH_WGS84XYZ('T', tranTemp.x2, tranTemp.y2, tranTemp.z2, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
					 //tranTemp.x2 = XYZ97to84_x; tranTemp.y2 = XYZ97to84_y;

					 tranTemp.x3 = x - 0.5;		tranTemp.y3 = y - 0.5;		tranTemp.z3 = z;
					 //TWD97ENH_WGS84XYZ('T', tranTemp.x3, tranTemp.y3, tranTemp.z3, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
					 //tranTemp.x3 = XYZ97to84_x; tranTemp.y3 = XYZ97to84_y;
					 //Tranxyz.push_back(tranTemp);
					 X = (tranTemp.x1 + tranTemp.x2 + tranTemp.x3) / 3;
					 Y = (tranTemp.y1 + tranTemp.y2 + tranTemp.y3) / 3;
					 Z = tranTemp.z1 = z;
					 GRDtemp.x = X; GRDtemp.y = Y; GRDtemp.z = Z;
					 GRDxyz.push_back(GRDtemp);

					 fprintf(fpsb, "%lf %lf %lf\n",X,Y,Z	);
					 tranTemp.x1 = x + 0.5;		tranTemp.y1 = y + 0.5;		tranTemp.z1 = z;
					 //TWD97ENH_WGS84XYZ('T', tranTemp.x1, tranTemp.y1, tranTemp.z1, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
					 //tranTemp.x1 = XYZ97to84_x; tranTemp.y1 = XYZ97to84_y;
					 tranTemp.x2 = x + 0.5;		tranTemp.y2 = y - 0.5;		tranTemp.z2 = z;
					 //TWD97ENH_WGS84XYZ('T', tranTemp.x2, tranTemp.y2, tranTemp.z2, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
					 //tranTemp.x2 = XYZ97to84_x; tranTemp.y2 = XYZ97to84_y;
					 tranTemp.x3 = x - 0.5;		tranTemp.y3 = y - 0.5;		tranTemp.z3 = z;
					 //TWD97ENH_WGS84XYZ('T', tranTemp.x3, tranTemp.y3, tranTemp.z3, f97ENHto84X, f97ENHto84Y, f97ENHto84Z);
					 //tranTemp.x3 = XYZ97to84_x; tranTemp.y3 = XYZ97to84_y;
					 //Tranxyz.push_back(tranTemp);
					 X = (tranTemp.x1 + tranTemp.x2 + tranTemp.x3) / 3;
					 Y = (tranTemp.y1 + tranTemp.y2 + tranTemp.y3) / 3;
					 Z = tranTemp.z1 = z;
					 GRDtemp.x = X; GRDtemp.y = Y; GRDtemp.z = Z;
					 GRDxyz.push_back(GRDtemp);

					 fprintf(fpsb, "%lf %lf %lf\n", X, Y, Z);

				 }
				 //ExportTranKML(fileb);
				 Tranxyz.clear();
				 fclose(fpsa);
				 fclose(fpsb);
			 }

			 fclose(fp);
		 }

		 void ExportTranKML(char filename[256])
		 {
			 FILE *pw = fopen(filename, "w");

			 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
			 fprintf(pw, "<Document>\n");
			 fprintf(pw, "	<name>KML</name>\n");
			 fprintf(pw, "	<Style id=\"PolyStyle00\">\n");
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
			 fprintf(pw, "			<longitude>%lf</longitude>\n", Tranxyz[((int)Tranxyz.size()/2)].x1);
			 fprintf(pw, "			<latitude>%lf</latitude>\n", Tranxyz[((int)Tranxyz.size() / 2)].y1);
			 fprintf(pw, "			<altitude>%lf</altitude>\n", Tranxyz[((int)Tranxyz.size() / 2)].z1 + 200);
			 fprintf(pw, "			<heading>80</heading>\n");
			 fprintf(pw, "			<tilt>45</tilt>\n");
			 fprintf(pw, "			<range>130</range>\n");
			 fprintf(pw, "			<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n");
			 fprintf(pw, "		</LookAt>\n");
			 //ExportLOD1KML

			 int startid = 0;
			 fprintf(pw, "	<name>KML</name>\n");

			 for (int i = 0; i < Tranxyz.size(); i++)
			 {

					 ////=================印出KML					 
					 fprintf(pw, "		<Placemark id=\"ID\">\n");
					 fprintf(pw, "			<name>KML_ID</name>\n");
					 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
					 fprintf(pw, "			<Polygon>\n");
					 fprintf(pw, "			<extrude>1</extrude>\n");
					 fprintf(pw, "			<altitudeMode>relativeToGround</altitudeMode>\n");
					 fprintf(pw, "			<outerBoundaryIs>\n");
					 fprintf(pw, "			<LinearRing>\n");
					 fprintf(pw, "					<coordinates>\n");
					 fprintf(pw, "									");
					 
					 fprintf(pw, "%lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf\n",
						 Tranxyz[i].x1, Tranxyz[i].y1, Tranxyz[i].z1,
						 Tranxyz[i].x2, Tranxyz[i].y2, Tranxyz[i].z2,
						 Tranxyz[i].x3, Tranxyz[i].y3, Tranxyz[i].z3,
						 Tranxyz[i].x1, Tranxyz[i].y1, Tranxyz[i].z1);

					 fprintf(pw, "					</coordinates>\n");
					 fprintf(pw, "			</LinearRing>\n");
					 fprintf(pw, "			</outerBoundaryIs>\n");
					 fprintf(pw, "			</Polygon>\n");
					 fprintf(pw, "		</Placemark>\n");
					 //=================印出KML
				 
			 }

			 fprintf(pw, "	</Folder>\n");
			 fprintf(pw, "</Document>\n");
			 fprintf(pw, "</kml>\n");

			 fclose(pw);
		 }


		 //開啟NewGRD
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.txt)|*.TXT";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		GRDxyz.clear();
		Tranxyz.clear();

		char *filename = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		char *name = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));

		if ((int)KML_GrdXYZ.size() > 0)
		{
			LoadNewTran(filename, name);//PointToTran//01_ReadMeFile.txt
			MessageBox::Show("LOAD完成");
		}else
			MessageBox::Show("請開啟KML檔案");		
	}
}


		 //開啟KML
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.kml)|*.KML";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{

		Filename01 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		Readbpcfile = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));

		strcat(Readbpcfile, "\\");
		//strcpy(FilenameTemp, Readbpcfile);

		TXYZ.clear();
		KMLAll.clear();
		KML_GrdXYZ.clear();

		//正常讀取全區LOD1 (KML)
		LoadLod1a(Filename01);//KML_GrdXYZ

		MessageBox::Show("LOAD完成");
	}

}

		 void LoadNewTran(char *filename, char *name)
		 {

			 FILE *fp = fopen(filename, "r");
			 double x, y, z;
			 char buf[128] = { '\0' };
			 char bufa[512] = { '\0' };
			 char bufb[512] = { '\0' };
			 char bufc[512] = { '\0' };


			 char file[256]; char filea[256]; char fileb[256];
			 strcpy(file, name);
			 strcat(file, "\\");
			 strcpy(filea, file);
			 strcat(filea, "02_");
			 int i = 0, j = 1, M = 0;
			 double f97ENHto84X = 0, f97ENHto84Y = 0, f97ENHto84Z = 0;
			 PointA p1,p2,p3;
			 int R = 0, Startid=0;

			 while (fgets(buf, 128, fp) != NULL) {
				 //GRDtemp; GRDxyz
				 sscanf(buf, "%s", bufa);
				 strcpy(bufb, file);
				 strcat(bufb, bufa);
				 FILE *fpsa = fopen(bufb, "r");

				 strcpy(bufc, filea);
				 strcat(bufc, bufa);
				 //strcat(bufc, ".grd");
				 FILE *fpsb = fopen(bufc, "w");
				 //strcpy(fileb, bufc);
				 //strcat(fileb, ".kml");
				 int flag = 0;
				 while (fgets(bufa, 512, fpsa) != NULL) {
					 R = 0;
					 sscanf(bufa, "%lf %lf %lf %lf %lf %lf %lf %lf %lf", 
						 &tranTemp.x1, &tranTemp.y1, &tranTemp.z1,
						 &tranTemp.x2, &tranTemp.y2, &tranTemp.z2,
						 &tranTemp.x3, &tranTemp.y3, &tranTemp.z3
						 );
					 p1.x = tranTemp.x1; p1.y = tranTemp.y1;	p1.z = tranTemp.z1;
					 p2.x = tranTemp.x2; p2.y = tranTemp.y2;	p2.z = tranTemp.z2;
					 p3.x = tranTemp.x3; p3.y = tranTemp.y3;	p3.z = tranTemp.z3;

					 //KML_GrdXYZ
					 for (int i = 0; (i < (int)KML_GrdXYZ.size()) && (R == 0); i++)
					 {
						 if (i != KML_GrdXYZ.size() - 1)
						 {
							 if (KML_GrdXYZ[i].Qflag != KML_GrdXYZ[i + 1].Qflag)
							 {
								 if (PointinPolygonGRD(p1,p2,p3, Startid, i))
								 {
									 fprintf(fpsb, "%lf %lf %lf %lf %lf %lf %lf %lf %lf\n", 
										 tranTemp.x1, tranTemp.y1, tranTemp.z1,
										 tranTemp.x2, tranTemp.y2, tranTemp.z2,
										 tranTemp.x3, tranTemp.y3, tranTemp.z3);
									 R = 1;
								 }
								 Startid = i + 1;
							 }

						 }
					 }
					 tranTemp.M = M; tranTemp.id = i;					 
					 //Tranxyz.push_back(tranTemp);
					 i = i + 1;

				 }
				 M = M + 1;
				 fclose(fpsa);
				 fclose(fpsb);
			 }
			 fclose(fp);
		 }


		 bool PointinPolygonGRD(PointA p1, PointA p2, PointA p3, int i, int Kcount) {
			 int j = 0;
			 bool inside = false;
			 for (j = Kcount - 1; i < Kcount; j = i++)
			 {
				 if (
					 ((KMLAll[i].y > p1.y) != (KMLAll[j].y > p1.y)) && (p1.x < (KMLAll[j].x - KMLAll[i].x) * (p1.y - KMLAll[i].y) / (KMLAll[j].y - KMLAll[i].y) + KMLAll[i].x) ||
					 ((KMLAll[i].y > p2.y) != (KMLAll[j].y > p2.y)) && (p2.x < (KMLAll[j].x - KMLAll[i].x) * (p2.y - KMLAll[i].y) / (KMLAll[j].y - KMLAll[i].y) + KMLAll[i].x) ||
					 ((KMLAll[i].y > p3.y) != (KMLAll[j].y > p3.y)) && (p3.x < (KMLAll[j].x - KMLAll[i].x) * (p3.y - KMLAll[i].y) / (KMLAll[j].y - KMLAll[i].y) + KMLAll[i].x)
					 )
				 {
					 inside = !inside;
				 }
			 }

			 return inside;
		 }

private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.txt)|*.TXT";
	//openFileDialog1->Filter = "(*.grd)|*.GRD";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		GRDxyz.clear();


		char *filename = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		char *name = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));

		LoadNewGrda(filename, name);

		MessageBox::Show("LOAD完成");
	}
}
		 void LoadNewGrda(char *filename, char *name)
		 {
	
				 FILE *fp = fopen(filename, "r");

				 double f97ENHto84X, f97ENHto84Y, f97ENHto84Z;
				 char buf[256] = { '\0' };
				 char bufa[512] = { '\0' };
				 char bufb[512] = { '\0' };
				 char file[256];
				 strcpy(file, name);
				 strcat(file, "\\");
				 int i = 0, j = 1;
				 double x1, y1, z1, x2, y2, z2, x3, y3, z3;
				 while (fgets(buf, 128, fp) != NULL) {
					 //GRDtemp; GRDxyz
					 sscanf(buf, "%s", bufa);
					 strcpy(bufb, file);
					 strcat(bufb, bufa);
					 FILE *fpsa = fopen(bufb, "r");

					 //fprintf(fps, "%s\n", bufb);

					 while (fgets(bufa, 256, fpsa) != NULL) {
						 sscanf(bufa, "%lf %lf %lf %lf %lf %lf %lf %lf %lf", 
							 &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3							 
							 );		
						 GRDtemp.x = x1; GRDtemp.y = y1; GRDtemp.z = z1;
						 GRDtemp.id = i; GRDtemp.M = j;
						 i = i + 1;
						 GRDxyz.push_back(GRDtemp);
						 GRDtemp.x = x2; GRDtemp.y = y2; GRDtemp.z = z2;
						 GRDtemp.id = i; GRDtemp.M = j;
						 i = i + 1;
						 GRDxyz.push_back(GRDtemp);
						 GRDtemp.x = x3; GRDtemp.y = y3; GRDtemp.z = z3;
						 GRDtemp.id = i; GRDtemp.M = j;
						 i = i + 1;
						 GRDxyz.push_back(GRDtemp);
					 }
					 j = j + 1;
					 fclose(fpsa);
				 }


				 fclose(fp);
			 
		 }

private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.kml)|*.kml";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		KML_ID.clear();
		KMLAll.clear();
		Filename01 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		Readbpcfile = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));
		strcat(Readbpcfile, "\\");

		LoadLod1b(Filename01);

		FILE *fp = fopen("G:\\程式區備份\\2017_change3 - 0 -data\\data\\更改模型\\a.txt", "w");
		fprintf(fp, "%d \n", KML_ID[0].NO);
		for (int i = 0; i < KMLAll.size(); i++)
		{
			fprintf(fp, "%d %d %lf %lf %lf\n", KMLAll[i].Id, KMLAll[i].FId, KMLAll[i].x, KMLAll[i].y, KMLAll[i].z);
			
		}
		fclose(fp);
		MessageBox::Show("LOAD polygon完成");
	}
}

		 //正常讀取全區LOD1 (KML)
		 void LoadLod1b(char filename[512])
		 {

			 char buf[25000] = { '\0' };
			 //FILE *fkml = fopen(filename, "r");
			 FILE *fkml;
			 err = fopen_s(&fkml, filename, "r");

			 char Build_NO[80] = "<td>FID</td>";
			 char check_coordinates[80] = "<coordinates>";
			 char check_coordinates2[80] = "<outerBoundaryIs>";
			 char check_coordinates3[80] = "<innerBoundaryIs>";
			 char check_coordinates4[80] = "<LinearRing>";

			 char *locNO = { '\0' };
			 char *loc = { '\0' };
			 char *locInner = { '\0' };
			 char *locInner2 = { '\0' };

			 int Qflag = 0;
			 int Kcount = 0;
			 int KMLTemp_count = 0;
			 int ta = 0;
			 int a = 0;
			 //int NumId = 0;
			 while (fgets(buf, 25000, fkml) != NULL) {

				 //字串搜尋 比對
				 locNO = strstr(buf, Build_NO);
				 if (locNO != NULL)
				 {
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 strcpy(getIDtemp.name, buf);
					 sscanf(buf, "			<td>%d</td>", &getIDtemp.NO);
					 //GetID getIDtemp;
					 KML_ID.push_back(getIDtemp);
				 }

				 //字串搜尋 比對
				 loc = strstr(buf, check_coordinates2);
				 if (loc != NULL)
				 {
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 //清空空白
					 //string *tmpStr = new string(buf);
					 //tmpStr->erase(tmpStr->begin(), tmpStr->begin() + tmpStr->find_first_not_of("								"));
					 ////strcpy(buf, tmpStr->c_str());
					 //strcpy_s(buf, sizeof(buf) / sizeof(buf[0]), tmpStr->c_str());

					 //std::printf("%s\n", buf);
					 Kcount = AnalysisKMLxyz(buf, getIDtemp.NO);
					 //KMLTemp_count = KMLTemp_count + 1;


					 Qflag = Qflag + 1;
					 ta = ta + 1;
				 }

				 //字串搜尋 比對
				 locInner = strstr(buf, check_coordinates3);
				 if (locInner != NULL)
				 {

					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 //清空空白
					 //string *tmpStr = new string(buf);
					 //tmpStr->erase(tmpStr->begin(), tmpStr->begin() + tmpStr->find_first_not_of("								"));
					 ////strcpy(buf, tmpStr->c_str());
					 //strcpy_s(buf, sizeof(buf) / sizeof(buf[0]), tmpStr->c_str());
					 //Kcount = AnalysisKMLxyzA(buf, getIDtemp.NO);

					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);
					 fgets(buf, 25000, fkml);

					 locInner2 = strstr(buf, check_coordinates4);
					 while (locInner2 != NULL)
					 {
						 fgets(buf, 25000, fkml);
						 fgets(buf, 25000, fkml);
						 //清空空白
						 string *tmpStr = new string(buf);
						 tmpStr->erase(tmpStr->begin(), tmpStr->begin() + tmpStr->find_first_not_of("								"));
						 //strcpy(buf, tmpStr->c_str());
						 strcpy_s(buf, sizeof(buf) / sizeof(buf[0]), tmpStr->c_str());
						 Kcount = AnalysisKMLxyzA(buf, getIDtemp.NO);

						 fgets(buf, 25000, fkml);
						 fgets(buf, 25000, fkml);
						 locInner2 = strstr(buf, check_coordinates4);
					 }


				 }

			 }
		 }

private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.kml)|*.kml";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		Filename01 = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));

		MessageBox::Show("LOAD 點雲完成");
	}
}



private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
	char *StartID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox9->Text)));
	int SiD = atoi(StartID);
	char *EndID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox10->Text)));
	double EiD = atof(EndID);

	//KMLAll
	for (int i = 0; i < (int)KMLAll.size(); i++)
	{
		if (KMLAll[i].Id == SiD)
		{
			KMLAll[i].z = EiD;
		}
	}

	//FILE *fp = fopen("G:\\程式區備份\\2017_change3 - 0 -data\\data\\更改模型\\b.txt", "w");
	//fprintf(fp, "%d \n", KML_ID[0].NO);
	//for (int i = 0; i < KMLAll.size(); i++)
	//{
	//	fprintf(fp, "%d %d %lf %lf %lf\n", KMLAll[i].Id, KMLAll[i].FId, KMLAll[i].x, KMLAll[i].y, KMLAll[i].z);

	//}
	//fclose(fp);
	char buf[128];
	sprintf(buf, "%d", KML_ID[0].NO);	
	strcat(Readbpcfile, buf);
	strcat(Readbpcfile, "_New.kml");
	FILE *fp = fopen(Readbpcfile, "w");
	fclose(fp);
	//ExportGRDLOD1_T02("G:\\程式區備份\\2017_change3 - 0 -data\\data\\更改模型\\a.kml");
	MessageBox::Show("完成");

}


		 void ExportGRDLOD1_T02(char filename[256])
		 {
			
			 //KML_BPCXYZ//KMLAll
			 FILE *pw = fopen(filename, "w");
			 int Checkcount = 0;
			 fprintf(pw, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			 fprintf(pw, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
			 fprintf(pw, "<Document>\n");
			 fprintf(pw, "	<name>KML_%d</name>\n", KML_ID[0].NO);
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
			 fprintf(pw, "		<name>KML_%d</name>\n", KML_ID[0].NO);
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
			 //ExportLOD1KML


			 //=================印出KML
			 fprintf(pw, "	<name>KML_%d</name>\n", KML_ID[0].NO);
			 fprintf(pw, "		<Placemark id=\"ID\">\n");
			 fprintf(pw, "			<description><![CDATA[<html xmlns:fo=\"http://www.w3.org/1999/XSL/Format\" xmlns:msxsl=\"urn:schemas-microsoft-com:xslt\">\n");
			 fprintf(pw, "			<head>\n");
			 fprintf(pw, "			<META http-equiv=\"Content - Type\" content=\"text / html\">\n");
			 fprintf(pw, "			<meta http-equiv=\"content - type\" content=\"text / html; charset = UTF - 8\">\n");
			 fprintf(pw, "			</head>\n");
			 fprintf(pw, "			<body style=\"margin:0px 0px 0px 0px; overflow:auto; background:#FFFFFF; \">\n");
			 fprintf(pw, "			<td>FID</td>\n\n");
			 fprintf(pw, "			<td>%d</td>\n", KML_ID[0].NO);
			 fprintf(pw, "			</html>]]></description>\n");
			 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
			 fprintf(pw, "			<MultiGeometry>\n");
			 fprintf(pw, "			<Polygon>\n");
			 fprintf(pw, "			<extrude>1</extrude>\n");
			 fprintf(pw, "			<altitudeMode>absolute</altitudeMode>\n");
			 fprintf(pw, "			<outerBoundaryIs>\n");
			 fprintf(pw, "			<LinearRing>\n");
			 fprintf(pw, "					<coordinates>\n");		


			 for (int g = 0; g < (int)KMLAll.size(); g++)
			 {
				 fprintf(pw, "%lf,%lf,%lf ", KMLAll[g].x, KMLAll[g].y, KMLAll[g].z);
			 }
			 fprintf(pw, " \n");

			 fprintf(pw, "					</coordinates>\n");
			 fprintf(pw, "			</LinearRing>\n");
			 fprintf(pw, "			</outerBoundaryIs>\n");
			 //KML_GrdXYZ
			 //for (int k = 0; k < KML_GrdXYZ.size(); k++)
			 //{

				//	 if (Checkcount == 0)
				//	 {
				//		 fprintf(pw, "			<innerBoundaryIs>\n");
				//		 fprintf(pw, "			<LinearRing>\n");
				//		 fprintf(pw, "					<coordinates>\n");
				//		 Checkcount = 1;
				//	 }

				//	 fprintf(pw, "%lf,%lf,%lf ", KML_GrdXYZ[k].x, KML_GrdXYZ[k].y, KML_GrdXYZ[k].z);

				// 
			 //}
			 //if (Checkcount == 1)
			 //{
				// fprintf(pw, "					</coordinates>\n");
				// fprintf(pw, "			</LinearRing>\n");
				// fprintf(pw, "			</innerBoundaryIs>\n");
				// Checkcount = 0;
			 //}


			 fprintf(pw, "			</Polygon>\n");
			 fprintf(pw, "			</MultiGeometry>\n");
			 fprintf(pw, "		</Placemark>\n");
			 //=================印出KML




			 //=================印出KML


			 //fprintf(pw, "	<name>KML_%d</name>\n", KML_ID[0].NO);

			 //int Hid = 0;
			 //for (int g = 0; g < (int)KMLAll.size(); g++)
			 //{
				// fprintf(pw, "		<Placemark id=\"ID\">\n");
				// fprintf(pw, "			<description>NO:%d\n", Hid);
				// fprintf(pw, "			%lf %lf %lf\n", KMLAll[g].x, KMLAll[g].y, KMLAll[g].z);
				// fprintf(pw, "			</description>\n");
				// fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
				// fprintf(pw, "			<Point>\n");
				// fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
				// fprintf(pw, "							<coordinates>\n");
				// fprintf(pw, "%lf,%lf,%lf \n",
				//	 KMLAll[g].x, KMLAll[g].y, KMLAll[g].z);
				// fprintf(pw, "							</coordinates>\n");
				// fprintf(pw, "			</Point>\n");
				// fprintf(pw, "		</Placemark>\n");

				// Hid = Hid + 1;
			 //}



			 ////KML_GrdXYZ
			 //for (int k = 0; k < KML_GrdXYZ.size(); k++)
			 //{
		

				//	 fprintf(pw, "		<Placemark id=\"ID\">\n");
				//	 fprintf(pw, "			<description>\n");
				//	 fprintf(pw, "			%lf %lf %lf\n", KML_GrdXYZ[k].x, KML_GrdXYZ[k].y, KML_GrdXYZ[k].z);
				//	 fprintf(pw, "			</description>\n");
				//	 fprintf(pw, "			<styleUrl>#PolyStyle001</styleUrl>\n");
				//	 fprintf(pw, "			<Point>\n");
				//	 fprintf(pw, "					<altitudeMode>absolute</altitudeMode>\n");
				//	 fprintf(pw, "							<coordinates>\n");
				//	 fprintf(pw, "%lf,%lf,%lf ", KML_GrdXYZ[k].x, KML_GrdXYZ[k].y, KML_GrdXYZ[k].z);
				//	 fprintf(pw, "							</coordinates>\n");
				//	 fprintf(pw, "			</Point>\n");
				//	 fprintf(pw, "		</Placemark>\n");



				// 
			 //}

			 //=================印出KML



			 fprintf(pw, "	</Folder>\n");
			 fprintf(pw, "</Document>\n");
			 fprintf(pw, "</kml>\n");
			 fclose(pw);
		 }





private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Reset();
		openFileDialog1->InitialDirectory = "";
		openFileDialog1->Filter = "(*.kml)|*.KML";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			PointAxyz.clear();

			char *D_filename = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
			String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
			char *D_path = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));
			String ^CSV_name = System::IO::Path::GetFileNameWithoutExtension(openFileDialog1->FileName);
			char *na = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_name)));
			
			strcpy(D_name, D_path);
			strcat(D_name,"\\");
			strcat(D_name, na);
			strcat(D_name, "_new.txt");			

			LoadpointcloudKML(D_filename);//PointToTran//01_ReadMeFile.txt		

			//
			
			MessageBox::Show("完成");

		}
}

		 void LoadpointcloudKML(char filename[512])
		 {
			 char buf[2500] = { '\0' };
			 char bufNO[512] = { '\0' };
			 FILE *fkml = fopen(filename, "r");

			 char check_coordinates[80] = "<coordinates>";
			 char *loc = { '\0' };

			 while (fgets(buf, 2500, fkml) != NULL) {
				 //字串搜尋 比對
				 loc = strstr(buf, check_coordinates);
				 if (loc != NULL)
				 {
					 fgets(bufNO, 512, fkml);		
					 sscanf(bufNO, "								%lf,%lf,%lf", &PointAtemp.x, &PointAtemp.y, &PointAtemp.z);
					 PointAxyz.push_back(PointAtemp);
				 }
			 }
			
			 

		 }

		 double GetavgH1()
		 {
			 double Maxh = 0, Mixh = 99999;
			 double avgH;
			 for (int w = 0; w < (int)PointAxyz.size(); w++)
			 {
				 if (Maxh < PointAxyz[w].z)Maxh = PointAxyz[w].z;
				 if (Mixh > PointAxyz[w].z)Mixh = PointAxyz[w].z;
			 }
			 double a01 = 0, a02 = 0, a03 = 0, a04 = 0, Havg = 0;
			 double a05 = 0, a06 = 0, a07 = 0, a08 = 0, a09 = 0, a010 = 0;
			 int a01c = 0, a02c = 0, a03c = 0, a04c = 0, a05c = 0;
			 int a06c = 0, a07c = 0, a08c = 0, a09c = 0, a010c = 0;
			 double a01H = 0, a02H = 0, a03H = 0, a04H = 0, a05H = 0;
			 double a06H = 0, a07H = 0, a08H = 0, a09H = 0, a010H = 0;
			 Havg = (Maxh - Mixh) / 10;

			 a01 = Mixh; a02 = Mixh + Havg; a03 = Mixh + Havg * 2; a04 = Mixh + Havg * 3;
			 a05 = Mixh + Havg * 4; a06 = Mixh + Havg * 5; a07 = Mixh + Havg * 6; a08 = Mixh + Havg * 7;
			 a09 = Mixh + Havg * 8; a010 = Mixh + Havg * 9;
			 a01 = Mixh; a02 = Mixh + Havg; a03 = Mixh + Havg * 2; a04 = Mixh + Havg * 3;
			 a05 = Mixh + Havg * 4; a06 = Mixh + Havg * 5; a07 = Mixh + Havg * 6; a08 = Mixh + Havg * 7;
			 a09 = Mixh + Havg * 8; a010 = Mixh + Havg * 9;

			 for (int w = 0; w < (int)PointAxyz.size(); w++)
			 {
				 if (PointAxyz[w].z >= a01  && PointAxyz[w].z < a02)					 {
					 a01c = a01c + 1;	a01H = a01H + PointAxyz[w].z;
				 }
				 else if (PointAxyz[w].z >= a02  && PointAxyz[w].z < a03)					 {
					 a02c = a02c + 1;	a02H = a02H + PointAxyz[w].z;
				 }
				 else if (PointAxyz[w].z >= a03  && PointAxyz[w].z < a04)					 {
					 a03c = a03c + 1;	a03H = a03H + PointAxyz[w].z;
				 }
				 else if (PointAxyz[w].z >= a04  && PointAxyz[w].z < a05)					 {
					 a04c = a04c + 1;	a04H = a04H + PointAxyz[w].z;
				 }
				 else if (PointAxyz[w].z >= a05  && PointAxyz[w].z < a06)					 {
					 a05c = a05c + 1;	a05H = a05H + PointAxyz[w].z;
				 }
				 else if (PointAxyz[w].z >= a06  && PointAxyz[w].z < a07)					 {
					 a06c = a06c + 1;	a06H = a06H + PointAxyz[w].z;
				 }
				 else if (PointAxyz[w].z >= a07  && PointAxyz[w].z < a08)					 {
					 a07c = a07c + 1;	a07H = a07H + PointAxyz[w].z;
				 }
				 else if (PointAxyz[w].z >= a08  && PointAxyz[w].z < a09)					 {
					 a08c = a08c + 1;	a08H = a08H + PointAxyz[w].z;
				 }
				 else if (PointAxyz[w].z >= a09  && PointAxyz[w].z < a010)					 {
					 a09c = a09c + 1;	a09H = a09H + PointAxyz[w].z;
				 }
				 else if (PointAxyz[w].z >= a09  && PointAxyz[w].z <= Maxh)					 {
					 a010c = a010c + 1;	a010H = a010H + PointAxyz[w].z;
				 }
			 }

			 if (a01c >= a02c){
				 if (a01c >= a03c)
					 if (a01c >= a04c)
						 if (a01c >= a05c)
							 if (a01c >= a06c)
								 if (a01c >= a07c)
									 if (a01c >= a08c)
										 if (a01c >= a09c)
											 if (a01c >= a010c)
												 avgH = a01H / a01c;
			 }
			 if (a02c >= a01c){
				 if (a02c >= a03c)
					 if (a02c >= a04c)
						 if (a02c >= a05c)
							 if (a02c >= a06c)
								 if (a02c >= a07c)
									 if (a02c >= a08c)
										 if (a02c >= a09c)
											 if (a02c >= a010c)
												 avgH = a02H / a02c;
			 }
			 if (a03c >= a01c){
				 if (a03c >= a02c)
					 if (a03c >= a04c)
						 if (a03c >= a05c)
							 if (a03c >= a06c)
								 if (a03c >= a07c)
									 if (a03c >= a08c)
										 if (a03c >= a09c)
											 if (a03c >= a010c)
												 avgH = a03H / a03c;
			 }
			 if (a04c >= a01c){
				 if (a04c >= a02c)
					 if (a04c >= a03c)
						 if (a04c >= a05c)
							 if (a04c >= a06c)
								 if (a04c >= a07c)
									 if (a04c >= a08c)
										 if (a04c >= a09c)
											 if (a04c >= a010c)
												 avgH = a04H / a04c;
			 }
			 if (a05c >= a01c){
				 if (a05c >= a02c)
					 if (a05c >= a03c)
						 if (a05c >= a04c)
							 if (a05c >= a06c)
								 if (a05c >= a07c)
									 if (a05c >= a08c)
										 if (a05c >= a09c)
											 if (a05c >= a010c)
												 avgH = a05H / a05c;
			 }
			 if (a06c >= a01c){
				 if (a06c >= a02c)
					 if (a06c >= a03c)
						 if (a06c >= a04c)
							 if (a06c >= a05c)
								 if (a06c >= a07c)
									 if (a06c >= a08c)
										 if (a06c >= a09c)
											 if (a06c >= a010c)
												 avgH = a06H / a06c;
			 }
			 if (a07c >= a01c){
				 if (a07c >= a02c)
					 if (a07c >= a03c)
						 if (a07c >= a04c)
							 if (a07c >= a05c)
								 if (a07c >= a06c)
									 if (a07c >= a08c)
										 if (a07c >= a09c)
											 if (a07c >= a010c)
												 avgH = a07H / a07c;
			 }
			 if (a08c >= a01c){
				 if (a08c >= a02c)
					 if (a08c >= a03c)
						 if (a08c >= a04c)
							 if (a08c >= a05c)
								 if (a08c >= a06c)
									 if (a08c >= a07c)
										 if (a08c >= a09c)
											 if (a08c >= a010c)
												 avgH = a08H / a08c;
			 }
			 if (a09c >= a01c){
				 if (a09c >= a02c)
					 if (a09c >= a03c)
						 if (a09c >= a04c)
							 if (a09c >= a05c)
								 if (a09c >= a06c)
									 if (a09c >= a07c)
										 if (a09c >= a08c)
											 if (a09c >= a010c)
												 avgH = a09H / a09c;
			 }
			 if (a010c >= a01c){
				 if (a010c >= a02c)
					 if (a010c >= a03c)
						 if (a010c >= a04c)
							 if (a010c >= a05c)
								 if (a010c >= a06c)
									 if (a010c >= a07c)
										 if (a010c >= a08c)
											 if (a010c >= a09c)
												 avgH = a010H / a010c;
			 }

			 return avgH;

		 }

private: System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) {
	//char *StartID = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(this->textBox11->Text)));
	//double SiD = atof(StartID);
	
	if ((int)PointAxyz.size() > 0 && (int)KMLAll1.size() > 0)
	{
		FILE *fp = fopen(D_name, "w");
		double avgH;
		avgH = GetavgH1();		

		fprintf(fp, "avg：%lf\n", avgH);

		double SiD = KMLAll1[0].z;		
		
		//fprintf(fp, "LOD 1高度：%lf\n", SiD);
		double Z = 0;
		double std1 = 0;
		int count = 0;

		for (int i = 0; i < PointAxyz.size(); i++)
		{
			if (abs(avgH - PointAxyz[i].z)<=1.5)
			{
				fprintf(fp, "點雲:%lf LOD 1:%lf 高程差:%lf \n", PointAxyz[i].x, SiD,PointAxyz[i].z - SiD);

				double Zi = PointAxyz[i].z - SiD;
				Z = Z + Zi;
				count = count + 1;
			}
			
			//fprintf(fp, "%lf %lf %lf 輸入高度：%lf 高程差：%lf\n", PointAxyz[i].x, PointAxyz[i].y, PointAxyz[i].z, SiD, PointAxyz[i].z - SiD);
		}
		Z = Z / count ;
		fprintf(fp, "平均高程差：%lf\n", Z);

		double Xz01 = 0;
		count = 0;
		for (int i = 0; i < PointAxyz.size(); i++)
		{
			if (abs(avgH - PointAxyz[i].z) <= 1.5)
			{
				double disZ = PointAxyz[i].z - SiD;
				disZ = disZ - Z;
				Xz01 = Xz01 + disZ*disZ;
				count = count + 1;
			}
			
			//fprintf(fp, "%lf %lf %lf 輸入高度：%lf 高程差：%lf\n", PointAxyz[i].x, PointAxyz[i].y, PointAxyz[i].z, SiD, PointAxyz[i].z - SiD);
		}
		Xz01 = Xz01 / (count-1);
		Xz01 = sqrt(Xz01);
		fprintf(fp, "差值標準差:%lf\n", Xz01);
		
		double Xz = 0;
		count = 0;
		for (int i = 0; i < PointAxyz.size(); i++)
		{
			if (abs(avgH - PointAxyz[i].z) <= 1.5)
			{
				double sum = PointAxyz[i].z - SiD;
				sum = sum*sum;
				Xz = Xz + sum;
				count = count + 1;
			}
			
			//std1 += ((PointAxyz[i].z - SiD) - Z)*((PointAxyz[i].z - SiD) - Z);
			//fprintf(fp, "%lf %lf %lf 輸入高度：%lf 高程差：%lf\n", PointAxyz[i].x, PointAxyz[i].y, PointAxyz[i].z, SiD, PointAxyz[i].z - SiD);
		}
		Xz = Xz / count;
		Xz = sqrt(Xz);

		fprintf(fp, "RMSE：%lf", Xz);
		fclose(fp);

		MessageBox::Show("完成");
	}



}


private: System::Void button23_Click(System::Object^  sender, System::EventArgs^  e) {

	openFileDialog1->Reset();
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "(*.kml)|*.KML";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{

		char *D_filename = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)));
		String ^CSV_path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		char *D_path = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_path)));
		String ^CSV_name = System::IO::Path::GetFileNameWithoutExtension(openFileDialog1->FileName);
		char *na = reinterpret_cast<char*>(static_cast<void*>(Marshal::StringToHGlobalAnsi(CSV_name)));
		//char D_name[256];
		//strcpy(D_name, D_path);
		//strcat(D_name, "\\");
		//strcat(D_name, na);
		//strcat(D_name, "_new.kml");

		KMLAll1.clear();
		KML_GrdXYZ1.clear();
		KML_ID.clear();
		

		LoadKML(D_filename);//PointToTran//01_ReadMeFile.txt
		char* str;

		
		MessageBox::Show("完成");

	}
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
					 Kcount = AnalysisPolygonxyzA(buf, getIDtemp.NO);

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
						 Kcount = AnalysisPolygonxyzA(buf, getIDtemp.NO);

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
								 
								 TKMLtemp.Qflag = KMLTemp_count;
								 TKMLtemp.FId = getIDtemp.NO;
								 KMLAll1.push_back(TKMLtemp);


							 }
						 }
					 }

				 }

			 }

			 return j;

		 }


		 //分析讀到的<coordinates>下一行中的所有的xyz(Loadkmlarray)
		 int AnalysisPolygonxyzA(char buf[25000], int KMLTemp_count)
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
								 KML_GrdXYZ1.push_back(TKMLtemp);

							 }
						 }
					 }

				 }

			 }

			 return j;

		 }


private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void button24_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}

