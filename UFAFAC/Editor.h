#pragma once
#include "Main.h"

namespace UFAFAC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Editor
	/// </summary>
	public ref class Editor : public System::Windows::Forms::Form
	{
	public:
		Editor(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		Main^ mainForm;

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Editor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::ListBox^ listBox3;

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->button1->Location = System::Drawing::Point(12, 862);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(251, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Annuler";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Editor::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->button2->Location = System::Drawing::Point(1279, 862);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(251, 38);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Sauvegarder";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->textBox1->Location = System::Drawing::Point(96, 28);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(473, 34);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(22, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 27);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Nom :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(22, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 27);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Auteur :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(22, 142);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 27);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Date : ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(22, 202);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 27);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Edition : ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(22, 275);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(154, 27);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Emplacement : ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(22, 348);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(133, 27);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Description : ";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->textBox2->Location = System::Drawing::Point(115, 80);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(313, 34);
			this->textBox2->TabIndex = 9;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->numericUpDown1->Location = System::Drawing::Point(100, 142);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 34);
			this->numericUpDown1->TabIndex = 10;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->numericUpDown2->Location = System::Drawing::Point(226, 140);
			this->numericUpDown2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 34);
			this->numericUpDown2->TabIndex = 11;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->numericUpDown3->Location = System::Drawing::Point(361, 140);
			this->numericUpDown3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, System::Int32::MinValue });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 34);
			this->numericUpDown3->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->label7->Location = System::Drawing::Point(127, 116);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(51, 27);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Jour";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->label8->Location = System::Drawing::Point(251, 116);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(57, 27);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Mois";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->label9->Location = System::Drawing::Point(384, 116);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(71, 27);
			this->label9->TabIndex = 15;
			this->label9->Text = L"Année";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->textBox3->Location = System::Drawing::Point(115, 199);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(313, 34);
			this->textBox3->TabIndex = 16;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->textBox4->Location = System::Drawing::Point(182, 272);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(313, 34);
			this->textBox4->TabIndex = 17;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->richTextBox1->Location = System::Drawing::Point(27, 377);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(564, 214);
			this->richTextBox1->TabIndex = 18;
			this->richTextBox1->Text = L"";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->button3->Location = System::Drawing::Point(27, 792);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(648, 38);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Joindre un fichier";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(27, 624);
			this->listBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(648, 164);
			this->listBox1->TabIndex = 20;
			// 
			// label10
			// 
			this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->label10->Location = System::Drawing::Point(726, 28);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(53, 27);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Tag :";
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->button4->Location = System::Drawing::Point(785, 24);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(245, 38);
			this->button4->TabIndex = 22;
			this->button4->Text = L"Modifier les Tags";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// textBox5
			// 
			this->textBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->textBox5->Location = System::Drawing::Point(731, 80);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(389, 34);
			this->textBox5->TabIndex = 23;
			// 
			// listBox2
			// 
			this->listBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 16;
			this->listBox2->Location = System::Drawing::Point(731, 128);
			this->listBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(389, 388);
			this->listBox2->TabIndex = 24;
			// 
			// listBox3
			// 
			this->listBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 16;
			this->listBox3->Location = System::Drawing::Point(1126, 80);
			this->listBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(389, 436);
			this->listBox3->TabIndex = 25;
			// 
			// Editor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1542, 911);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MinimumSize = System::Drawing::Size(1560, 958);
			this->Name = L"Editor";
			this->Text = L"Editor";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
