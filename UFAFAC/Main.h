#pragma once
#include "Editor.h"
namespace UFAFAC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ quiterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exploreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aideToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::ComponentModel::IContainer^ components;
	protected:



	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->quiterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exploreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->quiterToolStripMenuItem,
					this->exploreToolStripMenuItem, this->aideToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1426, 24);
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
			// exploreToolStripMenuItem
			// 
			this->exploreToolStripMenuItem->Name = L"exploreToolStripMenuItem";
			this->exploreToolStripMenuItem->Size = System::Drawing::Size(58, 20);
			this->exploreToolStripMenuItem->Text = L"Explore";
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
			this->textBox1->Location = System::Drawing::Point(410, 314);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(621, 30);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(638, 398);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(188, 31);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Rechercher";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(9, 799);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(188, 31);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Ajouter du contenu";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1426, 839);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Main";
			this->Text = L"Main";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void quiterToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Close();
	}
	private: System::Void aideToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		UFAFAC::Editor form;
		Hide();
		form.ShowDialog();
	}
	};
}
