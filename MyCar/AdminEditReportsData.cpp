#include "AdminEditReportsData.h"
#include "MyMenu.h"
#include "Admin.h"
#include "ReportOrderData.h"
#include "ReportTransactionData.h"
//
////
// ������ �������
System::Void ����������������������::AdminEditReportsData::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
	ReportOrderData^ Form2 = gcnew ReportOrderData();

	// �������� ����� �����
	Form2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ������ ����������
System::Void ����������������������::AdminEditReportsData::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	ReportTransactionData^ newForm3 = gcnew ReportTransactionData();

	// �������� ����� �����
	newForm3->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ���� ��������������
System::Void ����������������������::AdminEditReportsData::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	Admin^ newForm2 = gcnew Admin();

	// �������� ����� �����
	newForm2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// �����
System::Void ����������������������::AdminEditReportsData::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
//
// 
// ������� ����
// 
// 
// ������ ������� 
System::Void ����������������������::AdminEditReportsData::���������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	ReportOrderData^ Form2 = gcnew ReportOrderData();

	// �������� ����� �����
	Form2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ������ ����������
System::Void ����������������������::AdminEditReportsData::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	ReportTransactionData^ newForm2 = gcnew ReportTransactionData();

	// �������� ����� �����
	newForm2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ������� ����
System::Void ����������������������::AdminEditReportsData::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyMenu^ newForm2 = gcnew MyMenu();

	// �������� ����� �����
	newForm2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ���� ��������������
System::Void ����������������������::AdminEditReportsData::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Admin^ newForm2 = gcnew Admin();

	// �������� ����� �����
	newForm2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// �����
System::Void ����������������������::AdminEditReportsData::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
