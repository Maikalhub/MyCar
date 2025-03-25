#include "UserRentAutoDecorOrder.h"
#include "MyMenu.h"
#include "UserRentAutoWiewData.h"
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
//
// �������������� ����������� ������ ����� ������ ��� ����� ������ � textbox11 -> textbox22
System::Void ����������������������::UserRentAutoDecorOrder::textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    double time;
    double totalAmount;
    double tariff;
    // ��������� ������ ������� ����� � ��������� �����
    if (Double::TryParse(textBox11->Text, time))
    {
        // ����������� � ���� ������ Access
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
        OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

        // ��������� ���������� � ����� ������
        connection->Open();

        // ������ � ���� ������ ��� ��������� ������
        String^ queryTariff = "SELECT TOP 1 [�����] FROM [ReportCar]";
        OleDbCommand^ commandTariff = gcnew OleDbCommand(queryTariff, connection);

        // ��������� ������ � �������� �����
        Object^ result = commandTariff->ExecuteScalar();

        if (result != nullptr && Double::TryParse(result->ToString(), tariff))
        {
            // ������������ �����
            totalAmount = time * tariff;

            // ���������� ��������� � textBox22
            textBox22->Text = totalAmount.ToString();
        }
        else
        {
            textBox22->Text = "������: ���������� �������� ����� �� ���� ������";
        }

        // ��������� ���������� � ����� ������
        if (connection->State == ConnectionState::Open)
        {
            connection->Close();
        }
    }
    else {
        textBox22->Text = "������: ������� �������� ��������";
    }
}
// �������� �������
bool BalanceCheck(String^ value1, String^ value2, String^ value3)
{
    MessageBox::Show("��������� ����������. ���� ������� ���������", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);

    // ����������� � ���� ������ � ���������� ������
    String^ sourceConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

    // ����������� � ��������� ������ ��� ������
    OleDbConnection^ sourceConnectionReport = gcnew OleDbConnection(sourceConnectionString);
    sourceConnectionReport->Open();

    String^ queryReport = "SELECT * FROM Report";
    OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, sourceConnectionReport);
    OleDbDataReader^ readerReport = commandReport->ExecuteReader();

    // ����������� � ���� ������ ��� ������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(sourceConnectionString);
    
    try
    {
        dbConnection->Open();

        String^ query = "UPDATE [User] SET [������] = ? WHERE [�����] = ?";
        String^ query1 = "UPDATE [Report] SET [������] = ? WHERE [�����] = ?";

        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection);

        double sum = Convert::ToDouble(value1);
        double balance = Convert::ToDouble(value2);
        double result = 0;
        String^ resultConvertToString;

        // value1 == sum
        // value2 == balance

        if (sum > balance || balance == 0)
        {
            Console::WriteLine("���������� ������ ���������");
            return false;
        }
        else if (sum < balance)
        {
            result = balance - sum;
            resultConvertToString = Convert::ToString(result);

            // Update value2 with the new balance
            value2 = resultConvertToString;

            // Add parameters with the correct data type
            dbCommand->Parameters->AddWithValue("?", OleDbType::Double)->Value = Convert::ToDouble(value2);
            dbCommand->Parameters->AddWithValue("?", OleDbType::VarChar)->Value = value3;

            dbCommand1->Parameters->AddWithValue("?", OleDbType::Double)->Value = Convert::ToDouble(value2);
            dbCommand1->Parameters->AddWithValue("?", OleDbType::VarChar)->Value = value3;

            // ���������� ������
            dbCommand->ExecuteNonQuery();
            dbCommand1->ExecuteNonQuery();
            //Console::WriteLine("���������� ������ ������� \n ������ :" + value2);
            //Console::WriteLine("���������� ������ �������");
            //MessageBox::Show("������� �������� �������", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
            //MessageBox::Show("��� ������ :" + value2, "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
            return true;
        }
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������: " + ex->Message);
    }
    finally
    {
        readerReport->Close();
        sourceConnectionReport->Close();
        dbConnection->Close();
    }

}
// ������� ��������� 
void DataBase(String^ value1, String^ value2, String^ value3, String^ value4, String^ value5)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // �������� SQL-������� �� ������� ������
        String^ query = "INSERT INTO ReportOrder (���, �������, �����, �������, �����) VALUES (?, ?, ?, ?, ?)";

        // ��������� ���������� � ����� ������
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        // �������� ������� � �����������
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

        // ���������� ����������
        dbCommand->Parameters->AddWithValue("?", value1);
        dbCommand->Parameters->AddWithValue("?", value2);
        dbCommand->Parameters->AddWithValue("?", value3);
        dbCommand->Parameters->AddWithValue("?", value4);
        dbCommand->Parameters->AddWithValue("?", value5);

        // ���������� �������
        dbCommand->ExecuteNonQuery();

    }
    // Console::WriteLine("������ ������� ��������� � ���� ������.");
    catch (Exception^ ex)
    {
        MessageBox::Show("������ ������ 2");
    }

};
//
void InsertDataIntoDestinationDatabase(OleDbConnection^ destinationConnection,String^ value1, String^ value2, String^ value3 ,String^ value4, String^ value5, String^ value6, String^ value7, String^ value8, String^ value9, String^ value10)
{
    try
    {
        // ������� ����� ��������, � ������� �� ������ �������� ������
        String^ query = "INSERT INTO  ReportOrder ([�����], [������], [����� ������], [�����], [�����], [�������], [�������], [�����], [�����], [���]) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, destinationConnection);

        // ������� ����� ��������, � ������� �� ������ �������� ������
        String^ query1 = "INSERT INTO  ReportOrderOver ([�����], [������], [����� ������], [�����], [�����], [�������], [�������], [�����], [�����], [���]) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, destinationConnection);

        // ������� ����� ��������, � ������� �� ������ �������� ������
        String^ query2 = "INSERT INTO  ReportUserOrderOver ([�����], [������], [����� ������], [�����], [�����], [�������], [�������], [�����], [�����], [���]) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, destinationConnection);


        // �������� ��������� ������ ��� ��������� ��������
        dbCommand->Parameters->AddWithValue("?", value6);
        dbCommand->Parameters->AddWithValue("?", value7);
        dbCommand->Parameters->AddWithValue("?", value8);
        dbCommand->Parameters->AddWithValue("?", value9);
        dbCommand->Parameters->AddWithValue("?", value10);
        dbCommand->Parameters->AddWithValue("?", value2);
        dbCommand->Parameters->AddWithValue("?", value4);
        dbCommand->Parameters->AddWithValue("?", value5);
        dbCommand->Parameters->AddWithValue("?", value3); 
        dbCommand->Parameters->AddWithValue("?", value1);
//      dbCommand->Parameters->AddWithValue("?", value8);


        // �������� ��������� ������ ��� ��������� ��������
        dbCommand1->Parameters->AddWithValue("?", value6);
        dbCommand1->Parameters->AddWithValue("?", value7);
        dbCommand1->Parameters->AddWithValue("?", value8);
        dbCommand1->Parameters->AddWithValue("?", value9);
        dbCommand1->Parameters->AddWithValue("?", value10);
        dbCommand1->Parameters->AddWithValue("?", value2);
        dbCommand1->Parameters->AddWithValue("?", value4);
        dbCommand1->Parameters->AddWithValue("?", value5);
        dbCommand1->Parameters->AddWithValue("?", value3);
        dbCommand1->Parameters->AddWithValue("?", value1);
        //      dbCommand->Parameters->AddWithValue("?", value8);



        // �������� ��������� ������ ��� ��������� ��������
        dbCommand2->Parameters->AddWithValue("?", value6);
        dbCommand2->Parameters->AddWithValue("?", value7);
        dbCommand2->Parameters->AddWithValue("?", value8);
        dbCommand2->Parameters->AddWithValue("?", value9);
        dbCommand2->Parameters->AddWithValue("?", value10);
        dbCommand2->Parameters->AddWithValue("?", value2);
        dbCommand2->Parameters->AddWithValue("?", value4);
        dbCommand2->Parameters->AddWithValue("?", value5);
        dbCommand2->Parameters->AddWithValue("?", value3);
        dbCommand2->Parameters->AddWithValue("?", value1);
        //      dbCommand->Parameters->AddWithValue("?", value8);




        dbCommand->ExecuteNonQuery();
        dbCommand1->ExecuteNonQuery();
        dbCommand2->ExecuteNonQuery();

    }
    catch (Exception^ ex)
    {
        MessageBox::Show("������ ������2222: " + ex->Message);
    }
}
//
bool CombineAndInsertData(OleDbConnection^ destinationConnection, String^ value1, String^ value2, String^ value3, String^ value4, String^ value5)
{
    try 
    {
        // ����������� � ����� ������ � ���������� ������
        String^ sourceConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        OleDbConnection^ sourceConnectionCar = gcnew OleDbConnection(sourceConnectionString);
        OleDbConnection^ sourceConnectionReport = gcnew OleDbConnection(sourceConnectionString);

        sourceConnectionCar->Open();
        sourceConnectionReport->Open();

        String^ queryCar = "SELECT * FROM ReportCar";
        String^ queryReport = "SELECT * FROM Report";

        OleDbCommand^ commandCar = gcnew OleDbCommand(queryCar, sourceConnectionCar);
        OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, sourceConnectionReport);

        OleDbDataReader^ readerCar = commandCar->ExecuteReader();
        OleDbDataReader^ readerReport = commandReport->ExecuteReader();

        // ��������� ������ �� ������ ������ ������ �������
        if (readerCar->Read() && readerReport->Read())
        {
            String^ marka = readerCar->GetString(1);
            String^ model = readerCar->GetString(2);
            String^ carNumber = readerCar->GetString(3);
            String^ Tarif = readerCar->GetString(4);
            // �������� ������ �� ������ ������
            String^ Login = readerReport->GetString(1);
            String^ Balance = readerReport->GetString(2);
            if (BalanceCheck(value5, Balance, Login) == false)
            {
                //
                // �������
                // return;
                MessageBox::Show("������� �������� ��������. ����� ������ ��������� ������", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
                return false;
            }
            else if (BalanceCheck(value5, Balance, Login) == true)
            {
                //
                // ������� ������������ ������ � ����� �������
                InsertDataIntoDestinationDatabase(destinationConnection, value1, value2, value3, value4, value5, marka, model, carNumber, Tarif, Login);
            }

            readerCar->Close();
            readerReport->Close();

            sourceConnectionCar->Close();
            sourceConnectionReport->Close();
        }
    }
    catch (Exception^ ex) 
    {
        MessageBox::Show("������ ������ 1111: " + ex->Message);
    }
    return true;
}

