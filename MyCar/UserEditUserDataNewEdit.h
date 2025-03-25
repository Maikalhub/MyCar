#pragma once

namespace Êóğñîâîéïğîåêòôğîíòıíä {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ UserEditUserDataNewEdit
	/// </summary>
	public ref class UserEditUserDataNewEdit : public System::Windows::Forms::Form
	{
	public:
		UserEditUserDataNewEdit(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~UserEditUserDataNewEdit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::ToolStripMenuItem^ îÏğîãğàììåToolStripMenuItem;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^ ïîòâåğäèòüToolStripMenuItem;
	private:
	public: System::Windows::Forms::Button^ button3;
	public: System::Windows::Forms::Button^ button2;
	public: System::Windows::Forms::TextBox^ textBox2;
	public: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ ğåãèñòğàöèÿToolStripMenuItem;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::ToolStripMenuItem^ ãëàâíîåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîëüçîâàòåëÿToolStripMenuItem;

	protected:

	public:

	private:




	public:

	private:

	public:









	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserEditUserDataNewEdit::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîòâåğäèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ğåãèñòğàöèÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->ãëàâíîåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîëüçîâàòåëÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Lavender;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(197, 132);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(311, 28);
			this->label1->TabIndex = 76;
			this->label1->Text = L"Ñèñòåìà àğåíäû àâòîìîáèëåé";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label3->Location = System::Drawing::Point(53, 268);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 33);
			this->label3->TabIndex = 75;
			this->label3->Text = L"Ïàğîëü";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label2->Location = System::Drawing::Point(54, 219);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 33);
			this->label2->TabIndex = 74;
			this->label2->Text = L"Ëîãèí";
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button4->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::Control;
			this->button4->Location = System::Drawing::Point(29, 382);
			this->button4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(110, 68);
			this->button4->TabIndex = 73;
			this->button4->Text = L"Íàçàä";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &UserEditUserDataNewEdit::button4_Click);
			// 
			// îÏğîãğàììåToolStripMenuItem
			// 
			this->îÏğîãğàììåToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ãëàâíîåToolStripMenuItem,
					this->ïîëüçîâàòåëÿToolStripMenuItem
			});
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Ìåíş";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->label4->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label4.Image")));
			this->label4->Location = System::Drawing::Point(241, 174);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(191, 33);
			this->label4->TabIndex = 77;
			this->label4->Text = L"Ââåäèòå äàííûå";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserEditUserDataNewEdit::âûõîäToolStripMenuItem_Click);
			// 
			// ïîòâåğäèòüToolStripMenuItem
			// 
			this->ïîòâåğäèòüToolStripMenuItem->Name = L"ïîòâåğäèòüToolStripMenuItem";
			this->ïîòâåğäèòüToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->ïîòâåğäèòüToolStripMenuItem->Text = L"Ïîòâåğäèòü";
			this->ïîòâåğäèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserEditUserDataNewEdit::ïîòâåğäèòüToolStripMenuItem_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::Control;
			this->button3->Location = System::Drawing::Point(547, 382);
			this->button3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 68);
			this->button3->TabIndex = 71;
			this->button3->Text = L"Âûõîä";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &UserEditUserDataNewEdit::button3_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button2->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::Control;
			this->button2->Location = System::Drawing::Point(288, 382);
			this->button2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 68);
			this->button2->TabIndex = 70;
			this->button2->Text = L"Ïîòâåğäèòü";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &UserEditUserDataNewEdit::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBox2->BackColor = System::Drawing::Color::GhostWhite;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiBold Condensed", 15.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox2->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->textBox2->Location = System::Drawing::Point(188, 267);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(320, 33);
			this->textBox2->TabIndex = 69;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBox1->BackColor = System::Drawing::Color::GhostWhite;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiBold Condensed", 15.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox1->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->textBox1->Location = System::Drawing::Point(188, 222);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(320, 33);
			this->textBox1->TabIndex = 68;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ğåãèñòğàöèÿToolStripMenuItem,
					this->ïîòâåğäèòüToolStripMenuItem, this->îÏğîãğàììåToolStripMenuItem, this->âûõîäToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(684, 24);
			this->menuStrip1->TabIndex = 72;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ğåãèñòğàöèÿToolStripMenuItem
			// 
			this->ğåãèñòğàöèÿToolStripMenuItem->Name = L"ğåãèñòğàöèÿToolStripMenuItem";
			this->ğåãèñòğàöèÿToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->ğåãèñòğàöèÿToolStripMenuItem->Text = L"Íàçàä";
			this->ğåãèñòğàöèÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserEditUserDataNewEdit::ğåãèñòğàöèÿToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(582, 36);
			this->button1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 36);
			this->button1->TabIndex = 78;
			this->button1->Text = L"Ãëàâíîå ìåíş";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &UserEditUserDataNewEdit::button1_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button5->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::SystemColors::Control;
			this->button5->Location = System::Drawing::Point(582, 78);
			this->button5->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(91, 37);
			this->button5->TabIndex = 79;
			this->button5->Text = L"Ìåíş ïîëüçîâàòåëÿ";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &UserEditUserDataNewEdit::button5_Click);
			// 
			// ãëàâíîåToolStripMenuItem
			// 
			this->ãëàâíîåToolStripMenuItem->Name = L"ãëàâíîåToolStripMenuItem";
			this->ãëàâíîåToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ãëàâíîåToolStripMenuItem->Text = L"Ãëàâíîå";
			this->ãëàâíîåToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserEditUserDataNewEdit::ãëàâíîåToolStripMenuItem_Click);
			// 
			// ïîëüçîâàòåëÿToolStripMenuItem
			// 
			this->ïîëüçîâàòåëÿToolStripMenuItem->Name = L"ïîëüçîâàòåëÿToolStripMenuItem";
			this->ïîëüçîâàòåëÿToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ïîëüçîâàòåëÿToolStripMenuItem->Text = L"Ïîëüçîâàòåëÿ";
			this->ïîëüçîâàòåëÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserEditUserDataNewEdit::ïîëüçîâàòåëÿToolStripMenuItem_Click);
			// 
			// UserEditUserDataNewEdit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(700, 500);
			this->MinimumSize = System::Drawing::Size(700, 500);
			this->Name = L"UserEditUserDataNewEdit";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ROADliteLiesing  v. 2.4 - User";
			this->Load += gcnew System::EventHandler(this, &UserEditUserDataNewEdit::UserEditUserDataNewEdit_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UserEditUserDataNewEdit_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ğåãèñòğàöèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïîòâåğäèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ãëàâíîåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïîëüçîâàòåëÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
