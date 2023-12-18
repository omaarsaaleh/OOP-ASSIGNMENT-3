#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	ParamidTicTacToeGUI2022100720220220::MyForm frm;
	Application::Run(% frm);
}

bool ParamidTicTacToeGUI2022100720220220::MyForm::is_winner()
{
	//horizontal
	if (button2->Text == button3->Text && button2->Text == button4->Text && button2->Text != "")
		return true;
	else if (button5->Text == button6->Text && button5->Text == button7->Text && button5->Text != "")
		return true;
	else if (button6->Text == button7->Text && button6->Text == button8->Text && button6->Text != "")
		return true;
	else if (button7->Text == button8->Text && button7->Text == button9->Text && button7->Text != "")
		return true;
	// vertical
	else if (button1->Text == button3->Text && button1->Text == button7->Text && button1->Text != "")
		return true;
	// diagonals 
	else if (button1->Text == button4->Text && button1->Text == button9->Text && button1->Text != "")
		return true;
	else if (button1->Text == button2->Text && button1->Text == button5->Text && button1->Text != "")
		return true;
	else
		return false;
}

bool ParamidTicTacToeGUI2022100720220220::MyForm::is_draw()
{
	return (click == 9 && !is_winner());
}
