#include "User.h"
#include "MyMenu.h"
#include "UserRentAutoWiewData.h"
#include "UserEditUserDataNew.h"
using namespace System::Data;
using namespace System::Data::OleDb;
// ���������� ����
System::Void ����������������������::User::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    UserRentAutoWiewData^ newForm2 = gcnew UserRentAutoWiewData();

    // �������� ����� �����
    newForm2->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();

}
// �����
System::Void ����������������������::User::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	using namespace System::Data;
	using namespace System::Data::OleDb;
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
		MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		Application::Exit();
	};
}
// ������� � ���� 
System::Void ����������������������::User::button4_Click(System::Object^ sender, System::EventArgs^ e)
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
// �������� ������
System::Void ����������������������::User::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

	// �������� ����� �����
	newForm2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
//
// ������� ����
//
// 
// �������� ������
System::Void ����������������������::User::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

	// �������� ����� �����
	newForm2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ������ ����
System::Void ����������������������::User::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	UserRentAutoWiewData^ newForm2 = gcnew UserRentAutoWiewData();

	// �������� ����� �����
	newForm2->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ������� � ����
System::Void ����������������������::User::����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
// �����
System::Void ����������������������::User::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		Application::Exit();
	};
}
