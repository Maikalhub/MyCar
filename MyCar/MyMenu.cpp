#include "MyMenu.h"
#include "Admin.h"
#include "User.h"
#include "Registration.h"
#include "Header.h"
// остальные библиотеки
#include <msclr/marshal_cppstd.h> // библиотека для конвертирования введенных данных из WinForms на логику с++
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
        // добавить внутрь функции
        //read_file_data(admin, user, car, order, admin_, user_, car_, order_);
        //
        while (true)
        {
            //
            cout << "ВЫБЕРИТЕ, КАКИМ ОБРАЗОМ ВЫ ХОТИТЕ РАБОТАТЬ :\n1. РАБОТА ПРОГРАММЫ В КОСОЛИ\n2. РАБОТА ПРОГРАММЫ В WinForms\n3. ВЫХОД" << endl;
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
                // Загрузка иконки
                // Создаем экземпляр нашей формы и запускаем приложение.
                Application::Run(gcnew Курсовойпроектфронтэнд::MyMenu());
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



// регистрация
System::Void Курсовойпроектфронтэнд::MyMenu::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    Registration^ Form = gcnew Registration();
    Form->Show();
    this->Hide();
}
// потвердить
System::Void Курсовойпроектфронтэнд::MyMenu::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Получение введенного логина и пароля
    String^ username = textBox1->Text;
    String^ password = textBox2->Text;

    // Преобразование String^ в std::string
    std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
    std::string passwordStr = msclr::interop::marshal_as<std::string>(password);

    // Строка подключения к базе данных Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    // Создание объекта подключения
    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

    try
    {
        // Открытие подключения
        connection->Open();

        // Создание SQL-запроса для второй таблицы (User)
        String^ queryTable2 = "SELECT Баланс FROM [User] WHERE Логин = @Username AND Пароль = @Password";
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
            double balance = Convert::ToDouble(readerTable2["Баланс"]);

            // Закрытие читателя
            readerTable2->Close();

            // Создание SQL-запроса для добавления данных в целевую таблицу (Report)
            String^ queryReport = "INSERT INTO Report ([Логин], [Баланс]) VALUES (@Username, @Balance)";
            OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, connection);
            commandReport->Parameters->AddWithValue("@Username", username);
            commandReport->Parameters->AddWithValue("@Balance", balance);

            // Выполнение запроса
            commandReport->ExecuteNonQuery();

           
            // Показать форму User
            User^ userForm = gcnew User();
            userForm->Show();
            this->Hide();

            // добавление данных для потенциального изменения данных
          // 
          // Создание SQL-запроса для добавления данных в целевую таблицу (Report)
            String^ queryReport1 = "INSERT INTO ReportUserEdit ([Логин], [Пароль], [Баланс]) VALUES (@Username, @Password, @Balance)";
            OleDbCommand^ commandReport1 = gcnew OleDbCommand(queryReport1, connection);
            commandReport1->Parameters->AddWithValue("@Username", username);
            commandReport1->Parameters->AddWithValue("@Password", password);
            commandReport1->Parameters->AddWithValue("@Balance", balance);
            // Выполнение запроса
            commandReport1->ExecuteNonQuery();
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
// выход
System::Void Курсовойпроектфронтэнд::MyMenu::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    try
    {
        dbConnection->Open();

        // Создаем SQL-запрос для удаления всех записей из таблицы
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

        // Выполняем запрос
        dbCommand->ExecuteNonQuery();

        // Создаем SQL-запрос для удаления всех записей из таблицы
        String^ query1 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection);

        // Выполняем запрос
        dbCommand1->ExecuteNonQuery();

        // Создаем SQL-запрос для удаления всех записей из таблицы
        String^ query2 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection);

        // Выполняем запрос
        dbCommand2->ExecuteNonQuery();
        Console::WriteLine("Данные успешно удалены из Report, ReportUserEdit, ReportOrder");

        // Создаем SQL-запрос для удаления всех записей из таблицы
        String^ query3 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection);

        // Выполняем запрос
        dbCommand3->ExecuteNonQuery();
        Console::WriteLine("Данные успешно удалены из Report, ReportUserEdit, ReportOrder");
        // Важно закрыть соединение, даже если произошла ошибка
        dbConnection->Close();
    }
    catch (Exception^ ex)
    {
        // Обработка исключений, например, вывод ошибки в консоль или лог
        Console::WriteLine(ex->Message);
    }

    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