void Transaction1(OleDbConnection^ destinationConnection, String^ value1, String^ value2, String^ value3, String^ value4, String^ value5, bool w)
{
    try
    {
        String^ status1 = "������";
        String^ status2 = "�������";
        String^ CardHolder = "CardHolder";
        // ����������� � ����� ������ � ���������� ������
        String^ sourceConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        OleDbConnection^ sourceConnectionCar = gcnew OleDbConnection(sourceConnectionString);
        OleDbConnection^ sourceConnectionReport = gcnew OleDbConnection(sourceConnectionString);

        sourceConnectionCar->Open();
        sourceConnectionReport->Open();

        String^ queryCar = "SELECT * FROM ReportCar";
        String^ queryReport = "SELECT * FROM Report";

        OleDbCommand^ commandCar = gcnew OleDbCommand(queryCar, sourceConnectionCar);
        OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, sourceConnectionReport);

        OleDbDataReader^ readerCar = commandCar->ExecuteReader();
        OleDbDataReader^ readerReport = commandReport->ExecuteReader();

        String^ query2 = "INSERT INTO  [Transaction] ([����], [��������], [�����], [���], [������]) VALUES (?, ?, ?, ?, ?)";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, destinationConnection);


        // ��������� ������ �� ������ ������ ������ �������
        if (readerCar->Read() && readerReport->Read())
        {
            String^ marka = readerCar->GetString(1);
            String^ model = readerCar->GetString(2);
            String^ carNumber = readerCar->GetString(3);
            String^ Tarif = readerCar->GetString(4);
            // �������� ������ �� ������ ������
            String^ Login = readerReport->GetString(1);
            String^ Balance = readerReport->GetString(2);
            
            // ������� ����� ��������, � ������� �� ������ �������� ������
            //String^ query2 = "INSERT INTO  ReportUserOrderOver ([�����], [������], [����� ������], [�����], [�����], [�������], [�������], [�����], [�����], [���]) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        // ��������� ���������� ��� ������� � ������� Transaction


            dbCommand2->Parameters->AddWithValue("?", DateTime::Now);  // ���� � ����� ����������� �������������
            dbCommand2->Parameters->AddWithValue("?", CardHolder);  // ���� � ����� ����������� �������������
            dbCommand2->Parameters->AddWithValue("?", value5);  // ���� � ����� ����������� �������������
            dbCommand2->Parameters->AddWithValue("?", value1);  // ���� � ����� ����������� �������������

                dbCommand2->Parameters->AddWithValue("?", status1);
                dbCommand2->ExecuteNonQuery();

                readerCar->Close();
                readerReport->Close();

                sourceConnectionCar->Close();
                sourceConnectionReport->Close();//             
           
            // �������� ��������� ������ ��� ��������� ��������
            //dbCommand2->Parameters->AddWithValue("?", value6);
            //dbCommand2->Parameters->AddWithValue("?", value7);
            //dbCommand2->Parameters->AddWithValue("?", value8);
            //dbCommand2->Parameters->AddWithValue("?", value9);
            //dbCommand2->Parameters->AddWithValue("?", value10);
            //dbCommand2->Parameters->AddWithValue("?", value2);
            //dbCommand2->Parameters->AddWithValue("?", value4);
            //dbCommand2->Parameters->AddWithValue("?", value5);
            //dbCommand2->Parameters->AddWithValue("?", value3);
            //dbCommand2->Parameters->AddWithValue("?", value1);
            //      dbCommand->Parameters->AddWithValue("?", value8);









           
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("������ ������ ����������: " + ex->Message);
    }
}
void Transaction2(OleDbConnection^ destinationConnection, String^ value1, String^ value2, String^ value3, String^ value4, String^ value5, bool w)
{
    try
    {
        String^ status2 = "�������";
        String^ CardHolder = "CardHolder";
        // ����������� � ����� ������ � ���������� ������
        String^ sourceConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        OleDbConnection^ sourceConnectionCar = gcnew OleDbConnection(sourceConnectionString);
        OleDbConnection^ sourceConnectionReport = gcnew OleDbConnection(sourceConnectionString);

        sourceConnectionCar->Open();
        sourceConnectionReport->Open();

        String^ queryCar = "SELECT * FROM ReportCar";
        String^ queryReport = "SELECT * FROM Report";

        OleDbCommand^ commandCar = gcnew OleDbCommand(queryCar, sourceConnectionCar);
        OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, sourceConnectionReport);

        OleDbDataReader^ readerCar = commandCar->ExecuteReader();
        OleDbDataReader^ readerReport = commandReport->ExecuteReader();

        String^ query2 = "INSERT INTO  [Transaction] ([����], [��������], [�����], [���], [������]) VALUES (?, ?, ?, ?, ?)";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, destinationConnection);


        // ��������� ������ �� ������ ������ ������ �������
        if (readerCar->Read() && readerReport->Read())
        {
            String^ marka = readerCar->GetString(1);
            String^ model = readerCar->GetString(2);
            String^ carNumber = readerCar->GetString(3);
            String^ Tarif = readerCar->GetString(4);
            // �������� ������ �� ������ ������
            String^ Login = readerReport->GetString(1);
            String^ Balance = readerReport->GetString(2);

            // ������� ����� ��������, � ������� �� ������ �������� ������
            //String^ query2 = "INSERT INTO  ReportUserOrderOver ([�����], [������], [����� ������], [�����], [�����], [�������], [�������], [�����], [�����], [���]) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        // ��������� ���������� ��� ������� � ������� Transaction


            dbCommand2->Parameters->AddWithValue("?", DateTime::Now);  // ���� � ����� ����������� �������������
            dbCommand2->Parameters->AddWithValue("?", CardHolder);  // ���� � ����� ����������� �������������
            dbCommand2->Parameters->AddWithValue("?", value5);  // ���� � ����� ����������� �������������
            dbCommand2->Parameters->AddWithValue("?", value1);  // ���� � ����� ����������� �������������
            
                dbCommand2->Parameters->AddWithValue("?", status2); // 
                dbCommand2->ExecuteNonQuery();

                readerCar->Close();
                readerReport->Close();

                sourceConnectionCar->Close();
                sourceConnectionReport->Close();
            // �������� ��������� ������ ��� ��������� ��������
            //dbCommand2->Parameters->AddWithValue("?", value6);
            //dbCommand2->Parameters->AddWithValue("?", value7);
            //dbCommand2->Parameters->AddWithValue("?", value8);
            //dbCommand2->Parameters->AddWithValue("?", value9);
            //dbCommand2->Parameters->AddWithValue("?", value10);
            //dbCommand2->Parameters->AddWithValue("?", value2);
            //dbCommand2->Parameters->AddWithValue("?", value4);
            //dbCommand2->Parameters->AddWithValue("?", value5);
            //dbCommand2->Parameters->AddWithValue("?", value3);
            //dbCommand2->Parameters->AddWithValue("?", value1);
            //      dbCommand->Parameters->AddWithValue("?", value8);










        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("������ ������ ����������: " + ex->Message);
    }
}

