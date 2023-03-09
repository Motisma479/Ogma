#include "../TagWindow.h"

System::Void UFAFAC::TagWindow::New_Click(System::Object^ sender, System::EventArgs^ e)
{
	listBox1->Items->Add(textBox1->Text);
}
