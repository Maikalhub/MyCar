#include "ReportTransactionData.h"
#include  "Admin.h"
#include "MyMenu.h"
#include "AdminEditReportsData.h"

using namespace System::Data::OleDb;
using namespace System::Data;

//
System::Void Курсовойпроектфронтэнд::ReportTransactionData::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "SELECT * FROM [Transaction]"; // запрос
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
            dataGridView1->Rows->Add(dbReader["Номер"], dbReader["Дата"], dbReader["Карточка"], dbReader["Сумма"], dbReader["ФИО"], dbReader["Статус"]);

        }
    }
    // закрываем соединение
    dbReader->Close();
    dbConnection->Close();
    //
}

System::Void Курсовойпроектфронтэнд::ReportTransactionData::button2_Click(System::Object^ sender, System::EventArgs^ e)
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
            dataGridView1->Rows[index]->Cells[5]->Value == nullptr)
    {
        MessageBox::Show("Ошибка");
        return;
    }

    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Дата = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Карточка = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Сумма = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ ФИО = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Статус = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
  
    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "INSERT INTO [Transaction] VALUES ('" + Номер + "', '" + Дата + "', '" + Карточка + "', '" + Сумма + "', '" + ФИО + "', '" + Статус + "',)"; // запрос
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

System::Void Курсовойпроектфронтэнд::ReportTransactionData::button1_Click(System::Object^ sender, System::EventArgs^ e)
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

    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Дата = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Карточка = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Сумма = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ ФИО = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Статус = dataGridView1->Rows[index]->Cells[5]->Value->ToString();

    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "UPDATE [Transaction] SET Дата = '" + Дата + "', Карточка = '" + Карточка + "', Сумма = '" + Сумма + "', ФИО = '" + ФИО + "', Статус = '" + Статус + "'WHERE Номер = " + Номер;
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
// поиск (не готов)
System::Void Курсовойпроектфронтэнд::ReportTransactionData::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Курсовойпроектфронтэнд::ReportTransactionData::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Очистка данных в dataGridView1
    dataGridView1->Rows->Clear();
    return System::Void();
}

System::Void Курсовойпроектфронтэнд::ReportTransactionData::button3_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ guery = "DELETE FROM [Transaction] WHERE Номер = " + Номер;
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

System::Void Курсовойпроектфронтэнд::ReportTransactionData::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}

System::Void Курсовойпроектфронтэнд::ReportTransactionData::загрузитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "SELECT * FROM [Transaction]"; // запрос
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
            dataGridView1->Rows->Add(dbReader["Номер"], dbReader["Дата"], dbReader["Карточка"], dbReader["Сумма"], dbReader["ФИО"], dbReader["Статус"]);

        }
    }
    // закрываем соединение
    dbReader->Close();
    dbConnection->Close();
    //
}

System::Void Курсовойпроектфронтэнд::ReportTransactionData::добавитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
            dataGridView1->Rows[index]->Cells[5]->Value == nullptr)
    {
        MessageBox::Show("Ошибка");
        return;
    }

    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Дата = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Карточка = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Сумма = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ ФИО = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Статус = dataGridView1->Rows[index]->Cells[5]->Value->ToString();

    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "INSERT INTO [Transaction] VALUES ('" + Номер + "', '" + Дата + "', '" + Карточка + "', '" + Сумма + "', '" + ФИО + "', '" + Статус + "',)"; // запрос
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

System::Void Курсовойпроектфронтэнд::ReportTransactionData::обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Дата = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Карточка = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Сумма = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ ФИО = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Статус = dataGridView1->Rows[index]->Cells[5]->Value->ToString();

    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "UPDATE [Transaction] SET Дата = '" + Дата + "', Карточка = '" + Карточка + "', Сумма = '" + Сумма + "', ФИО = '" + ФИО + "', Статус = '" + Статус + "'WHERE Номер = " + Номер;
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

System::Void Курсовойпроектфронтэнд::ReportTransactionData::поискNoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Курсовойпроектфронтэнд::ReportTransactionData::очисткаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Очистка данных в dataGridView1
    dataGridView1->Rows->Clear();
    return System::Void();
}

System::Void Курсовойпроектфронтэнд::ReportTransactionData::удалитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ guery = "DELETE FROM [Transaction] WHERE Номер = " + Номер;
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

System::Void Курсовойпроектфронтэнд::ReportTransactionData::главноеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyMenu^ Form = gcnew MyMenu();
    Form->Show();
    this->Hide();
}

System::Void Курсовойпроектфронтэнд::ReportTransactionData::админToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Admin^ Form = gcnew Admin();
    Form->Show();
    this->Hide();
}

System::Void Курсовойпроектфронтэнд::ReportTransactionData::отчетToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    AdminEditReportsData^ Form = gcnew AdminEditReportsData();
    Form->Show();
    this->Hide();
}

System::Void Курсовойпроектфронтэнд::ReportTransactionData::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
