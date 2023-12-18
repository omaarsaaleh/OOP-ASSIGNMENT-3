#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	A3Fourinarow2022100720220220::MyForm frm;
	Application::Run(% frm);
}

bool A3Fourinarow2022100720220220::MyForm::is_winner()
{
	// check the rows 
	for (int i = 0; i <= 35; i += 7) {
		int in_a_row = 1;
		for (int j = 1; j <= 4 ; j++)
		{
		   Button^ currentButton = dynamic_cast<Button^>(Controls[String::Format("button{0}", i + j)]); 
		   for (int k = 1; k <= 3; k++) {
			   Button^ currentButton1 = dynamic_cast<Button^>(Controls[String::Format("button{0}", i + j + k)]);
			   if (currentButton->Text == currentButton1->Text && currentButton->Text != "")
			   {
				   in_a_row++;
				   if (in_a_row == 4) return true;
			   }
			   else
				   in_a_row = 1;
		   }
		   

		}
			 
	}
	// check the columns
	for (int i = 1; i <= 6; i++) {
		int in_a_row = 1;
		for (int j = 0; j <= 14; j += 7) {
			Button^ currentButton = dynamic_cast<Button^>(Controls[String::Format("button{0}", i + j)]);
			for (int k = 7; k <= 21; k += 7) {
				Button^ currentButton1 = dynamic_cast<Button^>(Controls[String::Format("button{0}", i + j + k)]);
				if (currentButton->Text == currentButton1->Text && currentButton->Text != "")
				{
					in_a_row++;
					if (in_a_row == 4) return true;
				}
				else
					in_a_row = 1;
			}
		}
	}
	// check the diagonals 
	int arr[] = {1,2,3,4,8,9,10,11,15,16,17,18,4,5,6,7,11,12,13,14,18,19,20,21};
	int increament = 8;
	int cnt = 0;
	for (int i : arr) {
		if (i == 4)
			cnt++;
		if (cnt == 2)
			increament = 6;
		int in_a_row = 1;
		Button^ currentButton = dynamic_cast<Button^>(Controls[String::Format("button{0}",i)]);
		for (int j = 8; j <= 24 ; j += increament) {
			Button^ currentButton1 = dynamic_cast<Button^>(Controls[String::Format("button{0}", i + increament)]);
			if (currentButton->Text == currentButton1->Text && currentButton->Text != "") {
				in_a_row++;
				if (in_a_row == 4) return true;
			}
			else
				in_a_row = 1;
		}

	}
 

}

 

bool A3Fourinarow2022100720220220::MyForm::is_over()
{
	return click == 42;
}
