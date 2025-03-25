#include "UserEditUserDataNew.h"
#include "MyMenu.h"
#include "User.h"
#include "UserEditUserDataNewEdit.h"
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
// ����������� ������
System::Void ����������������������::UserEditUserDataNew::UserEditUserDataNew_Load(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		// ����������� � ����� ������ � ���������� ������
		String^ sourceConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

		OleDbConnection^ sourceConnectionReport = gcnew OleDbConnection(sourceConnectionString);

		sourceConnectionReport->Open();

		String^ queryReport = "SELECT * FROM ReportUserEdit";

		OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, sourceConnectionReport);

		OleDbDataReader^ readerReport = commandReport->ExecuteReader();

		// ��������� ������ �� ������ ������ ������ �������
		if (readerReport->Read())
		{
			// �������� ������ �� ������ ������
			String^ Login = readerReport->GetString(2);
			String^ Password = readerReport->GetString(3);
			String^ Balance = readerReport->GetString(1);

			// ���������� ������ � ��������������� ��������� �����
			textBox2->Text = Login->ToString();

			textBox3->Text = Password->ToString();

			textBox1->Text = Balance->ToString();

			readerReport->Close();

			sourceConnectionReport->Close();
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("������ ������ ��������� ������: " + ex->Message);
	}
}
// ��������
System::Void ����������������������::UserEditUserDataNew::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	UserEditUserDataNewEdit^ newForm2 = gcnew UserEditUserDataNewEdit();


	// �������� ����� �����
	newForm2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ����������  // no
System::Void ����������������������::UserEditUserDataNew::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// �����
System::Void ����������������������::UserEditUserDataNew::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
	try
	{
		dbConnection->Open();

		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query = "DELETE FROM [Report]";
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

		// ��������� ������
		dbCommand->ExecuteNonQuery();

		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query1 = "DELETE FROM [ReportUserEdit]";
		OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection);

		// ��������� ������
		dbCommand1->ExecuteNonQuery();

		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query2 = "DELETE FROM [ReportOrder]";
		OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection);

		// ��������� ������
		dbCommand2->ExecuteNonQuery();
		Console::WriteLine("������ ������� ������� �� Report, ReportUserEdit, ReportOrder");

	}
	catch (Exception^ ex)
	{
		// ��������� ����������, ��������, ����� ������ � ������� ��� ���
		Console::WriteLine(ex->Message);
	}
	finally
	{
		// ����� ������� ����������, ���� ���� ��������� ������
		dbConnection->Close();
		MyMenu^ newForm2 = gcnew MyMenu();

		MessageBox::Show("�� ��������� � ������� ����", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// �������� ����� �����
		newForm2->Show();

		// �������� ������� ����� (���� ��� ����������)
		this->Hide();

	};
	MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
// ������� ����
System::Void ����������������������::UserEditUserDataNew::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
	try
	{
		dbConnection->Open();
		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query = "DELETE FROM [Report]";
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

		// ��������� ������
		dbCommand->ExecuteNonQuery();

		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query1 = "DELETE FROM [ReportUserEdit]";
		OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection);

		// ��������� ������
		dbCommand1->ExecuteNonQuery();

		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query2 = "DELETE FROM [ReportOrder]";
		OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection);

		// ��������� ������
		dbCommand2->ExecuteNonQuery();
		Console::WriteLine("������ ������� ������� �� Report, ReportUserEdit, ReportOrder");


	}
	catch (Exception^ ex)
	{
		// ��������� ����������, ��������, ����� ������ � ������� ��� ���
		Console::WriteLine(ex->Message);
	}
	finally
	{
		// ����� ������� ����������, ���� ���� ��������� ������
		dbConnection->Close();
		MyMenu^ newForm2 = gcnew MyMenu();

		MessageBox::Show("�� ��������� � ������� ����", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// �������� ����� �����
		newForm2->Show();

		// �������� ������� ����� (���� ��� ����������)
		this->Hide();

	};
}
// ���� ������������
System::Void ����������������������::UserEditUserDataNew::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	User^ newForm2 = gcnew User();

	MessageBox::Show("�� ��������� � ���� ������������", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// �������� ����� �����
	newForm2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ���������� // no
System::Void ����������������������::UserEditUserDataNew::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// ��������
System::Void ����������������������::UserEditUserDataNew::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	UserEditUserDataNewEdit^ newForm2 = gcnew UserEditUserDataNewEdit();


	// �������� ����� �����
	newForm2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}

System::Void ����������������������::UserEditUserDataNew::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	try
	{
		dbConnection->Open();

		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query = "DELETE FROM [Report]";
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

		// ��������� ������
		dbCommand->ExecuteNonQuery();

		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query1 = "DELETE FROM [ReportUserEdit]";
		OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection);

		// ��������� ������
		dbCommand1->ExecuteNonQuery();

		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query2 = "DELETE FROM [ReportOrder]";
		OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection);

		// ��������� ������
		dbCommand2->ExecuteNonQuery();
		Console::WriteLine("������ ������� ������� �� Report, ReportUserEdit, ReportOrder");

	}
	catch (Exception^ ex)
	{
		// ��������� ����������, ��������, ����� ������ � ������� ��� ���
		Console::WriteLine(ex->Message);
	}
	finally
	{
		// ����� ������� ����������, ���� ���� ��������� ������
		dbConnection->Close();
		MyMenu^ newForm2 = gcnew MyMenu();

		MessageBox::Show("�� ��������� � ������� ����", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// �������� ����� �����
		newForm2->Show();

		// �������� ������� ����� (���� ��� ����������)
		this->Hide();

	};
}

System::Void ����������������������::UserEditUserDataNew::������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	User^ newForm2 = gcnew User();

	MessageBox::Show("�� ��������� � ���� ������������", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// �������� ����� �����
	newForm2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}

System::Void ����������������������::UserEditUserDataNew::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	try
	{
		dbConnection->Open();

		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query = "DELETE FROM [Report]";
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

		// ��������� ������
		dbCommand->ExecuteNonQuery();

		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query1 = "DELETE FROM [ReportUserEdit]";
		OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection);

		// ��������� ������
		dbCommand1->ExecuteNonQuery();

		// ������� SQL-������ ��� �������� ���� ������� �� �������
		String^ query2 = "DELETE FROM [ReportOrder]";
		OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection);

		// ��������� ������
		dbCommand2->ExecuteNonQuery();
		Console::WriteLine("������ ������� ������� �� Report, ReportUserEdit, ReportOrder");

	}
	catch (Exception^ ex)
	{
		// ��������� ����������, ��������, ����� ������ � ������� ��� ���
		Console::WriteLine(ex->Message);
	}
	finally
	{
		// ����� ������� ����������, ���� ���� ��������� ������
		dbConnection->Close();
	};
	MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
