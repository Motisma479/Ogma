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
{/*
	TextBox^ value = ((TextBox^)sender);
	auto wtext = Utils::SystemStringToStdWString(value->Text);

	UpdateListBox(wtext);*/
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
	FilterComboBox->SelectedIndex = 0;
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
enum class FilterMode
{
	Name,
	Author,
	Date,
	Edition,
	Location,
	Description,
	Tags,
};

FilterMode StringToFilter(const std::wstring& wfilter)
{
	if (wfilter == L"Name")
		return FilterMode::Name;
	else if (wfilter == L"Auteurs")
		return FilterMode::Author;
	else if (wfilter == L"Date")
		return FilterMode::Date;
	else if (wfilter == L"Edition")
		return FilterMode::Edition;
	else if (wfilter == L"Description")
		return FilterMode::Description;
	else if (wfilter == L"Emplacement")
		return FilterMode::Location;
	else if (wfilter == L"Tags")
		return FilterMode::Tags;
	return FilterMode::Name;
}

void UFAFAC::Main::UpdateListBox(const std::wstring& wtext)
{
	listBox1->Items->Clear();
	std::vector<u32> fileIds;

	std::wstring filterValue = Utils::SystemStringToStdWString(FilterComboBox->Text);
	FilterMode filter = StringToFilter(filterValue);

	if (wtext.size() == 0)
	{
		fileIds = DataStructure::DataBase::Get().GetEntries();
	}
	else
	{
		switch (filter)
		{
		case FilterMode::Name:
			fileIds = DataStructure::DataBase::Get().GetEntriesByName(wtext);
			break;
		case FilterMode::Author:
			fileIds = DataStructure::DataBase::Get().GetEntriesByAuthor(wtext);
			break;
		case FilterMode::Date:
			break;
		case FilterMode::Edition:
			fileIds = DataStructure::DataBase::Get().GetEntriesByEdition(wtext);
			break;
		case FilterMode::Location:
			fileIds = DataStructure::DataBase::Get().GetEntriesByLocation(wtext);
			break;
		case FilterMode::Description:
			fileIds = DataStructure::DataBase::Get().GetEntriesByDescription(wtext);
			break;
		case FilterMode::Tags:
			//fileIds = DataStructure::DataBase::Get().GetEntriesByTags(wtext);
			break;
		default:
			break;
		}
	}


	for (auto&& i : fileIds) {
		auto file = DataStructure::DataBase::Get().GetEntryByIndex(i);
		System::String^ itemString;
		itemString = Utils::StdWStringToSystemString(file.name);
		ListBoxItem^ item = gcnew ListBoxItem(i, itemString);

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

System::Void UFAFAC::Main::FilterComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{

}

System::Void UFAFAC::Main::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	// Touche Entrer
	if (e->KeyChar == '\r')
	{
		TextBox^ value = ((TextBox^)sender);
		auto wtext = Utils::SystemStringToStdWString(value->Text);

		UpdateListBox(wtext);
	}
}

System::Void UFAFAC::Main::textBox1_Enter(System::Object^ sender, System::EventArgs^ e)
{
	listBox1->Show();
	/*UpdateListBox(L"");*/
}

System::Void UFAFAC::Main::textBox1_Leave(System::Object^ sender, System::EventArgs^ e)
{
	//listBox1->Hide();
}
