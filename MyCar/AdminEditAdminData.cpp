#include "AdminEditAdminData.h"
#include "MyMenu.h"
#include "Admin.h"
//
using namespace System::Data;
using namespace System::Data::OleDb;
//
//
//
// ���������
System::Void ����������������������::AdminEditAdminData::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ����������� � ���� ������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// ��������� ������ � ���� ������
	dbConnection->Open(); // ��������� ����������
	String^ guery = "SELECT * FROM [Admin]"; // ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); // ��������� ������

	if (dbReader->HasRows == false)
	{
		MessageBox::Show("������ ���������� ������");
		return System::Void();
	}
	else
	{
		// �������� ������ �� ��
		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["�����"], dbReader["�����"], dbReader["������"]);

		}
	}
	// ��������� ����������
	dbReader->Close();
	dbConnection->Close();
}
// ��������
System::Void ����������������������::AdminEditAdminData::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	//
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("������");
		return;
	}
	
	// ������ ������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	if
		(dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
			dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
			dataGridView1->Rows[index]->Cells[2]->Value == nullptr)
	{
		MessageBox::Show("������");
		return;
	}

	String^ ����� = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ ����� = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ ������ = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	// ����������� � ���� ������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// ��������� ������ � ���� ������
	dbConnection->Open(); // ��������� ����������
	String^ guery = "INSERT INTO [Admin] VALUES ('" + ����� + "', '" + ����� + "', '" + ������ + "')"; // ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);
	if (dbComand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("������ ���������� ������");
	}
	else
	{
		MessageBox::Show("������");
	}
	// ��������� ����������
	dbConnection->Close();
	//
}
// ��������
System::Void ����������������������::AdminEditAdminData::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ���������, ������� �� ����� ���� ������
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("�������� ���� ������ ��� ��������������");
		return;
	}

	// �������� ������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	// ���������, ����� ��� ������ � ��������� ������ ���� ���������
	for (int i = 0; i < dataGridView1->Columns->Count; i++)
	{
		if (dataGridView1->Rows[index]->Cells[i]->Value == nullptr)
		{
			MessageBox::Show("��� ���� ������ ���� ���������");
			return;
		}
	}

	// �������� �������� �� ��������� ������
	String^ ����� = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ ����� = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ ������ = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	// ����������� � ���� ������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// ��������� ������ � ���� ������ ��� ���������� ������
	dbConnection->Open();
	String^ guery = "UPDATE [Admin] SET ����� = '" + ����� + "', ������ = '" + ������ + "' WHERE ����� = " + �����;
	OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);

	//if (dbComand->ExecuteNonQuery() != 1)
	//{
	 //   MessageBox::Show("������ ��� ���������� ������");
	//}
	//else
	//{
	MessageBox::Show("������ ���������");
	// }

	 // ��������� ����������
	dbConnection->Close();
}
// �������
System::Void ����������������������::AdminEditAdminData::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ���������, ������� �� ����� ���� ������
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("�������� ���� ������ ��� ��������");
		return;
	}

	// �������� �������� �� ������ ������ ��������� ������ (��������, �������� ������� "�����")
	String^ ����� = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();

	// ����������� � ���� ������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// ��������� ������ � ���� ������ ��� �������� ������
	dbConnection->Open();
	String^ guery = "DELETE FROM [Admin] WHERE ����� = " + �����;
	OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);

	if (dbComand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("������ ��� �������� ������");
	}
	else
	{
		MessageBox::Show("������ �������");
	}

	// ��������� ����������
	dbConnection->Close();
}
// ����� (�� ������)
System::Void ����������������������::AdminEditAdminData::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// �������
System::Void ����������������������::AdminEditAdminData::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ������� ������ � dataGridView1
	dataGridView1->Rows->Clear();
}
// �����
System::Void ����������������������::AdminEditAdminData::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
//
// 
// ������� ����
// 
// 
// ���� ��������������
System::Void ����������������������::AdminEditAdminData::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	
}
// ���������
System::Void ����������������������::AdminEditAdminData::���������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ����������� � ���� ������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// ��������� ������ � ���� ������
	dbConnection->Open(); // ��������� ����������
	String^ guery = "SELECT * FROM [Admin]"; // ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); // ��������� ������

	if (dbReader->HasRows == false)
	{
		MessageBox::Show("������ ���������� ������");
		return System::Void();
	}
	else
	{
		// �������� ������ �� ��
		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["�����"], dbReader["�����"], dbReader["������"]);

		}
	}
	// ��������� ����������
	dbReader->Close();
	dbConnection->Close();
}
// ��������
System::Void ����������������������::AdminEditAdminData::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	//
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("������");
		return;
	}

	// ������ ������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	if
		(dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
			dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
			dataGridView1->Rows[index]->Cells[2]->Value == nullptr)
	{
		MessageBox::Show("������");
		return;
	}

	String^ ����� = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ ����� = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ ������ = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	// ����������� � ���� ������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// ��������� ������ � ���� ������
	dbConnection->Open(); // ��������� ����������
	String^ guery = "INSERT INTO [Admin] VALUES ('" + ����� + "', '" + ����� + "', '" + ������ + "')"; // ������
	OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);
	if (dbComand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("������ ���������� ������");
	}
	else
	{
		MessageBox::Show("������");
	}
	// ��������� ����������
	dbConnection->Close();
	//
}
// ��������
System::Void ����������������������::AdminEditAdminData::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ���������, ������� �� ����� ���� ������
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("�������� ���� ������ ��� ��������������");
		return;
	}

	// �������� ������ ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	// ���������, ����� ��� ������ � ��������� ������ ���� ���������
	for (int i = 0; i < dataGridView1->Columns->Count; i++)
	{
		if (dataGridView1->Rows[index]->Cells[i]->Value == nullptr)
		{
			MessageBox::Show("��� ���� ������ ���� ���������");
			return;
		}
	}

	// �������� �������� �� ��������� ������
	String^ ����� = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ ����� = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ ������ = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	// ����������� � ���� ������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// ��������� ������ � ���� ������ ��� ���������� ������
	dbConnection->Open();
	String^ guery = "UPDATE [Admin] SET ����� = '" + ����� + "', ������ = '" + ������ + "' WHERE ����� = " + �����;
	OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);

	//if (dbComand->ExecuteNonQuery() != 1)
	//{
	 //   MessageBox::Show("������ ��� ���������� ������");
	//}
	//else
	//{
	MessageBox::Show("������ ���������");
	// }

	 // ��������� ����������
	dbConnection->Close();
}
// �������
System::Void ����������������������::AdminEditAdminData::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ���������, ������� �� ����� ���� ������
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("�������� ���� ������ ��� ��������");
		return;
	}

	// �������� �������� �� ������ ������ ��������� ������ (��������, �������� ������� "�����")
	String^ ����� = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();

	// ����������� � ���� ������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	// ��������� ������ � ���� ������ ��� �������� ������
	dbConnection->Open();
	String^ guery = "DELETE FROM [Admin] WHERE ����� = " + �����;
	OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);

	if (dbComand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("������ ��� �������� ������");
	}
	else
	{
		MessageBox::Show("������ �������");
	}

	// ��������� ����������
	dbConnection->Close();
}
// �����
System::Void ����������������������::AdminEditAdminData::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// �������
System::Void ����������������������::AdminEditAdminData::�������NoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	// ������� ������ � dataGridView1
	dataGridView1->Rows->Clear();
}
// ������� ����
System::Void ����������������������::AdminEditAdminData::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyMenu^ form = gcnew MyMenu();

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// ���� ��������������
System::Void ����������������������::AdminEditAdminData::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Admin^ form = gcnew Admin();

	// �������� ����� �����
	form->Show();

	// �������� ������� ����� (���� ��� ����������)
	this->Hide();
}
// �����
System::Void ����������������������::AdminEditAdminData::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
