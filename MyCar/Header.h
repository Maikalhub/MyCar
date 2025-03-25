#pragma once

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include <Windows.h>
#include <iostream>
#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include <Windows.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <memory>  // unique_ptr
#include <stdexcept>  // runtime_error
//
using namespace std;
//
////
enum State
{
    begin, middle
};
// абстрактный класс
//
class User
{
public:
    //
    string login;
    string password;
    string FIO;
    string telefon;
    string pasport;
    string email;
    double balance;
    ////
    void set_login(string login)
    {
        this->login = login;
    }
    void set_password(string password)
    {
        this->password = password;
    }
    void set_FIO(string FIO)
    {
        this->FIO = FIO;
    }
    void set_telefon(string telefon)
    {
        this->telefon = telefon;
    }
    void set_pasport(string pasport)
    {
        this->pasport = pasport;
    }
    void set_email(string email)
    {
        this->email = email;
    }
    void set_balance(double balance)
    {
        this->balance = balance;
    }
    //
    string get_login(string login)
    {
        return login;
    }
    string get_password(string password)
    {
        return password;
    }
    string get_FIO(string FIO)
    {
        return FIO;
    }
    string get_telefon(string telefon)
    {
        return telefon;
    }
    string get_pasport(string pasport)
    {
        return pasport;
    }
    string get_email(string email)
    {
        return email;
    }
    double get_balance(double balance)
    {
        return balance;
    }
    ////
    User()
    {

    };
    User(const string& login, const string& password, const string& FIO, const string& telefon, const string& pasport, const string& email, double balance)
        : login(login), password(password), FIO(FIO), telefon(telefon), pasport(pasport), email(email), balance(balance)
    {

    }
    ~User()
    {

    };
    //
    int abstract()
    {
        return 1 ;
    };
};
// 
class Admin
{
public:
    //
    string login;
    string password;
    ////
    void set_login(string login)
    {
        this->login = login;
    }
    void set_password(string password)
    {
        this->password = password;
    }
    string get_login(string login)
    {
        return login;
    }
    string get_password(string password)
    {
        return password;
    }
    ////
    Admin()
    {

    };
    Admin(const string& login, const string& password)
        : login(login), password(password)
    {

    }
    ~Admin()
    {

    };
    //
};
//
class Car
{
public:
    //
    string marka;
    string model;
    string number;
    string time_postyplenia;
    double tarif;
    bool nalichie;
    ////
    void set_marka(string marka)
    {
        this->marka = marka;
    }
    void set_model(string model)
    {
        this->model = model;
    }
    void set_time_postyplenia(string time_postyplenia)
    {
        this->time_postyplenia = time_postyplenia;
    }
    void set_tarif(double tarif)
    {
        this->tarif = tarif;
    }
    bool set_nalichie(bool nalichie)
    {
        this->nalichie = nalichie;
    }
    string get_marka(string marka)
    {
        return marka;
    }
    string get_model(string model)
    {
        return model;
    }
    string get_time_postyplenia(string time_postyplenia)
    {
        return time_postyplenia;
    }
    double get_tarif(double tarif)
    {
        return tarif;
    }
    bool get_nalichie(bool nalichie)
    {
        return nalichie;
    }
    ////
    Car()
    {

    };
    //
};
//
class Order : public User, public Admin, public Car
{
public:
    //
    // string FIO;
    // string telefon;
    // string pasport;
    // string email;
    // double balance;
    // marka
    // model
    // nomer
    double sum;
    string time;
    // double tarif;
    ////
    //void abstract() override
    //{
        //return n;
        
   // };
   

};

template <class T>
class Transaction : public Order
{
public:
    T* currentState;
    T* prevState;
    string time1;
    double sum1;
    //
    string set_time1_trn(string time1)
    {
        this->time1 = time1;
    }
    string get_time1_trn(string time1)
    {
        return time1;
    }
    double set_sum_trn(double sum)
    {
        this->sum = sum;
    }
    double get_sum_trn(double sum)
    {
        return sum;
    }


    Transaction(const Transaction& obj) : currentState(new T(*(obj.currentState))), prevState(nullptr)
    {}

    ~Transaction()
    {
        delete currentState;
        delete prevState;
    }

    Transaction& operator=(const Transaction& obj);

    void showState(State state);

    bool beginTransactions(double sum);

    void commit();

    void deleteTransactions();

    void Transaction_all();

    const T* operator->() const;

    T* operator->();

    Transaction() = default;


    //void displayInfo() const override
    //{
    //	std::cout << "" << endl;
    //}
};


template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T>& obj);
//
template <class T>
T* Transaction<T>::operator->();
//
template <class T>
void Transaction<T>::showState(State state);
//
template <class T>
bool Transaction<T>::beginTransactions(double sum);
//
template <class T>
void Transaction<T>::commit();
//
template <class T>
void Transaction<T>::deleteTransactions();
//
template <class T>
void Transaction<T>::Transaction_all();
//
template <class T>
const T* Transaction<T>::operator->() const;


////
////
//// ФУНКЦИИ РАБОТЫ ПРОГРАММЫ (ОСНОВНЫЕ)
////
////

// шифрование
void encryptFile(const std::string& key, const std::string& inFile, const std::string& outFile);

// Функция для расшифровки файла с помощью ключа
void decryptFile(const std::string& key, const std::string& inFile, const std::string& outFile);


