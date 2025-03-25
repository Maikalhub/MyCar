#include "ReportOrderData.h"
#include "MyMenu.h"
#include "Admin.h"
#include "AdminEditReportsData.h"
//
using namespace System::Data::OleDb;
using namespace System::Data;
////
// ���������
System::Void ����������������������::ReportOrderData::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ����������� � ���� ������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // ��������� ������ � ���� ������
    dbConnection->Open(); // ��������� ����������
    String^ guery = "SELECT * FROM [ReportOrderOver]"; // ������
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
            dataGridView1->Rows->Add(dbReader["�����"], dbReader["������"], dbReader["����� ������"], dbReader["�����"], dbReader["�����"], dbReader["�������"], dbReader["�����"], dbReader["�����"], dbReader["���"]);

        }
    }
    // ��������� ����������
    dbReader->Close();
    dbConnection->Close();
    //
}
// ��������
System::Void ����������������������::ReportOrderData::button22_Click(System::Object^ sender, System::EventArgs^ e)
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
            dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[5]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[6]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[7]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[8]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[9]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[10]->Value == nullptr)
    {
        MessageBox::Show("������");
        return;
    }

    String^ ����� = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ ������ = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ ����������� = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ ������� = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
    String^ ������� = dataGridView1->Rows[index]->Cells[7]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[8]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[9]->Value->ToString();
    String^ ���= dataGridView1->Rows[index]->Cells[10]->Value->ToString();
    // ����������� � ���� ������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // ��������� ������ � ���� ������
    dbConnection->Open(); // ��������� ����������
    String^ guery = "INSERT INTO [ReportOrderOver] VALUES ('" + ����� + "', '" + ����� + "', '" + ������ + "', '" + ����������� + "', '" + ����� + "', '" + ����� + "', '" + ������� + "', '" + ������� + "', '" + ����� + "', '" + ����� + "', '" + ��� + "')"; // ������
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
}
// ��������
System::Void ����������������������::ReportOrderData::button1_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ ����������� = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ ������� = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
    String^ ������� = dataGridView1->Rows[index]->Cells[7]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[8]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[9]->Value->ToString();
    String^ ��� = dataGridView1->Rows[index]->Cells[10]->Value->ToString();

    // ����������� � ���� ������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // ��������� ������ � ���� ������ ��� ���������� ������
    dbConnection->Open();
    String^ guery = "UPDATE [ReportOrderOver] SET ����� = '" + ����� + "', ������ = '" + ������ + "', ����������� = '" + ����������� + "', ����� = '" + ����� + "', ����� = '" + ����� + "', ������� = '" + ������� + "', ������� = '" + ������� + "', ����� = '" + ����� + "', ����� = '" + ����� + "', ��� = '" + ��� + "'WHERE ����� = " + �����;
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
System::Void ����������������������::ReportOrderData::button3_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ guery = "DELETE FROM [ReportOrderOver] WHERE ����� = " + �����;
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
System::Void ����������������������::ReportOrderData::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// �������
System::Void ����������������������::ReportOrderData::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ������� ������ � dataGridView1
    dataGridView1->Rows->Clear();
    return System::Void();
}
// �����
System::Void ����������������������::ReportOrderData::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// ���������
System::Void ����������������������::ReportOrderData::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ����������� � ���� ������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // ��������� ������ � ���� ������
    dbConnection->Open(); // ��������� ����������
    String^ guery = "SELECT * FROM [ReportOrderOver]"; // ������
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
            dataGridView1->Rows->Add(dbReader["�����"], dbReader["������"], dbReader["����� ������"], dbReader["�����"], dbReader["�����"], dbReader["�������"], dbReader["�����"], dbReader["�����"], dbReader["���"]);

        }
    }
    // ��������� ����������
    dbReader->Close();
    dbConnection->Close();
    //
}
// ��������
System::Void ����������������������::ReportOrderData::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
            dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[5]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[6]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[7]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[8]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[9]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[10]->Value == nullptr)
    {
        MessageBox::Show("������");
        return;
    }

    String^ ����� = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ ������ = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ ����������� = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ ������� = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
    String^ ������� = dataGridView1->Rows[index]->Cells[7]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[8]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[9]->Value->ToString();
    String^ ��� = dataGridView1->Rows[index]->Cells[10]->Value->ToString();
    // ����������� � ���� ������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // ��������� ������ � ���� ������
    dbConnection->Open(); // ��������� ����������
    String^ guery = "INSERT INTO [ReportOrderOver] VALUES ('" + ����� + "', '" + ����� + "', '" + ������ + "', '" + ����������� + "', '" + ����� + "', '" + ����� + "', '" + ������� + "', '" + ������� + "', '" + ����� + "', '" + ����� + "', '" + ��� + "')"; // ������
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
}
// ��������
System::Void ����������������������::ReportOrderData::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ ����������� = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ ������� = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
    String^ ������� = dataGridView1->Rows[index]->Cells[7]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[8]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[9]->Value->ToString();
    String^ ��� = dataGridView1->Rows[index]->Cells[10]->Value->ToString();

    // ����������� � ���� ������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // ��������� ������ � ���� ������ ��� ���������� ������
    dbConnection->Open();
    String^ guery = "UPDATE [ReportOrderOver] SET ����� = '" + ����� + "', ������ = '" + ������ + "', ����������� = '" + ����������� + "', ����� = '" + ����� + "', ����� = '" + ����� + "', ������� = '" + ������� + "', ������� = '" + ������� + "', ����� = '" + ����� + "', ����� = '" + ����� + "', ��� = '" + ��� + "'WHERE ����� = " + �����;
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
System::Void ����������������������::ReportOrderData::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ guery = "DELETE FROM [ReportOrderOver] WHERE ����� = " + �����;
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
System::Void ����������������������::ReportOrderData::�����NoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// �������
System::Void ����������������������::ReportOrderData::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ������� ������ � dataGridView1
    dataGridView1->Rows->Clear();
    return System::Void();
}
// ������� ����
System::Void ����������������������::ReportOrderData::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyMenu^ newForm2 = gcnew MyMenu();

    MessageBox::Show("�� ��������� � ������� ����", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

    // �������� ����� �����
    newForm2->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();
}
// ���� ��������������
System::Void ����������������������::ReportOrderData::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Admin^ newForm2 = gcnew Admin();


    // �������� ����� �����
    newForm2->Show();

    // �������� ������� ����� (���� ��� ����������)
    this->Hide();
}
// �����
System::Void ����������������������::ReportOrderData::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}






















//
System::Void ����������������������::ReportOrderData::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
