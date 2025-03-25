#pragma once

namespace Êóğñîâîéïğîåêòôğîíòıíä {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ ReportOrderData
	/// </summary>
	public ref class ReportOrderData : public System::Windows::Forms::Form
	{
	public:
		ReportOrderData(void)
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
		~ReportOrderData()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button8;
	protected:
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::DataGridView^ dataGridView1;



	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;







	private: System::Windows::Forms::ToolStripMenuItem^ ìåíşToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ãëàâíîåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ àäìèíToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column11;
	private: System::Windows::Forms::ToolStripMenuItem^ äåéñòâèÿToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ çàãğóçèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ äîáàâèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ óäàëèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîèñêNoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ î÷èòñêàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îáíîâèòüToolStripMenuItem;
	private: System::Windows::Forms::Button^ button22;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ReportOrderData::typeid));
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->äåéñòâèÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàãğóçèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->äîáàâèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îáíîâèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->óäàëèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîèñêNoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->î÷èòñêàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ìåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ãëàâíîåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->àäìèíToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button22 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.BackgroundImage")));
			this->button8->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button8->ForeColor = System::Drawing::SystemColors::Control;
			this->button8->Location = System::Drawing::Point(1202, 326);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(123, 45);
			this->button8->TabIndex = 39;
			this->button8->Text = L"Î÷èñòêà";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &ReportOrderData::button8_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.BackgroundImage")));
			this->button7->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::SystemColors::Control;
			this->button7->Location = System::Drawing::Point(1202, 275);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(164, 45);
			this->button7->TabIndex = 38;
			this->button7->Text = L"Ïîèñê no";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &ReportOrderData::button7_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Sunken;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8, this->Column9, this->Column10,
					this->Column11
			});
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->dataGridView1->Location = System::Drawing::Point(36, 44);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1142, 428);
			this->dataGridView1->TabIndex = 36;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Íîìåğ";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Ìàğêà";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Ìîäåëü";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Íîìåğ ìàøèíû";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Òàğèô";
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Ëîãèí";
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Òåëåôîí";
			this->Column7->Name = L"Column7";
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Ïàñïîğò";
			this->Column8->Name = L"Column8";
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Ñóììà";
			this->Column9->Name = L"Column9";
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"Ïî÷òà";
			this->Column10->Name = L"Column10";
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"ÔÈÎ";
			this->Column11->Name = L"Column11";
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.BackgroundImage")));
			this->button6->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button6->ForeColor = System::Drawing::SystemColors::Control;
			this->button6->Location = System::Drawing::Point(1202, 72);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(123, 45);
			this->button6->TabIndex = 35;
			this->button6->Text = L"Çàãğóçèòü";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &ReportOrderData::button6_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::Control;
			this->button4->Location = System::Drawing::Point(1202, 377);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(123, 45);
			this->button4->TabIndex = 34;
			this->button4->Text = L"Âûõîä";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &ReportOrderData::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::Control;
			this->button3->Location = System::Drawing::Point(1202, 225);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(123, 45);
			this->button3->TabIndex = 33;
			this->button3->Text = L"Óäàëèòü";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &ReportOrderData::button3_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(1202, 174);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 45);
			this->button1->TabIndex = 31;
			this->button1->Text = L"Îáíîâèòü";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ReportOrderData::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->äåéñòâèÿToolStripMenuItem,
					this->ìåíşToolStripMenuItem, this->âûõîäToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1384, 24);
			this->menuStrip1->TabIndex = 37;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// äåéñòâèÿToolStripMenuItem
			// 
			this->äåéñòâèÿToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->çàãğóçèòüToolStripMenuItem,
					this->äîáàâèòüToolStripMenuItem, this->îáíîâèòüToolStripMenuItem, this->óäàëèòüToolStripMenuItem, this->ïîèñêNoToolStripMenuItem,
					this->î÷èòñêàToolStripMenuItem
			});
			this->äåéñòâèÿToolStripMenuItem->Name = L"äåéñòâèÿToolStripMenuItem";
			this->äåéñòâèÿToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->äåéñòâèÿToolStripMenuItem->Text = L"Äåéñòâèÿ";
			// 
			// çàãğóçèòüToolStripMenuItem
			// 
			this->çàãğóçèòüToolStripMenuItem->Name = L"çàãğóçèòüToolStripMenuItem";
			this->çàãğóçèòüToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->çàãğóçèòüToolStripMenuItem->Text = L"Çàãğóçèòü";
			this->çàãğóçèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReportOrderData::çàãğóçèòüToolStripMenuItem_Click);
			// 
			// äîáàâèòüToolStripMenuItem
			// 
			this->äîáàâèòüToolStripMenuItem->Name = L"äîáàâèòüToolStripMenuItem";
			this->äîáàâèòüToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->äîáàâèòüToolStripMenuItem->Text = L"Äîáàâèòü";
			this->äîáàâèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReportOrderData::äîáàâèòüToolStripMenuItem_Click);
			// 
			// îáíîâèòüToolStripMenuItem
			// 
			this->îáíîâèòüToolStripMenuItem->Name = L"îáíîâèòüToolStripMenuItem";
			this->îáíîâèòüToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->îáíîâèòüToolStripMenuItem->Text = L"Îáíîâèòü";
			this->îáíîâèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReportOrderData::îáíîâèòüToolStripMenuItem_Click);
			// 
			// óäàëèòüToolStripMenuItem
			// 
			this->óäàëèòüToolStripMenuItem->Name = L"óäàëèòüToolStripMenuItem";
			this->óäàëèòüToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->óäàëèòüToolStripMenuItem->Text = L"Óäàëèòü";
			this->óäàëèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReportOrderData::óäàëèòüToolStripMenuItem_Click);
			// 
			// ïîèñêNoToolStripMenuItem
			// 
			this->ïîèñêNoToolStripMenuItem->Name = L"ïîèñêNoToolStripMenuItem";
			this->ïîèñêNoToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->ïîèñêNoToolStripMenuItem->Text = L"Ïîèñê no";
			this->ïîèñêNoToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReportOrderData::ïîèñêNoToolStripMenuItem_Click);
			// 
			// î÷èòñêàToolStripMenuItem
			// 
			this->î÷èòñêàToolStripMenuItem->Name = L"î÷èòñêàToolStripMenuItem";
			this->î÷èòñêàToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->î÷èòñêàToolStripMenuItem->Text = L"Î÷èñòêà";
			this->î÷èòñêàToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReportOrderData::î÷èòñêàToolStripMenuItem_Click);
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
			// ãëàâíîåToolStripMenuItem
			// 
			this->ãëàâíîåToolStripMenuItem->Name = L"ãëàâíîåToolStripMenuItem";
			this->ãëàâíîåToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ãëàâíîåToolStripMenuItem->Text = L"Ãëàâíîå";
			this->ãëàâíîåToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReportOrderData::ãëàâíîåToolStripMenuItem_Click);
			// 
			// àäìèíToolStripMenuItem
			// 
			this->àäìèíToolStripMenuItem->Name = L"àäìèíToolStripMenuItem";
			this->àäìèíToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->àäìèíToolStripMenuItem->Text = L"Àäìèí";
			this->àäìèíToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReportOrderData::àäìèíToolStripMenuItem_Click);
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReportOrderData::âûõîäToolStripMenuItem_Click);
			// 
			// button22
			// 
			this->button22->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->button22->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button22.BackgroundImage")));
			this->button22->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button22->ForeColor = System::Drawing::SystemColors::Control;
			this->button22->Location = System::Drawing::Point(1202, 123);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(123, 45);
			this->button22->TabIndex = 40;
			this->button22->Text = L"Äîáàâèòü";
			this->button22->UseVisualStyleBackColor = false;
			this->button22->Click += gcnew System::EventHandler(this, &ReportOrderData::button22_Click);
			// 
			// ReportOrderData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1384, 511);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1400, 550);
			this->MinimumSize = System::Drawing::Size(1400, 550);
			this->Name = L"ReportOrderData";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ROADliteLiesing  v. 2.4 - Admin";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void äåéñòâèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void toolStripComboBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void çàãğóçèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void äîáàâèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void îáíîâèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void óäàëèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïîèñêNoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void î÷èòñêàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ãëàâíîåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void àäìèíToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e);
};
}
