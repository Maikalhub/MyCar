#include "UserRentAutoDecorOrder.h"
#include "MyMenu.h"
#include "UserRentAutoWiewData.h"
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
//
// автоматическое отображение данных суммы аренды при вводе данных в textbox11 -> textbox22
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    double time;
    double totalAmount;
    double tariff;
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
// проверка баланса
bool BalanceCheck(String^ value1, String^ value2, String^ value3)
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
    
    try
    {
        dbConnection->Open();

        String^ query = "UPDATE [User] SET [Баланс] = ? WHERE [Логин] = ?";
        String^ query1 = "UPDATE [Report] SET [Баланс] = ? WHERE [Логин] = ?";

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
            Console::WriteLine("Транзакция прошла неуспешно");
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

            // Выполнение команд
            dbCommand->ExecuteNonQuery();
            dbCommand1->ExecuteNonQuery();
            //Console::WriteLine("Транзакция прошла успешно \n Баланс :" + value2);
            //Console::WriteLine("Транзакция прошла успешно");
            //MessageBox::Show("Процесс завершен успешно", "Транзакция", MessageBoxButtons::OK, MessageBoxIcon::Information);
            //MessageBox::Show("Ваш баланс :" + value2, "Транзакция", MessageBoxButtons::OK, MessageBoxIcon::Information);
            return true;
        }
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка: " + ex->Message);
    }
    finally
    {
        readerReport->Close();
        sourceConnectionReport->Close();
        dbConnection->Close();
    }

}
// функции офомления 
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
//
void InsertDataIntoDestinationDatabase(OleDbConnection^ destinationConnection,String^ value1, String^ value2, String^ value3 ,String^ value4, String^ value5, String^ value6, String^ value7, String^ value8, String^ value9, String^ value10)
{
    try
    {
        // Укажите имена столбцов, в которые вы хотите вставить данные
        String^ query = "INSERT INTO  ReportOrder ([Марка], [Модель], [Номер машины], [Тариф], [Логин], [Телефон], [Паспорт], [Сумма], [Почта], [ФИО]) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, destinationConnection);

        // Укажите имена столбцов, в которые вы хотите вставить данные
        String^ query1 = "INSERT INTO  ReportOrderOver ([Марка], [Модель], [Номер машины], [Тариф], [Логин], [Телефон], [Паспорт], [Сумма], [Почта], [ФИО]) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, destinationConnection);

        // Укажите имена столбцов, в которые вы хотите вставить данные
        String^ query2 = "INSERT INTO  ReportUserOrderOver ([Марка], [Модель], [Номер машины], [Тариф], [Логин], [Телефон], [Паспорт], [Сумма], [Почта], [ФИО]) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, destinationConnection);


        // Добавьте параметры только для указанных столбцов
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


        // Добавьте параметры только для указанных столбцов
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



        // Добавьте параметры только для указанных столбцов
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
        MessageBox::Show("Ошибка данных2222: " + ex->Message);
    }
}
//
bool CombineAndInsertData(OleDbConnection^ destinationConnection, String^ value1, String^ value2, String^ value3, String^ value4, String^ value5)
{
    try 
    {
        // Подключение к базам данных и извлечение данных
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

        // Получение данных из первой строки каждой таблицы
        if (readerCar->Read() && readerReport->Read())
        {
            String^ marka = readerCar->GetString(1);
            String^ model = readerCar->GetString(2);
            String^ carNumber = readerCar->GetString(3);
            String^ Tarif = readerCar->GetString(4);
            // Получите данные из других таблиц
            String^ Login = readerReport->GetString(1);
            String^ Balance = readerReport->GetString(2);
            if (BalanceCheck(value5, Balance, Login) == false)
            {
                //
                // очистка
                // return;
                MessageBox::Show("Процесс завершен неудачно. Сумма аренды превышает баланс", "Транзакция", MessageBoxButtons::OK, MessageBoxIcon::Information);
                return false;
            }
            else if (BalanceCheck(value5, Balance, Login) == true)
            {
                //
                // Вставка объединенных данных в новую таблицу
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
        MessageBox::Show("Ошибка данных 1111: " + ex->Message);
    }
    return true;
}

void Transaction1(OleDbConnection^ destinationConnection, String^ value1, String^ value2, String^ value3, String^ value4, String^ value5, bool w)
{
    try
    {
        String^ status1 = "Отмена";
        String^ status2 = "Успешно";
        String^ CardHolder = "CardHolder";
        // Подключение к базам данных и извлечение данных
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

        String^ query2 = "INSERT INTO  [Transaction] ([Дата], [Карточка], [Сумма], [ФИО], [Статус]) VALUES (?, ?, ?, ?, ?)";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, destinationConnection);


        // Получение данных из первой строки каждой таблицы
        if (readerCar->Read() && readerReport->Read())
        {
            String^ marka = readerCar->GetString(1);
            String^ model = readerCar->GetString(2);
            String^ carNumber = readerCar->GetString(3);
            String^ Tarif = readerCar->GetString(4);
            // Получите данные из других таблиц
            String^ Login = readerReport->GetString(1);
            String^ Balance = readerReport->GetString(2);
            
            // Укажите имена столбцов, в которые вы хотите вставить данные
            //String^ query2 = "INSERT INTO  ReportUserOrderOver ([Марка], [Модель], [Номер машины], [Тариф], [Логин], [Телефон], [Паспорт], [Сумма], [Почта], [ФИО]) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        // Установка параметров для вставки в таблицу Transaction


            dbCommand2->Parameters->AddWithValue("?", DateTime::Now);  // Дата и время вставляются автоматически
            dbCommand2->Parameters->AddWithValue("?", CardHolder);  // Дата и время вставляются автоматически
            dbCommand2->Parameters->AddWithValue("?", value5);  // Дата и время вставляются автоматически
            dbCommand2->Parameters->AddWithValue("?", value1);  // Дата и время вставляются автоматически

                dbCommand2->Parameters->AddWithValue("?", status1);
                dbCommand2->ExecuteNonQuery();

                readerCar->Close();
                readerReport->Close();

                sourceConnectionCar->Close();
                sourceConnectionReport->Close();//             
           
            // Добавьте параметры только для указанных столбцов
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
        MessageBox::Show("Ошибка данных Транзакции: " + ex->Message);
    }
}
void Transaction2(OleDbConnection^ destinationConnection, String^ value1, String^ value2, String^ value3, String^ value4, String^ value5, bool w)
{
    try
    {
        String^ status2 = "Успешно";
        String^ CardHolder = "CardHolder";
        // Подключение к базам данных и извлечение данных
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

        String^ query2 = "INSERT INTO  [Transaction] ([Дата], [Карточка], [Сумма], [ФИО], [Статус]) VALUES (?, ?, ?, ?, ?)";
        OleDbCommand^ dbCommand2 = gcnew OleDbCommand(query2, destinationConnection);


        // Получение данных из первой строки каждой таблицы
        if (readerCar->Read() && readerReport->Read())
        {
            String^ marka = readerCar->GetString(1);
            String^ model = readerCar->GetString(2);
            String^ carNumber = readerCar->GetString(3);
            String^ Tarif = readerCar->GetString(4);
            // Получите данные из других таблиц
            String^ Login = readerReport->GetString(1);
            String^ Balance = readerReport->GetString(2);

            // Укажите имена столбцов, в которые вы хотите вставить данные
            //String^ query2 = "INSERT INTO  ReportUserOrderOver ([Марка], [Модель], [Номер машины], [Тариф], [Логин], [Телефон], [Паспорт], [Сумма], [Почта], [ФИО]) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        // Установка параметров для вставки в таблицу Transaction


            dbCommand2->Parameters->AddWithValue("?", DateTime::Now);  // Дата и время вставляются автоматически
            dbCommand2->Parameters->AddWithValue("?", CardHolder);  // Дата и время вставляются автоматически
            dbCommand2->Parameters->AddWithValue("?", value5);  // Дата и время вставляются автоматически
            dbCommand2->Parameters->AddWithValue("?", value1);  // Дата и время вставляются автоматически
            
                dbCommand2->Parameters->AddWithValue("?", status2); // 
                dbCommand2->ExecuteNonQuery();

                readerCar->Close();
                readerReport->Close();

                sourceConnectionCar->Close();
                sourceConnectionReport->Close();
            // Добавьте параметры только для указанных столбцов
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
        MessageBox::Show("Ошибка данных Транзакции: " + ex->Message);
    }
}

// офомление
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::Оформить_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    bool w = true;
    // работаем с бд
    OleDbConnection^ destinationConnection = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb");
    destinationConnection->Open();
    // работаем с данными, полученными в форме
    String^ ФИО = textBox1->Text;
    String^ Телефон = textBox2->Text;
    String^ Почта = textBox3->Text;
    String^ Паспорт = textBox4->Text;
    String^ Сумма = textBox22->Text;
    //
    //
    //textBox11->Text = " ";
    //добавляем данные в бд
    if (CombineAndInsertData(destinationConnection, ФИО, Телефон, Почта, Паспорт, Сумма) == false)
    {
        Transaction1(destinationConnection, ФИО, Телефон, Почта, Паспорт, Сумма, false);
        MessageBox::Show("Транзакция прошла неудачно", "Транзакция", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else
    {
        Transaction2(destinationConnection, ФИО, Телефон, Почта, Паспорт, Сумма, true);
        MessageBox::Show("Транзакция прошла успешно", "Транзакция", MessageBoxButtons::OK, MessageBoxIcon::Information);
        MessageBox::Show("Заказ успешно оформлен", "Успех!", MessageBoxButtons::OK, MessageBoxIcon::Information);

        
    }
    // Удаление данных из таблицы "Report"
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
    dbConnection->Open();
    String^ query = "DELETE FROM [ReportCar]";
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
    dbCommand->ExecuteNonQuery();
    // офомление  и заключение
    destinationConnection->Close();
    MyMenu^ form = gcnew MyMenu;
    this->Hide();
    form->Show();
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

        // Удаление данных из таблицы "ReportUserEdit"
        OleDbConnection^ dbConnection4 = gcnew OleDbConnection(connectionString);
        dbConnection4->Open();
        String^ query4 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand4 = gcnew OleDbCommand(query4, dbConnection4);
        dbCommand4->ExecuteNonQuery();

        Console::WriteLine("Успешно удалены все данные из 4 таблиц.");

    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка при удалении данных: " + ex->Message);
    }
    MessageBox::Show("Спасибо за пользование программой", "Прощание", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// вернутся к выбору авто
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::button3_Click(System::Object^ sender, System::EventArgs^ e)
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

        Console::WriteLine("Успешно удалены все данные из двух таблиц.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка при удалении данных: " + ex->Message);
    }
    MessageBox::Show("Вы вернулись к выбору авто. Введенные даныые удалены ", "Успех!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    UserRentAutoWiewData^ form = gcnew UserRentAutoWiewData;
    this->Hide();
    form->Show();
}
// вернутся в главное меню
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::button4_Click(System::Object^ sender, System::EventArgs^ e)
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

        // Удаление данных из таблицы "ReportUserEdit"
        OleDbConnection^ dbConnection3 = gcnew OleDbConnection(connectionString);
        dbConnection3->Open();
        String^ query3 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection3);
        dbCommand3->ExecuteNonQuery();

        Console::WriteLine("Успешно удалены все данные из Четырех таблиц.");
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
// 
// функции меню
//
//
// оформить
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::оформитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // работаем с бд
    OleDbConnection^ destinationConnection = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb");
    destinationConnection->Open();
    // работаем с данными, полученными в форме
    String^ ФИО = textBox1->Text;
    String^ Телефон = textBox2->Text;
    String^ Почта = textBox3->Text;
    String^ Паспорт = textBox4->Text;
    String^ Сумма = textBox22->Text;
    //
    //textBox11->Text = " ";
    //добавляем данные в бд
    CombineAndInsertData(destinationConnection, ФИО, Телефон, Почта, Паспорт, Сумма);
    // офомление  и заключение
    destinationConnection->Close();
    MessageBox::Show("Заказ успешно оформлен", "Успех!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

    // Удаление данных из таблицы "Report"
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
System::Void Курсовойпроектфронтэнд::UserRentAutoDecorOrder::главноеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
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

        // Удаление данных из таблицы "ReportOrder"
        OleDbConnection^ dbConnection3 = gcnew OleDbConnection(connectionString);
        dbConnection3->Open();
        String^ query3 = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection3);
        dbCommand3->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportUserEdit"
        OleDbConnection^ dbConnection4 = gcnew OleDbConnection(connectionString);
        dbConnection4->Open();
        String^ query4 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand4 = gcnew OleDbCommand(query4, dbConnection4);
        dbCommand4->ExecuteNonQuery();

        Console::WriteLine("Успешно удалены все данные из 4 таблиц.");
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
};
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

        Console::WriteLine("Успешно удалены все данные изтаблицы.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка при удалении данных: " + ex->Message);
    }
    MessageBox::Show("Вы вернулись к выбору авто. Введенные даныые удалены ", "Успех!", MessageBoxButtons::OK, MessageBoxIcon::Information);
    //
    UserRentAutoWiewData^ form = gcnew UserRentAutoWiewData;
    this->Hide();
    form->Show();
};
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

        // Удаление данных из таблицы "ReportUserEdit"
        OleDbConnection^ dbConnection3 = gcnew OleDbConnection(connectionString);
        dbConnection3->Open();
        String^ query3 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand3 = gcnew OleDbCommand(query3, dbConnection3);
        dbCommand3->ExecuteNonQuery();

        Console::WriteLine("Успешно удалены все данные из четырех таблиц.");
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка при удалении данных: " + ex->Message);
    }
    MessageBox::Show("Спасибо за пользование программой", "Прощание", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
};









//
//
//  функция добавления данных в бд (устарела)
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