// ���������
System::Void ����������������������::UserRentAutoDecorOrder::��������_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    bool w = true;
    // �������� � ��
    OleDbConnection^ destinationConnection = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb");
    destinationConnection->Open();
    // �������� � �������, ����������� � �����
    String^ ��� = textBox1->Text;
    String^ ������� = textBox2->Text;
    String^ ����� = textBox3->Text;
    String^ ������� = textBox4->Text;
    String^ ����� = textBox22->Text;
    //
    //
    //textBox11->Text = " ";
    //��������� ������ � ��
    if (CombineAndInsertData(destinationConnection, ���, �������, �����, �������, �����) == false)
    {
        Transaction1(destinationConnection, ���, �������, �����, �������, �����, false);
        MessageBox::Show("���������� ������ ��������", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else
    {
        Transaction2(destinationConnection, ���, �������, �����, �������, �����, true);
        MessageBox::Show("���������� ������ �������", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
        MessageBox::Show("����� ������� ��������", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);

        
    }
    // �������� ������ �� ������� "Report"
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
    dbConnection->Open();
    String^ query = "DELETE FROM [ReportCar]";
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
    dbCommand->ExecuteNonQuery();
    // ���������  � ����������
    destinationConnection->Close();
    MyMenu^ form = gcnew MyMenu;
    this->Hide();
    form->Show();
}
// �����
System::Void ����������������������::UserRentAutoDecorOrder::button2_Click(System::Object^ sender, System::EventArgs^ e)
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
        OleDbConnection^ dbConnection4 = gcnew OleDbConnection(connectionString);
        dbConnection4->Open();
        String^ query4 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand4 = gcnew OleDbCommand(query4, dbConnection4);
        dbCommand4->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� 4 ������.");

    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }
    MessageBox::Show("������� �� ����������� ����������", "��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// �������� � ������ ����
System::Void ����������������������::UserRentAutoDecorOrder::button3_Click(System::Object^ sender, System::EventArgs^ e)
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

        Console::WriteLine("������� ������� ��� ������ �� ���� ������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }
    MessageBox::Show("�� ��������� � ������ ����. ��������� ������ ������� ", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    UserRentAutoWiewData^ form = gcnew UserRentAutoWiewData;
    this->Hide();
    form->Show();
}
// �������� � ������� ����
System::Void ����������������������::UserRentAutoDecorOrder::button4_Click(System::Object^ sender, System::EventArgs^ e)
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
//
// 
// ������� ����
//
//
// ��������
System::Void ����������������������::UserRentAutoDecorOrder::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // �������� � ��
    OleDbConnection^ destinationConnection = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb");
    destinationConnection->Open();
    // �������� � �������, ����������� � �����
    String^ ��� = textBox1->Text;
    String^ ������� = textBox2->Text;
    String^ ����� = textBox3->Text;
    String^ ������� = textBox4->Text;
    String^ ����� = textBox22->Text;
    //
    //textBox11->Text = " ";
    //��������� ������ � ��
    CombineAndInsertData(destinationConnection, ���, �������, �����, �������, �����);
    // ���������  � ����������
    destinationConnection->Close();
    MessageBox::Show("����� ������� ��������", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

    // �������� ������ �� ������� "Report"
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
    dbConnection->Open();
    String^ query = "DELETE FROM [ReportCar]";
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
    dbCommand->ExecuteNonQuery();
    MyMenu^ form = gcnew MyMenu;
    this->Hide();
    form->Show();

};
//
System::Void ����������������������::UserRentAutoDecorOrder::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
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

        // �������� ������ �� ������� "ReportOrder"
        OleDbConnection^ dbConnection3 = gcnew OleDbConnection(connectionString);
        dbConnection3->Open();
        String^ query3 = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection3);
        dbCommand3->ExecuteNonQuery();

        // �������� ������ �� ������� "ReportUserEdit"
        OleDbConnection^ dbConnection4 = gcnew OleDbConnection(connectionString);
        dbConnection4->Open();
        String^ query4 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand4 = gcnew OleDbCommand(query4, dbConnection4);
        dbCommand4->ExecuteNonQuery();

        Console::WriteLine("������� ������� ��� ������ �� 4 ������.");
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
};
//
System::Void ����������������������::UserRentAutoDecorOrder::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
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

        Console::WriteLine("������� ������� ��� ������ ���������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }
    MessageBox::Show("�� ��������� � ������ ����. ��������� ������ ������� ", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    UserRentAutoWiewData^ form = gcnew UserRentAutoWiewData;
    this->Hide();
    form->Show();
};
//
System::Void ����������������������::UserRentAutoDecorOrder::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
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
    MessageBox::Show("������� �� ����������� ����������", "��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
};









//
//
//  ������� ���������� ������ � �� (��������)
/*
void DataBase1(String^ value1, String^ value2, String^ value3, String^ value4, String^ value5)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // �������� SQL-������� �� ������� ������
        String^ query = "INSERT INTO ReportCar (�����, ������, [����� ������], �����) VALUES (?, ?, ?, ?)";

        // ��������� ���������� � ����� ������
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        // �������� ������� � �����������
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

        // ���������� ����������
        dbCommand->Parameters->AddWithValue("?", value1);
        dbCommand->Parameters->AddWithValue("?", value2);
        dbCommand->Parameters->AddWithValue("?", value3);
        dbCommand->Parameters->AddWithValue("?", value4);

        // ���������� �������
        dbCommand->ExecuteNonQuery();

    }
    // Console::WriteLine("������ ������� ��������� � ���� ������.");
    catch (Exception^ ex)
    {
        MessageBox::Show("������ ������ 2");
    }

};
void DataBase2(String^ value1, String^ value2, String^ value3, String^ value4, String^ value5)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // �������� SQL-������� �� ������� ������
        String^ query = "INSERT INTO Report (�����) VALUES (?)";

        // ��������� ���������� � ����� ������
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        // �������� ������� � �����������
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

        // ���������� ����������
        dbCommand->Parameters->AddWithValue("?", value1);

        // ���������� �������
        dbCommand->ExecuteNonQuery();

    }
    //Console::WriteLine("������ ������� ��������� � ���� ������.");
    catch (Exception^ ex)
    {
        MessageBox::Show("������ ������ 2");
    }

};

*/