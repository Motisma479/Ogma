#include "../Main.h"
#include "../Editor.h"
#include "../Viewer.h"
#include <string>
#include "DataStructure/DataBase.hpp"
#include "DataStructure/DataBaseEntry.hpp"
#include "DataStructure/TagManager.hpp"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	UFAFAC::Main form;
	Application::Run(% form);
}


System::Void UFAFAC::Main::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	TextBox^ value = ((TextBox^)sender);
	auto wtext = Utils::SystemStringToStdWString(value->Text);

	UpdateListBox(wtext);
}

System::Void UFAFAC::Main::aideToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Hide();
}
System::Void UFAFAC::Main::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (editor)
	{
		editor->Close();
	}
	if (viewer)
	{
		viewer->Close();
	}
	editor = gcnew ref class Editor();
	editor->mainForm = this;
	editor->Show();
}
System::Void UFAFAC::Main::quiterToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Close();
}

UFAFAC::Main::Main(void)
{
	InitializeComponent();
	this->WindowState = FormWindowState::Maximized;
	DataStructure::DataBase::Initialize();
	DataStructure::TagManager::Initialize();
	DataStructure::DataBase::Get().CreateRandomEntries(5000);
}

ref class ListBoxItem
{
public:
	int ID;
	System::String^ Text;

	ListBoxItem(int id, System::String^ text)
	{
		ID = id;
		Text = text;
	}

	virtual System::String^ ToString() override
	{
		return Text;
	}
};
void UFAFAC::Main::UpdateListBox(const std::wstring& wtext)
{
	listBox1->Items->Clear();
	auto fileIds = DataStructure::DataBase::Get().GetEntriesByName(wtext);
	for (auto&& i : fileIds) {
		auto file = DataStructure::DataBase::Get().GetEntryByIndex(i);
		auto string = Utils::StdWStringToSystemString(DataStructure::DataBase::Get().strings.GetString(file.name));
		ListBoxItem^ item = gcnew ListBoxItem(i, string);
		
		listBox1->Items->Add(item);
	}
}

System::Void UFAFAC::Main::listBox1_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (viewer)
	{
		viewer->Close();
	}
	if (editor)
	{
		editor->Close();
	}
	viewer = gcnew ref class Viewer();
	viewer->mainForm = this;
	viewer->Show();
	sender;
	viewer->SetWindowName(listBox1->SelectedItem->ToString());
	DataStructure::DataBaseEntry entry = DataStructure::DataBase::Get().GetEntryByIndex(static_cast<ListBoxItem^>(listBox1->SelectedItem)->ID);
	viewer->SetAuthor(Utils::StdWStringToSystemString(DataStructure::DataBase::Get().strings.GetString(entry.authors)));

	viewer->SetDate(DataStructure::DataBase::Get().DateFromTimeStamp(entry.date).ToString());

	viewer->SetDescription(Utils::StdWStringToSystemString(DataStructure::DataBase::Get().strings.GetString(entry.description)));

	viewer->SetEdition(Utils::StdWStringToSystemString(DataStructure::DataBase::Get().strings.GetString(entry.edition)));
	
	viewer->SetEmplacement(Utils::StdWStringToSystemString(DataStructure::DataBase::Get().strings.GetString(entry.location)));

	//TODO
	//Change deez line by the actual stuff.
	viewer->SetAttachedFiles("The_TEST"); 
	/*viewer->SetDescription(Utils::StdWStringToSystemString(DataStructure::DataBase::Get().strings.GetString(entry.files)));*/
}

System::Void UFAFAC::Main::Main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	DataStructure::DataBase::Delete();
	DataStructure::TagManager::Delete();
}
