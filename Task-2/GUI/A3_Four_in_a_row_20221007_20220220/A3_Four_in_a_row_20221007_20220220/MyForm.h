#pragma once

namespace A3Fourinarow2022100720220220 {

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
			for (int i = 1; i <= 42; ++i) {
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
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ turn;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Button^ button29;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::Button^ button36;
	private: System::Windows::Forms::Button^ button37;
	private: System::Windows::Forms::Button^ button38;
	private: System::Windows::Forms::Button^ button39;
	private: System::Windows::Forms::Button^ button40;
	private: System::Windows::Forms::Button^ button41;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button42;
		   bool is_winner();
		   bool is_over();
		   int click = 0;
		   String^ symbol;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->turn = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(69, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Player1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(69, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Player2";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(165, 55);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(165, 104);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(325, 61);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"symbol";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(325, 110);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"symbol";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(416, 58);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(416, 104);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(225, 172);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(28, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"turn";
			// 
			// turn
			// 
			this->turn->Location = System::Drawing::Point(301, 166);
			this->turn->Name = L"turn";
			this->turn->Size = System::Drawing::Size(100, 22);
			this->turn->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(38, 227);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(72, 56);
			this->button1->TabIndex = 10;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(131, 227);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(72, 56);
			this->button2->TabIndex = 11;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(223, 227);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(72, 56);
			this->button3->TabIndex = 12;
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(328, 227);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(72, 56);
			this->button4->TabIndex = 13;
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(426, 227);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(72, 56);
			this->button5->TabIndex = 14;
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(525, 227);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(72, 56);
			this->button6->TabIndex = 15;
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(624, 227);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(72, 56);
			this->button7->TabIndex = 16;
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(38, 303);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(72, 56);
			this->button8->TabIndex = 17;
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(131, 303);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(72, 56);
			this->button9->TabIndex = 18;
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(223, 303);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(72, 56);
			this->button10->TabIndex = 19;
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(328, 303);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(72, 56);
			this->button11->TabIndex = 20;
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(426, 303);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(72, 56);
			this->button12->TabIndex = 21;
			this->button12->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(525, 303);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(72, 56);
			this->button13->TabIndex = 22;
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(624, 303);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(72, 56);
			this->button14->TabIndex = 23;
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(38, 382);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(72, 56);
			this->button15->TabIndex = 24;
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(131, 382);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(72, 56);
			this->button16->TabIndex = 25;
			this->button16->UseVisualStyleBackColor = true;
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(228, 382);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(72, 56);
			this->button17->TabIndex = 26;
			this->button17->UseVisualStyleBackColor = true;
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(328, 382);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(72, 56);
			this->button18->TabIndex = 27;
			this->button18->UseVisualStyleBackColor = true;
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(426, 382);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(72, 56);
			this->button19->TabIndex = 28;
			this->button19->UseVisualStyleBackColor = true;
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(525, 382);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(72, 56);
			this->button20->TabIndex = 29;
			this->button20->UseVisualStyleBackColor = true;
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(624, 382);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(72, 56);
			this->button21->TabIndex = 30;
			this->button21->UseVisualStyleBackColor = true;
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(38, 460);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(72, 56);
			this->button22->TabIndex = 37;
			this->button22->UseVisualStyleBackColor = true;
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(131, 460);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(72, 56);
			this->button23->TabIndex = 36;
			this->button23->UseVisualStyleBackColor = true;
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(228, 460);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(72, 56);
			this->button24->TabIndex = 35;
			this->button24->UseVisualStyleBackColor = true;
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(328, 460);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(72, 56);
			this->button25->TabIndex = 34;
			this->button25->UseVisualStyleBackColor = true;
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(426, 460);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(72, 56);
			this->button26->TabIndex = 33;
			this->button26->UseVisualStyleBackColor = true;
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(525, 460);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(72, 56);
			this->button27->TabIndex = 32;
			this->button27->UseVisualStyleBackColor = true;
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(624, 460);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(72, 56);
			this->button28->TabIndex = 31;
			this->button28->UseVisualStyleBackColor = true;
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(38, 537);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(72, 56);
			this->button29->TabIndex = 44;
			this->button29->UseVisualStyleBackColor = true;
			// 
			// button30
			// 
			this->button30->Location = System::Drawing::Point(131, 537);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(72, 56);
			this->button30->TabIndex = 43;
			this->button30->UseVisualStyleBackColor = true;
			// 
			// button31
			// 
			this->button31->Location = System::Drawing::Point(223, 537);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(72, 56);
			this->button31->TabIndex = 42;
			this->button31->UseVisualStyleBackColor = true;
			// 
			// button32
			// 
			this->button32->Location = System::Drawing::Point(328, 537);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(72, 56);
			this->button32->TabIndex = 41;
			this->button32->UseVisualStyleBackColor = true;
			// 
			// button33
			// 
			this->button33->Location = System::Drawing::Point(426, 537);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(72, 56);
			this->button33->TabIndex = 40;
			this->button33->UseVisualStyleBackColor = true;
			// 
			// button34
			// 
			this->button34->Location = System::Drawing::Point(525, 537);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(72, 56);
			this->button34->TabIndex = 39;
			this->button34->UseVisualStyleBackColor = true;
			// 
			// button35
			// 
			this->button35->Location = System::Drawing::Point(624, 537);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(72, 56);
			this->button35->TabIndex = 38;
			this->button35->UseVisualStyleBackColor = true;
			// 
			// button36
			// 
			this->button36->Location = System::Drawing::Point(38, 614);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(72, 56);
			this->button36->TabIndex = 51;
			this->button36->UseVisualStyleBackColor = true;
			// 
			// button37
			// 
			this->button37->Location = System::Drawing::Point(131, 614);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(72, 56);
			this->button37->TabIndex = 50;
			this->button37->UseVisualStyleBackColor = true;
			// 
			// button38
			// 
			this->button38->Location = System::Drawing::Point(228, 614);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(72, 56);
			this->button38->TabIndex = 49;
			this->button38->UseVisualStyleBackColor = true;
			// 
			// button39
			// 
			this->button39->Location = System::Drawing::Point(328, 614);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(72, 56);
			this->button39->TabIndex = 48;
			this->button39->UseVisualStyleBackColor = true;
			// 
			// button40
			// 
			this->button40->Location = System::Drawing::Point(426, 614);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(72, 56);
			this->button40->TabIndex = 47;
			this->button40->UseVisualStyleBackColor = true;
			// 
			// button41
			// 
			this->button41->Location = System::Drawing::Point(525, 614);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(72, 56);
			this->button41->TabIndex = 46;
			this->button41->UseVisualStyleBackColor = true;
			// 
			// button42
			// 
			this->button42->Location = System::Drawing::Point(624, 614);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(72, 56);
			this->button42->TabIndex = 45;
			this->button42->UseVisualStyleBackColor = true;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(300, 713);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 52;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(202, 719);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(76, 16);
			this->label6->TabIndex = 53;
			this->label6->Text = L"The Winner";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(742, 758);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button36);
			this->Controls->Add(this->button37);
			this->Controls->Add(this->button38);
			this->Controls->Add(this->button39);
			this->Controls->Add(this->button40);
			this->Controls->Add(this->button41);
			this->Controls->Add(this->button42);
			this->Controls->Add(this->button29);
			this->Controls->Add(this->button30);
			this->Controls->Add(this->button31);
			this->Controls->Add(this->button32);
			this->Controls->Add(this->button33);
			this->Controls->Add(this->button34);
			this->Controls->Add(this->button35);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button28);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->turn);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
 
	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ curruntButton = dynamic_cast<Button^>(sender);
		click++;
		if (click == 1)
			symbol = textBox3->Text;
		if (curruntButton->Text == "")
			curruntButton->Text = symbol;
			if (symbol == textBox3->Text) {
				symbol = textBox4->Text;
				curruntButton->BackColor = System::Drawing::Color::Red;
			}
			else {
				symbol = textBox3->Text;
				curruntButton->BackColor = System::Drawing::Color::Blue;
			}
			if (is_winner() || is_over()) {
				if (is_winner()) {
					if (click % 2 == 0)
						textBox6->Text = textBox2->Text;
					else
						textBox6->Text = textBox1->Text;
					for (int i = 1; i <= 42; i++) {
						Button^ currentButton = dynamic_cast<Button^>(Controls[String::Format("button{0}", i)]);
						if (currentButton->Text == "")
							currentButton->Enabled = false;
					}
				}
				else {
					textBox6->Text = "Draw!";
				}
	   }

	}

};
}
