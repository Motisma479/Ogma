#include "../TagWindow.h"
#include "../Editor.h"
#include "DataStructure/TagManager.hpp"
#include "Utils.h"

System::Void UFAFAC::TagWindow::New_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddTag();
}

System::Void UFAFAC::TagWindow::Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!listBox1->SelectedItem)
		return;
	DataStructure::TagManager::Get().RemoveTag(Utils::SystemStringToStdWString(listBox1->SelectedItem->ToString()));
	listBox1->Items->Remove(listBox1->SelectedItem);
}

System::Void UFAFAC::TagWindow::TagWindow_Load(System::Object^ sender, System::EventArgs^ e)
{
	for (auto&& tag : DataStructure::TagManager::Get().GetTags())
	{
		listBox1->Items->Add(Utils::StdWStringToSystemString(tag.GetName()));
	}
}

System::Void UFAFAC::TagWindow::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (e->KeyChar == (char)Keys::Return)
	{
		e->Handled = AddTag();
	}
}

bool UFAFAC::TagWindow::AddTag()
{
	auto string = Utils::SystemStringToStdWString(textBox1->Text);
	if (string.empty() || DataStructure::TagManager::Get().IsInside(string))
		return false;
	DataStructure::TagManager::Get().AddTag(string);
	listBox1->Items->Add(textBox1->Text);
	textBox1->Text = "";
	return true;
}

System::Void UFAFAC::TagWindow::TagWindow_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	editor->LoadAllTags();
}
