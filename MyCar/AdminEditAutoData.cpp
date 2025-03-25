#include "AdminEditAutoData.h"
#include "MyMenu.h"
#include "Admin.h"
//
using namespace System::Data::OleDb;
using namespace System::Data;
////
// загрузить
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::button6_Click(System::Object^ sender, System::EventArgs^ e)
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
// добавить
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::button5_Click(System::Object^ sender, System::EventArgs^ e)
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
            dataGridView1->Rows[index]->Cells[6]->Value == nullptr)
    {
        MessageBox::Show("Ошибка");
        return;
    }

    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Марка = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Модель = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Номермашины = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ Времяпоступления = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Тариф = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ Наличие = dataGridView1->Rows[index]->Cells[6]->Value->ToString();

    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "INSERT INTO [Auto] VALUES ('" + Номер + "', '" + Марка + "', '" + Модель + "', '" + Номермашины + "', '" + Времяпоступления + "', '" + Тариф + "','" + Наличие + "')"; // запрос
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
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::button1_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ Времяпоступления = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Тариф = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ Наличие = dataGridView1->Rows[index]->Cells[6]->Value->ToString();

    // Подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных для обновления записи
    dbConnection->Open();
    String^ guery = "UPDATE [Auto] SET Марка = '" + Марка + "', Модель = '" + Модель + "', Номермашины = '" + Номермашины + "', Времяпоступления = '" + Времяпоступления + "', Тариф = '" + Тариф + "', Наличие = '" + Наличие + "' WHERE Номер = " + Номер;
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
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::button3_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ guery = "DELETE FROM [Auto] WHERE Номер = " + Номер;
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
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// очистка
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Очистка данных в dataGridView1
    dataGridView1->Rows->Clear();
}
// выход
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::button4_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::загрузитьToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
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
// добавить
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::добавитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
            dataGridView1->Rows[index]->Cells[6]->Value == nullptr)
    {
        MessageBox::Show("Ошибка");
        return;
    }

    String^ Номер = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
    String^ Марка = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ Модель = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ Номермашины = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ Времяпоступления = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Тариф = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ Наличие = dataGridView1->Rows[index]->Cells[6]->Value->ToString();

    // подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных
    dbConnection->Open(); // открываем соединение
    String^ guery = "INSERT INTO [Auto] VALUES ('" + Номер + "', '" + Марка + "', '" + Модель + "', '" + Номермашины + "', '" + Времяпоступления + "', '" + Тариф + "','" + Наличие + "')"; // запрос
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
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ Времяпоступления = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
    String^ Тариф = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
    String^ Наличие = dataGridView1->Rows[index]->Cells[6]->Value->ToString();

    // Подключение к базе данных
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Выполняем запрос к базе данных для обновления записи
    dbConnection->Open();
    String^ guery = "UPDATE [Auto] SET Марка = '" + Марка + "', Модель = '" + Модель + "', Номермашины = '" + Номермашины + "', Времяпоступления = '" + Времяпоступления + "', Тариф = '" + Тариф + "', Наличие = '" + Наличие + "' WHERE Номер = " + Номер;
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
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::удалитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ guery = "DELETE FROM [Auto] WHERE Номер = " + Номер;
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
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::поискToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// очистка
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::очисткаNoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Очистка данных в dataGridView1
    dataGridView1->Rows->Clear();
}
// главное меню
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::главноеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyMenu^ newForm2 = gcnew MyMenu();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// меню администратора
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::админToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Admin^ newForm2 = gcnew Admin();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();
}
// выход
System::Void Курсовойпроектфронтэнд::AdminEditAutoData::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
