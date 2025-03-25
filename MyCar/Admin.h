#pragma once

namespace Êóğñîâîéïğîåêòôğîíòıíä {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ Admin
	/// </summary>
	public ref class Admin : public System::Windows::Forms::Form
	{
	public:
		Admin(void)
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
		~Admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ToolStripMenuItem^ ìåíşToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îò÷åòToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîòâåğäèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ğåãèñòğàöèÿToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ àğåíäàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Admin::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->ìåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îò÷åòToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->ïîòâåğäèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğåãèñòğàöèÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->àğåíäàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::Control;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(217, 373);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(118, 56);
			this->button2->TabIndex = 68;
			this->button2->Text = L"Âåğíóòüñÿ â ìåíş ";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Admin::button2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label5->Location = System::Drawing::Point(580, 263);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 22);
			this->label5->TabIndex = 67;
			this->label5->Text = L"Îò÷åò";
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button8->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button8->ForeColor = System::Drawing::SystemColors::Control;
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.Image")));
			this->button8->Location = System::Drawing::Point(534, 289);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(142, 56);
			this->button8->TabIndex = 66;
			this->button8->Text = L"Ğàáîòà ñ äàííûìè òğàíçàêöèè";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Admin::button8_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label4->Location = System::Drawing::Point(425, 263);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 22);
			this->label4->TabIndex = 65;
			this->label4->Text = L"Àâòî";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label3->Location = System::Drawing::Point(201, 264);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(124, 22);
			this->label3->TabIndex = 63;
			this->label3->Text = L"Ïîëüçîâàòåëü";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label2->Location = System::Drawing::Point(65, 263);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 22);
			this->label2->TabIndex = 62;
			this->label2->Text = L"Àäìèí";
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button9->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button9->ForeColor = System::Drawing::SystemColors::Control;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->Location = System::Drawing::Point(193, 289);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(142, 56);
			this->button9->TabIndex = 61;
			this->button9->Text = L"Ğàáîòà ñ äàííûìè";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Admin::button9_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button6->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button6->ForeColor = System::Drawing::SystemColors::Control;
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->Location = System::Drawing::Point(375, 289);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(142, 56);
			this->button6->TabIndex = 64;
			this->button6->Text = L"Ğàáîòà ñ äàííûìè àâòî";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Admin::button6_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(28, 289);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 56);
			this->button1->TabIndex = 58;
			this->button1->Text = L"Ğàáîòà ñ äàííûìè";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Admin::button1_Click);
			// 
			// ìåíşToolStripMenuItem
			// 
			this->ìåíşToolStripMenuItem->Name = L"ìåíşToolStripMenuItem";
			this->ìåíşToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->ìåíşToolStripMenuItem->Text = L"Ìåíş";
			this->ìåíşToolStripMenuItem->Click += gcnew System::EventHandler(this, &Admin::ìåíşToolStripMenuItem_Click);
			// 
			// îò÷åòToolStripMenuItem
			// 
			this->îò÷åòToolStripMenuItem->Name = L"îò÷åòToolStripMenuItem";
			this->îò÷åòToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->îò÷åòToolStripMenuItem->Text = L"Îò÷åò";
			this->îò÷åòToolStripMenuItem->Click += gcnew System::EventHandler(this, &Admin::îò÷åòToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Silver;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 27.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(185, 124);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(312, 45);
			this->label1->TabIndex = 57;
			this->label1->Text = L"Âûáåğèòå äåéñòâèå";
			this->label1->Click += gcnew System::EventHandler(this, &Admin::label1_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::Control;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(356, 373);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(118, 56);
			this->button3->TabIndex = 59;
			this->button3->Text = L"Âûõîä";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Admin::button3_Click);
			// 
			// ïîòâåğäèòüToolStripMenuItem
			// 
			this->ïîòâåğäèòüToolStripMenuItem->Name = L"ïîòâåğäèòüToolStripMenuItem";
			this->ïîòâåğäèòüToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->ïîòâåğäèòüToolStripMenuItem->Text = L"Àäìèí";
			this->ïîòâåğäèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &Admin::ïîòâåğäèòüToolStripMenuItem_Click);
			// 
			// ğåãèñòğàöèÿToolStripMenuItem
			// 
			this->ğåãèñòğàöèÿToolStripMenuItem->Name = L"ğåãèñòğàöèÿToolStripMenuItem";
			this->ğåãèñòğàöèÿToolStripMenuItem->Size = System::Drawing::Size(96, 20);
			this->ğåãèñòğàöèÿToolStripMenuItem->Text = L"Ïîëüçîâàòåëü";
			this->ğåãèñòğàöèÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &Admin::ğåãèñòğàöèÿToolStripMenuItem_Click);
			// 
			// àğåíäàToolStripMenuItem
			// 
			this->àğåíäàToolStripMenuItem->Name = L"àğåíäàToolStripMenuItem";
			this->àğåíäàToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->àğåíäàToolStripMenuItem->Text = L"Àâòî";
			this->àğåíäàToolStripMenuItem->Click += gcnew System::EventHandler(this, &Admin::àğåíäàToolStripMenuItem_Click);
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &Admin::âûõîäToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->ïîòâåğäèòüToolStripMenuItem,
					this->ğåãèñòğàöèÿToolStripMenuItem, this->àğåíäàToolStripMenuItem, this->îò÷åòToolStripMenuItem, this->ìåíşToolStripMenuItem,
					this->âûõîäToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(684, 24);
			this->menuStrip1->TabIndex = 60;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(700, 500);
			this->MinimumSize = System::Drawing::Size(700, 500);
			this->Name = L"Admin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ROADliteLiesing  v. 2.4 - Admin";
			this->Load += gcnew System::EventHandler(this, &Admin::Admin_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Admin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïîòâåğäèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ğåãèñòğàöèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void àğåíäàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void îò÷åòToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ìåíşToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
