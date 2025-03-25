     
                                                                     //***************************** ПЛАН *****************************
/*
                                           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ПЛАН * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                                           *                                                     Необходимо !!!!                                                  *
                                           *   1.исправить работу при изменении данных                                                                            *
                                           *   2.исправить работу изменения в бд                                                                                  *
                                           *   3.добавить проверку на уникальность данных логина и пароля                                                         *     
                                           *   4. поиск (5 форм)     
                                           *   5. при заход в админа удалить временные данные пользователя
                                           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

/*
//*****************************************************************************************************************
//  1) Разработка пользовательского меню, включающего следующие опции :
//    разделение ролей, авторизация пользователя, хранение пароля в зашифрованном виде
­//    просмотр, добавление, редактирование и удаление записей
­//    поиск, сортировка и фильтрация записей;
­//    реализация заказа(вывод данных в виде отчета);
­//    другие опции в зависимости от специфики автоматизируемой задачи.
// 2) Хранение исходной и итоговой информации в текстовых или / и бинарных файлах.Для хранения данных в оперативной памяти использовать контейнеры библиотеки STL(Standard Template Library).
// 3) Использование в программе следующих программных конструкций :
//    реализация базовых принципов объектно - ориентированного программирования
//    (инкапсуляции, наследования, полиморфизма);
//    использование абстрактных классов; !!!!!!!!!!!!!!!!
//    использование передачи параметров по ссылке и по значению;
//    использование встроенных, пользовательских, дружественных, виртуальных функции; !!!!!!!!!!!!!!!
//    использование пространств имен(встроенных и собственных); !!!!!!!
//    реализация обработки ошибок программы(средствами языка С++);
//    использование перегрузки методов и операторов, переопределение методов; !!!!!
//    использование шаблонов классов и методов;
//    использование статических методов и полей. !!!!!!11111
// ­   использование динамического выделения памяти и умных указателей(smart pointers).
//    использование потоков С++, перегрузки операторов ввода / вывода, контролирования работы с потоком. !!!!!!1
//*****************************************************************************************************************
*/
// шифрование
// поиск
// фнкуции
// 


// не определено
/*// функции меню
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::оформитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // работаем с бд
    OleDbConnection^ destinationConnection = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb");
    destinationConnection->Open();
    // работаем с данными, полученными в фомре
    String^ ФИО = textBox1->Text;
    String^ Телефон = textBox2->Text;
    String^ Почта = textBox3->Text;
    String^ Паспорт = textBox4->Text;
    String^ Сумма = textBox22->Text;
    //
    //добавляем данные в бд
    CombineAndInsertData(destinationConnection, ФИО, Телефон, Почта, Паспорт, Сумма);
    // офомление  и заключение
    destinationConnection->Close();
    MessageBox::Show("Заказ успешно оформлен", "Успех!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    User^ form = gcnew User;
    this->Hide();
    form->Show();
}
//
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::главноеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    MessageBox::Show("Вы вернулись в главное меню. Введенные даныые удалены ", "Успех!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    MyMenu^ form = gcnew MyMenu;
    this->Hide();
    form->Show();
}
//
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::данныеАвтоToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

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

        Console::WriteLine("Успешно удалены все данные из двух таблиц.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка при удалении данных: " + ex->Message);
    }
    MessageBox::Show("Вы вернулись в главное меню. Введенные даныые удалены ", "Успех!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    UserRentAutoWiewData^ form = gcnew UserRentAutoWiewData;
    this->Hide();
    form->Show();
}
//
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    MessageBox::Show("Спасибо за пользование программой", "Прощание", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}

*/


