#include "ReportOrderData.h"
#include "MyMenu.h"
#include "Admin.h"
#include "AdminEditReportsData.h"
//
using namespace System::Data::OleDb;
using namespace System::Data;
////
// загрузить
System::Void Курсовойпроектфронтэнд::ReportOrderData::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "SELECT * FROM [ReportOrderOver]"; // запрос
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
            dataGridView1->Rows->Add(dbReader["Номер"], dbReader["Модель"], dbReader["Номер машины"], dbReader["Тариф"], dbReader["Логин"], dbReader["Паспорт"], dbReader["Сумма"], dbReader["Почта"], dbReader["ФИО"]);

        }
    }
    // закрываем соединение
    dbReader->Close();
    dbConnection->Close();
    //
}
// добавить
System::Void Курсовойпроектфронтэнд::ReportOrderData::button22_Click(System::Object^ sender, System::EventArgs^ e)
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
            dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[5]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[6]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[7]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[8]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[9]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[10]->Value == nullptr)
    {
        MessageBox::Show("Ошибка");
        return;
    }

    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Марка = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Модель = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Номермашины = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ Тариф = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Логин = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ Телефон = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
    String^ Паспорт = dataGridView1->Rows[index]->Cells[7]->Value->ToString();
    String^ Сумма = dataGridView1->Rows[index]->Cells[8]->Value->ToString();
    String^ Почта = dataGridView1->Rows[index]->Cells[9]->Value->ToString();
    String^ ФИО= dataGridView1->Rows[index]->Cells[10]->Value->ToString();
    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "INSERT INTO [ReportOrderOver] VALUES ('" + Номер + "', '" + Марка + "', '" + Модель + "', '" + Номермашины + "', '" + Тариф + "', '" + Логин + "', '" + Телефон + "', '" + Паспорт + "', '" + Сумма + "', '" + Почта + "', '" + ФИО + "')"; // запрос
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
// обновить
System::Void Курсовойпроектфронтэнд::ReportOrderData::button1_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ Марка = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Модель = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Номермашины = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ Тариф = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Логин = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ Телефон = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
    String^ Паспорт = dataGridView1->Rows[index]->Cells[7]->Value->ToString();
    String^ Сумма = dataGridView1->Rows[index]->Cells[8]->Value->ToString();
    String^ Почта = dataGridView1->Rows[index]->Cells[9]->Value->ToString();
    String^ ФИО = dataGridView1->Rows[index]->Cells[10]->Value->ToString();

    // Подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных для обновления записи
    dbConnection->Open();
    String^ guery = "UPDATE [ReportOrderOver] SET Марка = '" + Марка + "', Модель = '" + Модель + "', Номермашины = '" + Номермашины + "', Тариф = '" + Тариф + "', Логин = '" + Логин + "', Телефон = '" + Телефон + "', Паспорт = '" + Паспорт + "', Сумма = '" + Сумма + "', Почта = '" + Почта + "', ФИО = '" + ФИО + "'WHERE Номер = " + Номер;
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
System::Void Курсовойпроектфронтэнд::ReportOrderData::button3_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ guery = "DELETE FROM [ReportOrderOver] WHERE Номер = " + Номер;
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
// поиск (не готово)
System::Void Курсовойпроектфронтэнд::ReportOrderData::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// очистка
System::Void Курсовойпроектфронтэнд::ReportOrderData::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Очистка данных в dataGridView1
    dataGridView1->Rows->Clear();
    return System::Void();
}
// выход
System::Void Курсовойпроектфронтэнд::ReportOrderData::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// загрузить
System::Void Курсовойпроектфронтэнд::ReportOrderData::загрузитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "SELECT * FROM [ReportOrderOver]"; // запрос
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
            dataGridView1->Rows->Add(dbReader["Номер"], dbReader["Модель"], dbReader["Номер машины"], dbReader["Тариф"], dbReader["Логин"], dbReader["Паспорт"], dbReader["Сумма"], dbReader["Почта"], dbReader["ФИО"]);

        }
    }
    // закрываем соединение
    dbReader->Close();
    dbConnection->Close();
    //
}
// добавить
System::Void Курсовойпроектфронтэнд::ReportOrderData::добавитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
            dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[5]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[6]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[7]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[8]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[9]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[10]->Value == nullptr)
    {
        MessageBox::Show("Ошибка");
        return;
    }

    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Марка = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Модель = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Номермашины = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ Тариф = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Логин = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ Телефон = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
    String^ Паспорт = dataGridView1->Rows[index]->Cells[7]->Value->ToString();
    String^ Сумма = dataGridView1->Rows[index]->Cells[8]->Value->ToString();
    String^ Почта = dataGridView1->Rows[index]->Cells[9]->Value->ToString();
    String^ ФИО = dataGridView1->Rows[index]->Cells[10]->Value->ToString();
    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "INSERT INTO [ReportOrderOver] VALUES ('" + Номер + "', '" + Марка + "', '" + Модель + "', '" + Номермашины + "', '" + Тариф + "', '" + Логин + "', '" + Телефон + "', '" + Паспорт + "', '" + Сумма + "', '" + Почта + "', '" + ФИО + "')"; // запрос
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
// обновить
System::Void Курсовойпроектфронтэнд::ReportOrderData::обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ Марка = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Модель = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Номермашины = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ Тариф = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Логин = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ Телефон = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
    String^ Паспорт = dataGridView1->Rows[index]->Cells[7]->Value->ToString();
    String^ Сумма = dataGridView1->Rows[index]->Cells[8]->Value->ToString();
    String^ Почта = dataGridView1->Rows[index]->Cells[9]->Value->ToString();
    String^ ФИО = dataGridView1->Rows[index]->Cells[10]->Value->ToString();

    // Подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных для обновления записи
    dbConnection->Open();
    String^ guery = "UPDATE [ReportOrderOver] SET Марка = '" + Марка + "', Модель = '" + Модель + "', Номермашины = '" + Номермашины + "', Тариф = '" + Тариф + "', Логин = '" + Логин + "', Телефон = '" + Телефон + "', Паспорт = '" + Паспорт + "', Сумма = '" + Сумма + "', Почта = '" + Почта + "', ФИО = '" + ФИО + "'WHERE Номер = " + Номер;
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
System::Void Курсовойпроектфронтэнд::ReportOrderData::удалитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ guery = "DELETE FROM [ReportOrderOver] WHERE Номер = " + Номер;
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
// поиск (не готово)
System::Void Курсовойпроектфронтэнд::ReportOrderData::поискNoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// очистка
System::Void Курсовойпроектфронтэнд::ReportOrderData::очитскаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Очистка данных в dataGridView1
    dataGridView1->Rows->Clear();
    return System::Void();
}
// главное меню
System::Void Курсовойпроектфронтэнд::ReportOrderData::главноеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyMenu^ newForm2 = gcnew MyMenu();

    MessageBox::Show("Вы вернулись в главное меню", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// меню администратора
System::Void Курсовойпроектфронтэнд::ReportOrderData::админToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Admin^ newForm2 = gcnew Admin();


    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// выход
System::Void Курсовойпроектфронтэнд::ReportOrderData::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}






















//
System::Void Курсовойпроектфронтэнд::ReportOrderData::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
