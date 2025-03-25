#include "AdminEditReportsData.h"
#include "MyMenu.h"
#include "Admin.h"
#include "ReportOrderData.h"
#include "ReportTransactionData.h"
//
////
// данные заказов
System::Void Курсовойпроектфронтэнд::AdminEditReportsData::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
	ReportOrderData^ Form2 = gcnew ReportOrderData();

	// Откройте новую форму
	Form2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// данные транзакций
System::Void Курсовойпроектфронтэнд::AdminEditReportsData::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	ReportTransactionData^ newForm3 = gcnew ReportTransactionData();

	// Откройте новую форму
	newForm3->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// меню администратора
System::Void Курсовойпроектфронтэнд::AdminEditReportsData::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	Admin^ newForm2 = gcnew Admin();

	// Откройте новую форму
	newForm2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// выход
System::Void Курсовойпроектфронтэнд::AdminEditReportsData::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
//
// 
// функции меню
// 
// 
// данные заказов 
System::Void Курсовойпроектфронтэнд::AdminEditReportsData::загрузитьToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	ReportOrderData^ Form2 = gcnew ReportOrderData();

	// Откройте новую форму
	Form2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// данные транзакций
System::Void Курсовойпроектфронтэнд::AdminEditReportsData::добавитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	ReportTransactionData^ newForm2 = gcnew ReportTransactionData();

	// Откройте новую форму
	newForm2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// главное меню
System::Void Курсовойпроектфронтэнд::AdminEditReportsData::главноеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyMenu^ newForm2 = gcnew MyMenu();

	// Откройте новую форму
	newForm2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// меню администратора
System::Void Курсовойпроектфронтэнд::AdminEditReportsData::админToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Admin^ newForm2 = gcnew Admin();

	// Откройте новую форму
	newForm2->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// выход
System::Void Курсовойпроектфронтэнд::AdminEditReportsData::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
