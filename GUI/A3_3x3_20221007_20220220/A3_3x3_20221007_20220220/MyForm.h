#pragma once

namespace A33x32022100720220220 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			for (int i = 1; i <= 9; ++i) {
				Button^ currentButton = dynamic_cast<Button^>(Controls[String::Format("button{0}", i)]);
				if (currentButton != nullptr) {
					currentButton->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
				}
			}
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;
		   String^ symbol;
		   int click = 0;
		   bool is_winner();
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(182, 172);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 68);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(285, 172);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 68);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(388, 172);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(97, 68);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(182, 246);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(97, 68);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(285, 246);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(97, 68);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(388, 246);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(97, 68);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(182, 320);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(97, 68);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(285, 320);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(97, 68);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(388, 320);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(97, 68);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(114, 36);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(131, 22);
			this->textBox1->TabIndex = 9;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(114, 64);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(131, 22);
			this->textBox2->TabIndex = 10;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 16);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Player1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 16);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Player2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(307, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 16);
			this->label3->TabIndex = 16;
			this->label3->Text = L"symbol";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(307, 33);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 16);
			this->label4->TabIndex = 15;
			this->label4->Text = L"symobl";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(379, 30);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(131, 22);
			this->textBox3->TabIndex = 14;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(379, 67);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(131, 22);
			this->textBox4->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(195, 454);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 16);
			this->label5->TabIndex = 18;
			this->label5->Text = L"The winner";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(285, 448);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(131, 22);
			this->textBox5->TabIndex = 17;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(195, 128);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(28, 16);
			this->label6->TabIndex = 20;
			this->label6->Text = L"turn";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(285, 122);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(131, 22);
			this->textBox6->TabIndex = 19;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(705, 578);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
 
private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e) {
	   Button^ clickedButton = dynamic_cast<Button^>(sender); // Get the button that was clicked
	   click++;
	   if (click == 1)
		   symbol = textBox3->Text;

	   clickedButton->Text = symbol;

	   if (symbol == textBox3->Text)
	   {
		   symbol = textBox4->Text;
		   clickedButton->BackColor = System::Drawing::Color::Red;
		   textBox6->Text = textBox2->Text;
	   }
	   else {
		   symbol = textBox3->Text;
		   clickedButton->BackColor = System::Drawing::Color::Blue;
		   textBox6->Text = textBox1->Text;
	   }

	   if (is_winner()) {

		   (click % 2 == 0) ? textBox5->Text = textBox2->Text : textBox5->Text = textBox1->Text;

		   for (int i = 1; i <= 9; ++i) {
			   Button^ currentButton = dynamic_cast<Button^>(Controls[String::Format("button{0}", i)]);
			   currentButton->Enabled = false;
		   }

	   }
	   else if (click == 9 && !is_winner()) {
		   textBox5->Text = "Draw!";
	   }
}
};
}
