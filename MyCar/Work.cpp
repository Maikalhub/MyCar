     
                                                                     //***************************** ���� *****************************
/*
                                           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ���� * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                                           *                                                     ���������� !!!!                                                  *
                                           *   1.��������� ������ ��� ��������� ������                                                                            *
                                           *   2.��������� ������ ��������� � ��                                                                                  *
                                           *   3.�������� �������� �� ������������ ������ ������ � ������                                                         *     
                                           *   4. ����� (5 ����)     
                                           *   5. ��� ����� � ������ ������� ��������� ������ ������������
                                           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

/*
//*****************************************************************************************************************
//  1) ���������� ����������������� ����, ����������� ��������� ����� :
//    ���������� �����, ����������� ������������, �������� ������ � ������������� ����
�//    ��������, ����������, �������������� � �������� �������
�//    �����, ���������� � ���������� �������;
�//    ���������� ������(����� ������ � ���� ������);
�//    ������ ����� � ����������� �� ��������� ���������������� ������.
// 2) �������� �������� � �������� ���������� � ��������� ��� / � �������� ������.��� �������� ������ � ����������� ������ ������������ ���������� ���������� STL(Standard Template Library).
// 3) ������������� � ��������� ��������� ����������� ����������� :
//    ���������� ������� ��������� �������� - ���������������� ����������������
//    (������������, ������������, ������������);
//    ������������� ����������� �������; !!!!!!!!!!!!!!!!
//    ������������� �������� ���������� �� ������ � �� ��������;
//    ������������� ����������, ����������������, �������������, ����������� �������; !!!!!!!!!!!!!!!
//    ������������� ����������� ����(���������� � �����������); !!!!!!!
//    ���������� ��������� ������ ���������(���������� ����� �++);
//    ������������� ���������� ������� � ����������, ��������������� �������; !!!!!
//    ������������� �������� ������� � �������;
//    ������������� ����������� ������� � �����. !!!!!!11111
// �   ������������� ������������� ��������� ������ � ����� ����������(smart pointers).
//    ������������� ������� �++, ���������� ���������� ����� / ������, ��������������� ������ � �������. !!!!!!1
//*****************************************************************************************************************
*/
// ����������
// �����
// �������
// 


// �� ����������
/*// ������� ����
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
    //��������� ������ � ��
    CombineAndInsertData(destinationConnection, ���, �������, �����, �������, �����);
    // ���������  � ����������
    destinationConnection->Close();
    MessageBox::Show("����� ������� ��������", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    User^ form = gcnew User;
    this->Hide();
    form->Show();
}
//
System::Void ����������������������::UserRentAutoDecorOrder::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    MessageBox::Show("�� ��������� � ������� ����. ��������� ������ ������� ", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    MyMenu^ form = gcnew MyMenu;
    this->Hide();
    form->Show();
}
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
    MessageBox::Show("�� ��������� � ������� ����. ��������� ������ ������� ", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    UserRentAutoWiewData^ form = gcnew UserRentAutoWiewData;
    this->Hide();
    form->Show();
}
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

        Console::WriteLine("������� ������� ��� ������ �� ���� ������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }
    MessageBox::Show("������� �� ����������� ����������", "��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}

*/


