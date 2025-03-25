#include "UserEditUserDataNewEdit.h"
#include "UserEditUserDataNew.h"
#include "MyMenu.h"
#include "User.h"
//
#include <msclr/marshal_cppstd.h> // ���������� ��� ��������������� ��������� ������ �� WinForms �� ������ �++
#include <string>
#include <Windows.h>
#include <OleDb.h>
#include <iostream>
//
using namespace std;
//
using namespace System;
using namespace System::Windows::Forms;
//
using namespace System::Data;
using namespace System::Data::OleDb;
////
//
// 
// �������������� ����������� ������
System::Void ����������������������::UserEditUserDataNewEdit::UserEditUserDataNewEdit_Load(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// �����
System::Void ����������������������::UserEditUserDataNewEdit::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

    // �������� ����� �����
    newForm2->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();
}
// ����������
System::Void ����������������������::UserEditUserDataNewEdit::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ����������� � ���� ������ Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

    // ��������� ���������� � ����� ������
    connection->Open();

    String^ oldlogin;

    // ������ � ���� ������ ��� ��������� ������� ������
    String^ query = "SELECT [�����] FROM [Report] ";
    OleDbCommand^ command = gcnew OleDbCommand(query, connection);

    // �������� ������ �����
    OleDbDataReader^ reader = command->ExecuteReader();
    if (reader->Read())
    {
        oldlogin = reader["�����"]->ToString();
    }
    else
    {
        // ��������� ���������� � ����� ������ � ������, ���� ��� ������
        if (connection->State == ConnectionState::Open)
        {
            connection->Close();
        }
        Console::WriteLine("�� ������� �������� ������ �����");
        return;
    }

    // ������ � ���� ������ ��� ���������� ������ � ������� ReportUserEdit
    String^ updateQuery = "UPDATE [ReportUserEdit] SET [�����] = ?, [������] = ? WHERE [�����] = ?";
    OleDbCommand^ updateCommand = gcnew OleDbCommand(updateQuery, connection);
    updateCommand->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand->Parameters->AddWithValue("newPasswordParam", textBox2->Text);
    updateCommand->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // ��������� ����������
    updateCommand->ExecuteNonQuery();

    // ������ � ���� ������ ��� ���������� ������ � ������� Report
    String^ updateQuery1 = "UPDATE [Report] SET [�����] = ? WHERE [�����] = ?";
    OleDbCommand^ updateCommand1 = gcnew OleDbCommand(updateQuery1, connection);
    updateCommand1->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand1->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // ��������� ����������
    updateCommand1->ExecuteNonQuery();

    // ������ � ���� ������ ��� ���������� ������ � ������� User
    String^ updateQuery2 = "UPDATE [User] SET [�����] = ?, [������] = ? WHERE [�����] = ?";
    OleDbCommand^ updateCommand2 = gcnew OleDbCommand(updateQuery2, connection);
    updateCommand2->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand2->Parameters->AddWithValue("newPasswordParam", textBox2->Text);
    updateCommand2->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // ��������� ����������
    updateCommand2->ExecuteNonQuery();

    // ��������� ���������� � ����� ������
    if (connection->State == ConnectionState::Open)
    {
        connection->Close();
    }

    Console::WriteLine("������ ������� ��������");

    UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

    // �������� ����� �����
    newForm2->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();
}

// �����
System::Void ����������������������::UserEditUserDataNewEdit::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // �������� ������ �� ������� "Report"
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
        dbConnection->Open();
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        dbCommand->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportCar"
        OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
        dbConnection1->Open();
        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);
        dbCommand1->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportOrder"
        OleDbConnection^ dbConnection2 = gcnew OleDbConnection(connectionString);
        dbConnection2->Open();
        String^ query2 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection2);
        dbCommand2->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� ���� ������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }
    MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// ������� ����
