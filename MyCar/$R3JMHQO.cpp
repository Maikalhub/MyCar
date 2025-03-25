

#include "КУРСОВАЯ РАБОТА.h"

void autorisation()
{
   
};
//
void registration()
{};
////
//
int Admin_menu_2()
{
    //
    int choose1;
    //
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                  ВЫБЕРИТЕ ДЕЙСТВИЕ                                                   |" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << "|      1) ДАННЫЕ АДМИНИСТРАТОРА                                                                                        |" << endl;
    cout << "|      2) ДАННЫЕ ПОЛЬЗОВАТЕЛЯ                                                                                          |" << endl;
    cout << "|      3) ДАННЫЕ АВТОМОБИЛЕЙ                                                                                           |" << endl;
    cout << "|      4) ДАННЫЕ ОПЕРАЦИЙ                                                                                              |" << endl;
    cout << "|      5) ВЕРНУТЬСЯ В МЕНЮ АДМИНИСТРАТОРА                                                                              |" << endl;
    cout << "|      6) ВЫХОД                                                                                                        |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    cout << "ВВЕДИТЕ ДЕЙСТВИЕ :" << endl;
    cin >> choose1;
    //
    switch (choose1)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break; 
    case 6:
        return 0;
    default:
        break;
    }
    //
};
//
int Admin_()
{
    //
    int choose;
    //
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                         ВЫ ВОШЛИ В СИСТЕМУ КАК АДМИНИСТРАТОР                                         |" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                     ЗДРАСТВУЙТЕ                                                      |" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                  ВЫБЕРИТЕ ДЕЙСТВИЕ                                                   |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|      1) РАБОТА С ДАННЫМИ                                                                                             |" << endl;
    cout << "|      2) ВЕРНУТЬСЯ К АВТОРИЗАЦИИ                                                                                      |" << endl;
    cout << "|      3) ВЫХОД                                                                                                        |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    cout << "ВВЕДИТЕ ДЕЙСТВИЕ :" << endl; 
    cin >> choose;
    //
    switch (choose)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        return 0;
    default:
        break;
    }
    //
};
//
void User_()
{
    //
    int choose;
    //
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                         ВЫ ВОШЛИ В СИСТЕМУ КАК АДМИНИСТРАТОР                                         |" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                     ЗДРАСТВУЙТЕ                                                      |" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                  ВЫБЕРИТЕ ДЕЙСТВИЕ                                                   |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|      1) МОИ ДАННЫЕ                                                                                                   |" << endl;
    cout << "|      2) АРЕНДОВАТЬ АВТОМОБИЛЬ                                                                                        |" << endl;
    cout << "|      3) ВЕРНУТЬСЯ К АВТОРИЗАЦИИ                                                                                      |" << endl;
    cout << "|      4) ВЫХОД                                                                                                        |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    cout << "ВВЕДИТЕ ДЕЙСТВИЕ :" << endl;
    cin >> choose;
    //
    switch (choose)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    //
};
////
void User_Edit_User_Uniqe()
{};
//
void Auto()
{};
////
void Admin_Data_Admin()
{};
//
void Admin_Data_User()
{};
//
void Admin_Data_Auto()
{};
//
void Admin_Data_Order()
{};
//
void Admin_Data_Transaction()
{};
void Data_Entry()
{
};
void Data_Reading()
{
};
void Data_Print()
{
};
void Data_Edit()
{
};
void Data_Copy()
{
};
void Data_Add()
{
};
void Data_Delete()
{
};
void Data_Sort()
{
};
void Data_Save()
{
}
void GetBalance()
{
}
void GetOrder()
{
}
void AutoCheck()
{
}
void Exit()
{
}
////
template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T>& obj)
{
    if (this != &obj)
    {
        delete currentState;
        currentState = new T(*(obj.currentState));
    }
    return *this;
}
//
template <class T>
T* Transaction<T>::operator->()
{
    return currentState;
}
//
template <class T>
void Transaction<T>::showState(State state)
{
    cout << "Состояние объекта ";
    if (!state)
        cout << "до начала транзакции " << endl;
    else
        cout << "после выполнения транзакции " << endl;
    if (prevState)
        cout << "prevState = " << prevState->getNumber() << endl;
    else
        cout << "prevState = NULL" << endl;
    cout << "currentState = " << currentState->getNumber() << endl;
}
//
template <class T>
bool Transaction<T>::beginTransactions(int sum)
{
    delete prevState;
    prevState = currentState;
    currentState = new T(*prevState);
    if (!currentState)
        return false;
    currentState->setNumber(sum);
    return true;
}
//
template <class T>
void Transaction<T>::commit()
{
    delete prevState;
    prevState = nullptr;
}
//
template <class T>
void Transaction<T>::deleteTransactions()
{
    if (prevState != nullptr)
    {
        delete currentState;
        currentState = prevState;
        prevState = nullptr;
    }
}
//
template <class T>
void Transaction<T>::Transaction_all()
{
    // Your implementation here
}
//
template <class T>
const T* Transaction<T>::operator->() const
{
    return currentState;
}


/*//Реализация конвертирующих функций для работы с фронт-разработкой, с помощью WinForms 
std::string& Convert_String_to_string(String^ s, std::string& os)      //1
{
    // TODO: вставьте здесь оператор return
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s).ToPointer());
    os = chars;
    Marshal::FreeGlobal(IntPtr((void*)chars));

    return os;
};
//
String^ Convert_string_to_String(std::string& os, String^ s) //2
{
    // TODO: вставьте здесь оператор return
    s = gcnew System::String(os.c_str());

    return s;
};
//
std::string& Convert_String_to_string(String^ s) // 3
{
    // TODO: вставьте здесь оператор return
    std::string os;
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s).ToPointer());
    os = chars;
    Marshal::FreeGlobal(IntPtr((void*)chars));

    return os;
};
//
String^ Convert_string_to_String(std::string::os) // 4
{
    System::String^ s = gcnew System::String(os.c_str());

    return s;
}
//
System::String^ Convert_char_to_String(char* ch) // 5
{
    // TODO: вставьте здесь оператор return
    char* chr = new char();
    chr[0] = vh;
    System::String^ str;
    for (int i = 0; chr[i] != '\0'; i++)
    {
        str += wchar_t(ch);
    }
    return str;
}
//
char* Convert_String_to_char(System::String^ string) // 6
{
    using namespace Runtime::InteropServices;
    return(char*)(void*)Marshal::StringToGlobalAnsi(string);
};*/