//
// функции меню
//
System::Void Курсовойпроектфронтэнд::MyMenu::регистрацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Registration^ Form = gcnew Registration();
    Form->Show();
    this->Hide();
}
//
System::Void Курсовойпроектфронтэнд::MyMenu::потвердитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

            // Создание SQL-запроса для первой таблицы
            String^ queryTable1 = "SELECT * FROM [Admin] WHERE Username= +Логин AND Password = +Пароль";
            OleDbCommand^ commandTable1 = gcnew OleDbCommand(queryTable1, connection);

            // Привязка параметров к запросу
            commandTable1->Parameters->AddWithValue("Username", username);
            commandTable1->Parameters->AddWithValue("Password", password);

            // Выполнение запроса
            OleDbDataReader^ readerTable1 = commandTable1->ExecuteReader();

            // Проверка результатов запроса для первой таблицы
            if (readerTable1->Read())
            {
                MessageBox::Show("Добро пожаловать, Администратор " + username, "Приветствуем!", MessageBoxButtons::OK, MessageBoxIcon::Information);
                // Закрытие читателя
                readerTable1->Close();
                Admin^ adminForm = gcnew Admin();
                adminForm->Show();
                this->Hide();

                readerTable1->Close();

                // Завершение проверки, так как запись найдена в первой таблице
            }
            readerTable1->Close();

            // Создание SQL-запроса для второй таблицы (User)
            String^ queryTable2 = "SELECT Баланс FROM [User] WHERE Логин = @Username AND Пароль = @Password";
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
                double balance = Convert::ToDouble(readerTable2["Баланс"]);

                // Получение баланса пользователя
                MessageBox::Show("Добро пожаловать, Пользователь " + username, "Приветствуем!", MessageBoxButtons::OK, MessageBoxIcon::Information);

                // Закрытие читателя
                readerTable2->Close();

                // Создание SQL-запроса для добавления данных в целевую таблицу (Report)
                String^ queryReport = "INSERT INTO Report ([Логин], [Баланс]) VALUES (@Username, @Balance)";
                OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, connection);
                commandReport->Parameters->AddWithValue("@Username", username);
                commandReport->Parameters->AddWithValue("@Balance", balance);
                // Преобразование String^ в std::string
                //std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
                //void TransferData(User ^ secondClass)
                //{
                  //  secondClass->ReceiveData(data);
               // }
               // 
                //ТransferData(username);
                // Выполнение запроса
                commandReport->ExecuteNonQuery();

                // Показать форму User
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
            // Обработка исключений
            MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally
        {
            // Закрытие подключения в любом случае
            connection->Close();
        }
};
//
System::Void Курсовойпроектфронтэнд::MyMenu::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    try
    {
       
        dbConnection->Open();

        // Создаем SQL-запрос для удаления всех записей из таблицы
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

        // Выполняем запрос
        dbCommand->ExecuteNonQuery();

        // Создаем SQL-запрос для удаления всех записей из таблицы
        String^ query1 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection);

        // Выполняем запрос
        dbCommand1->ExecuteNonQuery();

        // Создаем SQL-запрос для удаления всех записей из таблицы
        String^ query2 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, dbConnection);

        // Выполняем запрос
        dbCommand2->ExecuteNonQuery();
        Console::WriteLine("Данные успешно удалены из Report, ReportUserEdit, ReportOrder");

        // Создаем SQL-запрос для удаления всех записей из таблицы
        String^ query3 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection);

        // Выполняем запрос
        dbCommand3->ExecuteNonQuery();
        Console::WriteLine("Данные успешно удалены из Report, ReportUserEdit, ReportOrder");
        // Важно закрыть соединение, даже если произошла ошибка
        dbConnection->Close();
    }
    catch (Exception^ ex)
    {
        // Обработка исключений, например, вывод ошибки в консоль или лог
        Console::WriteLine(ex->Message);
    }
    
        MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
        Application::Exit();
}
//
System::Void Курсовойпроектфронтэнд::MyMenu::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Эта программа аренды автомобилей! Авторизируйтесь и вы сможете арендовать любой автомобиль из каталога. Если вы не авторизировались, вы можете пройти регистрацию, нажав на соответствующую кнопку в меню. Приятного пользования!!!\n РоадЛайтЛизинг(c) 2023 г.  ", "Справка", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void Курсовойпроектфронтэнд::MyMenu::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Показать форму User
    AdminAutorisation^ userForm = gcnew AdminAutorisation();
    userForm->Show();
    this->Hide();
}
//

