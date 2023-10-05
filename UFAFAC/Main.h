#pragma once
#include "Utils.h"
#include "IsEditor.hpp"

#include <iostream>
#include <vector>
#include <string>

static std::vector<std::wstring> tempDatas
{
	L"Test1",
	L"Test2",
	L"Amogus",
	L"JFIEWUBFAI",
};

namespace UFAFAC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Main : public System::Windows::Forms::Form
	{
	public:

		Main(void);
		void CloseEverything();
		void RemoveSelectedFromList();
	private: System::Windows::Forms::ListBox^ listBox1;
	public:

		ref class Editor^ editor;
	private: System::Windows::Forms::ComboBox^ FilterComboBox;
	private: System::Windows::Forms::NumericUpDown^ FromDateYear;
	private: System::Windows::Forms::NumericUpDown^ FromDateMonth;


	private: System::Windows::Forms::NumericUpDown^ FromDateDay;
	private: System::Windows::Forms::NumericUpDown^ ToDateYear;
	private: System::Windows::Forms::NumericUpDown^ ToDateMonth;
	private: System::Windows::Forms::NumericUpDown^ ToDateDay;
	private: System::Windows::Forms::Label^ FromText;
	private: System::Windows::Forms::Label^ ToText;
	private: System::Windows::Forms::ListBox^ Tag_ListBox;
	private: System::Windows::Forms::ListBox^ AllTags_ListBox;
	private: System::Windows::Forms::TextBox^ Tag_TextBox;
	private: System::Windows::Forms::ToolStripMenuItem^ fichierToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exporterUneSauvegardeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ importerUneSauvegardeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ quiterToolStripMenuItem1;




	public:

	public:

	public:
		ref class Viewer^ viewer;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:

	public:
		static Main^ instance = nullptr;
	protected:
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip1;


	private: System::Windows::Forms::ToolStripMenuItem^ aideToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Button^ button2;
	private: System::ComponentModel::IContainer^ components;
	protected:



	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fichierToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exporterUneSauvegardeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importerUneSauvegardeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->quiterToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->FilterComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->FromDateYear = (gcnew System::Windows::Forms::NumericUpDown());
			this->FromDateMonth = (gcnew System::Windows::Forms::NumericUpDown());
			this->FromDateDay = (gcnew System::Windows::Forms::NumericUpDown());
			this->ToDateYear = (gcnew System::Windows::Forms::NumericUpDown());
			this->ToDateMonth = (gcnew System::Windows::Forms::NumericUpDown());
			this->ToDateDay = (gcnew System::Windows::Forms::NumericUpDown());
			this->FromText = (gcnew System::Windows::Forms::Label());
			this->ToText = (gcnew System::Windows::Forms::Label());
			this->Tag_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->AllTags_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->Tag_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FromDateYear))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FromDateMonth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FromDateDay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ToDateYear))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ToDateMonth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ToDateDay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fichierToolStripMenuItem,
					this->aideToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1021, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fichierToolStripMenuItem
			// 
			this->fichierToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->exporterUneSauvegardeToolStripMenuItem,
					this->importerUneSauvegardeToolStripMenuItem, this->toolStripMenuItem1, this->quiterToolStripMenuItem1
			});
			this->fichierToolStripMenuItem->Name = L"fichierToolStripMenuItem";
			this->fichierToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->fichierToolStripMenuItem->Text = L"Fichier";
			// 
			// exporterUneSauvegardeToolStripMenuItem
			// 
			this->exporterUneSauvegardeToolStripMenuItem->Name = L"exporterUneSauvegardeToolStripMenuItem";
			this->exporterUneSauvegardeToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->exporterUneSauvegardeToolStripMenuItem->Text = L"Exporter une sauvegarde";
			this->exporterUneSauvegardeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::saveToolStripMenuItem_Click);
			// 
			// importerUneSauvegardeToolStripMenuItem
			// 
			this->importerUneSauvegardeToolStripMenuItem->Name = L"importerUneSauvegardeToolStripMenuItem";
			this->importerUneSauvegardeToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->importerUneSauvegardeToolStripMenuItem->Text = L"Importer une sauvegarde";
			this->importerUneSauvegardeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::loadToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(203, 6);
			// 
			// quiterToolStripMenuItem1
			// 
			this->quiterToolStripMenuItem1->Name = L"quiterToolStripMenuItem1";
			this->quiterToolStripMenuItem1->Size = System::Drawing::Size(206, 22);
			this->quiterToolStripMenuItem1->Text = L"Quiter";
			this->quiterToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Main::quiterToolStripMenuItem_Click);
			// 
			// aideToolStripMenuItem
			// 
			this->aideToolStripMenuItem->Name = L"aideToolStripMenuItem";
			this->aideToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->aideToolStripMenuItem->Text = L"Aide";
			this->aideToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::aideToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->textBox1->Location = System::Drawing::Point(208, 221);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(580, 30);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Main::textBox1_TextChanged);
			this->textBox1->Enter += gcnew System::EventHandler(this, &Main::textBox1_Enter);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Main::textBox1_KeyPress);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(9, 717);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(188, 31);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Ajouter du contenu";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(50, 252);
			this->listBox1->Margin = System::Windows::Forms::Padding(2);
			this->listBox1->MaximumSize = System::Drawing::Size(6550, 4070);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(915, 446);
			this->listBox1->TabIndex = 4;
			this->listBox1->Click += gcnew System::EventHandler(this, &Main::listBox1_Click);
			this->listBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::listBox1_DoubleClick);
			// 
			// FilterComboBox
			// 
			this->FilterComboBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->FilterComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->FilterComboBox->FormattingEnabled = true;
			this->FilterComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Nom", L"Auteurs", L"Date", L"Emplacement",
					L"Edition", L"Description", L"Tags"
			});
			this->FilterComboBox->Location = System::Drawing::Point(793, 226);
			this->FilterComboBox->Name = L"FilterComboBox";
			this->FilterComboBox->Size = System::Drawing::Size(89, 21);
			this->FilterComboBox->TabIndex = 5;
			this->FilterComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::FilterComboBox_SelectedIndexChanged);
			// 
			// FromDateYear
			// 
			this->FromDateYear->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->FromDateYear->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->FromDateYear->Location = System::Drawing::Point(316, 218);
			this->FromDateYear->Margin = System::Windows::Forms::Padding(2);
			this->FromDateYear->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6000, 0, 0, 0 });
			this->FromDateYear->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, System::Int32::MinValue });
			this->FromDateYear->Name = L"FromDateYear";
			this->FromDateYear->Size = System::Drawing::Size(67, 29);
			this->FromDateYear->TabIndex = 15;
			this->FromDateYear->ValueChanged += gcnew System::EventHandler(this, &Main::FromDateYear_ValueChanged);
			// 
			// FromDateMonth
			// 
			this->FromDateMonth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->FromDateMonth->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->FromDateMonth->Location = System::Drawing::Point(262, 218);
			this->FromDateMonth->Margin = System::Windows::Forms::Padding(2);
			this->FromDateMonth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->FromDateMonth->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->FromDateMonth->Name = L"FromDateMonth";
			this->FromDateMonth->Size = System::Drawing::Size(50, 29);
			this->FromDateMonth->TabIndex = 14;
			this->FromDateMonth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->FromDateMonth->ValueChanged += gcnew System::EventHandler(this, &Main::FromDateMonth_ValueChanged);
			// 
			// FromDateDay
			// 
			this->FromDateDay->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->FromDateDay->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->FromDateDay->Location = System::Drawing::Point(208, 218);
			this->FromDateDay->Margin = System::Windows::Forms::Padding(2);
			this->FromDateDay->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->FromDateDay->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->FromDateDay->Name = L"FromDateDay";
			this->FromDateDay->Size = System::Drawing::Size(50, 29);
			this->FromDateDay->TabIndex = 13;
			this->FromDateDay->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->FromDateDay->ValueChanged += gcnew System::EventHandler(this, &Main::FromDateDay_ValueChanged);
			// 
			// ToDateYear
			// 
			this->ToDateYear->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ToDateYear->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->ToDateYear->Location = System::Drawing::Point(715, 218);
			this->ToDateYear->Margin = System::Windows::Forms::Padding(2);
			this->ToDateYear->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6000, 0, 0, 0 });
			this->ToDateYear->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, System::Int32::MinValue });
			this->ToDateYear->Name = L"ToDateYear";
			this->ToDateYear->Size = System::Drawing::Size(74, 29);
			this->ToDateYear->TabIndex = 18;
			this->ToDateYear->ValueChanged += gcnew System::EventHandler(this, &Main::ToDateYear_ValueChanged);
			// 
			// ToDateMonth
			// 
			this->ToDateMonth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ToDateMonth->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->ToDateMonth->Location = System::Drawing::Point(661, 218);
			this->ToDateMonth->Margin = System::Windows::Forms::Padding(2);
			this->ToDateMonth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->ToDateMonth->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ToDateMonth->Name = L"ToDateMonth";
			this->ToDateMonth->Size = System::Drawing::Size(50, 29);
			this->ToDateMonth->TabIndex = 17;
			this->ToDateMonth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ToDateMonth->ValueChanged += gcnew System::EventHandler(this, &Main::ToDateMonth_ValueChanged);
			// 
			// ToDateDay
			// 
			this->ToDateDay->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ToDateDay->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->ToDateDay->Location = System::Drawing::Point(607, 218);
			this->ToDateDay->Margin = System::Windows::Forms::Padding(2);
			this->ToDateDay->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->ToDateDay->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ToDateDay->Name = L"ToDateDay";
			this->ToDateDay->Size = System::Drawing::Size(50, 29);
			this->ToDateDay->TabIndex = 16;
			this->ToDateDay->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ToDateDay->ValueChanged += gcnew System::EventHandler(this, &Main::ToDateDay_ValueChanged);
			// 
			// FromText
			// 
			this->FromText->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->FromText->AutoSize = true;
			this->FromText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->FromText->Location = System::Drawing::Point(203, 190);
			this->FromText->Name = L"FromText";
			this->FromText->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->FromText->Size = System::Drawing::Size(115, 26);
			this->FromText->TabIndex = 19;
			this->FromText->Text = L"À Partir de";
			// 
			// ToText
			// 
			this->ToText->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ToText->AutoSize = true;
			this->ToText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->ToText->Location = System::Drawing::Point(703, 190);
			this->ToText->Name = L"ToText";
			this->ToText->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->ToText->Size = System::Drawing::Size(86, 26);
			this->ToText->TabIndex = 20;
			this->ToText->Text = L"Jusqu\'à";
			// 
			// Tag_ListBox
			// 
			this->Tag_ListBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Tag_ListBox->FormattingEnabled = true;
			this->Tag_ListBox->Location = System::Drawing::Point(496, 100);
			this->Tag_ListBox->Margin = System::Windows::Forms::Padding(2);
			this->Tag_ListBox->Name = L"Tag_ListBox";
			this->Tag_ListBox->Size = System::Drawing::Size(293, 147);
			this->Tag_ListBox->TabIndex = 28;
			this->Tag_ListBox->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::Tag_ListBox_MouseDoubleClick);
			// 
			// AllTags_ListBox
			// 
			this->AllTags_ListBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->AllTags_ListBox->FormattingEnabled = true;
			this->AllTags_ListBox->Location = System::Drawing::Point(208, 139);
			this->AllTags_ListBox->Margin = System::Windows::Forms::Padding(2);
			this->AllTags_ListBox->Name = L"AllTags_ListBox";
			this->AllTags_ListBox->Size = System::Drawing::Size(286, 108);
			this->AllTags_ListBox->TabIndex = 27;
			this->AllTags_ListBox->DoubleClick += gcnew System::EventHandler(this, &Main::AllTags_ListBox_DoubleClick);
			// 
			// Tag_TextBox
			// 
			this->Tag_TextBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Tag_TextBox->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->Tag_TextBox->Location = System::Drawing::Point(208, 100);
			this->Tag_TextBox->Margin = System::Windows::Forms::Padding(2);
			this->Tag_TextBox->Name = L"Tag_TextBox";
			this->Tag_TextBox->Size = System::Drawing::Size(286, 29);
			this->Tag_TextBox->TabIndex = 26;
			this->Tag_TextBox->TextChanged += gcnew System::EventHandler(this, &Main::Tag_TextBox_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(279, 43);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(509, 144);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 29;
			this->pictureBox1->TabStop = false;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1021, 757);
			this->Controls->Add(this->Tag_ListBox);
			this->Controls->Add(this->AllTags_ListBox);
			this->Controls->Add(this->Tag_TextBox);
			this->Controls->Add(this->ToText);
			this->Controls->Add(this->FromText);
			this->Controls->Add(this->ToDateYear);
			this->Controls->Add(this->ToDateMonth);
			this->Controls->Add(this->ToDateDay);
			this->Controls->Add(this->FromDateYear);
			this->Controls->Add(this->FromDateMonth);
			this->Controls->Add(this->FromDateDay);
			this->Controls->Add(this->FilterComboBox);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(1037, 796);
			this->Name = L"Main";
			this->Text = L"Ogma";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Main::Main_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FromDateYear))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FromDateMonth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FromDateDay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ToDateYear))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ToDateMonth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ToDateDay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void quiterToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void aideToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void loadToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void listBox1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void listBox1_DoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void textBox1_Enter(System::Object^ sender, System::EventArgs^ e);
	private: void UpdateListBox(const std::wstring& wtext);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void FilterComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);

	private: System::Void FromDateYear_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FromDateMonth_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FromDateDay_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToDateYear_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToDateMonth_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToDateDay_ValueChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void AllTags_ListBox_DoubleClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Tag_ListBox_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void Tag_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
