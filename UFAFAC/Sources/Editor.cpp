#include "../Editor.h"
#include "../Main.h"
#include "../TagWindow.h"
#include "DataStructure/TagManager.hpp"

void UFAFAC::Editor::LoadAllTags()
{
	AllTags_ListBox->Items->Clear();
	for (auto&& tag : DataStructure::TagManager::Get().GetTags())
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
	auto filename = DataStructure::TagManager::Get().GetTagsByName(wtext);
	for (auto&& i : filename) {
		AllTags_ListBox->Items->Add(System::Runtime::InteropServices::Marshal::PtrToStringUni(IntPtr((void*)i.GetName().c_str())));
	}
}

System::Void UFAFAC::Editor::AllTags_ListBox_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{

}

System::Void UFAFAC::Editor::AddFile_Button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Stream^ myStream;
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;

	openFileDialog->InitialDirectory = "C:\\";
	openFileDialog->Filter = "All files(*.*)|*.*";
	openFileDialog->FilterIndex = 1;
	openFileDialog->RestoreDirectory = true;

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = openFileDialog->OpenFile()) != nullptr)
		{
			myStream->Close();
		}
	}
}