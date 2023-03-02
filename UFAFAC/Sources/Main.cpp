#include "../Main.h"
#include "../Editor.h"
#include <string>

using namespace System;
using namespace System::Windows::Forms;
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
	System::String^ text = (*value).Text;
	System::Runtime::InteropServices::Marshal::StringToCoTaskMemUni(text);
	auto arr = text->ToCharArray();
	auto wtext = std::wstring();
	Utils::MarshalString(text, wtext);


	listBox1->Items->Clear();
	auto filename = Utils::GetFilesByName(wtext, tempDatas);
	for (auto i : filename) {
		listBox1->Items->Add(System::Runtime::InteropServices::
			Marshal::PtrToStringUni(IntPtr((void*)i.c_str())));
	}
}

System::Void UFAFAC::Main::aideToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Hide();
	
}
System::Void UFAFAC::Main::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
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
}
