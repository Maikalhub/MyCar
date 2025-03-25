#include "UserEditUserDataNew.h"
#include "MyMenu.h"
#include "User.h"
#include "UserEditUserDataNewEdit.h"
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
////
//
// 
// отображение данных
System::Void Курсовойпроектфронтэнд::UserEditUserDataNew::UserEditUserDataNew_Load(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		// Подключение к базам данных и извлечение данных
		String^ sourceConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Data1.accdb";

		OleDbConnection^ sourceConnectionReport = gcnew OleDbConnection(sourceConnectionString);

		sourceConnectionReport->Open();

		String^ queryReport = "SELECT * FROM ReportUserEdit";

		OleDbCommand^ commandReport = gcnew OleDbCommand(queryReport, sourceConnectionReport);

		OleDbDataReader^ readerReport = commandReport->ExecuteReader();

		// Получение данных из первой строки каждой таблицы
		if (readerReport->Read())
		{
			// Получите данные из других таблиц
			String^ Login = readerReport->GetString(2);
			String^ Password = readerReport->GetString(3);
			String^ Balance = readerReport->GetString(1);

			// Отображаем данные в соответствующих текстовых полях
			textBox2->Text = Login->ToString();

			textBox3->Text = Password->ToString();

			textBox1->Text = Balance->ToString();

			readerReport->Close();

			sourceConnectionReport->Close();
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Ошибка данных Изменения данных: " + ex->Message);
	}
}
// изменить
System::Void Курсовойпроектфронтэнд::UserEditUserDataNew::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	UserEditUserDataNewEdit^ newForm2 = gcnew UserEditUserDataNewEdit();


	// Откройте новую форму
	newForm2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// потвердить  // no
System::Void Курсовойпроектфронтэнд::UserEditUserDataNew::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// выход
System::Void Курсовойпроектфронтэнд::UserEditUserDataNew::button3_Click(System::Object^ sender, System::EventArgs^ e)
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
	MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
// главное меню
System::Void Курсовойпроектфронтэнд::UserEditUserDataNew::button5_Click(System::Object^ sender, System::EventArgs^ e)
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
// меню пользователя
System::Void Курсовойпроектфронтэнд::UserEditUserDataNew::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	User^ newForm2 = gcnew User();

	MessageBox::Show("Вы вернулись в меню пользователя", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// Откройте новую форму
	newForm2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// потвердить // no
System::Void Курсовойпроектфронтэнд::UserEditUserDataNew::потвердитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
// изменить
System::Void Курсовойпроектфронтэнд::UserEditUserDataNew::регистрацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	UserEditUserDataNewEdit^ newForm2 = gcnew UserEditUserDataNewEdit();


	// Откройте новую форму
	newForm2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}

System::Void Курсовойпроектфронтэнд::UserEditUserDataNew::главноеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		MyMenu^ newForm2 = gcnew MyMenu();

		MessageBox::Show("Вы вернулись в главное меню", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Откройте новую форму
		newForm2->Show();

		// Закройте текущую форму (если это необходимо)
		this->Hide();

	};
}

System::Void Курсовойпроектфронтэнд::UserEditUserDataNew::пользовательToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	User^ newForm2 = gcnew User();

	MessageBox::Show("Вы вернулись в меню пользователя", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// Откройте новую форму
	newForm2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}

System::Void Курсовойпроектфронтэнд::UserEditUserDataNew::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
	};
	MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
