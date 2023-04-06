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
	DataStructure::DataBase::Get().CreateRandomEntries(200);
}

void UFAFAC::Main::UpdateListBox(const std::wstring& wtext)
{
	listBox1->Items->Clear();
	auto filename = DataStructure::DataBase::Get().GetEntriesByName(wtext);
	for (auto&& i : filename) {
		auto string = Utils::StdWStringToSystemString(DataStructure::DataBase::Get().strings.GetString(i->name));
		listBox1->Items->Add(string);
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

	viewer->SetWindowName(listBox1->SelectedItem->ToString());
}

System::Void UFAFAC::Main::Main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	DataStructure::DataBase::Delete();
	DataStructure::TagManager::Delete();
}