//
// 
// получение данных в реальном времени
std::string getCurrentTime();
// 
// 
// считывание данных из файлов
void read_file_data(Admin& admin, User& user, Car& car, Order& order, vector<Admin>& admin_, vector<User>& user_, vector<Car>& car_, vector<Order>& order_);
// считывание данных администратора из файла
void read_file_data_Admin(Admin& admin, vector<Admin>& admin_);
// считывание данных пользователя из файла
void read_file_data_User(User& user, vector<User>& user_);
// считывание данных автомобиля из файла
void read_file_data_Car(Car& car, vector<Car>& car_);
// считывание данных заказа из файла
void read_file_data_Order(Order& order, vector<Order>& order_);
//
// обновление данных пользователя
void update_user_data_file(const vector<User>& user_);
// добавление данных заказа
void update_user_order_data_file(Order& order);


// получание баланса пользователя
double balance_from_user_data(string& login);







//  проверка данных администратора
bool admin_data_check(string& login, string& password);
// проверка данных пользователя
bool user_data_check(string& login, string& password);
// проверка данных автомобиля
bool car_data_check(string& marka, string& model, string& number);


// регистрация (для пользователя, для администратора функция добавления делает соответствующую работу) 
bool registration_user();



//
// (администратор) просмотр данных администратора
void admin_view_admin_data();
// (администратор) просмотр данных пользователя
void admin_view_user_data();
// (администратор) просмотр данных автомобиля
void admin_view_car_data();
// (администратор) просмотр данных заказа
void admin_view_order_data();
//
//

//

//
// (администратор) добавление данных администратора
bool admin_add_admin_data();
// (администратор) добавление данных пользователя
bool admin_add_user_data();
// (администратор) добавление данных автомобиля
bool admin_add_car_data();
// (администратор) добавление данных заказа (не нужна)
bool admin_add_order_data();
//
//

//
// (администратор) работа с данными администратора 
int admin_work_admin_data(string& login, string& password);
// (администратор) работа с данными пользователя 
int admin_work_user_data(string& login, string& password);
// (администратор) работа с данными автомобилей 
int admin_work_car_data(string& login, string& password);
// (администратор) работа с данными операций 
int admin_work_operation_data(string& login, string& password);
//

//






// (пользователь) просмотр данных пользователя 
void user_data_my_data(string& login, string& password);
// (пользователь) редактирование данных пользователя 
void edit_user_data_my_data(string& login, string& password);

// (пользователь) работа с данными пользователя 
void user_work_my_data(string& login, string& password);
// (пользователь) работа с данными пользователя 





// (пользователь) просмотр данных автомобиля
void user_view_car_data();



void update_car_nalichie_data_file(string& marka, string& model, string& number);


void update_user_data_file2(double& m, string& login);



// (пользватель) аренда автомобиля
void user_order_car_data_over(string& login, string& password);

// (пользватель) поиск автомобиля
void user_search_car_data();

// (пользватель) сортировка автомобиля
void user_sort_car_data();


// (пользователь) начало оформление заказа пользователя 
void user_work_rent_auto(string& login, string& password);




//
//

//

// работа с данными (меню администратора)
int admin_menu_work_data(string& login, string& password);




// меню администратора
int admin_menu(string& login, string& password);

// меню пользователя
void user_menu(string& login, string& password);



// авторизация администратора
bool autorisation_admin(string& login, string& password);

// авторизация пользователя
bool autorisation_user(string& login, string& password);

// авторизация программы (главное меню программы)
void autorisation_total();
//

////
//

////




// запись в файл
/*void read_file_data(Admin& admin, User& user, Car& car, Order& order,vector<Admin>& admin_, vector<User>& user_, vector<Car>& car_, vector<Order>& order_)
{
    //
    ifstream file_1("Admin.txt");
    ifstream file_2("User.txt");
    ifstream file_3("Car.txt");
    ifstream file_4("Order.txt");
    //   ifstream file_5("Operation.txt");
       //
    if (!file_1.is_open())
    {
        cout << "Ошибка при открытии файла (-ов) или в файле нет данных1." << endl;
        return;
    }
    //
    if (!file_2.is_open())
    {
        cout << "Ошибка при открытии файла (-ов) или в файле нет данных2." << endl;
        return;
    }
    //
    if (!file_3.is_open())
    {
        cout << "Ошибка при открытии файла (-ов) или в файле нет данных3." << endl;
        return;
    }
    //
    if (!file_4.is_open())
    {
        cout << "Ошибка при открытии файла (-ов) или в файле нет данных4." << endl;
        return;
    }
    //
  //  if (!file_5.is_open())
  //  {
  //  	cout << "Ошибка при открытии файла (-ов) или в файле нет данных5." << endl;
  //  	return;
 //   }
    //
    while (file_1 >> admin.login)
    {
        file_1 >> admin.password;
        admin_.push_back(admin);
    }
    //
    while (file_2 >> user.login)
    {
        file_2 >> user.password;
        file_2 >> user.FIO;
        file_2 >> user.telefon;
        file_2 >> user.pasport;
        file_2 >> user.email;
        file_2 >> user.balance;
        user_.push_back(user);
    }
    //
    while (file_3 >> car.marka)

    {
        file_3 >> car.model;
        file_3 >> car.time_postyplenia;
        file_3 >> car.tarif;
        file_3 >> car.nalichie;
        car_.push_back(car);
    }
    //
    while (file_4 >> order.marka)
    {
        file_4 >> order.model;
        file_4 >> order.tarif;
        file_4 >> order.sum;
        order_.push_back(order);
    }
    //
    //while (file_5 >> transaction.FIO)
    //{
    //    file_5 >> transaction.time;
    //    file_5 >> transaction.sum;
    ///	transaction_.push_back(make_unique<Transaction<Order>>(transaction));
    //}
    //

   // cout << "ДАННЫЕ УСПЕШНО ОБРАБОТАНЫ И ДОБАВЛЕНЫ" << endl;

    //
    file_1.close();
    file_2.close();
    file_3.close();
    file_4.close();
    //  file_5.close();
      //
}
*/