System::Void ����������������������::UserEditUserDataNewEdit::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // �������� ������ �� ������� "Report"
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
        dbConnection->Open();
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        dbCommand->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportCar"
        OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
        dbConnection1->Open();
        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);
        dbCommand1->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportOrder"
        OleDbConnection^ dbConnection2 = gcnew OleDbConnection(connectionString);
        dbConnection2->Open();
        String^ query2 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection2);
        dbCommand2->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� ���� ������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }

    MyMenu^ newForm2 = gcnew MyMenu();

    // �������� ����� �����
    newForm2->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();
}
// ���� ������������
System::Void ����������������������::UserEditUserDataNewEdit::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    User^ newForm2 = gcnew User();

    // �������� ����� �����
    newForm2->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();
}
// �����
System::Void ����������������������::UserEditUserDataNewEdit::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

    // �������� ����� �����
    newForm2->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();
}
// ����������
System::Void ����������������������::UserEditUserDataNewEdit::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ����������� � ���� ������ Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

    // ��������� ���������� � ����� ������
    connection->Open();

    String^ oldlogin;

    // ������ � ���� ������ ��� ��������� ������� ������
    String^ query = "SELECT [�����] FROM [Report] ";
    OleDbCommand^ command = gcnew OleDbCommand(query, connection);

    // �������� ������ �����
    OleDbDataReader^ reader = command->ExecuteReader();
    if (reader->Read())
    {
        oldlogin = reader["�����"]->ToString();
    }
    else
    {
        // ��������� ���������� � ����� ������ � ������, ���� ��� ������
        if (connection->State == ConnectionState::Open)
        {
            connection->Close();
        }
        Console::WriteLine("�� ������� �������� ������ �����");
        return;
    }

    // ������ � ���� ������ ��� ���������� ������ � ������� ReportUserEdit
    String^ updateQuery = "UPDATE [ReportUserEdit] SET [�����] = ?, [������] = ? WHERE [�����] = ?";
    OleDbCommand^ updateCommand = gcnew OleDbCommand(updateQuery, connection);
    updateCommand->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand->Parameters->AddWithValue("newPasswordParam", textBox2->Text);
    updateCommand->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // ��������� ����������
    updateCommand->ExecuteNonQuery();

    // ������ � ���� ������ ��� ���������� ������ � ������� Report
    String^ updateQuery1 = "UPDATE [Report] SET [�����] = ?, [������] = ? WHERE [�����] = ?";
    OleDbCommand^ updateCommand1 = gcnew OleDbCommand(updateQuery1, connection);
    updateCommand1->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand1->Parameters->AddWithValue("newPasswordParam", textBox2->Text);
    updateCommand1->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // ��������� ����������
    updateCommand1->ExecuteNonQuery();

    // ������ � ���� ������ ��� ���������� ������ � ������� User
    String^ updateQuery2 = "UPDATE [User] SET [�����] = ?, [������] = ? WHERE [�����] = ?";
    OleDbCommand^ updateCommand2 = gcnew OleDbCommand(updateQuery2, connection);
    updateCommand2->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand2->Parameters->AddWithValue("newPasswordParam", textBox2->Text);
    updateCommand2->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // ��������� ����������
    updateCommand2->ExecuteNonQuery();

    // ��������� ���������� � ����� ������
    if (connection->State == ConnectionState::Open)
    {
        connection->Close();
    }

    Console::WriteLine("������ ������� ��������");

    UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

    // �������� ����� �����
    newForm2->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();
}
// ������� ����
System::Void ����������������������::UserEditUserDataNewEdit::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // �������� ������ �� ������� "Report"
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
        dbConnection->Open();
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        dbCommand->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportCar"
        OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
        dbConnection1->Open();
        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);
        dbCommand1->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportOrder"
        OleDbConnection^ dbConnection2 = gcnew OleDbConnection(connectionString);
        dbConnection2->Open();
        String^ query2 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection2);
        dbCommand2->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� ���� ������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }

    MyMenu^ newForm2 = gcnew MyMenu();

    // �������� ����� �����
    newForm2->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();
}
// ���� ������������
System::Void ����������������������::UserEditUserDataNewEdit::������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    
    User^ newForm2 = gcnew User();

    // �������� ����� �����
    newForm2->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();
}
// �����
System::Void ����������������������::UserEditUserDataNewEdit::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // �������� ������ �� ������� "Report"
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
        dbConnection->Open();
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        dbCommand->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportCar"
        OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
        dbConnection1->Open();
        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);
        dbCommand1->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportOrder"
        OleDbConnection^ dbConnection2 = gcnew OleDbConnection(connectionString);
        dbConnection2->Open();
        String^ query2 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection2);
        dbCommand2->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� ���� ������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }
    MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
