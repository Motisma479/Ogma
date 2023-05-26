#include "../Viewer.h"
#include "Utils.h"
#include "../Editor.h"
#include "../Main.h"
#include "../TagWindow.h"
#include <windows.h>
#include <stdlib.h>
#include <filesystem>

void UFAFAC::Viewer::SetWindowName(System::String^ name)
{
	this->Text = name;
	this->DocumentTitle->Text = name;
}

void UFAFAC::Viewer::SetAuthor(System::String^ author)
{
	this->Author->Text = author;
}

void UFAFAC::Viewer::SetDate(System::String^ date)
{
	this->Date->Text = date;
}

void UFAFAC::Viewer::SetDescription(System::String^ desc)
{
	this->Description->Text = desc;
}

void UFAFAC::Viewer::SetEdition(System::String^ edit)
{
	this->Edition->Text = edit;
}

void UFAFAC::Viewer::SetEmplacement(System::String^ emp)
{
	this->Emplacement->Text = emp;
}

void UFAFAC::Viewer::SetAttachedFiles(System::String^ file)
{
		this->AttachedFiles_ListBox->Items->Add(file);
}

System::Void UFAFAC::Viewer::AttachedFiles_ListBox_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	auto value = ((System::String^)AttachedFiles_ListBox->SelectedItem);
	auto wtext = Utils::SystemStringToStdWString(value);

	// Open File with Path
	ShellExecuteW(NULL, L"open", wtext.c_str(), NULL, NULL, SW_SHOWDEFAULT);
}

System::Void UFAFAC::Viewer::Viewer_Load(System::Object^ sender, System::EventArgs^ e)
{

	//Debug
	auto path = std::filesystem::current_path().wstring();
	path = path.substr(0, path.find_last_of('\\')) + L"/UFAFAC.sln";
	auto string = Utils::StdWStringToSystemString(path);
	AttachedFiles_ListBox->Items->Add(string);
}