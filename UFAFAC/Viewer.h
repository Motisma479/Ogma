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
	/// Description résumée de Viewer
	/// </summary>
	public ref class Viewer : public System::Windows::Forms::Form
	{
	public:
		Viewer(void)
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
		~Viewer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ DocumentTitle;
	private: System::Windows::Forms::Label^ Author;
	private: System::Windows::Forms::Label^ Description;
	private: System::Windows::Forms::Label^ Date;
	private: System::Windows::Forms::Label^ Edition;
	private: System::Windows::Forms::Label^ Emplacement;
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
			this->DocumentTitle = (gcnew System::Windows::Forms::Label());
			this->Author = (gcnew System::Windows::Forms::Label());
			this->Description = (gcnew System::Windows::Forms::Label());
			this->Date = (gcnew System::Windows::Forms::Label());
			this->Edition = (gcnew System::Windows::Forms::Label());
			this->Emplacement = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// DocumentTitle
			// 
			this->DocumentTitle->AutoSize = true;
			this->DocumentTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24));
			this->DocumentTitle->Location = System::Drawing::Point(12, 19);
			this->DocumentTitle->Name = L"DocumentTitle";
			this->DocumentTitle->Size = System::Drawing::Size(223, 37);
			this->DocumentTitle->TabIndex = 0;
			this->DocumentTitle->Text = L"DocumentTitle";
			// 
			// Author
			// 
			this->Author->AutoSize = true;
			this->Author->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->Author->Location = System::Drawing::Point(19, 60);
			this->Author->Name = L"Author";
			this->Author->Size = System::Drawing::Size(82, 29);
			this->Author->TabIndex = 1;
			this->Author->Text = L"Author";
			// 
			// Description
			// 
			this->Description->AutoSize = true;
			this->Description->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Description->Location = System::Drawing::Point(20, 166);
			this->Description->Name = L"Description";
			this->Description->Size = System::Drawing::Size(89, 20);
			this->Description->TabIndex = 2;
			this->Description->Text = L"Description";
			// 
			// Date
			// 
			this->Date->AutoSize = true;
			this->Date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Date->Location = System::Drawing::Point(20, 98);
			this->Date->Name = L"Date";
			this->Date->Size = System::Drawing::Size(44, 20);
			this->Date->TabIndex = 3;
			this->Date->Text = L"Date";
			// 
			// Edition
			// 
			this->Edition->AutoSize = true;
			this->Edition->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Edition->Location = System::Drawing::Point(15, 418);
			this->Edition->Name = L"Edition";
			this->Edition->Size = System::Drawing::Size(58, 20);
			this->Edition->TabIndex = 4;
			this->Edition->Text = L"Edition";
			// 
			// Emplacement
			// 
			this->Emplacement->AutoSize = true;
			this->Emplacement->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Emplacement->Location = System::Drawing::Point(15, 456);
			this->Emplacement->Name = L"Emplacement";
			this->Emplacement->Size = System::Drawing::Size(107, 20);
			this->Emplacement->TabIndex = 5;
			this->Emplacement->Text = L"Emplacement";
			// 
			// Viewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(993, 594);
			this->Controls->Add(this->Emplacement);
			this->Controls->Add(this->Edition);
			this->Controls->Add(this->Date);
			this->Controls->Add(this->Description);
			this->Controls->Add(this->Author);
			this->Controls->Add(this->DocumentTitle);
			this->Name = L"Viewer";
			this->Text = L"Viewer";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
