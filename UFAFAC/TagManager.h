#pragma once

namespace UFAFAC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de TagManager
	/// </summary>
	public ref class TagManager : public System::Windows::Forms::Form
	{
	public:
		TagManager(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~TagManager()
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
		System::ComponentModel::Container ^components;

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
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(12, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(431, 148);
			this->listBox1->TabIndex = 0;
			// 
			// New
			// 
			this->New->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->New->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->New->Location = System::Drawing::Point(12, 312);
			this->New->Name = L"New";
			this->New->Size = System::Drawing::Size(88, 36);
			this->New->TabIndex = 2;
			this->New->Text = L"Nouveau";
			this->New->UseVisualStyleBackColor = false;
			// 
			// Delete
			// 
			this->Delete->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Delete->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Delete->Location = System::Drawing::Point(330, 312);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(104, 36);
			this->Delete->TabIndex = 3;
			this->Delete->Text = L"Suprimer";
			this->Delete->UseVisualStyleBackColor = false;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->textBox1->Location = System::Drawing::Point(12, 217);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(422, 32);
			this->textBox1->TabIndex = 4;
			// 
			// TagManager
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(446, 360);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Delete);
			this->Controls->Add(this->New);
			this->Controls->Add(this->listBox1);
			this->Name = L"TagManager";
			this->Text = L"TagManager";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
