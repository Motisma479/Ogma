#pragma once

namespace UFAFAC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de TagWindow
	/// </summary>
	public ref class TagWindow : public System::Windows::Forms::Form
	{
	public:
		TagWindow(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		ref class Editor^ editor;
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~TagWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ New;
	private: System::Windows::Forms::Button^ Delete;
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->New = (gcnew System::Windows::Forms::Button());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(9, 10);
			this->listBox1->Margin = System::Windows::Forms::Padding(2);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(324, 121);
			this->listBox1->TabIndex = 0;
			// 
			// New
			// 
			this->New->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->New->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->New->Location = System::Drawing::Point(9, 254);
			this->New->Margin = System::Windows::Forms::Padding(2);
			this->New->Name = L"New";
			this->New->Size = System::Drawing::Size(66, 29);
			this->New->TabIndex = 2;
			this->New->Text = L"Nouveau";
			this->New->UseVisualStyleBackColor = false;
			this->New->Click += gcnew System::EventHandler(this, &TagWindow::New_Click);
			// 
			// Delete
			// 
			this->Delete->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Delete->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Delete->Location = System::Drawing::Point(248, 254);
			this->Delete->Margin = System::Windows::Forms::Padding(2);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(78, 29);
			this->Delete->TabIndex = 3;
			this->Delete->Text = L"Suprimer";
			this->Delete->UseVisualStyleBackColor = false;
			this->Delete->Click += gcnew System::EventHandler(this, &TagWindow::Delete_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->textBox1->Location = System::Drawing::Point(9, 176);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(318, 27);
			this->textBox1->TabIndex = 4;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TagWindow::textBox1_KeyPress);
			// 
			// TagWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 292);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Delete);
			this->Controls->Add(this->New);
			this->Controls->Add(this->listBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"TagWindow";
			this->Text = L"TagWindow";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TagWindow::TagWindow_FormClosing);
			this->Load += gcnew System::EventHandler(this, &TagWindow::TagWindow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void New_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TagWindow_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: bool AddTag();
	private: System::Void TagWindow_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}
