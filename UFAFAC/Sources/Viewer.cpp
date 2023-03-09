#include "../Viewer.h"
#include "Utils.h"

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
