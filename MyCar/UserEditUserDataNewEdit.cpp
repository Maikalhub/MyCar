#include "UserEditUserDataNewEdit.h"
#include "UserEditUserDataNew.h"
#include "MyMenu.h"
#include "User.h"
//
#include <msclr/marshal_cppstd.h> // библиотека для конвертирования введенных данных из WinForms на логику с++
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
// автоматическое отображение данных
System::Void Курсовойпроектфронтэнд::UserEditUserDataNewEdit::UserEditUserDataNewEdit_Load(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// назад
System::Void Курсовойпроектфронтэнд::UserEditUserDataNewEdit::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// потвердить
System::Void Курсовойпроектфронтэнд::UserEditUserDataNewEdit::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Подключение к базе данных Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

    // Открываем соединение с базой данных
    connection->Open();

    String^ oldlogin;

    // Запрос к базе данных для получения старого логина
    String^ query = "SELECT [Логин] FROM [Report] ";
    OleDbCommand^ command = gcnew OleDbCommand(query, connection);

    // Получаем старый логин
    OleDbDataReader^ reader = command->ExecuteReader();
    if (reader->Read())
    {
        oldlogin = reader["Логин"]->ToString();
    }
    else
    {
        // Закрываем соединение с базой данных в случае, если нет данных
        if (connection->State == ConnectionState::Open)
        {
            connection->Close();
        }
        Console::WriteLine("Не удалось получить старый логин");
        return;
    }

    // Запрос к базе данных для обновления данных в таблице ReportUserEdit
    String^ updateQuery = "UPDATE [ReportUserEdit] SET [Логин] = ?, [Пароль] = ? WHERE [Логин] = ?";
    OleDbCommand^ updateCommand = gcnew OleDbCommand(updateQuery, connection);
    updateCommand->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand->Parameters->AddWithValue("newPasswordParam", textBox2->Text);
    updateCommand->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // Выполняем обновление
    updateCommand->ExecuteNonQuery();

    // Запрос к базе данных для обновления данных в таблице Report
    String^ updateQuery1 = "UPDATE [Report] SET [Логин] = ? WHERE [Логин] = ?";
    OleDbCommand^ updateCommand1 = gcnew OleDbCommand(updateQuery1, connection);
    updateCommand1->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand1->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // Выполняем обновление
    updateCommand1->ExecuteNonQuery();

    // Запрос к базе данных для обновления данных в таблице User
    String^ updateQuery2 = "UPDATE [User] SET [Логин] = ?, [Пароль] = ? WHERE [Логин] = ?";
    OleDbCommand^ updateCommand2 = gcnew OleDbCommand(updateQuery2, connection);
    updateCommand2->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand2->Parameters->AddWithValue("newPasswordParam", textBox2->Text);
    updateCommand2->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // Выполняем обновление
    updateCommand2->ExecuteNonQuery();

    // Закрываем соединение с базой данных
    if (connection->State == ConnectionState::Open)
    {
        connection->Close();
    }

    Console::WriteLine("Данные успешно изменены");

    UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}

// выход
System::Void Курсовойпроектфронтэнд::UserEditUserDataNewEdit::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // Удаление данных из таблицы "Report"
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
        dbConnection->Open();
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        dbCommand->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportCar"
        OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
        dbConnection1->Open();
        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);
        dbCommand1->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportOrder"
        OleDbConnection^ dbConnection2 = gcnew OleDbConnection(connectionString);
        dbConnection2->Open();
        String^ query2 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection2);
        dbCommand2->ExecuteNonQuery();

        Console::WriteLine("Успешно удалены все данные из трех таблиц.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка при удалении данных: " + ex->Message);
    }
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// главное меню
System::Void Курсовойпроектфронтэнд::UserEditUserDataNewEdit::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // Удаление данных из таблицы "Report"
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
        dbConnection->Open();
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        dbCommand->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportCar"
        OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
        dbConnection1->Open();
        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);
        dbCommand1->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportOrder"
        OleDbConnection^ dbConnection2 = gcnew OleDbConnection(connectionString);
        dbConnection2->Open();
        String^ query2 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection2);
        dbCommand2->ExecuteNonQuery();

        Console::WriteLine("Успешно удалены все данные из трех таблиц.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка при удалении данных: " + ex->Message);
    }

    MyMenu^ newForm2 = gcnew MyMenu();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// меню пользователя
