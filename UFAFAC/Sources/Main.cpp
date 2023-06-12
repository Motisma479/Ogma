#include "../Main.h"
#include "../Editor.h"
#include "../Viewer.h"
#include <string>
#include "DataStructure/DataBase.hpp"
#include "DataStructure/DataBaseEntry.hpp"
#include "DataStructure/TagManager.hpp"
#include "Parsing/FileParser.hpp"

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
	auto& dataBase = DataStructure::DataBase::Get();
	Parsing::FileParser parser;
	/*
	parser.ReadTags(dataBase.tags);
	parser.ReadMainFile(dataBase);
	*/
	dataBase.CreateRandomTags(16);
	dataBase.CreateRandomEntries(16384);
	parser.WriteMainFile(dataBase);
	parser.WriteTags(dataBase.tags);
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
	std::vector<u32> fileIds;
	if (wtext.size() == 0)
	{
		fileIds = DataStructure::DataBase::Get().GetEntries();
	}
	else
	{
		fileIds = DataStructure::DataBase::Get().GetEntriesByName(wtext);
	}
	for (auto&& i : fileIds) {
		auto file = DataStructure::DataBase::Get().GetEntryByIndex(i);
		auto string = Utils::StdWStringToSystemString(file.name);
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
	viewer->SetAuthor(Utils::StdWStringToSystemString(entry.authors));

	viewer->SetDate(DataStructure::DataBase::Get().DateFromTimeStamp(entry.date).ToString());

	viewer->SetDescription(Utils::StdWStringToSystemString(entry.description));

	viewer->SetEdition(Utils::StdWStringToSystemString(entry.edition));
	
	viewer->SetEmplacement(Utils::StdWStringToSystemString(entry.location));

	//TODO
	//Change deez line by the actual stuff.
	for (size_t i = 0; i < entry.files.size(); i++)
	{
		viewer->SetAttachedFiles(Utils::StdWStringToSystemString(entry.files[i]));
	}
	/*viewer->SetDescription(Utils::StdWStringToSystemString(DataStructure::DataBase::Get().strings.GetString(entry.files)));*/
}

System::Void UFAFAC::Main::Main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	DataStructure::DataBase::Delete();
}