// ������ � ��������������� ������� ������ (����)
/*
#include "UserRentAutoDecorOrder.h"
#include "MyMenu.h"
#include "UserRentAutoWiewData.h"




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

// �������������� ����������� ������ ����� ������ ��� ����� ������ � textbox11 -> textbox22
System::Void ����������������������::UserRentAutoDecorOrder::textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    double time;
    double totalAmount;
    double tariff;
    String^ managedString;
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
// ���������
System::Void ����������������������::UserRentAutoDecorOrder::��������_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ ��� = textBox1->Text;
    String^ ������� = textBox2->Text;
    String^ ����� = textBox3->Text;
    String^ ������� = textBox4->Text;
    String^ ����� = textBox22->Text;
    // ������ �����������, �� �������  ����� ���������� 
    DataBase(���, �������, �����, �������, �����);

    MessageBox::Show("����� ������� ��������", "�����!", MessageBoxButtons::OK, MessageBoxIcon::Information);
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

        Console::WriteLine("������� ������� ��� ������ �� ���� ������.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("������ ��� �������� ������: " + ex->Message);
    }

    Application::Exit();
}











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


// �������� ������� 
/*bool BalanceCheck(String^ value1, String^ value2, String^ value3)
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
    dbConnection->Open();

    String^ guery = "UPDATE [Auto] SET ������ = '" + value2  + "' WHERE ����� = " + value3;
    OleDbCommand^ dbCommand = gcnew OleDbCommand(guery, dbConnection);

    double sum = Convert::ToDouble(value1);
    double balance = Convert::ToDouble(value2);
    double result = 0;
    String^ resultConvertToString;

    // value1 == sum
    // value2 == balance

    if (sum > balance || balance == 0)
    {
        Console::WriteLine("���������� ������ ���������");
        return 0;
    }
    else if (sum < balance)
    {
        result = balance - sum;
        resultConvertToString = Convert::ToString(result);

        // Update value2 with the new balance
        value2 = resultConvertToString;

        // Add parameter with the correct data type
        dbCommand->Parameters->AddWithValue("?", OleDbType::Double)->Value = Convert::ToDouble(value2);

        // ���������� �������
        dbCommand->ExecuteNonQuery();

        Console::WriteLine("���������� ������ ������� \n ������ :" + value2);
        Console::WriteLine("���������� ������ �������");
        return 1;
    }

    readerReport->Close();
    sourceConnectionReport->Close();
    dbConnection->Close();

//    return false;
}
*/












