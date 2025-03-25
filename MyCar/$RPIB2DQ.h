#pragma once
//
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include <Windows.h>
#include <windows.h>
#include <tchar.h>
#include <oledb.h>
#include <msado15.h>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>

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
    string time_postyplenia;
    int tarif;
    string nalichie;
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
    void set_tarif(int tarif)
    {
        this->tarif = tarif;
    }
    void set_nalichie(int nalichie)
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
    int get_tarif(int tarif)
    {
        return tarif;
    }
    string get_password(string nalichie)
    {
        return nalichie;
    }
    ////
    Car()
    {

    };
    Car(const string& marka, const string& model, const string& time_postyplenia, int tarif, const string& nalichie)
        : marka(marka), model(model), time_postyplenia(time_postyplenia), tarif(tarif), nalichie(nalichie)
    {

    }
    ~Car()
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
    void set_sum_arenda(double sum)
    {
        this->sum = sum;
    }
    void set_time_arenda(string time)
    {
        this->nalichie = nalichie;
    }
    //
    double get_sum_arenda(double sum)
    {
        return sum;
    }
    //
    string get_time_arenda(string time)
    {
        return time;
    }
    //
    ////
    Order()
    {

    };
    //
    Order(double sum, const string& time)
        : sum(sum), time(time)
    {
    }
    //
    ~Order()
    {

    };
    //

};
// шаблонный класс
template <class T>
class Transaction : public Order 
{
public:
    //
    int sum;
    string time;
    T* currentState;
    T* prevState;
    //
public:
    //
    Transaction() : sum(0), time(nullptr), prevState(nullptr), currentState(new T)
    {}
    //
    Transaction(const Transaction& obj) : currentState(new T(*(obj.currentState))), prevState(nullptr)
    {}
    //
    ~Transaction()
    {
        delete currentState;
        delete prevState;
    }
    //
    Transaction& operator=(const Transaction& obj);
    //
    void showState(State state);
    //
    bool beginTransactions(int sum);
    //
    void commit();
    //
    void deleteTransactions();
    //
    void Transaction_all();
    //
    const T* operator->() const;
    //
    T* operator->();
    //
};
////
void autorisation();
//
void registration();
////
//
void User_();
////
void User_Edit_User_Uniqe();
//
void Auto();
////
void Admin_Data_Admin();
//
void Admin_Data_User();
//
void Admin_Data_Auto();
//
void Admin_Data_Order();
//
void Admin_Data_Transaction();
////
void Data_Entry();
void Data_Reading();
void Data_Print();
void Data_Edit();
void Data_Copy();
void Data_Add();
void Data_Delete();
void Data_Sort();
void Data_Save();
//
void GetBalance();
void GetOrder();
void AutoCheck();
//
void Exit();