// Работа с дополнительными данными заказа (демо)
/*
#include "UserRentAutoDecorOrder.h"
#include "MyMenu.h"
#include "UserRentAutoWiewData.h"




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

void DataBase(String^ value1, String^ value2, String^ value3, String^ value4, String^ value5)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // Создание SQL-запроса на вставку данных
        String^ query = "INSERT INTO ReportOrder (ФИО, Телефон, Почта, Паспорт, Сумма) VALUES (?, ?, ?, ?, ?)";

        // Установка соединения с базой данных
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        // Создание команды с параметрами
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

        // Добавление параметров
        dbCommand->Parameters->AddWithValue("?", value1);
        dbCommand->Parameters->AddWithValue("?", value2);
        dbCommand->Parameters->AddWithValue("?", value3);
        dbCommand->Parameters->AddWithValue("?", value4);
        dbCommand->Parameters->AddWithValue("?", value5);

        // Выполнение команды
        dbCommand->ExecuteNonQuery();

    }
    // Console::WriteLine("Данные успешно добавлены в базу данных.");
    catch (Exception^ ex)
    {
        MessageBox::Show("Ошибка данных 2");
    }

};

// автоматическое отображение данных суммы аренды при вводе данных в textbox11 -> textbox22
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    double time;
    double totalAmount;
    double tariff;
    String^ managedString;
    // Переносим логику расчета суммы в отдельный метод
    if (Double::TryParse(textBox11->Text, time))
    {
        // Подключение к базе данных Access
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
        OleDbConnection^ connection = gcnew OleDbConnection(connectionString);

        // Открываем соединение с базой данных
        connection->Open();

        // Запрос к базе данных для получения тарифа
        String^ queryTariff = "SELECT TOP 1 [Тариф] FROM [ReportCar]";
        OleDbCommand^ commandTariff = gcnew OleDbCommand(queryTariff, connection);

        // Выполняем запрос и получаем тариф
        Object^ result = commandTariff->ExecuteScalar();

        if (result != nullptr && Double::TryParse(result->ToString(), tariff))
        {
            // Рассчитываем сумму
            totalAmount = time * tariff;

            // Отображаем результат в textBox22
            textBox22->Text = totalAmount.ToString();
        }
        else
        {
            textBox22->Text = "Ошибка: Невозможно получить тариф из базы данных";
        }

        // Закрываем соединение с базой данных
        if (connection->State == ConnectionState::Open)
        {
            connection->Close();
        }
    }
    else {
        textBox22->Text = "Ошибка: Введите числовое значение";
    }
}
// офомление
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::Оформить_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ ФИО = textBox1->Text;
    String^ Телефон = textBox2->Text;
    String^ Почта = textBox3->Text;
    String^ Паспорт = textBox4->Text;
    String^ Сумма = textBox22->Text;
    // данные добавляются, но выводит  общее исключение 
    DataBase(ФИО, Телефон, Почта, Паспорт, Сумма);

    MessageBox::Show("Заказ успешно оформлен", "Успех!", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
// выход
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::button2_Click(System::Object^ sender, System::EventArgs^ e)
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

    Application::Exit();
}











/*
void DataBase1(String^ value1, String^ value2, String^ value3, String^ value4, String^ value5)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // Создание SQL-запроса на вставку данных
        String^ query = "INSERT INTO ReportCar (Марка, Модель, [Номер машины], Тариф) VALUES (?, ?, ?, ?)";

        // Установка соединения с базой данных
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        // Создание команды с параметрами
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

        // Добавление параметров
        dbCommand->Parameters->AddWithValue("?", value1);
        dbCommand->Parameters->AddWithValue("?", value2);
        dbCommand->Parameters->AddWithValue("?", value3);
        dbCommand->Parameters->AddWithValue("?", value4);

        // Выполнение команды
        dbCommand->ExecuteNonQuery();

    }
    // Console::WriteLine("Данные успешно добавлены в базу данных.");
    catch (Exception^ ex)
    {
        MessageBox::Show("Ошибка данных 2");
    }

};
void DataBase2(String^ value1, String^ value2, String^ value3, String^ value4, String^ value5)
{
    try
    {
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        // Создание SQL-запроса на вставку данных
        String^ query = "INSERT INTO Report (Логин) VALUES (?)";

        // Установка соединения с базой данных
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        // Создание команды с параметрами
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

        // Добавление параметров
        dbCommand->Parameters->AddWithValue("?", value1);

        // Выполнение команды
        dbCommand->ExecuteNonQuery();

    }
    //Console::WriteLine("Данные успешно добавлены в базу данных.");
    catch (Exception^ ex)
    {
        MessageBox::Show("Ошибка данных 2");
    }

};

*/


// проверка баланса 
/*bool BalanceCheck(String^ value1, String^ value2, String^ value3)
{
    MessageBox::Show("Подождите пожалуйста. Идет процесс транзации", "Транзакция", MessageBoxButtons::OK, MessageBoxIcon::Information);

    // Подключение к базе данных и извлечение данных
    String^ sourceConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

    // Подключение к источнику данных для чтения
    OleDbConnection^ sourceConnectionReport = gcnew OleDbConnection(sourceConnectionString);
    sourceConnectionReport->Open();

    String^ queryReport = "SELECT * FROM Report";
    OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, sourceConnectionReport);
    OleDbDataReader^ readerReport = commandReport->ExecuteReader();

    // Подключение к базе данных для записи
    OleDbConnection^ dbConnection = gcnew OleDbConnection(sourceConnectionString);
    dbConnection->Open();

    String^ guery = "UPDATE [Auto] SET Баланс = '" + value2  + "' WHERE Логин = " + value3;
    OleDbCommand^ dbCommand = gcnew OleDbCommand(guery, dbConnection);

    double sum = Convert::ToDouble(value1);
    double balance = Convert::ToDouble(value2);
    double result = 0;
    String^ resultConvertToString;

    // value1 == sum
    // value2 == balance

    if (sum > balance || balance == 0)
    {
        Console::WriteLine("Транзакция прошла неуспешно");
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

        // Выполнение команды
        dbCommand->ExecuteNonQuery();

        Console::WriteLine("Транзакция прошла успешно \n Баланс :" + value2);
        Console::WriteLine("Транзакция прошла успешно");
        return 1;
    }

    readerReport->Close();
    sourceConnectionReport->Close();
    dbConnection->Close();

//    return false;
}
*/












/*// Создание SQL-запроса для первой таблицы
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
            return;
            // Завершение проверки, так как запись найдена в первой таблице
        }
        */



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