System::Void Курсовойпроектфронтэнд::UserEditUserDataNewEdit::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    User^ newForm2 = gcnew User();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// назад
System::Void Курсовойпроектфронтэнд::UserEditUserDataNewEdit::регистрацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// потвердить
System::Void Курсовойпроектфронтэнд::UserEditUserDataNewEdit::потвердитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Подключение к базе данных Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

    // Открываем соединение с базой данных
    connection->Open();

    String^ oldlogin;

    // Запрос к базе данных для получения старого логина
    String^ query = "SELECT [Логин] FROM [Report] ";
    OleDbCommand^ command = gcnew OleDbCommand(query, connection);

    // Получаем старый логин
    OleDbDataReader^ reader = command->ExecuteReader();
    if (reader->Read())
    {
        oldlogin = reader["Логин"]->ToString();
    }
    else
    {
        // Закрываем соединение с базой данных в случае, если нет данных
        if (connection->State == ConnectionState::Open)
        {
            connection->Close();
        }
        Console::WriteLine("Не удалось получить старый логин");
        return;
    }

    // Запрос к базе данных для обновления данных в таблице ReportUserEdit
    String^ updateQuery = "UPDATE [ReportUserEdit] SET [Логин] = ?, [Пароль] = ? WHERE [Логин] = ?";
    OleDbCommand^ updateCommand = gcnew OleDbCommand(updateQuery, connection);
    updateCommand->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand->Parameters->AddWithValue("newPasswordParam", textBox2->Text);
    updateCommand->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // Выполняем обновление
    updateCommand->ExecuteNonQuery();

    // Запрос к базе данных для обновления данных в таблице Report
    String^ updateQuery1 = "UPDATE [Report] SET [Логин] = ?, [Пароль] = ? WHERE [Логин] = ?";
    OleDbCommand^ updateCommand1 = gcnew OleDbCommand(updateQuery1, connection);
    updateCommand1->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand1->Parameters->AddWithValue("newPasswordParam", textBox2->Text);
    updateCommand1->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // Выполняем обновление
    updateCommand1->ExecuteNonQuery();

    // Запрос к базе данных для обновления данных в таблице User
    String^ updateQuery2 = "UPDATE [User] SET [Логин] = ?, [Пароль] = ? WHERE [Логин] = ?";
    OleDbCommand^ updateCommand2 = gcnew OleDbCommand(updateQuery2, connection);
    updateCommand2->Parameters->AddWithValue("newLoginParam", textBox1->Text);
    updateCommand2->Parameters->AddWithValue("newPasswordParam", textBox2->Text);
    updateCommand2->Parameters->AddWithValue("oldLoginParam", oldlogin);

    // Выполняем обновление
    updateCommand2->ExecuteNonQuery();

    // Закрываем соединение с базой данных
    if (connection->State == ConnectionState::Open)
    {
        connection->Close();
    }

    Console::WriteLine("Данные успешно изменены");

    UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// главное меню
System::Void Курсовойпроектфронтэнд::UserEditUserDataNewEdit::главноеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // Удаление данных из таблицы "Report"
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
        dbConnection->Open();
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        dbCommand->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportCar"
        OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
        dbConnection1->Open();
        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);
        dbCommand1->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportOrder"
        OleDbConnection^ dbConnection2 = gcnew OleDbConnection(connectionString);
        dbConnection2->Open();
        String^ query2 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection2);
        dbCommand2->ExecuteNonQuery();

        Console::WriteLine("Успешно удалены все данные из трех таблиц.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка при удалении данных: " + ex->Message);
    }

    MyMenu^ newForm2 = gcnew MyMenu();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// меню пользователя
System::Void Курсовойпроектфронтэнд::UserEditUserDataNewEdit::пользователяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    
    User^ newForm2 = gcnew User();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// выход
System::Void Курсовойпроектфронтэнд::UserEditUserDataNewEdit::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // Удаление данных из таблицы "Report"
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
        dbConnection->Open();
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        dbCommand->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportCar"
        OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
        dbConnection1->Open();
        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);
        dbCommand1->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportOrder"
        OleDbConnection^ dbConnection2 = gcnew OleDbConnection(connectionString);
        dbConnection2->Open();
        String^ query2 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection2);
        dbCommand2->ExecuteNonQuery();

        Console::WriteLine("Успешно удалены все данные из трех таблиц.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка при удалении данных: " + ex->Message);
    }
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
