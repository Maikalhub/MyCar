#include "Registration.h"
#include "MyMenu.h"
//
using namespace System::Data;
using namespace System::Data::OleDb;
//
////
//
// главное меню
System::Void Курсовойпроектфронтэнд::Registration::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyMenu^ form = gcnew MyMenu();

    MessageBox::Show("Вы вернулись в меню", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

    // Откройте новую форму
    form->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();

}
// потвердить
System::Void Курсовойпроектфронтэнд::Registration::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ Логин = textBox1->ToString();
    String^ Пароль = textBox2->ToString();
    double  balance = 100;
    String^ Баланс = Convert::ToString(balance);

    try
    {
        // подключение к базе данных
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        // Выполняем запрос к базе данных
        dbConnection->Open(); // открываем соединение
        String^ guery = "INSERT INTO [User] ([Логин], [Пароль], [Баланс]) VALUES (?, ?, ?)"; // запрос

        OleDbCommand^ dbCommand = gcnew OleDbCommand(guery, dbConnection);

        dbCommand->Parameters->AddWithValue("?", Логин);
        dbCommand->Parameters->AddWithValue("?", Пароль);
        dbCommand->Parameters->AddWithValue("?", Баланс);

        dbCommand->ExecuteNonQuery();
        MessageBox::Show("Вы зарегистрированы");
        dbConnection->Close();

        //

        MyMenu^ form = gcnew MyMenu();

        MessageBox::Show("Вы вернулись в меню", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

        // Откройте новую форму
        form->Show();

        // Закройте текущую форму (если это необходимо)
        this->Hide();

    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка: " + ex->Message);
    }
   
}
// выход
System::Void Курсовойпроектфронтэнд::Registration::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// потвердить (не готово)
System::Void Курсовойпроектфронтэнд::Registration::потвердитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ Логин = textBox1->ToString();
    String^ Пароль = textBox2->ToString();
    double  balance = 100;
    String^ Баланс = Convert::ToString(balance);

    try
    {
        // подключение к базе данных
        String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        // Выполняем запрос к базе данных
        dbConnection->Open(); // открываем соединение
        String^ guery = "INSERT INTO [User] ([Логин], [Пароль], [Баланс]) VALUES (?, ?, ?)"; // запрос

        OleDbCommand^ dbCommand = gcnew OleDbCommand(guery, dbConnection);

        dbCommand->Parameters->AddWithValue("?", Логин);
        dbCommand->Parameters->AddWithValue("?", Пароль);
        dbCommand->Parameters->AddWithValue("?", Баланс);

        dbCommand->ExecuteNonQuery();
        MessageBox::Show("Вы зарегистрированы");
        dbConnection->Close();

        //

        MyMenu^ form = gcnew MyMenu();

        MessageBox::Show("Вы вернулись в меню", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

        // Откройте новую форму
        form->Show();

        // Закройте текущую форму (если это необходимо)
        this->Hide();

    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Ошибка: " + ex->Message);
    }
}
// главное меню
System::Void Курсовойпроектфронтэнд::Registration::регистрацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyMenu^ form = gcnew MyMenu();

    MessageBox::Show("Вы вернулись в меню", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

    // Откройте новую форму
    form->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();

}
// выход
System::Void Курсовойпроектфронтэнд::Registration::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
    Application::Exit();
}
// справка (не готово)
System::Void Курсовойпроектфронтэнд::Registration::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
