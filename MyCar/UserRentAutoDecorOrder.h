#pragma once

namespace Курсовойпроектфронтэнд {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для UserRentAutoDecorOrder
	/// </summary>
	public ref class UserRentAutoDecorOrder : public System::Windows::Forms::Form
	{
	public:
		UserRentAutoDecorOrder(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~UserRentAutoDecorOrder()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:



	private: System::Windows::Forms::ToolStripMenuItem^ менюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ главноеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ данныеАвтоToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox22;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Button^ Оформить;
	private: System::Windows::Forms::ToolStripMenuItem^ оформитьToolStripMenuItem;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserRentAutoDecorOrder::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->оформитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->менюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->главноеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->данныеАвтоToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Оформить = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->оформитьToolStripMenuItem,
					this->менюToolStripMenuItem, this->выходToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(684, 24);
			this->menuStrip1->TabIndex = 66;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// оформитьToolStripMenuItem
			// 
			this->оформитьToolStripMenuItem->Name = L"оформитьToolStripMenuItem";
			this->оформитьToolStripMenuItem->Size = System::Drawing::Size(78, 20);
			this->оформитьToolStripMenuItem->Text = L"Оформить";
			this->оформитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserRentAutoDecorOrder::оформитьToolStripMenuItem_Click);
			// 
			// менюToolStripMenuItem
			// 
			this->менюToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->главноеToolStripMenuItem,
					this->данныеАвтоToolStripMenuItem
			});
			this->менюToolStripMenuItem->Name = L"менюToolStripMenuItem";
			this->менюToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->менюToolStripMenuItem->Text = L"Меню";
			// 
			// главноеToolStripMenuItem
			// 
			this->главноеToolStripMenuItem->Name = L"главноеToolStripMenuItem";
			this->главноеToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->главноеToolStripMenuItem->Text = L"Главное";
			this->главноеToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserRentAutoDecorOrder::главноеToolStripMenuItem_Click);
			// 
			// данныеАвтоToolStripMenuItem
			// 
			this->данныеАвтоToolStripMenuItem->Name = L"данныеАвтоToolStripMenuItem";
			this->данныеАвтоToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->данныеАвтоToolStripMenuItem->Text = L"Данные Авто";
			this->данныеАвтоToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserRentAutoDecorOrder::данныеАвтоToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserRentAutoDecorOrder::выходToolStripMenuItem_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiBold Condensed", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::Control;
			this->button4->Location = System::Drawing::Point(565, 362);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(88, 40);
			this->button4->TabIndex = 64;
			this->button4->Text = L"Вернуться в главное меню";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &UserRentAutoDecorOrder::button4_Click);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiBold SemiConden", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::Control;
			this->button3->Location = System::Drawing::Point(565, 408);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(88, 41);
			this->button3->TabIndex = 63;
			this->button3->Text = L"Вернуться к выбору авто";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &UserRentAutoDecorOrder::button3_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::Control;
			this->button2->Location = System::Drawing::Point(358, 369);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 55);
			this->button2->TabIndex = 62;
			this->button2->Text = L"Выход";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &UserRentAutoDecorOrder::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label3->Location = System::Drawing::Point(353, 276);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(242, 25);
			this->label3->TabIndex = 61;
			this->label3->Text = L"Стоимость услуги аренды";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label2->Location = System::Drawing::Point(8, 316);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 18);
			this->label2->TabIndex = 60;
			this->label2->Text = L"Время";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(194, 131);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(298, 29);
			this->label1->TabIndex = 59;
			this->label1->Text = L"Введите оставшиеся данные";
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(358, 304);
			this->textBox22->Multiline = true;
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(228, 25);
			this->textBox22->TabIndex = 58;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(85, 316);
			this->textBox11->Multiline = true;
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(111, 20);
			this->textBox11->TabIndex = 57;
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &UserRentAutoDecorOrder::textBox11_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::White;
			this->label7->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label7->Location = System::Drawing::Point(8, 283);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 18);
			this->label7->TabIndex = 74;
			this->label7->Text = L"Паспорт";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::White;
			this->label6->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label6->Location = System::Drawing::Point(8, 257);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(53, 18);
			this->label6->TabIndex = 73;
			this->label6->Text = L"Почта";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label5->Location = System::Drawing::Point(8, 228);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(71, 18);
			this->label5->TabIndex = 72;
			this->label5->Text = L"Телефон";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label4->Location = System::Drawing::Point(12, 200);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 18);
			this->label4->TabIndex = 71;
			this->label4->Text = L"ФИО";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(85, 283);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(111, 20);
			this->textBox4->TabIndex = 70;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(85, 257);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(111, 20);
			this->textBox3->TabIndex = 69;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(85, 228);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(111, 20);
			this->textBox2->TabIndex = 68;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(85, 198);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(111, 20);
			this->textBox1->TabIndex = 67;
			// 
			// Оформить
			// 
			this->Оформить->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Оформить.BackgroundImage")));
			this->Оформить->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->Оформить->ForeColor = System::Drawing::SystemColors::Control;
			this->Оформить->Location = System::Drawing::Point(74, 369);
			this->Оформить->Name = L"Оформить";
			this->Оформить->Size = System::Drawing::Size(140, 55);
			this->Оформить->TabIndex = 77;
			this->Оформить->Text = L"Оформить";
			this->Оформить->UseVisualStyleBackColor = false;
			this->Оформить->Click += gcnew System::EventHandler(this, &UserRentAutoDecorOrder::Оформить_Click);
			// 
			// UserRentAutoDecorOrder
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox22);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Оформить);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(700, 500);
			this->MinimumSize = System::Drawing::Size(700, 500);
			this->Name = L"UserRentAutoDecorOrder";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ROADliteLiesing  v. 2.4 - Order";
			this->Load += gcnew System::EventHandler(this, &UserRentAutoDecorOrder::UserRentAutoDecorOrder_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UserRentAutoDecorOrder_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void Оформить_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void оформитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void главноеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void данныеАвтоToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
