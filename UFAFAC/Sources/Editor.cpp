#include "../Editor.h"
#include "../Main.h"
#include "../TagWindow.h"
#include "DataStructure/DataBase.hpp"

void UFAFAC::Editor::LoadAllTags()
{
	AllTags_ListBox->Items->Clear();
	for (auto&& tag : DataStructure::DataBase::Get().tags.GetTags())
	{
		AllTags_ListBox->Items->Add(Utils::StdWStringToSystemString(tag.GetName()));
	}
}

System::Void UFAFAC::Editor::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Hide();
}

System::Void UFAFAC::Editor::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (tagWindow)
		tagWindow->Close();
	tagWindow = gcnew TagWindow();
	tagWindow->editor = this;
	tagWindow->Show();
}

System::Void UFAFAC::Editor::Editor_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (tagWindow)
		tagWindow->Close();
	delete CurrentFile;
}

System::Void UFAFAC::Editor::Editor_Load(System::Object^ sender, System::EventArgs^ e)
{
	LoadAllTags();
	CurrentFile = new DataStructure::DataBaseEntry();
}

System::Void UFAFAC::Editor::Tag_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	TextBox^ value = ((TextBox^)sender);
	auto wtext = Utils::SystemStringToStdWString(value->Text);
	UpdateAllTagsListBox(wtext);
}

void UFAFAC::Editor::UpdateAllTagsListBox(const std::wstring& wtext)
{
	AllTags_ListBox->Items->Clear();
	auto filename = DataStructure::DataBase::Get().tags.GetTagsByName(wtext);
	for (auto&& i : filename) {
		AllTags_ListBox->Items->Add(System::Runtime::InteropServices::Marshal::PtrToStringUni(IntPtr((void*)i.GetName().c_str())));
	}
}

System::Void UFAFAC::Editor::AllTags_ListBox_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	//TODO : add To file
	if (!Tag_ListBox->Items->Contains(AllTags_ListBox->SelectedItem))
		Tag_ListBox->Items->Add(AllTags_ListBox->SelectedItem);
}

System::Void UFAFAC::Editor::AddFile_Button_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;

	openFileDialog->InitialDirectory = "C:\\";
	openFileDialog->Filter = "All files(*.*)|*.*";
	openFileDialog->FilterIndex = 1;
	openFileDialog->RestoreDirectory = true;
	openFileDialog->Multiselect = true;

	auto dr = openFileDialog->ShowDialog();
	if (dr == System::Windows::Forms::DialogResult::OK)
	{
		for (int i = 0; i < openFileDialog->FileNames->Length; i++)
		{
			JointFilesList->Items->Add(openFileDialog->FileNames[i]);
		}
	}
}

System::Void UFAFAC::Editor::Tag_ListBox_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	//TODO : Remove To file
	Tag_ListBox->Items->Remove(Tag_ListBox->SelectedItem);
}

System::Void UFAFAC::Editor::JointFilesList_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	JointFilesList->Items->Remove(JointFilesList->SelectedItem);
}