// авторизация
/* // Получение введенного логина и пароля
    String^ username = textBox1->Text;
    String^ password = textBox2->Text;

    // Преобразование String^ в std::string
    std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
    std::string passwordStr = msclr::interop::marshal_as<std::string>(password);

    // Строка подключения к базе данных Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    // Создание объекта подключения
    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

    try
    {
        // Открытие подключения
        connection->Open();

        // Создание SQL-запроса для второй таблицы (User)
        String^ queryTable2 = "SELECT Баланс FROM [User] WHERE Логин = @Username AND Пароль = @Password";
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
            double balance = Convert::ToDouble(readerTable2["Баланс"]);

            // Закрытие читателя
            readerTable2->Close();

            // Создание SQL-запроса для добавления данных в целевую таблицу (Report)
            String^ queryReport = "INSERT INTO Report ([Логин], [Баланс]) VALUES (@Username, @Balance)";
            OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, connection);
            commandReport->Parameters->AddWithValue("@Username", username);
            commandReport->Parameters->AddWithValue("@Balance", balance);

            // Выполнение запроса
            commandReport->ExecuteNonQuery();

           
            // Показать форму User
            User^ userForm = gcnew User();
            userForm->Show();
            this->Hide();

            // добавление данных для потенциального изменения данных
          // 
          // Создание SQL-запроса для добавления данных в целевую таблицу (Report)
            String^ queryReport1 = "INSERT INTO ReportUserEdit ([Логин], [Пароль], [Баланс]) VALUES (@Username, @Password, @Balance)";
            OleDbCommand^ commandReport1 = gcnew OleDbCommand(queryReport1, connection);
            commandReport1->Parameters->AddWithValue("@Username", username);
            commandReport1->Parameters->AddWithValue("@Password", password);
            commandReport1->Parameters->AddWithValue("@Balance", balance);
            // Выполнение запроса
            commandReport1->ExecuteNonQuery();
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
    }*/
//
/*System::Void Курсовойпроектфронтэнд::MyMenu::потвердитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Получение введенного логина и пароля
    String^ username = textBox1->Text;
    String^ password = textBox2->Text;

    // Преобразование String^ в std::string
    std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
    std::string passwordStr = msclr::interop::marshal_as<std::string>(password);

    // Строка подключения к базе данных Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    // Создание объекта подключения
    OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

    try
    {
        // Открытие подключения
        connection->Open();

        // Создание SQL-запроса для первой таблицы
        String^ queryTable1 = "SELECT * FROM [Admin] WHERE Username= +Логин AND Password = +Пароль";
        OleDbCommand^ commandTable1 = gcnew OleDbCommand(queryTable1, connection);

        // Привязка параметров к запросу
        commandTable1->Parameters->AddWithValue("Username", username);
        commandTable1->Parameters->AddWithValue("Password", password);

        // Выполнение запроса
        OleDbDataReader^ readerTable1 = commandTable1->ExecuteReader();

        // Проверка результатов запроса для первой таблицы
        if (readerTable1->Read())
        {
            MessageBox::Show("Добро пожаловать, Администратор " + username, "Приветствуем!", MessageBoxButtons::OK, MessageBoxIcon::Information);
            // Закрытие читателя
            readerTable1->Close();
            Admin^ adminForm = gcnew Admin();
            adminForm->Show();
            this->Hide();
            // Завершение проверки, так как запись найдена в первой таблице
        }
        else
        {
            MessageBox::Show("Authentication failed. Please check your username and password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        // Если запись не найдена в первой таблице, проводим проверку во второй таблице

        // Создание SQL-запроса для второй таблицы
        String^ queryTable2 = "SELECT * FROM [User] WHERE Логин = @Username AND Пароль = @Password AND Баланс = @Баланс " ;
        OleDbCommand^ commandTable2 = gcnew OleDbCommand(queryTable2, connection);

        // Привязка параметров к запросу
        commandTable2->Parameters->AddWithValue("@Username", username);
        commandTable2->Parameters->AddWithValue("@Password", password);
        commandTable2->Parameters->AddWithValue("@Баланс", balance);
        // Выполнение запроса
        OleDbDataReader^ readerTable2 = commandTable2->ExecuteReader();

        // Проверка результатов запроса для второй таблицы
        if (readerTable2->Read())
        {
            // Получение баланса пользователя
            MessageBox::Show("Добро пожаловать, Пользователь " + username, "Приветствуем!", MessageBoxButtons::OK, MessageBoxIcon::Information);

            // Закрытие читателя
            readerTable2->Close();

            // Подключение к базе данных Access
            System::String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
            OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
            connection->Open();

            // Запрос для добавления данных в целевую таблицу
            System::String^ destinationQuery = "INSERT INTO Report ([Логин], [Баланс]) VALUES (@Value1, @Value3)";
            OleDbCommand^ destinationCommand = gcnew OleDbCommand(destinationQuery, connection);
            destinationCommand->Parameters->AddWithValue("@Value1", username);
            destinationCommand->Parameters->AddWithValue("@Value3", balance);

            // Выполняем запрос
            destinationCommand->ExecuteNonQuery();

            // Показать форму User
            User^ userForm = gcnew User();
            userForm->Show();
            this->Hide();
        }       
        else
        {
            MessageBox::Show("Authentication failed. Please check your username and password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

        // Закрытие читателей
        readerTable1->Close();
        readerTable2->Close();

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
*/
//
//void Курсовойпроектфронтэнд::MyMenu::ТransferData(String^ login)
//{
  //  UserEditUserData^ useredituserdata;
    //useredituserdata->ReceiveData(login);
//}
//