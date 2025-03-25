#include "User.h"
#include "MyMenu.h"
#include "UserRentAutoWiewData.h"
#include "UserEditUserDataNew.h"
using namespace System::Data;
using namespace System::Data::OleDb;
// арендовать авто
System::Void Курсовойпроектфронтэнд::User::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    UserRentAutoWiewData^ newForm2 = gcnew UserRentAutoWiewData();

    // Откройте новую форму
    newForm2->Show();

    // Закройте текущую форму (если это необходимо)
    this->Hide();

}
// выход
System::Void Курсовойпроектфронтэнд::User::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	using namespace System::Data;
	using namespace System::Data::OleDb;
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
		MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
		Application::Exit();
	};
}
// возврат в меню 
System::Void Курсовойпроектфронтэнд::User::button4_Click(System::Object^ sender, System::EventArgs^ e)
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
		MyMenu^ newForm2 = gcnew MyMenu();

		MessageBox::Show("Вы вернулись в главное меню", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Откройте новую форму
		newForm2->Show();

		// Закройте текущую форму (если это необходимо)
		this->Hide();

	};
}
// изменить данные
System::Void Курсовойпроектфронтэнд::User::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

	// Откройте новую форму
	newForm2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
//
// функции меню
//
// 
// изменить данные
System::Void Курсовойпроектфронтэнд::User::потвердитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	UserEditUserDataNew^ newForm2 = gcnew UserEditUserDataNew();

	// Откройте новую форму
	newForm2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// аренда авто
System::Void Курсовойпроектфронтэнд::User::регистрацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	UserRentAutoWiewData^ newForm2 = gcnew UserRentAutoWiewData();

	// Откройте новую форму
	newForm2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// возврат в меню
System::Void Курсовойпроектфронтэнд::User::менюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		MyMenu^ newForm2 = gcnew MyMenu();

		MessageBox::Show("Вы вернулись в главное меню", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Откройте новую форму
		newForm2->Show();

		// Закройте текущую форму (если это необходимо)
		this->Hide();

	};
}
// выход
System::Void Курсовойпроектфронтэнд::User::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
		Application::Exit();
	};
}
