#include "Registration.h"
#include "MyMenu.h"
//
using namespace System::Data;
using namespace System::Data::OleDb;
//
////
//
// ������� ����
System::Void ����������������������::Registration::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyMenu^ form = gcnew MyMenu();

    MessageBox::Show("�� ��������� � ����", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

    // �������� ����� �����
    form->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();

}
// ����������
System::Void ����������������������::Registration::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ ����� = textBox1->ToString();
    String^ ������ = textBox2->ToString();
    double  balance = 100;
    String^ ������ = Convert::ToString(balance);

    try
    {
        // ����������� � ���� ������
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        // ��������� ������ � ���� ������
        dbConnection->Open(); // ��������� ����������
        String^ guery = "INSERT INTO [User] ([�����], [������], [������]) VALUES (?, ?, ?)"; // ������

        OleDbCommand^ dbCommand = gcnew OleDbCommand(guery, dbConnection);

        dbCommand->Parameters->AddWithValue("?", �����);
        dbCommand->Parameters->AddWithValue("?", ������);
        dbCommand->Parameters->AddWithValue("?", ������);

        dbCommand->ExecuteNonQuery();
        MessageBox::Show("�� ����������������");
        dbConnection->Close();

        //

        MyMenu^ form = gcnew MyMenu();

        MessageBox::Show("�� ��������� � ����", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

        // �������� ����� �����
        form->Show();

        // �������� ������� ����� (���� ��� ����������)
        this->Hide();

    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������: " + ex->Message);
    }
   
}
// �����
System::Void ����������������������::Registration::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// ���������� (�� ������)
System::Void ����������������������::Registration::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ ����� = textBox1->ToString();
    String^ ������ = textBox2->ToString();
    double  balance = 100;
    String^ ������ = Convert::ToString(balance);

    try
    {
        // ����������� � ���� ������
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        // ��������� ������ � ���� ������
        dbConnection->Open(); // ��������� ����������
        String^ guery = "INSERT INTO [User] ([�����], [������], [������]) VALUES (?, ?, ?)"; // ������

        OleDbCommand^ dbCommand = gcnew OleDbCommand(guery, dbConnection);

        dbCommand->Parameters->AddWithValue("?", �����);
        dbCommand->Parameters->AddWithValue("?", ������);
        dbCommand->Parameters->AddWithValue("?", ������);

        dbCommand->ExecuteNonQuery();
        MessageBox::Show("�� ����������������");
        dbConnection->Close();

        //

        MyMenu^ form = gcnew MyMenu();

        MessageBox::Show("�� ��������� � ����", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

        // �������� ����� �����
        form->Show();

        // �������� ������� ����� (���� ��� ����������)
        this->Hide();

    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������: " + ex->Message);
    }
}
// ������� ����
System::Void ����������������������::Registration::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyMenu^ form = gcnew MyMenu();

    MessageBox::Show("�� ��������� � ����", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

    // �������� ����� �����
    form->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();

}
// �����
System::Void ����������������������::Registration::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// ������� (�� ������)
System::Void ����������������������::Registration::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
