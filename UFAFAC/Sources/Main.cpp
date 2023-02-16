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