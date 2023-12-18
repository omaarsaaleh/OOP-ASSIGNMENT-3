#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
   A33x32022100720220220::MyForm frm;
    Application::Run(% frm);
}

bool A33x32022100720220220::MyForm::is_winner()
{
    if (button1->Text == button2->Text && button1->Text == button3->Text && button1->Text != "")
        return true;
    else if (button4->Text == button5->Text && button4->Text == button6->Text && button4->Text != "")
        return true;
    else if (button7->Text == button8->Text && button7->Text == button9->Text && button7->Text != "")
        return true;
    else if (button1->Text == button4->Text && button1->Text == button7->Text && button1->Text != "")
        return true;
    else if (button2->Text == button5->Text && button2->Text == button8->Text && button2->Text != "")
        return true;
    else if (button3->Text == button6->Text && button3->Text == button9->Text && button3->Text != "")
        return true;
    else if (button1->Text == button5->Text && button1->Text == button9->Text && button1->Text != "")
        return true;
    else if (button3->Text == button7->Text && button3->Text == button5->Text && button3->Text != "")
        return true;
    return false;
}
