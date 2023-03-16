#include "../Editor.h"
#include "../Main.h"
#include "../TagWindow.h"

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