#pragma once

namespace Êóğñîâîéïğîåêòôğîíòıíä {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ UserRentAutoWiewData
	/// </summary>
	public ref class UserRentAutoWiewData : public System::Windows::Forms::Form
	{
	public:
		UserRentAutoWiewData(void)
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
		~UserRentAutoWiewData()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button5;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ğåæèìToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ãëàâíîåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ìåíşToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîèñêToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîòâåğäèòüToolStripMenuItem;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ToolStripMenuItem^ çàãğóçèòüToolStripMenuItem;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserRentAutoWiewData::typeid));
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğåæèìToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ãëàâíîåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ìåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîèñêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîòâåğäèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->çàãğóçèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::SystemColors::Control;
			this->button5->Location = System::Drawing::Point(750, 419);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(142, 56);
			this->button5->TabIndex = 58;
			this->button5->Text = L"Âåğíóòüñÿ â ìåíş ğåæèìà";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::button5_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::Control;
			this->button2->Location = System::Drawing::Point(750, 48);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 48);
			this->button2->TabIndex = 55;
			this->button2->Text = L"Çàãğóçèòü";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::button2_Click);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(750, 189);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 48);
			this->button1->TabIndex = 54;
			this->button1->Text = L"Çàêàçàòü";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::button1_Click);
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::âûõîäToolStripMenuItem_Click);
			// 
			// ğåæèìToolStripMenuItem
			// 
			this->ğåæèìToolStripMenuItem->Name = L"ğåæèìToolStripMenuItem";
			this->ğåæèìToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->ğåæèìToolStripMenuItem->Text = L"Ïîëüçîâàòåëü";
			this->ğåæèìToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::ğåæèìToolStripMenuItem_Click);
			// 
			// ãëàâíîåToolStripMenuItem
			// 
			this->ãëàâíîåToolStripMenuItem->Name = L"ãëàâíîåToolStripMenuItem";
			this->ãëàâíîåToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->ãëàâíîåToolStripMenuItem->Text = L"Ãëàâíîå";
			this->ãëàâíîåToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::ãëàâíîåToolStripMenuItem_Click);
			// 
			// ìåíşToolStripMenuItem
			// 
			this->ìåíşToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ãëàâíîåToolStripMenuItem,
					this->ğåæèìToolStripMenuItem
			});
			this->ìåíşToolStripMenuItem->Name = L"ìåíşToolStripMenuItem";
			this->ìåíşToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->ìåíşToolStripMenuItem->Text = L"Ìåíş";
			this->ìåíşToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::ìåíşToolStripMenuItem_Click);
			// 
			// ïîèñêToolStripMenuItem
			// 
			this->ïîèñêToolStripMenuItem->Name = L"ïîèñêToolStripMenuItem";
			this->ïîèñêToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->ïîèñêToolStripMenuItem->Text = L"Ïîèñê no";
			this->ïîèñêToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::ïîèñêToolStripMenuItem_Click);
			// 
			// ïîòâåğäèòüToolStripMenuItem
			// 
			this->ïîòâåğäèòüToolStripMenuItem->Name = L"ïîòâåğäèòüToolStripMenuItem";
			this->ïîòâåğäèòüToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->ïîòâåğäèòüToolStripMenuItem->Text = L"Çàêàçàòü";
			this->ïîòâåğäèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::ïîòâåğäèòüToolStripMenuItem_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::Control;
			this->button3->Location = System::Drawing::Point(750, 357);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(142, 56);
			this->button3->TabIndex = 57;
			this->button3->Text = L"Âåğíóòñÿ â ãëàâíîå ìåíş";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::button3_Click);
			// 
			// çàãğóçèòüToolStripMenuItem
			// 
			this->çàãğóçèòüToolStripMenuItem->Name = L"çàãğóçèòüToolStripMenuItem";
			this->çàãğóçèòüToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->çàãğóçèòüToolStripMenuItem->Text = L"Çàãğóçèòü";
			this->çàãğóçèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::çàãğóçèòüToolStripMenuItem_Click);
			// 
			// button7
			// 
			this->button7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.BackgroundImage")));
			this->button7->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::SystemColors::Control;
			this->button7->Location = System::Drawing::Point(750, 121);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(142, 41);
			this->button7->TabIndex = 52;
			this->button7->Text = L"Ïîèñê no";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::button7_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::Control;
			this->button4->Location = System::Drawing::Point(750, 263);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(142, 46);
			this->button4->TabIndex = 51;
			this->button4->Text = L"Âûõîä";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &UserRentAutoWiewData::button4_Click);
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Íàëè÷èå";
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Òàğèô";
			this->Column7->Name = L"Column7";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Âğåìÿ ïîñòóïëåíèÿ";
			this->Column5->Name = L"Column5";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Íîìåğ ìàøèíû ";
			this->Column4->Name = L"Column4";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Ìîäåëü";
			this->Column3->Name = L"Column3";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Ìàğêà";
			this->Column2->Name = L"Column2";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Íîìåğ";
			this->Column1->Name = L"Column1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->çàãğóçèòüToolStripMenuItem,
					this->ïîòâåğäèòüToolStripMenuItem, this->ïîèñêToolStripMenuItem, this->ìåíşToolStripMenuItem, this->âûõîäToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(904, 24);
			this->menuStrip1->TabIndex = 53;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::CornflowerBlue;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column7, this->Column6
			});
			this->dataGridView1->GridColor = System::Drawing::Color::White;
			this->dataGridView1->Location = System::Drawing::Point(23, 38);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(721, 451);
			this->dataGridView1->TabIndex = 50;
			// 
			// UserRentAutoWiewData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(904, 531);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button5);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(920, 570);
			this->MinimumSize = System::Drawing::Size(920, 570);
			this->Name = L"UserRentAutoWiewData";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ROADliteLiesing  v. 2.4 - Auto";
			this->Load += gcnew System::EventHandler(this, &UserRentAutoWiewData::UserRentAutoWiewData_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UserRentAutoWiewData_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void çàãğóçèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïîòâåğäèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïîèñêToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ìåíşToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {};
private: System::Void ãëàâíîåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ğåæèìToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
