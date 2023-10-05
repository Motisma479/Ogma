#include "../Main.h"
#include "../Editor.h"
#include "../Viewer.h"
#include <filesystem>
#include <windows.h>
#include <shobjidl_core.h>
#include <string>
#include "DataStructure/DataBase.hpp"
#include "DataStructure/DataBaseEntry.hpp"
#include "DataStructure/TagManager.hpp"
#include "Parsing/FileParser.hpp"
#include "DataStructure/Tag.h"
#include "Parsing/FileCompressor.hpp"

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
	ShellExecute(0, 0, L"https://github.com/Motisma479/UFAFAC/wiki", 0, 0, SW_SHOW);
}

System::Void UFAFAC::Main::saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	auto& dataBase = DataStructure::DataBase::Get();
	Parsing::FileParser::SaveToFile(dataBase);
	Parsing::Serializer sr;
	Parsing::FileParser::WriteMainFile(dataBase, sr);
	time_t timeLocal;
	struct tm dateTime;
	char text[64];
	std::wstring name = L"Backups\\Database_backup_";
	_time64(&timeLocal);
	_localtime64_s(&dateTime, &timeLocal);
	strftime(text, 64, "%Y_%m_%d-%H_%M_%S", &dateTime);
	for (u8 i = 0; i < 64 && text[i]; ++i)
	{
		name.push_back(text[i]);
	}
	CreateDirectory(L"Backups", NULL);
	name.append(L".back");
	if (Parsing::FileCompressor::CompressToFile(sr, name))
	{
		::MessageBox(static_cast<HWND>(Handle.ToPointer()), (L"Fichier sauvegard� en tant que \"" + name + L"\".").c_str(), L"Information", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		::MessageBox(static_cast<HWND>(Handle.ToPointer()), (L"le fichier \"" + name + L"\" n'a pas pu �tre sauvegard�.").c_str(), L"Erreur", MB_OK | MB_ICONERROR);
	}
}

System::Void UFAFAC::Main::loadToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	OPENFILENAMEW ofn;
	WCHAR szFile[1024] = { 0 };
	ZeroMemory(&ofn, sizeof(OPENFILENAMEW));
	ofn.lStructSize = sizeof(OPENFILENAMEW);
	ofn.hwndOwner = static_cast<HWND>(Handle.ToPointer());
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = L"*.back";
	ofn.nFilterIndex = 1;
	auto string = std::filesystem::current_path().append(L"Backups").wstring();
	ofn.lpstrInitialDir = string.c_str();
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	if (GetOpenFileNameW(&ofn) == TRUE)
	{
		std::vector<u8> result;
		Parsing::FileCompressor::DecompressFromFile(result, ofn.lpstrFile);
		CloseEverything();
		DataStructure::DataBase::Delete();
		DataStructure::DataBase::Initialize();
		auto& dataBase = DataStructure::DataBase::Get();
		if (Parsing::FileParser::ReadMainFile(dataBase, Parsing::Deserializer(result)))
		{
			::MessageBox(static_cast<HWND>(Handle.ToPointer()), (std::wstring(L"Fichier \"") + ofn.lpstrFile + L"\" Charg� avec succ�s.").c_str(), L"Information", MB_OK | MB_ICONINFORMATION);
		}
		else
		{
			::MessageBox(static_cast<HWND>(Handle.ToPointer()), (std::wstring(L"le fichier \"") + ofn.lpstrFile + L"\" n'a pas pu �tre charg�.").c_str(), L"Erreur", MB_OK | MB_ICONERROR);
		}
	}
}

