#include "AdminEditUserData.h"
#include "MyMenu.h"
#include "Admin.h"
//
using namespace System::Data::OleDb;
using namespace System::Data;
////
// загрузить
System::Void Курсовойпроектфронтэнд::AdminEditUserData::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "SELECT * FROM [User]"; // запрос
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
            dataGridView1->Rows->Add(dbReader["Номер"], dbReader["Логин"], dbReader["Пароль"], dbReader["Баланс"]);

        }
    }
    // закрываем соединение
    dbReader->Close();
    dbConnection->Close();
    //
}
// добавить
System::Void Курсовойпроектфронтэнд::AdminEditUserData::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    //
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Ошибка");
        return;
    }

    // Узнаем индекс выбранной строки
    int index = dataGridView1->SelectedRows[0]->Index;

    if
        (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[3]->Value == nullptr)
    {
        MessageBox::Show("Ошибка");
        return;
    }

    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Логин = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Пароль = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Баланс = dataGridView1->Rows[index]->Cells[3]->Value->ToString();

    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "INSERT INTO [User] VALUES ('" + Номер + "', '" + Логин + "', '" + Пароль + "', '" + Баланс + "')"; // запрос
    OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);
    if (dbComand->ExecuteNonQuery() != 1)
    {
        MessageBox::Show("Ошибка считывания данных");
    }
    else
    {
        MessageBox::Show("Готово");
    }

    // закрываем соединение
    dbConnection->Close();
}
// обновить / редактировать
System::Void Курсовойпроектфронтэнд::AdminEditUserData::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Проверяем, выбрана ли ровно одна строка
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Выберите одну строку для редактирования");
        return;
    }

    // Получаем индекс выбранной строки
    int index = dataGridView1->SelectedRows[0]->Index;

    // Проверяем, чтобы все ячейки в выбранной строке были заполнены
    for (int i = 0; i < dataGridView1->Columns->Count; i++)
    {
        if (dataGridView1->Rows[index]->Cells[i]->Value == nullptr)
        {
            MessageBox::Show("Все поля должны быть заполнены");
            return;
        }
    }

    // Получаем значения из выбранной строки
    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Логин = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Пароль = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Баланс = dataGridView1->Rows[index]->Cells[3]->Value->ToString();

    // Подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных для обновления записи
    dbConnection->Open();
    String^ guery = "UPDATE [User] SET Логин = '" + Логин + "', Пароль = '" + Пароль + "', Баланс = '" + Баланс + "'WHERE Номер = " + Номер;
    OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);

    //if (dbComand->ExecuteNonQuery() != 1)
    //{
     //   MessageBox::Show("Ошибка при обновлении данных");
    //}
    //else
    //{
    MessageBox::Show("Данные обновлены");
    // }

     // Закрываем соединение
    dbConnection->Close();
}
// удалить
System::Void Курсовойпроектфронтэнд::AdminEditUserData::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Проверяем, выбрана ли ровно одна строка
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Выберите одну строку для удаления");
        return;
    }

    // Получаем значение из первой ячейки выбранной строки (например, значение столбца "Номер")
    String^ Номер = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();

    // Подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных для удаления записи
    dbConnection->Open();
    String^ guery = "DELETE FROM [User] WHERE Номер = " + Номер;
    OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);

    if (dbComand->ExecuteNonQuery() != 1)
    {
        MessageBox::Show("Ошибка при удалении данных");
    }
    else
    {
        MessageBox::Show("Данные удалены");
    }

    // Закрываем соединение
    dbConnection->Close();
}
// поиск (не готов)
System::Void Курсовойпроектфронтэнд::AdminEditUserData::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// очистка
System::Void Курсовойпроектфронтэнд::AdminEditUserData::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Очистка данных в dataGridView1
    dataGridView1->Rows->Clear();
    return System::Void();
}
// выход
System::Void Курсовойпроектфронтэнд::AdminEditUserData::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
//
//
// функции меню
//
//
// загрузить
System::Void Курсовойпроектфронтэнд::AdminEditUserData::загрузитьToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "SELECT * FROM [User]"; // запрос
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
            dataGridView1->Rows->Add(dbReader["Номер"], dbReader["Логин"], dbReader["Пароль"], dbReader["Баланс"]);

        }
    }
    // закрываем соединение
    dbReader->Close();
    dbConnection->Close();
    //
}
// добавить
System::Void Курсовойпроектфронтэнд::AdminEditUserData::добавитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    //
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Ошибка");
        return;
    }

    // Узнаем индекс выбранной строки
    int index = dataGridView1->SelectedRows[0]->Index;

    if
        (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[3]->Value == nullptr)
    {
        MessageBox::Show("Ошибка");
        return;
    }

    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Логин = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Пароль = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Баланс = dataGridView1->Rows[index]->Cells[3]->Value->ToString();

    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "INSERT INTO [User] VALUES ('" + Номер + "', '" + Логин + "', '" + Пароль + "', '" + Баланс + "')"; // запрос
    OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);
    if (dbComand->ExecuteNonQuery() != 1)
    {
        MessageBox::Show("Ошибка считывания данных");
    }
    else
    {
        MessageBox::Show("Готово");
    }

    // закрываем соединение
    dbConnection->Close();
}
// обновить / редактировать
System::Void Курсовойпроектфронтэнд::AdminEditUserData::обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Проверяем, выбрана ли ровно одна строка
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Выберите одну строку для редактирования");
        return;
    }

    // Получаем индекс выбранной строки
    int index = dataGridView1->SelectedRows[0]->Index;

    // Проверяем, чтобы все ячейки в выбранной строке были заполнены
    for (int i = 0; i < dataGridView1->Columns->Count; i++)
    {
        if (dataGridView1->Rows[index]->Cells[i]->Value == nullptr)
        {
            MessageBox::Show("Все поля должны быть заполнены");
            return;
        }
    }

    // Получаем значения из выбранной строки
    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Логин = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Пароль = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Баланс = dataGridView1->Rows[index]->Cells[3]->Value->ToString();

    // Подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных для обновления записи
    dbConnection->Open();
    String^ guery = "UPDATE [User] SET Логин = '" + Логин + "', Пароль = '" + Пароль + "', Баланс = '" + Баланс + "'WHERE Номер = " + Номер;
    OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);

    //if (dbComand->ExecuteNonQuery() != 1)
    //{
     //   MessageBox::Show("Ошибка при обновлении данных");
    //}
    //else
    //{
    MessageBox::Show("Данные обновлены");
    // }

     // Закрываем соединение
    dbConnection->Close();
}
// удалить
System::Void Курсовойпроектфронтэнд::AdminEditUserData::удалитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Проверяем, выбрана ли ровно одна строка
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Выберите одну строку для удаления");
        return;
    }

    // Получаем значение из первой ячейки выбранной строки (например, значение столбца "Номер")
    String^ Номер = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();

    // Подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных для удаления записи
    dbConnection->Open();
    String^ guery = "DELETE FROM [User] WHERE Номер = " + Номер;
    OleDbCommand^ dbComand = gcnew OleDbCommand(guery, dbConnection);

    if (dbComand->ExecuteNonQuery() != 1)
    {
        MessageBox::Show("Ошибка при удалении данных");
    }
    else
    {
        MessageBox::Show("Данные удалены");
    }

    // Закрываем соединение
    dbConnection->Close();
}
// поиск (не готов)
System::Void Курсовойпроектфронтэнд::AdminEditUserData::поискToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// очистка
System::Void Курсовойпроектфронтэнд::AdminEditUserData::очисткаNoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Очистка данных в dataGridView1
    dataGridView1->Rows->Clear();
    return System::Void();
}
// главное меню
System::Void Курсовойпроектфронтэнд::AdminEditUserData::главноеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyMenu^ newForm2 = gcnew MyMenu();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// меню администратора 
System::Void Курсовойпроектфронтэнд::AdminEditUserData::админToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Admin^ newForm2 = gcnew Admin();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// выход
System::Void Курсовойпроектфронтэнд::AdminEditUserData::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
