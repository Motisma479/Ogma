#pragma once

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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->button1->Location = System::Drawing::Point(12, 985);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(251, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Annuler";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// Editor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1902, 1033);
			this->Controls->Add(this->button1);
			this->Name = L"Editor";
			this->Text = L"Editor";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
