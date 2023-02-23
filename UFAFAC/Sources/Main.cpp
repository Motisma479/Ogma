#include "../Main.h"

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

	std::vector<std::string> tempDatas;
	tempDatas.push_back("Test1");
	tempDatas.push_back("Test2");
	tempDatas.push_back("amogus");
	tempDatas.push_back("fauygw");
	auto filename = Utils::GetFilesByName(Utils::SystemStringToStdString(text), tempDatas);
}
