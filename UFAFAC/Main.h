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
	private: System::Windows::Forms::ListBox^ listBox1;
	public:

		ref class Editor^ editor;
	private: System::Windows::Forms::ComboBox^ FilterComboBox;
	public:

	public:

	public:
		ref class Viewer^ viewer;

	protected:
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ quiterToolStripMenuItem;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->quiterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->FilterComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->quiterToolStripMenuItem,
					this->aideToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(800, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// quiterToolStripMenuItem
			// 
			this->quiterToolStripMenuItem->Name = L"quiterToolStripMenuItem";
			this->quiterToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->quiterToolStripMenuItem->Text = L"Quitter";
			this->quiterToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::quiterToolStripMenuItem_Click);
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
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->textBox1->Location = System::Drawing::Point(98, 145);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(580, 30);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Main::textBox1_TextChanged);
			this->textBox1->Enter += gcnew System::EventHandler(this, &Main::textBox1_Enter);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Main::textBox1_KeyPress);
			this->textBox1->Leave += gcnew System::EventHandler(this, &Main::textBox1_Leave);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(9, 461);
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
			this->listBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(98, 176);
			this->listBox1->Margin = System::Windows::Forms::Padding(2);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(580, 108);
			this->listBox1->TabIndex = 4;
			this->listBox1->SelectedValueChanged += gcnew System::EventHandler(this, &Main::listBox1_SelectedValueChanged);
			// 
			// FilterComboBox
			// 
			this->FilterComboBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FilterComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->FilterComboBox->FormattingEnabled = true;
			this->FilterComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Nom", L"Auteurs", L"Date", L"Emplacement",
					L"Edition", L"Description", L"Tags"
			});
			this->FilterComboBox->Location = System::Drawing::Point(683, 150);
			this->FilterComboBox->Name = L"FilterComboBox";
			this->FilterComboBox->Size = System::Drawing::Size(89, 21);
			this->FilterComboBox->TabIndex = 5;
			this->FilterComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::FilterComboBox_SelectedIndexChanged);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 501);
			this->Controls->Add(this->FilterComboBox);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Main";
			this->Text = L"Main";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Main::Main_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void quiterToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void aideToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void listBox1_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_Enter(System::Object^ sender, System::EventArgs^ e);
	private: void UpdateListBox(const std::wstring& wtext);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void FilterComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
};
}
