#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	A32022100720220220task25in5::MyForm frm;
	Application::Run(% frm);
}

bool A32022100720220220task25in5::MyForm::game_is_over()
{
    int cnt = 0;
    for (int i = 1; i <= 25; ++i) {
        Button^ currentButton = dynamic_cast<Button^>(Controls[String::Format("button{0}", i)]);
        if ( currentButton->Text == textBox4->Text || currentButton->Text == textBox5->Text)
            cnt++;
    }

    // Check if the number of buttons is equal to (total number of buttons - 1)
    if (cnt == 25)
        return true;

    return false;
}
 

bool A32022100720220220task25in5::MyForm::is_winner()
{
    // Check the rows 
    for (int j = 0; j <= 20; j+=5) {
        for (int i = 1; i <= 3; i++)
        {
            Button^ currentButton1 = dynamic_cast<Button^>(Controls[String::Format("button{0}",j + i)]);
            Button^ currentButton2 = dynamic_cast<Button^>(Controls[String::Format("button{0}",j + i + 1)]);
            Button^ currentButton3 = dynamic_cast<Button^>(Controls[String::Format("button{0}",j + i + 2)]);
            if (currentButton1->Text == currentButton2->Text && currentButton1->Text == currentButton3->Text)
            {
                if (currentButton1->Text == symbol)
                    score_X++;
                else
                    score_O++;
            }
        }
    }
    // Check the columes 
    for (int j = 0; j <= 10; j+=5) {
        for (int i = 1; i <= 5; i++)
        {
            Button^ currentButton1 = dynamic_cast<Button^>(Controls[String::Format("button{0}", j + i)]);
            Button^ currentButton2 = dynamic_cast<Button^>(Controls[String::Format("button{0}",j + i + 5)]);
            Button^ currentButton3 = dynamic_cast<Button^>(Controls[String::Format("button{0}",j + i + 10)]);
            if (currentButton1->Text == currentButton2->Text && currentButton1->Text == currentButton3->Text)
            {
                if (currentButton1->Text == symbol)
                    score_X++;
                else
                    score_O++;
            }
        }
    }
    int arri[] = {1,7,13,6,12,11,2,8,3};
    for (int i : arri) {
        Button^ currentButton1 = dynamic_cast<Button^>(Controls[String::Format("button{0}",i)]);
        Button^ currentButton2 = dynamic_cast<Button^>(Controls[String::Format("button{0}", 6 + i)]);
        Button^ currentButton3 = dynamic_cast<Button^>(Controls[String::Format("button{0}", 12 +  i)]);
        if (currentButton1->Text == currentButton2->Text && currentButton1->Text == currentButton3->Text)
        {
            if (currentButton1->Text == symbol)
                score_X++;
            else
                score_O++;
        }
    }
      int arri1[] = {5,9,13,10,14,15,4,8,3};
      for (int i : arri1) {
          Button^ currentButton1 = dynamic_cast<Button^>(Controls[String::Format("button{0}", i)]);
          Button^ currentButton2 = dynamic_cast<Button^>(Controls[String::Format("button{0}", 4 + i)]);
          Button^ currentButton3 = dynamic_cast<Button^>(Controls[String::Format("button{0}", 8 + i)]);
          if (currentButton1->Text == currentButton2->Text && currentButton1->Text == currentButton3->Text)
          {
              if (currentButton1->Text == symbol)
                  score_X++;
              else
                  score_O++;
          }
      }
    return score_X > score_O;
}

bool A32022100720220220task25in5::MyForm::is_draw()
{
    return score_O == score_X;
}