void UFAFAC::Main::CloseEverything()
{
	if (editor)
	{
		editor->Close();
	}
	if (viewer)
	{
		if (viewer->editor)
		{
			viewer->editor->Close();
		}
		viewer->Close();
	}
	listBox1->Items->Clear();
}
void UFAFAC::Main::RemoveSelectedFromList()
{
	listBox1->Items->Remove(listBox1->SelectedItem);
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
	instance = this;
	InitializeComponent();
	this->WindowState = FormWindowState::Maximized;
	DataStructure::DataBase::Initialize();
	auto& dataBase = DataStructure::DataBase::Get();
	FilterComboBox->SelectedIndex = 0;
	
	if (Parsing::FileParser::ReadFromFile(dataBase))
	{
		UpdateListBox(L"");
		return;
	}
	dataBase.CreateRandomTags(16);
	dataBase.CreateRandomEntries(16384);
	Parsing::FileParser::SaveToFile(dataBase);
	UpdateListBox(L"");
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
	auto entries = DataStructure::DataBase::Get().GetEntries();
	if (wtext.size() <= 0 && listBox1->Items->Count == entries.size())
		return;
	listBox1->Items->Clear();
	std::vector<u32> fileIds;

	std::wstring filterValue = Utils::SystemStringToStdWString(FilterComboBox->Text);
	FilterMode filter = StringToFilter(filterValue);

	if (wtext.size() == 0)
	{
		fileIds = entries;
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
		case FilterMode::Date: {
			DataStructure::DataBase& dataBase = DataStructure::DataBase::Get();
			DataStructure::Date fromDate;
			DataStructure::Date toDate;
			fromDate.day = static_cast<int>(FromDateDay->Value);
			fromDate.month = static_cast<int>(FromDateMonth->Value);
			fromDate.year = static_cast<int>(FromDateYear->Value);
			toDate.day = static_cast<int>(ToDateDay->Value);
			toDate.month = static_cast<int>(ToDateMonth->Value);
			toDate.year = static_cast<int>(ToDateYear->Value);

			auto date1 = dataBase.TimeStampFromDate(fromDate);
			auto date2 = dataBase.TimeStampFromDate(toDate);
			fileIds = DataStructure::DataBase::Get().GetEntriesByTimeStamp(date1, date2);
			break;
		}
		case FilterMode::Edition:
			fileIds = DataStructure::DataBase::Get().GetEntriesByEdition(wtext);
			break;
		case FilterMode::Location:
			fileIds = DataStructure::DataBase::Get().GetEntriesByLocation(wtext);
			break;
		case FilterMode::Description:
			fileIds = DataStructure::DataBase::Get().GetEntriesByDescription(wtext);
			break;
		case FilterMode::Tags: {
			std::vector<u32> tagsId;
			for (int i = 0; i < Tag_ListBox->Items->Count; i++)
			{
				tagsId.push_back(DataStructure::DataBase::Get().tags.FindTag(Utils::SystemStringToStdWString(Tag_ListBox->Items[i]->ToString())));
			}
			fileIds = DataStructure::DataBase::Get().GetEntriesByTags(tagsId, false);
			break;
		}
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

System::Void UFAFAC::Main::listBox1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (listBox1->IndexFromPoint(listBox1->PointToClient(Control::MousePosition)) == -1)
		listBox1->ClearSelected();
}

System::Void UFAFAC::Main::listBox1_DoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (viewer)
	{
		viewer->Close();
	}
	if (editor)
	{
		editor->Close();
	}
	if (listBox1->SelectedItem == nullptr) return;
	viewer = gcnew ref class Viewer();
	viewer->mainForm = this;
	viewer->Show();
	sender;
	viewer->SetWindowName(listBox1->SelectedItem->ToString());
	DataStructure::DataBaseEntry& entry = DataStructure::DataBase::Get().GetEntryByIndex(static_cast<ListBoxItem^>(listBox1->SelectedItem)->ID);
	viewer->selected = &entry;
	
	viewer->SetAuthor(Utils::StdWStringToSystemString(entry.authors));

	viewer->SetDate(DataStructure::DataBase::Get().DateFromTimeStamp(entry.date).ToString());

	viewer->SetDescription(Utils::StdWStringToSystemString(entry.description));

	viewer->SetEdition(Utils::StdWStringToSystemString(entry.edition));

	viewer->SetEmplacement(Utils::StdWStringToSystemString(entry.location));

	for (size_t i = 0; i < entry.files.size(); i++)
	{
		viewer->SetAttachedFiles(Utils::StdWStringToSystemString(entry.files[i]));
	}
	
	std::vector<::Tag>& tags = DataStructure::DataBase::Get().tags.GetTags();
	for (size_t i = 0; i < entry.tags.size(); i++)
	{
		viewer->SetTags(Utils::StdWStringToSystemString(tags[entry.tags[i]].GetName()));
	}
	
	/*viewer->SetDescription(Utils::StdWStringToSystemString(DataStructure::DataBase::Get().strings.GetString(entry.files)));*/
}

