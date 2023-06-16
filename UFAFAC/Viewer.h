#pragma once
#include "Main.h"
#include "DataStructure/DataBaseEntry.hpp"
#include "IsEditor.hpp"
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
	private: System::Windows::Forms::Button^ Supr;
	public:

	public:

	public:
		ref class Editor^ editor;

		void SetWindowName(System::String^ name);
		void SetAuthor(System::String^ author);
		void SetDate(System::String^ date);
		void SetDescription(System::String^ desc);
		void SetEdition(System::String^ edit);
		void SetEmplacement(System::String^ emp);
		void SetAttachedFiles(System::String^ file);
		void SetTags(System::String^ file);


		Main^ mainForm;
	private: System::Windows::Forms::Label^ AttachedFiles_Label;
	private: System::Windows::Forms::ListBox^ AttachedFiles_ListBox;
	private: System::Windows::Forms::RichTextBox^ Description;
	private: System::Windows::Forms::ListBox^ Tags_listBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ Edit;
	public:
		DataStructure::DataBaseEntry* selected;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Viewer::typeid));
			this->DocumentTitle = (gcnew System::Windows::Forms::Label());
			this->Author = (gcnew System::Windows::Forms::Label());
			this->Date = (gcnew System::Windows::Forms::Label());
			this->Edition = (gcnew System::Windows::Forms::Label());
			this->Emplacement = (gcnew System::Windows::Forms::Label());
			this->AttachedFiles_Label = (gcnew System::Windows::Forms::Label());
			this->AttachedFiles_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->Description = (gcnew System::Windows::Forms::RichTextBox());
			this->Tags_listBox = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Edit = (gcnew System::Windows::Forms::Button());
			this->Supr = (gcnew System::Windows::Forms::Button());
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
			this->Edition->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
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
			this->Emplacement->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Emplacement->AutoSize = true;
			this->Emplacement->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Emplacement->Location = System::Drawing::Point(15, 456);
			this->Emplacement->Name = L"Emplacement";
			this->Emplacement->Size = System::Drawing::Size(107, 20);
			this->Emplacement->TabIndex = 5;
			this->Emplacement->Text = L"Emplacement";
			// 
			// AttachedFiles_Label
			// 
			this->AttachedFiles_Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->AttachedFiles_Label->AutoSize = true;
			this->AttachedFiles_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->AttachedFiles_Label->Location = System::Drawing::Point(15, 489);
			this->AttachedFiles_Label->Name = L"AttachedFiles_Label";
			this->AttachedFiles_Label->Size = System::Drawing::Size(107, 20);
			this->AttachedFiles_Label->TabIndex = 6;
			this->AttachedFiles_Label->Text = L"Fichier(s) joint";
			// 
			// AttachedFiles_ListBox
			// 
			this->AttachedFiles_ListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->AttachedFiles_ListBox->FormattingEnabled = true;
			this->AttachedFiles_ListBox->Location = System::Drawing::Point(13, 522);
			this->AttachedFiles_ListBox->Name = L"AttachedFiles_ListBox";
			this->AttachedFiles_ListBox->Size = System::Drawing::Size(495, 69);
			this->AttachedFiles_ListBox->TabIndex = 7;
			this->AttachedFiles_ListBox->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Viewer::AttachedFiles_ListBox_MouseDoubleClick);
			// 
			// Description
			// 
			this->Description->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Description->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->Description->Location = System::Drawing::Point(19, 120);
			this->Description->Margin = System::Windows::Forms::Padding(2);
			this->Description->Name = L"Description";
			this->Description->ReadOnly = true;
			this->Description->Size = System::Drawing::Size(956, 296);
			this->Description->TabIndex = 19;
			this->Description->Text = L"";
			// 
			// Tags_listBox
			// 
			this->Tags_listBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Tags_listBox->FormattingEnabled = true;
			this->Tags_listBox->Location = System::Drawing::Point(514, 444);
			this->Tags_listBox->Name = L"Tags_listBox";
			this->Tags_listBox->Size = System::Drawing::Size(467, 147);
			this->Tags_listBox->TabIndex = 20;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(510, 418);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 20);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Tags :";
			// 
			// Edit
			// 
			this->Edit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Edit->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Edit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Edit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Edit->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->Edit->Location = System::Drawing::Point(899, 12);
			this->Edit->Name = L"Edit";
			this->Edit->Size = System::Drawing::Size(82, 35);
			this->Edit->TabIndex = 22;
			this->Edit->Text = L"Editer";
			this->Edit->UseVisualStyleBackColor = false;
			this->Edit->Click += gcnew System::EventHandler(this, &Viewer::Edit_Click);
			// 
			// Supr
			// 
			this->Supr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Supr->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Supr->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Supr->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Supr->Font = (gcnew System::Drawing::Font(L"Calibri", 13, System::Drawing::FontStyle::Bold));
			this->Supr->Location = System::Drawing::Point(791, 12);
			this->Supr->Name = L"Supr";
			this->Supr->Size = System::Drawing::Size(102, 35);
			this->Supr->TabIndex = 23;
			this->Supr->Text = L"Suprimer";
			this->Supr->UseVisualStyleBackColor = false;
			this->Supr->Click += gcnew System::EventHandler(this, &Viewer::Supr_Click);
			// 
			// Viewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(993, 594);
			this->Controls->Add(this->Supr);
			this->Controls->Add(this->Edit);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Tags_listBox);
			this->Controls->Add(this->Description);
			this->Controls->Add(this->AttachedFiles_ListBox);
			this->Controls->Add(this->AttachedFiles_Label);
			this->Controls->Add(this->Emplacement);
			this->Controls->Add(this->Edition);
			this->Controls->Add(this->Date);
			this->Controls->Add(this->Author);
			this->Controls->Add(this->DocumentTitle);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(1009, 633);
			this->Name = L"Viewer";
			this->Text = L"Viewer";
			this->Load += gcnew System::EventHandler(this, &Viewer::Viewer_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AttachedFiles_ListBox_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void Viewer_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void Edit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Supr_Click(System::Object^ sender, System::EventArgs^ e);
};
}
