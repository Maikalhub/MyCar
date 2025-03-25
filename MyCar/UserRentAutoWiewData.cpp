#include "UserRentAutoWiewData.h"
#include "MyMenu.h"
#include "UserRentAutoDecorOrder.h" // офомление  остальных данных заказа 
#include "User.h"
//
using namespace System::Data::OleDb;
using namespace System::Data;
////
// загрузить
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "SELECT * FROM [Auto]"; // запрос
    OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);
    OleDbDataReader^ dbReader = dbComand->ExecuteReader(); // считываем данные

    if (dbReader->HasRows == false)
    {
        MessageBox::Show("Ошибка считывания данных");
        return System::Void();
    }
    else
    {
        // заполним данные из бд
        while (dbReader->Read())
        {
            dataGridView1->Rows->Add(dbReader["Номер"], dbReader["Марка"], dbReader["Модель"], dbReader["Номер машины"], dbReader["Время поступления"], dbReader["Тариф"], dbReader["Наличие"]);

        }
    }
    // закрываем соединение
    dbReader->Close();
    dbConnection->Close();
}
// заказать
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Ошибка: Выберите одну строку для добавления в базу данных.");
        return;
    }

    int index = dataGridView1->SelectedRows[0]->Index;

    if (dataGridView1->Rows[index]->Cells->Count < 6) // Проверка на наличие как минимум 6 столбцов
    {
        MessageBox::Show("Ошибка: Недостаточно данных в строке.");
        return;
    }


    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Марка = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Модель = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Номермашины = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ Тариф = dataGridView1->Rows[index]->Cells[5]->Value->ToString();

    // Подключение к базе данных Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open();
    String^ query = "INSERT INTO [ReportCar] VALUES ('" + Номер + "', '" + Марка + "', '" + Модель + "', '" + Номермашины + "', '" + Тариф + "')";
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

    if (dbCommand->ExecuteNonQuery() != 1)
    {
        MessageBox::Show("Ошибка: Не удалось выполнить запрос в базу данных.");
    }
    else
    {
        MessageBox::Show("Готово: Данные успешно добавлены в базу данных.");
    }

    // Закрываем соединение
    dbConnection->Close();

    UserRentAutoDecorOrder^ form = gcnew UserRentAutoDecorOrder;
    this->Hide();
    form->Show();
}
// выход
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
    OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
    try
    {
        dbConnection->Open();

        // Создаем SQL-запрос для удаления всех записей из таблицы
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

        // Выполняем запрос
        dbCommand->ExecuteNonQuery();

        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);

        // Выполняем запрос
        dbCommand1->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportUserEdit"
        OleDbConnection^ dbConnection4 = gcnew OleDbConnection(connectionString);
        dbConnection4->Open();
        String^ query4 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand4 = gcnew OleDbCommand(query4, dbConnection4);
        dbCommand4->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportUserEdit"
        OleDbConnection^ dbConnection5 = gcnew OleDbConnection(connectionString);
        dbConnection5->Open();
        String^ query5 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand5 = gcnew OleDbCommand(query5, dbConnection5);
        dbCommand5->ExecuteNonQuery();

        Console::WriteLine("Успешно удалены все данные из 4 таблиц.");

       
    }
    catch (Exception^ ex)
    {
        // Обработка исключений, например, вывод ошибки в консоль или лог
        Console::WriteLine(ex->Message);
    }
    finally
    {
        // Важно закрыть соединение, даже если произошла ошибка
        dbConnection->Close();
    }
    MessageBox::Show("Спасибо за пользование программой", "Прощание", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// поиск (не готово)
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
// меню пользователя
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::button5_Click(System::Object^ sender, System::EventArgs^ e)
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
    User^ form = gcnew User;
    this->Hide();
    form->Show();
}
// главное меню
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::button3_Click(System::Object^ sender, System::EventArgs^ e)
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
//загрузить
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::загрузитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "SELECT * FROM [Auto]"; // запрос
    OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);
    OleDbDataReader^ dbReader = dbComand->ExecuteReader(); // считываем данные

    if (dbReader->HasRows == false)
    {
        MessageBox::Show("Ошибка считывания данных");
        return System::Void();
    }
    else
    {
        // заполним данные из бд
        while (dbReader->Read())
        {
            dataGridView1->Rows->Add(dbReader["Номер"], dbReader["Марка"], dbReader["Модель"], dbReader["Номер машины"], dbReader["Время поступления"], dbReader["Тариф"], dbReader["Наличие"]);

        }
    }
    // закрываем соединение
    dbReader->Close();
    dbConnection->Close();
}
//заказать
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::потвердитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Ошибка: Выберите одну строку для добавления в базу данных.");
        return;
    }

    int index = dataGridView1->SelectedRows[0]->Index;

    if (dataGridView1->Rows[index]->Cells->Count < 6) // Проверка на наличие как минимум 6 столбцов
    {
        MessageBox::Show("Ошибка: Недостаточно данных в строке.");
        return;
    }


    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Марка = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Модель = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Номермашины = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ Тариф = dataGridView1->Rows[index]->Cells[5]->Value->ToString();

    // Подключение к базе данных Access
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open();
    String^ query = "INSERT INTO [ReportCar] VALUES ('" + Номер + "', '" + Марка + "', '" + Модель + "', '" + Номермашины + "', '" + Тариф + "')";
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

    if (dbCommand->ExecuteNonQuery() != 1)
    {
        MessageBox::Show("Ошибка: Не удалось выполнить запрос в базу данных.");
    }
    else
    {
        MessageBox::Show("Готово: Данные успешно добавлены в базу данных.");
    }

    // Закрываем соединение
    dbConnection->Close();

    UserRentAutoDecorOrder^ form = gcnew UserRentAutoDecorOrder;
    this->Hide();
    form->Show();
}
// поиск 
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::поискToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
// главное меню
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::главноеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
// вернуться к выбору авто
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::режимToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    User^ form = gcnew User;
    this->Hide();
    form->Show();
}
// выход
System::Void Курсовойпроектфронтэнд::UserRentAutoWiewData::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
    OleDbConnection^ dbConnection1 = gcnew OleDbConnection(connectionString);
    try
    {
        dbConnection->Open();

        // Создаем SQL-запрос для удаления всех записей из таблицы
        String^ query = "DELETE FROM [Report]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

        // Выполняем запрос
        dbCommand->ExecuteNonQuery();

        String^ query1 = "DELETE FROM [ReportCar]";
        OleDbCommand^ dbCommand1 = gcnew OleDbCommand(query1, dbConnection1);

        // Выполняем запрос
        dbCommand1->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportUserEdit"
        OleDbConnection^ dbConnection4 = gcnew OleDbConnection(connectionString);
        dbConnection4->Open();
        String^ query4 = "DELETE FROM [ReportUserEdit]";
        OleDbCommand^ dbCommand4 = gcnew OleDbCommand(query4, dbConnection4);
        dbCommand4->ExecuteNonQuery();

        // Удаление данных из таблицы "ReportUserEdit"
        OleDbConnection^ dbConnection5 = gcnew OleDbConnection(connectionString);
        dbConnection5->Open();
        String^ query5 = "DELETE FROM [ReportOrder]";
        OleDbCommand^ dbCommand5 = gcnew OleDbCommand(query5, dbConnection5);
        dbCommand5->ExecuteNonQuery();

        Console::WriteLine("Успешно удалены все данные из 4 таблиц.");


    }
    catch (Exception^ ex)
    {
        // Обработка исключений, например, вывод ошибки в консоль или лог
        Console::WriteLine(ex->Message);
    }
    finally
    {
        // Важно закрыть соединение, даже если произошла ошибка
        dbConnection->Close();
    }
    MessageBox::Show("Спасибо за пользование программой", "Прощание", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
