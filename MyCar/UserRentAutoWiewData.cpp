#include "UserRentAutoWiewData.h"
#include "MyMenu.h"
#include "UserRentAutoDecorOrder.h" // ���������  ��������� ������ ������ 
#include "User.h"
//
using namespace System::Data::OleDb;
using namespace System::Data;
////
// ���������
System::Void ����������������������::UserRentAutoWiewData::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ����������� � ���� ������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // ��������� ������ � ���� ������
    dbConnection->Open(); // ��������� ����������
    String^ guery = "SELECT * FROM [Auto]"; // ������
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
            dataGridView1->Rows->Add(dbReader["�����"], dbReader["�����"], dbReader["������"], dbReader["����� ������"], dbReader["����� �����������"], dbReader["�����"], dbReader["�������"]);

        }
    }
    // ��������� ����������
    dbReader->Close();
    dbConnection->Close();
}
// ��������
System::Void ����������������������::UserRentAutoWiewData::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("������: �������� ���� ������ ��� ���������� � ���� ������.");
        return;
    }

    int index = dataGridView1->SelectedRows[0]->Index;

    if (dataGridView1->Rows[index]->Cells->Count < 6) // �������� �� ������� ��� ������� 6 ��������
    {
        MessageBox::Show("������: ������������ ������ � ������.");
        return;
    }


    String^ ����� = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ ������ = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ ����������� = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[5]->Value->ToString();

    // ����������� � ���� ������ Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // ��������� ������ � ���� ������
    dbConnection->Open();
    String^ query = "INSERT INTO [ReportCar] VALUES ('" + ����� + "', '" + ����� + "', '" + ������ + "', '" + ����������� + "', '" + ����� + "')";
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

    if (dbCommand->ExecuteNonQuery() != 1)
    {
        MessageBox::Show("������: �� ������� ��������� ������ � ���� ������.");
    }
    else
    {
        MessageBox::Show("������: ������ ������� ��������� � ���� ������.");
    }

    // ��������� ����������
    dbConnection->Close();

    UserRentAutoDecorOrder^ form = gcnew UserRentAutoDecorOrder;
    this->Hide();
    form->Show();
}
// �����
System::Void ����������������������::UserRentAutoWiewData::button4_Click(System::Object^ sender, System::EventArgs^ e)
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

        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);

        // ��������� ������
        dbCommand1->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportUserEdit"
        OleDbConnection^ dbConnection4 = gcnew OleDbConnection(connectionString);
        dbConnection4->Open();
        String^ query4 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand4 = gcnew OleDbCommand(query4, dbConnection4);
        dbCommand4->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportUserEdit"
        OleDbConnection^ dbConnection5 = gcnew OleDbConnection(connectionString);
        dbConnection5->Open();
        String^ query5 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand5 = gcnew OleDbCommand(query5, dbConnection5);
        dbCommand5->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� 4 ������.");

       
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
    }
    MessageBox::Show("������� �� ����������� ����������", "��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// ����� (�� ������)
System::Void ����������������������::UserRentAutoWiewData::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
// ���� ������������
System::Void ����������������������::UserRentAutoWiewData::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";


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

        // �������� ������ �� ������� "ReportUserEdit"
        OleDbConnection^ dbConnection3 = gcnew OleDbConnection(connectionString);
        dbConnection3->Open();
        String^ query3 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection3);
        dbCommand3->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� ������� ������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }
    MessageBox::Show("�� ��������� � ������� ����. ��������� ������ ������� ", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    User^ form = gcnew User;
    this->Hide();
    form->Show();
}
// ������� ����
System::Void ����������������������::UserRentAutoWiewData::button3_Click(System::Object^ sender, System::EventArgs^ e)
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

        // �������� ������ �� ������� "ReportUserEdit"
        OleDbConnection^ dbConnection3 = gcnew OleDbConnection(connectionString);
        dbConnection3->Open();
        String^ query3 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection3);
        dbCommand3->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� ������� ������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }
    MessageBox::Show("�� ��������� � ������� ����. ��������� ������ ������� ", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    MyMenu^ form = gcnew MyMenu;
    this->Hide();
    form->Show();
}
//���������
System::Void ����������������������::UserRentAutoWiewData::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ����������� � ���� ������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // ��������� ������ � ���� ������
    dbConnection->Open(); // ��������� ����������
    String^ guery = "SELECT * FROM [Auto]"; // ������
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
            dataGridView1->Rows->Add(dbReader["�����"], dbReader["�����"], dbReader["������"], dbReader["����� ������"], dbReader["����� �����������"], dbReader["�����"], dbReader["�������"]);

        }
    }
    // ��������� ����������
    dbReader->Close();
    dbConnection->Close();
}
//��������
System::Void ����������������������::UserRentAutoWiewData::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("������: �������� ���� ������ ��� ���������� � ���� ������.");
        return;
    }

    int index = dataGridView1->SelectedRows[0]->Index;

    if (dataGridView1->Rows[index]->Cells->Count < 6) // �������� �� ������� ��� ������� 6 ��������
    {
        MessageBox::Show("������: ������������ ������ � ������.");
        return;
    }


    String^ ����� = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ ������ = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ ����������� = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ ����� = dataGridView1->Rows[index]->Cells[5]->Value->ToString();

    // ����������� � ���� ������ Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // ��������� ������ � ���� ������
    dbConnection->Open();
    String^ query = "INSERT INTO [ReportCar] VALUES ('" + ����� + "', '" + ����� + "', '" + ������ + "', '" + ����������� + "', '" + ����� + "')";
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

    if (dbCommand->ExecuteNonQuery() != 1)
    {
        MessageBox::Show("������: �� ������� ��������� ������ � ���� ������.");
    }
    else
    {
        MessageBox::Show("������: ������ ������� ��������� � ���� ������.");
    }

    // ��������� ����������
    dbConnection->Close();

    UserRentAutoDecorOrder^ form = gcnew UserRentAutoDecorOrder;
    this->Hide();
    form->Show();
}
// ����� 
System::Void ����������������������::UserRentAutoWiewData::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
// ������� ����
System::Void ����������������������::UserRentAutoWiewData::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

        // �������� ������ �� ������� "ReportUserEdit"
        OleDbConnection^ dbConnection3 = gcnew OleDbConnection(connectionString);
        dbConnection3->Open();
        String^ query3 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection3);
        dbCommand3->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� ������� ������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }
    MessageBox::Show("�� ��������� � ������� ����. ��������� ������ ������� ", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    MyMenu^ form = gcnew MyMenu;
    this->Hide();
    form->Show();
}
// ��������� � ������ ����
System::Void ����������������������::UserRentAutoWiewData::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{

    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        
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

        // �������� ������ �� ������� "ReportUserEdit"
        OleDbConnection^ dbConnection3 = gcnew OleDbConnection(connectionString);
        dbConnection3->Open();
        String^ query3 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection3);
        dbCommand3->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� ������� ������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }
    MessageBox::Show("�� ��������� � ������� ����. ��������� ������ ������� ", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    User^ form = gcnew User;
    this->Hide();
    form->Show();
}
// �����
System::Void ����������������������::UserRentAutoWiewData::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);

        // ��������� ������
        dbCommand1->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportUserEdit"
        OleDbConnection^ dbConnection4 = gcnew OleDbConnection(connectionString);
        dbConnection4->Open();
        String^ query4 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand4 = gcnew OleDbCommand(query4, dbConnection4);
        dbCommand4->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportUserEdit"
        OleDbConnection^ dbConnection5 = gcnew OleDbConnection(connectionString);
        dbConnection5->Open();
        String^ query5 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand5 = gcnew OleDbCommand(query5, dbConnection5);
        dbCommand5->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� 4 ������.");


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
    }
    MessageBox::Show("������� �� ����������� ����������", "��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
