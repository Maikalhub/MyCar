#include "Admin.h"
#include "MyMenu.h"
#include "AdminEditAdminData.h"
#include "AdminEditUserData.h"
#include "AdminEditAutoData.h"
#include "AdminEditReportsData.h"
///
///
///
// �������� ������ ������
System::Void ����������������������::Admin::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditAdminData^ form = gcnew AdminEditAdminData();

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// �������� ������ ������������
System::Void ����������������������::Admin::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditUserData^ form = gcnew AdminEditUserData();

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// �������� ������ ����
System::Void ����������������������::Admin::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditAutoData^ form = gcnew AdminEditAutoData();

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// �������� ������ �������
System::Void ����������������������::Admin::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditReportsData^ form = gcnew AdminEditReportsData();

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ����������� � ����
System::Void ����������������������::Admin::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyMenu^ form = gcnew MyMenu();

	MessageBox::Show("�� ��������� � ����", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();


}
// �����
System::Void ����������������������::Admin::button3_Click(System::Object^ sender, System::EventArgs^ e)
{

	MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
//
// ������� ����
// 
// �������� ������ ������ 
System::Void ����������������������::Admin::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditAdminData^ form = gcnew AdminEditAdminData();

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// �������� ������ ������������
System::Void ����������������������::Admin::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditUserData^ form = gcnew AdminEditUserData();

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// �������� ������ ����
System::Void ����������������������::Admin::������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditAutoData^ form = gcnew AdminEditAutoData();

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// �������� ������ �������
System::Void ����������������������::Admin::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditReportsData^ form = gcnew AdminEditReportsData();

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ����������� � ����
System::Void ����������������������::Admin::����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyMenu^ form = gcnew MyMenu();

	MessageBox::Show("�� ��������� � ����", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// �����
System::Void ����������������������::Admin::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