System::Void UFAFAC::Main::Main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Parsing::FileParser::SaveToFile(DataStructure::DataBase::Get());
	DataStructure::DataBase::Delete();
}

System::Void UFAFAC::Main::FilterComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::wstring filterValue = Utils::SystemStringToStdWString(FilterComboBox->Text);
	FilterMode filter = StringToFilter(filterValue);
	if (filter == FilterMode::Date)
	{
		textBox1->Hide();

		FromDateDay->Show();
		ToDateDay->Show();
		FromDateMonth->Show();
		ToDateMonth->Show();
		FromDateYear->Show();
		ToDateYear->Show();
		FromText->Show();
		ToText->Show();
		Tag_ListBox->Hide();
		AllTags_ListBox->Hide();
		Tag_TextBox->Hide();
	}
	else if (filter == FilterMode::Tags)
	{
		textBox1->Hide();
		FromDateDay->Hide();
		ToDateDay->Hide();
		FromDateMonth->Hide();
		ToDateMonth->Hide();
		FromDateYear->Hide();
		ToDateYear->Hide();
		FromText->Hide();
		ToText->Hide();

		Tag_ListBox->Show();
		AllTags_ListBox->Show();
		Tag_TextBox->Show();

		AllTags_ListBox->Items->Clear();
		for (auto&& tag : DataStructure::DataBase::Get().tags.GetTags())
		{
			AllTags_ListBox->Items->Add(Utils::StdWStringToSystemString(tag.GetName()));
		}
	}
	else
	{
		FromDateDay->Hide();
		ToDateDay->Hide();
		FromDateMonth->Hide();
		ToDateMonth->Hide();
		FromDateYear->Hide();
		ToDateYear->Hide();
		FromText->Hide();
		ToText->Hide();
		Tag_ListBox->Hide();
		AllTags_ListBox->Hide();
		Tag_TextBox->Hide();

		textBox1->Show();
	}
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
}

System::Void UFAFAC::Main::FromDateYear_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	UpdateListBox(L"Time");
}

System::Void UFAFAC::Main::FromDateMonth_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	UpdateListBox(L"Time");
}

System::Void UFAFAC::Main::FromDateDay_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	UpdateListBox(L"Time");
}

System::Void UFAFAC::Main::ToDateYear_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	UpdateListBox(L"Time");
}

System::Void UFAFAC::Main::ToDateMonth_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	UpdateListBox(L"Time");
}

System::Void UFAFAC::Main::ToDateDay_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	UpdateListBox(L"Time");
}

System::Void UFAFAC::Main::AllTags_ListBox_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	if (!Tag_ListBox->Items->Contains(AllTags_ListBox->SelectedItem))
		Tag_ListBox->Items->Add(AllTags_ListBox->SelectedItem);

	UpdateListBox(L"Tags");
}

System::Void UFAFAC::Main::Tag_ListBox_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	Tag_ListBox->Items->Remove(Tag_ListBox->SelectedItem);
	UpdateListBox(L"Tags");
}

System::Void UFAFAC::Main::Tag_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{

	TextBox^ value = ((TextBox^)sender);
	auto wtext = Utils::SystemStringToStdWString(value->Text);

	AllTags_ListBox->Items->Clear();
	auto filename = DataStructure::DataBase::Get().tags.GetTagsByName(wtext);
	for (auto&& i : filename) {
		AllTags_ListBox->Items->Add(System::Runtime::InteropServices::Marshal::PtrToStringUni(IntPtr((void*)i.GetName().c_str())));
	}
}
