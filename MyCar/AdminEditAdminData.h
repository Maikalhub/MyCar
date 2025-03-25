#pragma once

namespace Êóğñîâîéïğîåêòôğîíòıíä {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ AdminEditAdminData
	/// </summary>
	public ref class AdminEditAdminData : public System::Windows::Forms::Form
	{
	public:
		AdminEditAdminData(void)
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
		~AdminEditAdminData()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ãëàâíîåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ìåíşToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ àäìèíToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ î÷èñòêàNoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîèñêToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ óäàëèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îáíîâèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ äîáàâèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ çàãğóçèòüToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ äåéñòâèÿToolStripMenuItem;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button6;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminEditAdminData::typeid));
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ãëàâíîåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ìåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->àäìèíToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->î÷èñòêàNoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîèñêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->óäàëèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îáíîâèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->äîáàâèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàãğóçèòüToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->äåéñòâèÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditAdminData::âûõîäToolStripMenuItem_Click);
			// 
			// ãëàâíîåToolStripMenuItem
			// 
			this->ãëàâíîåToolStripMenuItem->Name = L"ãëàâíîåToolStripMenuItem";
			this->ãëàâíîåToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ãëàâíîåToolStripMenuItem->Text = L"Ãëàâíîå";
			this->ãëàâíîåToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditAdminData::ãëàâíîåToolStripMenuItem_Click);
			// 
			// ìåíşToolStripMenuItem
			// 
			this->ìåíşToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ãëàâíîåToolStripMenuItem,
					this->àäìèíToolStripMenuItem
			});
			this->ìåíşToolStripMenuItem->Name = L"ìåíşToolStripMenuItem";
			this->ìåíşToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->ìåíşToolStripMenuItem->Text = L"Ìåíş";
			// 
			// àäìèíToolStripMenuItem
			// 
			this->àäìèíToolStripMenuItem->Name = L"àäìèíToolStripMenuItem";
			this->àäìèíToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->àäìèíToolStripMenuItem->Text = L"Àäìèí";
			this->àäìèíToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditAdminData::àäìèíToolStripMenuItem_Click);
			// 
			// î÷èñòêàNoToolStripMenuItem
			// 
			this->î÷èñòêàNoToolStripMenuItem->Name = L"î÷èñòêàNoToolStripMenuItem";
			this->î÷èñòêàNoToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->î÷èñòêàNoToolStripMenuItem->Text = L"Î÷èñòêà";
			this->î÷èñòêàNoToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditAdminData::î÷èñòêàNoToolStripMenuItem_Click);
			// 
			// ïîèñêToolStripMenuItem
			// 
			this->ïîèñêToolStripMenuItem->Name = L"ïîèñêToolStripMenuItem";
			this->ïîèñêToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ïîèñêToolStripMenuItem->Text = L"Ïîèñê no";
			this->ïîèñêToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditAdminData::ïîèñêToolStripMenuItem_Click);
			// 
			// óäàëèòüToolStripMenuItem
			// 
			this->óäàëèòüToolStripMenuItem->Name = L"óäàëèòüToolStripMenuItem";
			this->óäàëèòüToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->óäàëèòüToolStripMenuItem->Text = L"Óäàëèòü";
			this->óäàëèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditAdminData::óäàëèòüToolStripMenuItem_Click);
			// 
			// îáíîâèòüToolStripMenuItem
			// 
			this->îáíîâèòüToolStripMenuItem->Name = L"îáíîâèòüToolStripMenuItem";
			this->îáíîâèòüToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->îáíîâèòüToolStripMenuItem->Text = L"Îáíîâèòü";
			this->îáíîâèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditAdminData::îáíîâèòüToolStripMenuItem_Click);
			// 
			// äîáàâèòüToolStripMenuItem
			// 
			this->äîáàâèòüToolStripMenuItem->Name = L"äîáàâèòüToolStripMenuItem";
			this->äîáàâèòüToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->äîáàâèòüToolStripMenuItem->Text = L"Äîáàâèòü";
			this->äîáàâèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditAdminData::äîáàâèòüToolStripMenuItem_Click);
			// 
			// çàãğóçèòüToolStripMenuItem1
			// 
			this->çàãğóçèòüToolStripMenuItem1->Name = L"çàãğóçèòüToolStripMenuItem1";
			this->çàãğóçèòüToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->çàãğóçèòüToolStripMenuItem1->Text = L"Çàãğóçèòü";
			this->çàãğóçèòüToolStripMenuItem1->Click += gcnew System::EventHandler(this, &AdminEditAdminData::çàãğóçèòüToolStripMenuItem1_Click);
			// 
			// äåéñòâèÿToolStripMenuItem
			// 
			this->äåéñòâèÿToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->çàãğóçèòüToolStripMenuItem1,
					this->äîáàâèòüToolStripMenuItem, this->îáíîâèòüToolStripMenuItem, this->óäàëèòüToolStripMenuItem, this->ïîèñêToolStripMenuItem,
					this->î÷èñòêàNoToolStripMenuItem
			});
			this->äåéñòâèÿToolStripMenuItem->Name = L"äåéñòâèÿToolStripMenuItem";
			this->äåéñòâèÿToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->äåéñòâèÿToolStripMenuItem->Text = L"Äåéñòâèÿ";
			this->äåéñòâèÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &AdminEditAdminData::äåéñòâèÿToolStripMenuItem_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.BackgroundImage")));
			this->button8->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button8->ForeColor = System::Drawing::SystemColors::Control;
			this->button8->Location = System::Drawing::Point(444, 301);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(137, 39);
			this->button8->TabIndex = 30;
			this->button8->Text = L"Î÷èñòêà";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &AdminEditAdminData::button8_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.BackgroundImage")));
			this->button6->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button6->ForeColor = System::Drawing::SystemColors::Control;
			this->button6->Location = System::Drawing::Point(444, 76);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(137, 39);
			this->button6->TabIndex = 26;
			this->button6->Text = L"Çàãğóçèòü";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &AdminEditAdminData::button6_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::Control;
			this->button4->Location = System::Drawing::Point(444, 346);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(137, 39);
			this->button4->TabIndex = 24;
			this->button4->Text = L"Âûõîä";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &AdminEditAdminData::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::Control;
			this->button3->Location = System::Drawing::Point(444, 211);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(137, 39);
			this->button3->TabIndex = 23;
			this->button3->Text = L"Óäàëèòü";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &AdminEditAdminData::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::Control;
			this->button2->Location = System::Drawing::Point(444, 121);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(137, 39);
			this->button2->TabIndex = 22;
			this->button2->Text = L"Äîáàâèòü";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &AdminEditAdminData::button2_Click);
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Ïàğîëü";
			this->Column3->Name = L"Column3";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Ëîãèí";
			this->Column2->Name = L"Column2";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Íîìåğ";
			this->Column1->Name = L"Column1";
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.BackgroundImage")));
			this->button7->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::SystemColors::Control;
			this->button7->Location = System::Drawing::Point(444, 256);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(203, 39);
			this->button7->TabIndex = 29;
			this->button7->Text = L"Ïîèñê no";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &AdminEditAdminData::button7_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Sunken;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->dataGridView1->Location = System::Drawing::Point(27, 76);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(340, 309);
			this->dataGridView1->TabIndex = 27;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(444, 166);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(203, 39);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Îáíîâèòü";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AdminEditAdminData::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->äåéñòâèÿToolStripMenuItem,
					this->ìåíşToolStripMenuItem, this->âûõîäToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(684, 24);
			this->menuStrip1->TabIndex = 28;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// AdminEditAdminData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(700, 500);
			this->MinimumSize = System::Drawing::Size(700, 500);
			this->Name = L"AdminEditAdminData";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ROADliteLiesing  v. 2.4 - Admin";
			this->Load += gcnew System::EventHandler(this, &AdminEditAdminData::AdminEditAdminData_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AdminEditAdminData_Load(System::Object^ sender, System::EventArgs^ e) {};
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void äåéñòâèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void çàãğóçèòüToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void äîáàâèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void îáíîâèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void óäàëèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïîèñêToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void î÷èñòêàNoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ãëàâíîåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void àäìèíToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
