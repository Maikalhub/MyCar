#pragma once

namespace Êóğñîâîéïğîåêòôğîíòıíä {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ UserEditUserDataNew
	/// </summary>
	public ref class UserEditUserDataNew : public System::Windows::Forms::Form
	{
	public:
		UserEditUserDataNew(void)
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
		~UserEditUserDataNew()
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

	private:
	public: System::Windows::Forms::Button^ button3;

	public: System::Windows::Forms::TextBox^ textBox2;
	public: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ ğåãèñòğàöèÿToolStripMenuItem;
	private: System::Windows::Forms::Label^ label5;
	public: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::ToolStripMenuItem^ ãëàâíîåToolStripMenuItem;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ ïîëüçîâàòåëüToolStripMenuItem;
	public: System::Windows::Forms::Button^ button1;
	private:
	public: System::Windows::Forms::Button^ button5;
	private:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserEditUserDataNew::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ãëàâíîåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîëüçîâàòåëüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ğåãèñòğàöèÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Lavender;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(212, 118);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(261, 39);
			this->label1->TabIndex = 76;
			this->label1->Text = L"Èçìåíåíèå äàííûõ";
			this->label1->Click += gcnew System::EventHandler(this, &UserEditUserDataNew::label1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label3->Location = System::Drawing::Point(52, 260);
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
			this->label2->Location = System::Drawing::Point(53, 211);
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
			this->button4->Location = System::Drawing::Point(28, 374);
			this->button4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(110, 68);
			this->button4->TabIndex = 73;
			this->button4->Text = L"Èçìåíèòü äàííûå";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &UserEditUserDataNew::button4_Click);
			// 
			// îÏğîãğàììåToolStripMenuItem
			// 
			this->îÏğîãğàììåToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ãëàâíîåToolStripMenuItem,
					this->ïîëüçîâàòåëüToolStripMenuItem
			});
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Ìåíş";
			// 
			// ãëàâíîåToolStripMenuItem
			// 
			this->ãëàâíîåToolStripMenuItem->Name = L"ãëàâíîåToolStripMenuItem";
			this->ãëàâíîåToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->ãëàâíîåToolStripMenuItem->Text = L"Ãëàâíîå";
			this->ãëàâíîåToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserEditUserDataNew::ãëàâíîåToolStripMenuItem_Click);
			// 
			// ïîëüçîâàòåëüToolStripMenuItem
			// 
			this->ïîëüçîâàòåëüToolStripMenuItem->Name = L"ïîëüçîâàòåëüToolStripMenuItem";
			this->ïîëüçîâàòåëüToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->ïîëüçîâàòåëüToolStripMenuItem->Text = L"Ïîëüçîâàòåëü";
			this->ïîëüçîâàòåëüToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserEditUserDataNew::ïîëüçîâàòåëüToolStripMenuItem_Click);
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
			this->label4->Location = System::Drawing::Point(256, 166);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(160, 33);
			this->label4->TabIndex = 77;
			this->label4->Text = L"Âàøè äàííûå";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserEditUserDataNew::âûõîäToolStripMenuItem_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::Control;
			this->button3->Location = System::Drawing::Point(546, 374);
			this->button3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 68);
			this->button3->TabIndex = 71;
			this->button3->Text = L"Âûõîä";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &UserEditUserDataNew::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBox2->BackColor = System::Drawing::Color::GhostWhite;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiBold Condensed", 15.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox2->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->textBox2->Location = System::Drawing::Point(187, 259);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
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
			this->textBox1->Location = System::Drawing::Point(187, 214);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(320, 33);
			this->textBox1->TabIndex = 68;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ğåãèñòğàöèÿToolStripMenuItem,
					this->îÏğîãğàììåToolStripMenuItem, this->âûõîäToolStripMenuItem
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
			this->ğåãèñòğàöèÿToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->ğåãèñòğàöèÿToolStripMenuItem->Text = L"Èçìåíèòü";
			this->ğåãèñòğàöèÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserEditUserDataNew::ğåãèñòğàöèÿToolStripMenuItem_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label5->Location = System::Drawing::Point(53, 308);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(90, 33);
			this->label5->TabIndex = 79;
			this->label5->Text = L"Áàëàíñ";
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBox3->BackColor = System::Drawing::Color::GhostWhite;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiBold Condensed", 15.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox3->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->textBox3->Location = System::Drawing::Point(188, 307);
			this->textBox3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(320, 33);
			this->textBox3->TabIndex = 78;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(578, 37);
			this->button1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 46);
			this->button1->TabIndex = 80;
			this->button1->Text = L"Ìåíş ïîëüçîâàåòëÿ";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &UserEditUserDataNew::button1_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button5->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::SystemColors::Control;
			this->button5->Location = System::Drawing::Point(282, 375);
			this->button5->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(106, 68);
			this->button5->TabIndex = 81;
			this->button5->Text = L"Ãëàâíîå ìåíş";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &UserEditUserDataNew::button5_Click);
			// 
			// UserEditUserDataNew
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(700, 500);
			this->MinimumSize = System::Drawing::Size(700, 500);
			this->Name = L"UserEditUserDataNew";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ROADliteLiesing  v. 2.4 - Menu";
			this->Load += gcnew System::EventHandler(this, &UserEditUserDataNew::UserEditUserDataNew_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {};
private: System::Void UserEditUserDataNew_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïîòâåğäèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ğåãèñòğàöèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ãëàâíîåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïîëüçîâàòåëüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
