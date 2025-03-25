#include "AdminAutorisation.h"
#include "MyMenu.h"
#include "Admin.h"
//
using namespace std;
//
using namespace System;
using namespace System::Windows::Forms;
//
using namespace System::Data;
using namespace System::Data::OleDb;
//
System::Void ����������������������::AdminAutorisation::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    // �������� ����� 
    MyMenu^ userForm = gcnew MyMenu();
    userForm->Show();
    this->Hide();
}

System::Void ����������������������::AdminAutorisation::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ��������� ���������� ������ � ������
    String^ username = textBox1->Text;
    String^ password = textBox2->Text;

    // �������������� String^ � std::string

    // ������ ����������� � ���� ������ Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    // �������� ������� �����������
    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

    try
    {
        // �������� �����������
        connection->Open();

        // �������� SQL-������� ��� ������ ������� (User)
        String^ queryTable2 = "SELECT ����� FROM [Admin] WHERE ����� = @Username AND ������ = @Password";
        OleDbCommand^ commandTable2 = gcnew OleDbCommand(queryTable2, connection);

        // �������� ���������� � �������
        commandTable2->Parameters->AddWithValue("@Username", username);
        commandTable2->Parameters->AddWithValue("@Password", password);



        // ���������� �������
        OleDbDataReader^ readerTable2 = commandTable2->ExecuteReader();

        // �������� ����������� ������� ��� ������ �������
        if (readerTable2->Read())
        {
            // ��������� ������� ������������

            // �������� ��������
            readerTable2->Close();

            // �������� ����� User
            Admin^ userForm = gcnew Admin();
            userForm->Show();
            this->Hide();

        }
        else
        {
            MessageBox::Show("Authentication failed. Please check your username and password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (Exception^ ex)
    {
        // ��������� ����������
        MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally
    {
        // �������� ����������� � ����� ������
        connection->Close();
    }
}

System::Void ����������������������::AdminAutorisation::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}

System::Void ����������������������::AdminAutorisation::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ��������� ���������� ������ � ������
    String^ username = textBox1->Text;
    String^ password = textBox2->Text;

    // �������������� String^ � std::string

    // ������ ����������� � ���� ������ Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    // �������� ������� �����������
    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

    try
    {
        // �������� �����������
        connection->Open();

        // �������� SQL-������� ��� ������ ������� (User)
        String^ queryTable2 = "SELECT ����� FROM [Admin] WHERE ����� = @Username AND ������ = @Password";
        OleDbCommand^ commandTable2 = gcnew OleDbCommand(queryTable2, connection);

        // �������� ���������� � �������
        commandTable2->Parameters->AddWithValue("@Username", username);
        commandTable2->Parameters->AddWithValue("@Password", password);



        // ���������� �������
        OleDbDataReader^ readerTable2 = commandTable2->ExecuteReader();

        // �������� ����������� ������� ��� ������ �������
        if (readerTable2->Read())
        {
            // ��������� ������� ������������

            // �������� ��������
            readerTable2->Close();

            // �������� ����� User
            Admin^ userForm = gcnew Admin();
            userForm->Show();
            this->Hide();

        }
        else
        {
            MessageBox::Show("Authentication failed. Please check your username and password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (Exception^ ex)
    {
        // ��������� ����������
        MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally
    {
        // �������� ����������� � ����� ������
        connection->Close();
    }
}

System::Void ����������������������::AdminAutorisation::����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // �������� ����� 
    MyMenu^ userForm = gcnew MyMenu();
    userForm->Show();
    this->Hide();
}

System::Void ����������������������::AdminAutorisation::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}

System::Void ����������������������::AdminAutorisation::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("��� ��������� ������ �����������! ��������������� � �� ������� ���������� ����� ���������� �� ��������. ���� �� �� ����������������, �� ������ ������ �����������, ����� �� ��������������� ������ � ����. ��������� �����������!!!\n ��������������(c) 2023 �.  ", "�������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