/*// �������� SQL-������� ��� ������ �������
        String^ queryTable1 = "SELECT * FROM [Admin] WHERE Username= +����� AND Password = +������";
        OleDbCommand^ commandTable1 = gcnew OleDbCommand(queryTable1, connection);

        // �������� ���������� � �������
        commandTable1->Parameters->AddWithValue("Username", username);
        commandTable1->Parameters->AddWithValue("Password", password);

        // ���������� �������
        OleDbDataReader^ readerTable1 = commandTable1->ExecuteReader();

        // �������� ����������� ������� ��� ������ �������
        if (readerTable1->Read())
        {
            MessageBox::Show("����� ����������, ������������� " + username, "������������!", MessageBoxButtons::OK, MessageBoxIcon::Information);
            // �������� ��������
            readerTable1->Close();
            Admin^ adminForm = gcnew Admin();
            adminForm->Show();
            this->Hide();
            return;
            // ���������� ��������, ��� ��� ������ ������� � ������ �������
        }
        */



        // �����������
        /* // ��������� ���������� ������ � ������
            String^ username = textBox1->Text;
            String^ password = textBox2->Text;

            // �������������� String^ � std::string
            std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
            std::string passwordStr = msclr::interop::marshal_as<std::string>(password);

            // ������ ����������� � ���� ������ Access
            String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
            // �������� ������� �����������
            OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

            try
            {
                // �������� �����������
                connection->Open();

                // �������� SQL-������� ��� ������ ������� (User)
                String^ queryTable2 = "SELECT ������ FROM [User] WHERE ����� = @Username AND ������ = @Password";
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
                    double balance = Convert::ToDouble(readerTable2["������"]);

                    // �������� ��������
                    readerTable2->Close();

                    // �������� SQL-������� ��� ���������� ������ � ������� ������� (Report)
                    String^ queryReport = "INSERT INTO Report ([�����], [������]) VALUES (@Username, @Balance)";
                    OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, connection);
                    commandReport->Parameters->AddWithValue("@Username", username);
                    commandReport->Parameters->AddWithValue("@Balance", balance);

                    // ���������� �������
                    commandReport->ExecuteNonQuery();


                    // �������� ����� User
                    User^ userForm = gcnew User();
                    userForm->Show();
                    this->Hide();

                    // ���������� ������ ��� �������������� ��������� ������
                  //
                  // �������� SQL-������� ��� ���������� ������ � ������� ������� (Report)
                    String^ queryReport1 = "INSERT INTO ReportUserEdit ([�����], [������], [������]) VALUES (@Username, @Password, @Balance)";
                    OleDbCommand^ commandReport1 = gcnew OleDbCommand(queryReport1, connection);
                    commandReport1->Parameters->AddWithValue("@Username", username);
                    commandReport1->Parameters->AddWithValue("@Password", password);
                    commandReport1->Parameters->AddWithValue("@Balance", balance);
                    // ���������� �������
                    commandReport1->ExecuteNonQuery();
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
            }*/






            /*System::Void ����������������������::MyMenu::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
            {
                // ��������� ���������� ������ � ������
                String^ username = textBox1->Text;
                String^ password = textBox2->Text;

                // �������������� String^ � std::string
                std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
                std::string passwordStr = msclr::interop::marshal_as<std::string>(password);

                // ������ ����������� � ���� ������ Access
                String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
                // �������� ������� �����������
                OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

                try
                {
                    // �������� �����������
                    connection->Open();

                    // �������� SQL-������� ��� ������ �������
                    String^ queryTable1 = "SELECT * FROM [Admin] WHERE Username= +����� AND Password = +������";
                    OleDbCommand^ commandTable1 = gcnew OleDbCommand(queryTable1, connection);

                    // �������� ���������� � �������
                    commandTable1->Parameters->AddWithValue("Username", username);
                    commandTable1->Parameters->AddWithValue("Password", password);

                    // ���������� �������
                    OleDbDataReader^ readerTable1 = commandTable1->ExecuteReader();

                    // �������� ����������� ������� ��� ������ �������
                    if (readerTable1->Read())
                    {
                        MessageBox::Show("����� ����������, ������������� " + username, "������������!", MessageBoxButtons::OK, MessageBoxIcon::Information);
                        // �������� ��������
                        readerTable1->Close();
                        Admin^ adminForm = gcnew Admin();
                        adminForm->Show();
                        this->Hide();
                        // ���������� ��������, ��� ��� ������ ������� � ������ �������
                    }
                    else
                    {
                        MessageBox::Show("Authentication failed. Please check your username and password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                    // ���� ������ �� ������� � ������ �������, �������� �������� �� ������ �������

                    // �������� SQL-������� ��� ������ �������
                    String^ queryTable2 = "SELECT * FROM [User] WHERE ����� = @Username AND ������ = @Password AND ������ = @������ " ;
                    OleDbCommand^ commandTable2 = gcnew OleDbCommand(queryTable2, connection);

                    // �������� ���������� � �������
                    commandTable2->Parameters->AddWithValue("@Username", username);
                    commandTable2->Parameters->AddWithValue("@Password", password);
                    commandTable2->Parameters->AddWithValue("@������", balance);
                    // ���������� �������
                    OleDbDataReader^ readerTable2 = commandTable2->ExecuteReader();

                    // �������� ����������� ������� ��� ������ �������
                    if (readerTable2->Read())
                    {
                        // ��������� ������� ������������
                        MessageBox::Show("����� ����������, ������������ " + username, "������������!", MessageBoxButtons::OK, MessageBoxIcon::Information);

                        // �������� ��������
                        readerTable2->Close();

                        // ����������� � ���� ������ Access
                        System::String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
                        OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
                        connection->Open();

                        // ������ ��� ���������� ������ � ������� �������
                        System::String^ destinationQuery = "INSERT INTO Report ([�����], [������]) VALUES (@Value1, @Value3)";
                        OleDbCommand^ destinationCommand = gcnew OleDbCommand(destinationQuery, connection);
                        destinationCommand->Parameters->AddWithValue("@Value1", username);
                        destinationCommand->Parameters->AddWithValue("@Value3", balance);

                        // ��������� ������
                        destinationCommand->ExecuteNonQuery();

                        // �������� ����� User
                        User^ userForm = gcnew User();
                        userForm->Show();
                        this->Hide();
                    }
                    else
                    {
                        MessageBox::Show("Authentication failed. Please check your username and password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }

                    // �������� ���������
                    readerTable1->Close();
                    readerTable2->Close();

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
            */