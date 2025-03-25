#include "AdminAutorisation.h"
#include "MyMenu.h"
#include "Admin.h"
//
using namespace std;
//
using namespace System;
using namespace System::Windows::Forms;
//
using namespace System::Data;
using namespace System::Data::OleDb;
//
System::Void Курсовойпроектфронтэнд::AdminAutorisation::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Показать форму 
    MyMenu^ userForm = gcnew MyMenu();
    userForm->Show();
    this->Hide();
}

System::Void Курсовойпроектфронтэнд::AdminAutorisation::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Получение введенного логина и пароля
    String^ username = textBox1->Text;
    String^ password = textBox2->Text;

    // Преобразование String^ в std::string

    // Строка подключения к базе данных Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    // Создание объекта подключения
    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

    try
    {
        // Открытие подключения
        connection->Open();

        // Создание SQL-запроса для второй таблицы (User)
        String^ queryTable2 = "SELECT Логин FROM [Admin] WHERE Логин = @Username AND Пароль = @Password";
        OleDbCommand^ commandTable2 = gcnew OleDbCommand(queryTable2, connection);

        // Привязка параметров к запросу
        commandTable2->Parameters->AddWithValue("@Username", username);
        commandTable2->Parameters->AddWithValue("@Password", password);



        // Выполнение запроса
        OleDbDataReader^ readerTable2 = commandTable2->ExecuteReader();

        // Проверка результатов запроса для второй таблицы
        if (readerTable2->Read())
        {
            // Получение баланса пользователя

            // Закрытие читателя
            readerTable2->Close();

            // Показать форму User
            Admin^ userForm = gcnew Admin();
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
        // Обработка исключений
        MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally
    {
        // Закрытие подключения в любом случае
        connection->Close();
    }
}

System::Void Курсовойпроектфронтэнд::AdminAutorisation::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}

System::Void Курсовойпроектфронтэнд::AdminAutorisation::потвердитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Получение введенного логина и пароля
    String^ username = textBox1->Text;
    String^ password = textBox2->Text;

    // Преобразование String^ в std::string

    // Строка подключения к базе данных Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    // Создание объекта подключения
    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

    try
    {
        // Открытие подключения
        connection->Open();

        // Создание SQL-запроса для второй таблицы (User)
        String^ queryTable2 = "SELECT Логин FROM [Admin] WHERE Логин = @Username AND Пароль = @Password";
        OleDbCommand^ commandTable2 = gcnew OleDbCommand(queryTable2, connection);

        // Привязка параметров к запросу
        commandTable2->Parameters->AddWithValue("@Username", username);
        commandTable2->Parameters->AddWithValue("@Password", password);



        // Выполнение запроса
        OleDbDataReader^ readerTable2 = commandTable2->ExecuteReader();

        // Проверка результатов запроса для второй таблицы
        if (readerTable2->Read())
        {
            // Получение баланса пользователя

            // Закрытие читателя
            readerTable2->Close();

            // Показать форму User
            Admin^ userForm = gcnew Admin();
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
        // Обработка исключений
        MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally
    {
        // Закрытие подключения в любом случае
        connection->Close();
    }
}

System::Void Курсовойпроектфронтэнд::AdminAutorisation::менюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Показать форму 
    MyMenu^ userForm = gcnew MyMenu();
    userForm->Show();
    this->Hide();
}

System::Void Курсовойпроектфронтэнд::AdminAutorisation::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}

System::Void Курсовойпроектфронтэнд::AdminAutorisation::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Эта программа аренды автомобилей! Авторизируйтесь и вы сможете арендовать любой автомобиль из каталога. Если вы не авторизировались, вы можете пройти регистрацию, нажав на соответствующую кнопку в меню. Приятного пользования!!!\n РоадЛайтЛизинг(c) 2023 г.  ", "Справка", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
