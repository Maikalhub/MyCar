#include "MyMenu.h"
#include "Admin.h"
#include "User.h"
#include "Registration.h"
#include "Header.h"
// ��������� ����������
#include <msclr/marshal_cppstd.h> // ���������� ��� ��������������� ��������� ������ �� WinForms �� ������ �++
#include <string>
#include <Windows.h>
#include <OleDb.h>
#include <iostream>
#include "AdminAutorisation.h"
//
using namespace std;
//
using namespace System;
using namespace System::Windows::Forms;
//
using namespace System::Data;
using namespace System::Data::OleDb;
//
// 
[STAThread]
int main()
{
    //
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //
    try
    {
        //
        int i = 0;
        int n;
        //
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        //
        Admin admin;
        User user;
        Car car;
        Order order;
        Transaction<Order>;
        //
        vector<Admin> admin_;
        vector <User> user_;
        vector<Car> car_;
        vector<Order> order_;
        //
        vector<unique_ptr<Transaction<Order>>>;
        //
        // �������� ������ �������
        //read_file_data(admin, user, car, order, admin_, user_, car_, order_);
        //
        while (true)
        {
            //
            cout << "��������, ����� ������� �� ������ �������� :\n1. ������ ��������� � ������\n2. ������ ��������� � WinForms\n3. �����" << endl;
            cin >> n;
            //
            switch (n)
            {
            case 1:
                autorisation_total();
                break;
            case 2:
                Application::EnableVisualStyles();
                Application::SetCompatibleTextRenderingDefault(false);
                // �������� ������
                // ������� ��������� ����� ����� � ��������� ����������.
                Application::Run(gcnew ����������������������::MyMenu());
            case 3:
                return 0;
            default:
                break;
            }
            //
        }
    }
    catch (const std::exception& e)
    {
        //
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return 1;
        //
    }
    catch (...)
    {
        //
        std::cerr << "An unknown exception occurred." << std::endl;
        return 1;
        //
    }
    //
}



// �����������
System::Void ����������������������::MyMenu::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    Registration^ Form = gcnew Registration();
    Form->Show();
    this->Hide();
}
// ����������
System::Void ����������������������::MyMenu::button2_Click(System::Object^ sender, System::EventArgs^ e)
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
    }
}
// �����
System::Void ����������������������::MyMenu::button3_Click(System::Object^ sender, System::EventArgs^ e)
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

        // ������� SQL-������ ��� �������� ���� ������� �� �������
        String^ query3 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection);

        // ��������� ������
        dbCommand3->ExecuteNonQuery();
        Console::WriteLine("������ ������� ������� �� Report, ReportUserEdit, ReportOrder");
        // ����� ������� ����������, ���� ���� ��������� ������
        dbConnection->Close();
    }
    catch (Exception^ ex)
    {
        // ��������� ����������, ��������, ����� ������ � ������� ��� ���
        Console::WriteLine(ex->Message);
    }

    MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
//
// ������� ����
//
System::Void ����������������������::MyMenu::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Registration^ Form = gcnew Registration();
    Form->Show();
    this->Hide();
}
//
System::Void ����������������������::MyMenu::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

                readerTable1->Close();

                // ���������� ��������, ��� ��� ������ ������� � ������ �������
            }
            readerTable1->Close();

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

                // ��������� ������� ������������
                MessageBox::Show("����� ����������, ������������ " + username, "������������!", MessageBoxButtons::OK, MessageBoxIcon::Information);

                // �������� ��������
                readerTable2->Close();

                // �������� SQL-������� ��� ���������� ������ � ������� ������� (Report)
                String^ queryReport = "INSERT INTO Report ([�����], [������]) VALUES (@Username, @Balance)";
                OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, connection);
                commandReport->Parameters->AddWithValue("@Username", username);
                commandReport->Parameters->AddWithValue("@Balance", balance);
                // �������������� String^ � std::string
                //std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
                //void TransferData(User ^ secondClass)
                //{
                  //  secondClass->ReceiveData(data);
               // }
               // 
                //�ransferData(username);
                // ���������� �������
                commandReport->ExecuteNonQuery();

                // �������� ����� User
                User^ userForm = gcnew User();
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
};
//
System::Void ����������������������::MyMenu::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

        // ������� SQL-������ ��� �������� ���� ������� �� �������
        String^ query3 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection);

        // ��������� ������
        dbCommand3->ExecuteNonQuery();
        Console::WriteLine("������ ������� ������� �� Report, ReportUserEdit, ReportOrder");
        // ����� ������� ����������, ���� ���� ��������� ������
        dbConnection->Close();
    }
    catch (Exception^ ex)
    {
        // ��������� ����������, ��������, ����� ������ � ������� ��� ���
        Console::WriteLine(ex->Message);
    }
    
        MessageBox::Show("������� �� �������������. ����������!!!", "��������� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
        Application::Exit();
}
//
System::Void ����������������������::MyMenu::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("��� ��������� ������ �����������! ��������������� � �� ������� ���������� ����� ���������� �� ��������. ���� �� �� ����������������, �� ������ ������ �����������, ����� �� ��������������� ������ � ����. ��������� �����������!!!\n ��������������(c) 2023 �.  ", "�������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void ����������������������::MyMenu::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    // �������� ����� User
    AdminAutorisation^ userForm = gcnew AdminAutorisation();
    userForm->Show();
    this->Hide();
}
//

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
//
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
//
//void ����������������������::MyMenu::�ransferData(String^ login)
//{
  //  UserEditUserData^ useredituserdata;
    //useredituserdata->ReceiveData(login);
//}
//