#pragma once

namespace ���������������������� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� AdminEditUserData
	/// </summary>
	public ref class AdminEditUserData : public System::Windows::Forms::Form
	{
	public:
		AdminEditUserData(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~AdminEditUserData()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button6;
	protected:
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������NoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminEditUserData::typeid));
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������NoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button6->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button6->ForeColor = System::Drawing::SystemColors::Control;
			this->button6->Location = System::Drawing::Point(484, 65);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(140, 43);
			this->button6->TabIndex = 26;
			this->button6->Text = L"���������";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &AdminEditUserData::button6_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button4->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::Control;
			this->button4->Location = System::Drawing::Point(484, 359);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(140, 43);
			this->button4->TabIndex = 24;
			this->button4->Text = L"�����";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &AdminEditUserData::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::Control;
			this->button3->Location = System::Drawing::Point(484, 212);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(140, 43);
			this->button3->TabIndex = 23;
			this->button3->Text = L"�������";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &AdminEditUserData::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::Control;
			this->button2->Location = System::Drawing::Point(484, 114);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 43);
			this->button2->TabIndex = 22;
			this->button2->Text = L"��������";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &AdminEditUserData::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(484, 163);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 43);
			this->button1->TabIndex = 21;
			this->button1->Text = L"��������";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AdminEditUserData::button1_Click);
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"������";
			this->Column4->Name = L"Column4";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"������";
			this->Column3->Name = L"Column3";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"�����";
			this->Column2->Name = L"Column2";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"�����";
			this->Column1->Name = L"Column1";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(22, 55);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(442, 362);
			this->dataGridView1->TabIndex = 27;
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->���������ToolStripMenuItem1,
					this->��������ToolStripMenuItem, this->��������ToolStripMenuItem, this->�������ToolStripMenuItem, this->�����ToolStripMenuItem,
					this->�������NoToolStripMenuItem
			});
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->��������ToolStripMenuItem->Text = L"��������";
			// 
			// ���������ToolStripMenuItem1
			// 
			this->���������ToolStripMenuItem1->Name = L"���������ToolStripMenuItem1";
			this->���������ToolStripMenuItem1->Size = System::Drawing::Size(128, 22);
			this->���������ToolStripMenuItem1->Text = L"���������";
			this->���������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &AdminEditUserData::���������ToolStripMenuItem1_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditUserData::��������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditUserData::��������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditUserData::�������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->�����ToolStripMenuItem->Text = L"����� no";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditUserData::�����ToolStripMenuItem_Click);
			// 
			// �������NoToolStripMenuItem
			// 
			this->�������NoToolStripMenuItem->Name = L"�������NoToolStripMenuItem";
			this->�������NoToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->�������NoToolStripMenuItem->Text = L"�������";
			this->�������NoToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditUserData::�������NoToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditUserData::�����ToolStripMenuItem_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button8->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button8->ForeColor = System::Drawing::SystemColors::Control;
			this->button8->Location = System::Drawing::Point(484, 310);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(140, 43);
			this->button8->TabIndex = 30;
			this->button8->Text = L"�������";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &AdminEditUserData::button8_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button7->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::SystemColors::Control;
			this->button7->Location = System::Drawing::Point(484, 261);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(187, 43);
			this->button7->TabIndex = 29;
			this->button7->Text = L"����� no";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &AdminEditUserData::button7_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�������ToolStripMenuItem,
					this->�����ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditUserData::�������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditUserData::�����ToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->��������ToolStripMenuItem,
					this->����ToolStripMenuItem, this->�����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(684, 24);
			this->menuStrip1->TabIndex = 28;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// AdminEditUserData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(700, 500);
			this->MinimumSize = System::Drawing::Size(700, 500);
			this->Name = L"AdminEditUserData";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ROADliteLiesing  v. 2.4 - Admin";
			this->Load += gcnew System::EventHandler(this, &AdminEditUserData::AdminEditUserData_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AdminEditUserData_Load(System::Object^ sender, System::EventArgs^ e) {};
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ���������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �������NoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
