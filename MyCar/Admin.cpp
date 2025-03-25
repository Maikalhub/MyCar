#include "Admin.h"
#include "MyMenu.h"
#include "AdminEditAdminData.h"
#include "AdminEditUserData.h"
#include "AdminEditAutoData.h"
#include "AdminEditReportsData.h"
///
///
///
// просмотр данных админа
System::Void Курсовойпроектфронтэнд::Admin::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditAdminData^ form = gcnew AdminEditAdminData();

	// Откройте новую форму
	form->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// просмотр данных пользователя
System::Void Курсовойпроектфронтэнд::Admin::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditUserData^ form = gcnew AdminEditUserData();

	// Откройте новую форму
	form->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// просмотр данных авто
System::Void Курсовойпроектфронтэнд::Admin::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditAutoData^ form = gcnew AdminEditAutoData();

	// Откройте новую форму
	form->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// просмотр данных отчетов
System::Void Курсовойпроектфронтэнд::Admin::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditReportsData^ form = gcnew AdminEditReportsData();

	// Откройте новую форму
	form->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// возвращение в меню
System::Void Курсовойпроектфронтэнд::Admin::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyMenu^ form = gcnew MyMenu();

	MessageBox::Show("Вы вернулись в меню", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// Откройте новую форму
	form->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();


}
// выход
System::Void Курсовойпроектфронтэнд::Admin::button3_Click(System::Object^ sender, System::EventArgs^ e)
{

	MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
//
// функции меню
// 
// просмотр данных админа 
System::Void Курсовойпроектфронтэнд::Admin::потвердитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditAdminData^ form = gcnew AdminEditAdminData();

	// Откройте новую форму
	form->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// просмотр данных пользователя
System::Void Курсовойпроектфронтэнд::Admin::регистрацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditUserData^ form = gcnew AdminEditUserData();

	// Откройте новую форму
	form->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// просмотр данных авто
System::Void Курсовойпроектфронтэнд::Admin::арендаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditAutoData^ form = gcnew AdminEditAutoData();

	// Откройте новую форму
	form->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// просмотр данных отчетов
System::Void Курсовойпроектфронтэнд::Admin::отчетToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	AdminEditReportsData^ form = gcnew AdminEditReportsData();

	// Откройте новую форму
	form->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// возвращение в меню
System::Void Курсовойпроектфронтэнд::Admin::менюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyMenu^ form = gcnew MyMenu();

	MessageBox::Show("Вы вернулись в меню", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// Откройте новую форму
	form->Show();

	// Закройте текущую форму (если это необходимо)
	this->Hide();
}
// выход
System::Void Курсовойпроектфронтэнд::Admin::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Спасибо за использование. Досвидания!!!", "Программа завершена", MessageBoxButtons::OK, MessageBoxIcon::Information);
	Application::Exit();
}
