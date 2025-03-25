#include "Header.h"


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
//9
template <class T>
T* Transaction<T>::operator->()
{
    return currentState;
}
//
template <class T>
void Transaction<T>::showState(State state)
{
    cout << "��������� ������� ";
    if (!state)
        cout << "�� ������ ���������� " << endl;
    else
        cout << "����� ���������� ���������� " << endl;
    if (prevState)
        cout << "prevState = " << prevState->get_sum(sum) << endl;
    else
        cout << "prevState = NULL" << endl;
    cout << "currentState = " << currentState->get_sum(sum) << endl;
}
//
template <class T>
bool Transaction<T>::beginTransactions(double sum)
{
    delete prevState;
    prevState = currentState;
    currentState = new T(*prevState);
    if (!currentState)
        return false;
    currentState->get_sum(sum);
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


///
///
/// 
///
/// 


void friendFunction(const User& user)
{
}



// ����������
void encryptFile(const std::string& key, const std::string& inFile, const std::string& outFile) {
    std::ifstream fin(inFile, std::ios::binary);
    std::ofstream fout(outFile, std::ios::binary);
    if (!fin || !fout) {
        std::cerr << "Error opening files\n";
        return;
    }
    char ch;
    int i = 0;
    int n = key.size();
    while (fin.get(ch)) {
        ch ^= key[i];
        fout.put(ch);
        i = (i + 1) % n;
    }
    fin.close();
    fout.close();
}

// ������� ��� ����������� ����� � ������� �����
void decryptFile(const std::string& key, const std::string& inFile, const std::string& outFile) {
    std::ifstream fin(inFile, std::ios::binary);
    std::ofstream fout(outFile, std::ios::binary);
    if (!fin || !fout)
    {
        return;
    }
    char ch;
    int i = 0;
    int n = key.size();
    while (fin.get(ch)) {
        ch ^= key[i];
        fout.put(ch);
        i = (i + 1) % n;
    }
    fin.close();
    fout.close();
}



//
// 
// ��������� ������ � �������� �������
std::string getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    struct tm timeInfo;
    localtime_s(&timeInfo, &in_time_t);

    std::stringstream ss;
    ss << std::put_time(&timeInfo, "%Y-%m-%d %X");
    return ss.str();
}
// 
// 
// ���������� ������ �� ������
void read_file_data(Admin& admin, User& user, Car& car, Order& order, vector<Admin>& admin_, vector<User>& user_, vector<Car>& car_, vector<Order>& order_)
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
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������1." << endl;
        return;
    }
    //
    if (!file_2.is_open())
    {
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������2." << endl;
        return;
    }
    //
    if (!file_3.is_open())
    {
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������3." << endl;
        return;
    }
    //
    if (!file_4.is_open())
    {
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������4." << endl;
        return;
    }
    //
  //  if (!file_5.is_open())
  //  {
  //  	cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������5." << endl;
  //  	return;
 //   }
    //


    cout << "������ ������� ���������� � ���������" << endl;

    //
    file_1.close();
    file_2.close();
    file_3.close();
    file_4.close();
    //  file_5.close();
      //
}
// ���������� ������ �������������� �� �����
void read_file_data_Admin(Admin& admin, vector<Admin>& admin_)
{
    //
    ifstream file_1("Admin.txt");
    //
    if (!file_1.is_open())
    {
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������1." << endl;
        return;
    }
    //
    while (file_1 >> admin.login)
    {
        file_1 >> admin.password;
        admin_.push_back(admin);
    }

    cout << "������ ������� ���������� � ���������" << endl;

    //
    file_1.close();

}
// ���������� ������ ������������ �� �����
void read_file_data_User(User& user, vector<User>& user_)
{
    //
    ifstream file_2("User.txt");
    //
    if (!file_2.is_open())
    {
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������2." << endl;
        return;
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
    cout << "������ ������� ���������� � ���������" << endl;

    //
    file_2.close();
    //
}
// ���������� ������ ���������� �� �����
void read_file_data_Car(Car& car, vector<Car>& car_)
{
    //
    ifstream file_3("Car.txt");
    //
    if (!file_3.is_open())
    {
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������3." << endl;
        return;
    }
    //
    while (file_3 >> car.marka)
    {
        file_3 >> car.model;
        file_3 >> car.number;
        file_3 >> car.time_postyplenia;
        file_3 >> car.tarif;
        file_3 >> car.nalichie;
        car_.push_back(car);
    }
    //
    file_3.close();
    //
}
// ���������� ������ ������ �� �����
void read_file_data_Order(Order& order, vector<Order>& order_)
{
    //
    ifstream file_4("Order.txt");
    //
    if (!file_4.is_open())
    {
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������4." << endl;
        return;
    }
    //
    while (file_4 >> order.marka)
    {
        file_4 >> order.model;
        file_4 >> order.number;
        file_4 >> order.tarif;
        file_4 >> order.sum;
        order_.push_back(order);
    }
    //
    file_4.close();
    //
}
//


// ��������� ������� ������������
double balance_from_user_data(string& login)
{
    //
    string login_file;
    double balance_;
    //
    ifstream file; // ������ � ������� ��������� (������)
    //
    string sr; // �������� ������ (��� �������� ������ � �����)
    //
    bool fl = 0;
    //
    file.open("User.txt"); // ��������� ����
    //
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                ��� ����������� ������� ������                                        |" << endl;
    cout << "+======================================================================================================================+" << endl;
    //

        // �������� � ������, ���� �� �� ����������  
    while (!file.eof())
    {
        // ��������� ������ ��� �������� 
        getline(file, login_file);
        //
        if (login_file == login)
        {
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);

            file >> balance_;
            fl = 1;
            login = login_file;
            return balance_;
            break;
        }
        else
        {
            // ���������� ������� ��� ��������� �������� ���� �� ���������� ����
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);

        }
    }
    //
    file.close();
    //
}
// ���������� ������ ������������
void update_user_data_file(const vector<User>& user_)
{
    //
    ofstream file_("User.txt", ios::trunc);
    //
    for (const User& user : user_)
    {
        file_ << user.login << "\n";
        file_ << user.password << "\n";
        file_ << user.FIO << "\n";
        file_ << user.telefon << "\n";
        file_ << user.pasport << "\n";
        file_ << user.email << "\n";
    }
    //
    file_.close();
}
// ���������� ������ ����������
void update_car_nalichie_data_file(string& marka, string& model, string& number)
{
    std::fstream file("Car.txt", std::ios::in | std::ios::out);

    if (file.is_open())
    {
        while (!file.eof())
        {
            std::streampos currentPosition = file.tellg();

            Car apt;
            file >> apt.marka;
            file >> apt.model;
            file >> apt.number;
            file >> apt.time_postyplenia;
            file >> apt.tarif;
            file >> apt.nalichie;

            if (apt.marka == marka && apt.model == model && apt.number == number)
            {
                // ���� ��� ������ ����������, �������� nalichie
                if (apt.nalichie == 1)
                {
                    apt.nalichie = 0;

                    // ���������� ��������� ������/������ � ������� �������
                    file.seekp(currentPosition);

                    // ���������� ���������� ������ ������� � ����
                    file << apt.marka << "\n";
                    file << apt.model << "\n";
                    file << apt.number << "\n";
                    file << apt.time_postyplenia << "\n";
                    file << apt.tarif << "\n";
                    file << apt.nalichie << "\n";


                    break; // ����� �� ����� ����� ���������� ������
                }
            }
        }

        file.close();
    }
    else
    {
        std::cerr << "�� ������� ������� ���� ��� ������.\n";
    }
}//
// ���������� ������ ������������ 2
void update_user_data_file2(double& m, string& login)
{
    std::ifstream infile("User.txt");
    std::vector<User> users_;

    // ������ ������ �� �����
    User tempUser;
    while (infile >> tempUser.login)
    {
        infile >> tempUser.password;
        infile >> tempUser.FIO;
        infile >> tempUser.telefon;
        infile >> tempUser.pasport;
        infile >> tempUser.email;
        infile >> tempUser.balance;
        users_.push_back(tempUser);
    }
    infile.close();

    // ���������� ������� ��� ����������� ������������
    auto it = std::find_if(users_.begin(), users_.end(),
        [&login](const User& u)
        {
            return u.login == login;
        });

    if (it != users_.end())
    {
        it->balance = m;

        // ���������� ������ � ����
        std::ofstream outfile("User.txt", std::ios::trunc);
        for (const User& user : users_)
        {
            outfile << user.login << "\n";
            outfile << user.password << "\n";
            outfile << user.FIO << "\n";
            outfile << user.telefon << "\n";
            outfile << user.pasport << "\n";
            outfile << user.email << "\n";
            outfile << user.balance << "\n\n";
        }
        outfile.close();

        std::cout << "������ ������������ ������� ���������." << std::endl;
    }
    else
    {
        std::cout << "������������ � ��������� ������� �� ������." << std::endl;
    }
}
// ���������� ������ ������
void update_user_order_data_file(Order& order)
{
    //
    ofstream file_("Order.txt", ios::app);
    //
    file_ << order.marka << "\n";
    file_ << order.model << "\n";
    file_ << order.number << "\n";
    file_ << order.tarif << "\n";
    file_ << order.sum << "\n";
    file_ << "\n";
    //
    //order_add_to_file_.close();
    file_.close();
}
//


//  �������� ������ ��������������
bool admin_data_check(string& login, string& password)
{
    //
    string login_file;
    ifstream file;
    //
    //
    int role = 0;
    bool status = false;
    string sr;
    bool fl = 0;
    //
    file.open("Admin.txt");
    //

    while (!file.eof())
    {
        //
        getline(file, login_file);
        //
        if (login_file == login)
        {
            fl = 1;
        }
        else
        {
            getline(file, sr);
            getline(file, sr);
        }
    }
    //
    return fl;
    cin.ignore();
    file.close();
    //
}
// �������� ������ ������������
bool user_data_check(string& login, string& password)
{
    string login_file;
    ifstream file;
    //
    //
    int role = 0;
    bool status = false;
    string sr;
    bool fl = 0;
    //
    file.open("User.txt");
    //

    while (!file.eof())
    {
        //
        getline(file, login_file);
        //
        if (login_file == login)
        {
            fl = 1;
        }
        else
        {
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);

        }
    }
    //
    return fl;
    cin.ignore();
    file.close();
    //
}
// �������� ������ ����������
bool car_data_check(string& marka, string& model, string& number)
{
    //
    string marka_file;
    string model_file;
    string number_file;
    //
    ifstream file;
    //
    //
    int role = 0;
    bool status = false;
    string sr;
    bool fl = 0;
    //
    file.open("Car.txt");
    //
    while (!file.eof())
    {
        //
        getline(file, marka_file);
        getline(file, model_file);
        getline(file, number_file);
        //
        if (marka_file == marka && model_file == model && number_file == number)
        {
            fl = 1;
        }
        else
        {
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
            getline(file, sr);
        }
    }
    //
    return fl;
    cin.ignore();
    file.close();
    //
}
//


// (������������) ����������� (��� ������������, ��� �������������� ������� ���������� ������ ��������������� ������) 
bool registration_user()
{
    //
    ofstream file_; // ������ ��� ������ ������ 
    //
    string login;
    string password;
    double balance = 100;
    string Name_;
    string IO_;
    string telefon_;
    string pasport_;
    //
    int buffer = 0;
    bool status = 0;
    //
    file_.open("User.txt", ios::app); // ������ � ������
    //
    string s;
    while (true)
    {
        //
        cout << "+======================================================================================================================+" << endl;
        cout << "|                                                     ������� ������                                                   |" << endl;
        cout << "+======================================================================================================================+" << endl;
        //
        cout << "������� ����� : " << endl;
        cin >> login;
        cout << "������� ������ : " << endl;
        cin >> password;
        // �������� �� ������������ ������ ������ � ���������
        if (user_data_check(login, password) == 1)
        {
            status = 0;
        }
        else
        {
            // ���������� ������ � ����
            file_ << login << "\n";    // login
            file_ << password << "\n"; // pasword
            file_ << buffer << "\n";   // FIO
            file_ << buffer << "\n";   // telefon
            file_ << buffer << "\n";   // pasport
            file_ << buffer << "\n";   // email
            file_ << balance << "\n";  // balance
            file_ << "\n"; // ������ ������ ������ � ����� ��� ����������
            // ������ � ������� �����-������ 
            cout.setf(ios::right); // ������������� ���� �������������� ��� ������ � ������� (������������� ������ ����������� ������ �� ������ �������) 
            cout.width(20); // ������
            cout.unsetf(ios::right); // ������� ���� �������������
            cout << "�� ������� ����������������" << endl;
            status = 1;
            // ������������ � ������� ���� 
        }
        //
    }
    return status;
    file_.close();

    //
};



//
// (�������������) �������� ������ ��������������
void admin_view_admin_data()
{
    //
    Admin admin_view;
    //
    vector<Admin> admin_view_;
    //
    read_file_data_Admin(admin_view, admin_view_);
    //
    if (admin_view_.empty())
    {
        cout << "��� ������ ��� �����������." << endl;
        return;
    }
    //
    cout << "+----------------------------------------------------------+" << endl;
    cout << "|            �����            |           ������           |" << endl;
    cout << "+----------------------------------------------------------+" << endl;
    //
    for (const auto& rep1 : admin_view_)
    {
        cout << "|" << setw(15) << rep1.login << setw(15) << "|" << setw(14) << rep1.password << setw(15) << "|" << endl;
        cout << "+----------------------------------------------------------+" << endl;
    }
    //
    admin_view_.clear();
    //
}
// (�������������) �������� ������ ������������
void admin_view_user_data()
{
    //
    User user_view;
    //
    vector<User> user_view_;
    //
    read_file_data_User(user_view, user_view_);
    //
    if (user_view_.empty())
    {
        cout << "��� ������ ��� �����������." << endl;
        return;
    }
    //
    cout << "+------------------------------------------------------------------------------------------+" << endl;
    cout << "|            �����            |            ������            |            ������           |" << endl;
    cout << "+------------------------------------------------------------------------------------------+" << endl;
    //
    for (const auto& rep1 : user_view_)
    {
        cout << "|" << setw(15) << rep1.login << setw(15) << "|" << setw(16) << rep1.password << setw(15) << "|" << setw(15) << rep1.balance << setw(15) << "|" << endl;
        cout << "+------------------------------------------------------------------------------------------+" << endl;
    }
    //
    user_view_.clear();
    //
}
// (�������������) �������� ������ ����������
void admin_view_car_data()
{
    //
    Car car_view;
    //
    vector<Car> car_view_;
    //
    read_file_data_Car(car_view, car_view_);
    //
    string car_yes = "������";
    string car_no = "�� ������";
    //
    if (car_view_.empty())
    {
        cout << "��� ������ ��� �����������." << endl;
        return;
    }
    //
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        �����        |         ������         |         �����         |       �����       |          �������          |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    for (const auto& rep1 : car_view_)
    {
        //if (rep1.nalichie == 1)
        //{
          //  car_yes
        //}
        //else
        //{

        //}
        cout << "|" << setw(11) << rep1.marka << setw(11) << "|" << setw(13) << rep1.model << setw(12) << "|" << setw(15) << rep1.number << setw(9) << "|" << setw(11) << rep1.tarif << setw(9) << "|" << setw(14) << rep1.nalichie << setw(14) << "|" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    }
    //
    car_view_.clear();
    //
}
// (�������������) �������� ������ ������
void admin_view_order_data()
{
    //
    Order order_view;
    //
    vector<Order> order_view_;
    //
    read_file_data_Order(order_view, order_view_);
    //
    if (order_view_.empty())
    {
        cout << "��� ������ ��� �����������." << endl;
        return;
    }
    //
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        �����        |         ������         |         �����         |       �����       |           �����           |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    for (const auto& rep1 : order_view_)
    {
        cout << "|" << setw(10) << rep1.marka << setw(10) << "|" << setw(10) << rep1.model << setw(10) << "|" << setw(10) << rep1.number << setw(10) << "|" << setw(10) << rep1.tarif << setw(10) << rep1.sum << setw(10) << "|" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;

    }
    //
    order_view_.clear();
    //
}
//
//

//

//
// (�������������) ���������� ������ ��������������
bool admin_add_admin_data()
{
    //
    string login;
    string password;
    //
    ofstream file_("Admin.txt", ios::app);
    //
    Admin admin_add;
    //
    vector<Admin> admin_add_;
    //
    bool status = 0;
    //
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                           ���������� ������ ��������������                                           |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    cout << "������� ����� : ";
    cin >> login;
    //
    cout << "������� ������ : ";
    cin >> password;
    // �������� �� ������������ ������ ������ � ���������
    if (admin_data_check(login, password) == 1)
    {
        status = 0;
    }
    else
    {
        //
        file_ << login << "\n";
        file_ << password << "\n";
        file_ << "\n";
        file_.close();
        //
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                              ������ ������� ���������                                                |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
    }
    //
  //  admin_.push_back(admin);
    //
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                ���� ������ ��������                                                  |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    return status;
    file_.close();
};
// (�������������) ���������� ������ ������������
bool admin_add_user_data()
{
    //
    ofstream file_; // ������ ��� ������ ������ 
    //
    string login;
    string password;
    double balance = 100;
    string Name_;
    string IO_;
    string telefon_;
    string pasport_;
    //
    int buffer = 0;
    bool status = 0;
    //
    file_.open("User.txt", ios::app); // ������ � ������
    //
    string s;
    while (true)
    {
        //
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                           ���������� ������ ������������                                             |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� ����� : " << endl;
        cin >> login;
        cout << "������� ������ : " << endl;
        cin >> password;
        // �������� �� ������������ ������ ������ � ���������
        if (user_data_check(login, password) == 1)
        {
            status = 0;
            break;
        }
        else
        {
            // ���������� ������ � ����
            file_ << login << "\n";    // login
            file_ << password << "\n"; // pasword
            file_ << buffer << "\n";   // FIO
            file_ << buffer << "\n";   // telefon
            file_ << buffer << "\n";   // pasport
            file_ << buffer << "\n";   // email
            file_ << balance << "\n";  // balance
            file_ << "\n"; // ������ ������ ������ � ����� ��� ����������
            // ������ � ������� �����-������ 
            cout.setf(ios::right); // ������������� ���� �������������� ��� ������ � ������� (������������� ������ ����������� ������ �� ������ �������) 
            cout.width(20); // ������
            cout.unsetf(ios::right); // ������� ���� �������������
            cout << "�� ������� ����������������" << endl;
            status = 1;
            break;
            // ������������ � ������� ���� 
        }
        //
    }
    //
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                ���� ������ ��������                                                  |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    return status;
    file_.close();
    // 
};
// (�������������) ���������� ������ ����������
bool admin_add_car_data()
{
    //
    ofstream file_; // ������ ��� ������ ������ 
    //
    string marka;
    string model;
    string number;
    string time_postyplenia;
    double tarif;
    bool nalichie;
    //
    int buffer = 0;
    bool status = 0;
    //
    file_.open("Car.txt", ios::app); // ������ � ������
    //
    string s;
    while (true)
    {
        //
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                           ���������� ������ ������������                                             |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� ����� ������ : " << endl;
        cin >> marka;
        cout << "������� ������ ������ : " << endl;
        cin >> model;
        cout << "������� ����� ������ : " << endl;
        cin >> number;
        // �������� �� ������������ ������ ������ � ���������
        if (car_data_check(marka, model, number) == 1)
        {
            status = 0;
            break;
        }
        else
        {
            cout << "������� ����� ����������� ������ : " << endl;
            cin >> time_postyplenia;
            cout << "������� ����� ������ : " << endl;
            cin >> tarif;
            cout << "������� ������� ������ (1 - �� 0 - ���) : " << endl;
            cin >> nalichie;
            // ���������� ������ � ����
            file_ << marka << "\n";    // login
            file_ << model << "\n"; // pasword
            file_ << number << "\n";   // FIO
            file_ << time_postyplenia << "\n";   // telefon
            file_ << tarif << "\n";   // pasport
            file_ << nalichie << "\n";   // email
            file_ << "\n"; // ������ ������ ������ � ����� ��� ����������
            // ������ � ������� �����-������ 
            cout.setf(ios::right); // ������������� ���� �������������� ��� ������ � ������� (������������� ������ ����������� ������ �� ������ �������) 
            cout.width(20); // ������
            cout.unsetf(ios::right); // ������� ���� �������������
            cout << "�� ������� ����������������" << endl;
            status = 1;
            break;
            // ������������ � ������� ���� 
        }
        //
    }
    //
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                ���� ������ ��������                                                  |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    return status;
    file_.close();
    // 
};
// (�������������) ���������� ������ ������ (�� �����)
bool admin_add_order_data()
{
    return 0;
};
//


//
// (�������������) ������ � ������� �������������� 
int admin_work_admin_data(string& login, string& password)
{
    //
    int choose;
    //
    while (true)
    {
        cout << "+======================================================================================================================+" << endl;
        cout << "|                                               �������� ������ ��� ������                                             |" << endl;
        cout << "+======================================================================================================================+" << endl;
        cout << "|      1) �������� ������                                                                                              |" << endl;
        cout << "|      2) ���������� ������                                                                                            |" << endl;
        cout << "|      3) �������������� ������                                                                                        |" << endl;
        cout << "|      4) �������� ������                                                                                              |" << endl;
        cout << "|      5) ����� ������                                                                                                 |" << endl;
        cout << "|      6) ����������                                                                                                   |" << endl;
        cout << "|      7) �������� ���� ������                                                                                         |" << endl;
        cout << "|      8) ��������� � ���� ������                                                                                      |" << endl;
        cout << "|      9) �����                                                                                                        |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� �������� :" << endl;
        cin >> choose;
        //
        switch (choose)
        {
        case 1:
            admin_view_admin_data();
            break;
        case 2:
            if (admin_add_admin_data() == 1)
            {
                cout << "�� ������� �������� ������ :) " << endl;
            }
            else
            {
                cout << "�� �� ������ ���������������� :( " << endl;

            }
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:
            admin_menu_work_data(login, password);
            break;
        case 9:
            //
            cout << "+======================================================================================================================+" << endl;
            cout << "|                                       ������� �� ����������� ����������                                              |" << endl;
            cout << "+======================================================================================================================+" << endl;
            //
            exit(0);
            //
            break;
        default:
            cout << "������������ �����. ����������, ��������� ���� :" << endl;
        }
        //
    }
    //
};
// (�������������) ������ � ������� ������������ 
int admin_work_user_data(string& login, string& password)
{
    //
    int choose;
    //
    while (true)
    {
        cout << "+======================================================================================================================+" << endl;
        cout << "|                                               �������� ������ ��� ������                                             |" << endl;
        cout << "+======================================================================================================================+" << endl;
        cout << "|      1) �������� ������                                                                                              |" << endl;
        cout << "|      2) ���������� ������                                                                                            |" << endl;
        cout << "|      3) �������������� ������                                                                                        |" << endl;
        cout << "|      4) �������� ������                                                                                              |" << endl;
        cout << "|      5) ����� ������                                                                                                 |" << endl;
        cout << "|      6) ����������                                                                                                   |" << endl;
        cout << "|      7) �������� ���� ������                                                                                         |" << endl;
        cout << "|      8) ��������� � ���� ������                                                                                      |" << endl;
        cout << "|      9) �����                                                                                                        |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� �������� :" << endl;
        cin >> choose;
        //
        switch (choose)
        {
        case 1:
            admin_view_user_data();
            break;
        case 2:
            if (admin_add_user_data() == 1)
            {
                cout << "�� ������� �������� ������ :) " << endl;
            }
            else
            {
                cout << "�� �� ������ �������� ������ :( " << endl;
            }
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:
            admin_menu_work_data(login, password);
            break;
        case 9:
            //
            cout << "+======================================================================================================================+" << endl;
            cout << "|                                       ������� �� ����������� ����������                                              |" << endl;
            cout << "+======================================================================================================================+" << endl;
            //
            exit(0);
            //
            break;
        default:
            cout << "������������ �����. ����������, ��������� ���� :" << endl;
        }
        //
    }
    //
};
// (�������������) ������ � ������� ����������� 
int admin_work_car_data(string& login, string& password)
{
    //
    int choose;
    //
    while (true)
    {
        cout << "+======================================================================================================================+" << endl;
        cout << "|                                               �������� ������ ��� ������                                             |" << endl;
        cout << "+======================================================================================================================+" << endl;
        cout << "|      1) �������� ������                                                                                              |" << endl;
        cout << "|      2) ���������� ������                                                                                            |" << endl;
        cout << "|      3) �������������� ������                                                                                        |" << endl;
        cout << "|      4) �������� ������                                                                                              |" << endl;
        cout << "|      5) ����� ������                                                                                                 |" << endl;
        cout << "|      6) ����������                                                                                                   |" << endl;
        cout << "|      7) �������� ���� ������                                                                                         |" << endl;
        cout << "|      8) ��������� � ���� ������                                                                                      |" << endl;
        cout << "|      9) �����                                                                                                        |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� �������� :" << endl;
        cin >> choose;
        //
        switch (choose)
        {
        case 1:
            admin_view_car_data();
            break;
        case 2:
            if (admin_add_car_data() == 1)
            {
                cout << "�� ������� �������� ������ :) " << endl;
            }
            else
            {
                cout << "�� �� ������ �������� ������ :( " << endl;
            }
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:
            admin_menu_work_data(login, password);
            break;
        case 9:
            //
            cout << "+======================================================================================================================+" << endl;
            cout << "|                                       ������� �� ����������� ����������                                              |" << endl;
            cout << "+======================================================================================================================+" << endl;
            //
            exit(0);
            //
            break;
        default:
            cout << "������������ �����. ����������, ��������� ���� :" << endl;
        }
        //
    }
    //
};
// (�������������) ������ � ������� �������� 
int admin_work_operation_data(string& login, string& password)
{
    //
    int choose;
    //
    while (true)
    {
        cout << "+======================================================================================================================+" << endl;
        cout << "|                                               �������� ������ ��� ������                                             |" << endl;
        cout << "+======================================================================================================================+" << endl;
        cout << "|      1) �������� ������                                                                                              |" << endl;
        cout << "|      2) ���������� ������                                                                                            |" << endl;
        cout << "|      3) �������������� ������                                                                                        |" << endl;
        cout << "|      4) �������� ������                                                                                              |" << endl;
        cout << "|      5) ����� ������                                                                                                 |" << endl;
        cout << "|      6) ����������                                                                                                   |" << endl;
        cout << "|      7) �������� ���� ������                                                                                         |" << endl;
        cout << "|      8) ��������� � ���� ������                                                                                      |" << endl;
        cout << "|      9) �����                                                                                                        |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� �������� :" << endl;
        cin >> choose;
        //
        switch (choose)
        {
        case 1:
            admin_view_order_data();
            break;
        case 2:
            cout << "���������� ������ �� ������������� :( " << endl;
            break;
        case 3:
            cout << "�������������� ������ �� ������������� :( " << endl;
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:
            admin_menu_work_data(login, password);
            break;
        case 9:
            //
            cout << "+======================================================================================================================+" << endl;
            cout << "|                                       ������� �� ����������� ����������                                              |" << endl;
            cout << "+======================================================================================================================+" << endl;
            //
            exit(0);
            //
            break;
        default:
            cout << "������������ �����. ����������, ��������� ���� :" << endl;
        }
        //
    }
    //
};
//


// (������������) �������� ������ ������������ 
void user_data_my_data(string& login, string& password)
{
    User user_my_data;
    vector<User> user_my_data_;
    read_file_data_User(user_my_data, user_my_data_);
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                 ������ ������������                                                  |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    auto it = find_if(user_my_data_.begin(), user_my_data_.end(),
        [&login, &password](const User& user_my_data_)
        {
            return user_my_data_.login == login && user_my_data_.password == password;
        });
    //
    if (it != user_my_data_.end())
    {
        cout << "���� ������ :" << endl;
        cout << "����� : " << endl << (*it).login << endl;
        cout << "������ : " << endl << (*it).password << endl;
        cout << "������ : " << endl << (*it).balance << endl;
    }
    //
    else
    {
        cout << "������ �� ������.";
        cin.clear();
        cin.clear();
        return;
    }
    user_my_data_.clear();
};
// (������������) �������������� ������ ������������ 
void edit_user_data_my_data(string& login, string& password)
{
    //
    User user_edit;
    vector<User> user_edit_;

    auto it = find_if(user_edit_.begin(), user_edit_.end(),
        [&login, &password](const User& user_edit)
        {
            return user_edit.login == login && user_edit.password == password;
        });
    //
    if (it != user_edit_.end())
    {
        cout << "������� ����� ������ ������������:" << endl;

        cout << "��� : ";
        cin >> it->FIO;

        cout << "������� : ";
        cin >> it->telefon;

        cout << "������� : ";
        cin >> it->pasport;

        cout << "����� : ";
        cin >> it->email;

        update_user_data_file(user_edit_);

        cout << "������ ������������ ������� ���������." << endl;
    }
    else
    {

        cout << "������������ � ��������� ������� � ������� �� ������." << endl;
    }
    //
};

// (������������) ������ � ������� ������������ 
void user_work_my_data(string& login, string& password)
{
    //
    int choose;
    //
    while (true)
    {
        cout << "+======================================================================================================================+" << endl;
        cout << "|                                                  �������� ��������                                                   |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|      1) �������� ������                                                                                              |" << endl;
        cout << "|      2) ������������� ������                                                                                         |" << endl;
        cout << "|      3) ��������� � ���� ������������                                                                                |" << endl;
        cout << "|      4) �����                                                                                                        |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� �������� :" << endl;
        cin >> choose;
        //
        switch (choose)
        {
        case 1:
            user_data_my_data(login, password);
            break;
        case 2:
            edit_user_data_my_data(login, password);
            break;
        case 3:
            user_menu(login, password);
            break;
        case 4:
            //
            cout << "+======================================================================================================================+" << endl;
            cout << "|                                       ������� �� ����������� ����������                                              |" << endl;
            cout << "+======================================================================================================================+" << endl;
            //
            exit(0);
            //
            break;
        default:
            cout << "������������ �����. ����������, ��������� ���� :" << endl;
        }
        //
    }
    //
};
// (������������) ������ � ������� ������������ 


// (������������)�������� ������ ����������
void user_view_car_data()
{
    //
    Car car_view;
    //
    vector<Car> car_view_;
    //
    read_file_data_Car(car_view, car_view_);
    //
    string car_yes = "������";
    string car_no = "�� ������";
    //
    if (car_view_.empty())
    {
        cout << "��� ������ ��� �����������." << endl;
        return;
    }
    //
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        �����        |         ������         |         �����         |       �����       |          �������          |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    for (const auto& rep1 : car_view_)
    {
        if (rep1.nalichie == 1)
        {
            //  car_yes
          //}
          //else
          //{

          //}
            cout << "|" << setw(11) << rep1.marka << setw(11) << "|" << setw(13) << rep1.model << setw(12) << "|" << setw(15) << rep1.number << setw(9) << "|" << setw(11) << rep1.tarif << setw(9) << "|" << setw(14) << rep1.nalichie << setw(14) << "|" << endl;
            cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        }
    }
    //
    car_view_.clear();
    //
}

// (������������) ������ ����������
void user_order_car_data_over(string& login, string& password)
{
    //

    Car car_order;
    //
    vector<Car> car_order_;
    //
    Order order_order;
    //
    vector<Order> order_order_;
    //
    read_file_data_Car(car_order, car_order_);
    //
    int choose;
    int time;
    int sum;
    double m;
    bool fl = false;
    double cost;
    string time_;
    //
    ofstream file_;
    // �������� ������ ������� ������������
    m = balance_from_user_data(login);
    //
    cout << "��� ����� :" << endl;
    cout << login << endl;
    cout << "��� ������ :" << endl;
    cout << m << endl;
    //
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                 ���� ������ ������                                                   |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    string marka;
    string model;
    string number;
    string time_postyplenia;
    double tarif;
    bool nalichie;
    //
    //
    int buffer = 0;
    bool status = 0;
    //
    file_.open("Car.txt", ios::app); // ������ � ������
    //
    string s;
    while (true)
    {
        //
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                           ���������� ������ ������������                                             |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� ����� ������ : " << endl;
        cin >> order_order.marka;
        cout << "������� ������ ������ : " << endl;
        cin >> order_order.model;
        cout << "������� ����� ������ : " << endl;
        cin >> order_order.number;



        //
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                                ���� ������ ��������                                                  |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //

        auto it = find_if(car_order_.begin(), car_order_.end(),
            [&order_order](const Car& car_order)
            {
                return car_order.marka == order_order.marka && car_order.model == order_order.model && car_order.number == order_order.number;
            });
        //
        if (it != car_order_.end())
        {
            cout << "������ ������ ���� � �������" << endl;
            cout << "���������� � ������ :" << endl;
            cout << "����� : " << (*it).marka << endl;
            cout << "����� : " << (*it).number << endl;
            cout << "����� ����������� : " << (*it).time_postyplenia << endl;
            cout << "����� (����� ������� � ��������� �� ���/���) : " << (*it).tarif << endl;
            cout << "���������� ����� � ������������" << endl;
            //
            tarif = (*it).tarif;
            fl = true;
        }
        //
        else
        {
            cout << "������ �� ������." << endl;
            return;
        }

        //
        cout << "����� :" << endl;
        cout << tarif << endl;
        if (fl)
        {
            cout << "�� ����� ������ �������� ? ( ������� 1 - ��  2 - ���  3 - ����� ) " << endl;
            cout << "��� ����� : ";
            cin >> choose;
            //
            switch (choose)
            {
            case 1:
                // ������������ ����� ������� �����
                // ���������� ��������� ������ ������
                cout << "������� ����� : ";
                cin >> time;
                // ������ ����� ����� ������
                sum = time * tarif;
                cout << "�������� ����� : ";
                cout << sum << endl;
                //
                //
                //
                // ���������� ����������
                cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
                cout << "|                                           ������� ������� ����������                                                  |" << endl;
                cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
                /*file_.open("User.txt");
                // �������� �� ������������ �����
                if (sum <= 0)
                {
                    cout << "����� ������ ���� ������ 0. ������ ����������" << endl;
                    transaction.deleteTransactions();//������ ���������� ���
                    cout << "���������� ���� ��������" << endl;
                    transaction.commit();//����������� ����������
                    transaction.showState(State::middle);
                    break;
                }
                //
                transaction.setNumber(0);//��������� ������������� �������
                transaction.showState(State::begin);
                cout << "��������� ������������� ������ �������" << endl;
                cout << "--------------------------------------------------"<< endl;
                if (transaction.beginTransactions(sum) == false)
                {
                    cout << "���������� ���� ��������" << endl;
                    transaction.deleteTransactions();//������ ����������
                    transaction.commit();//����������� ����������
                    transaction.showState(State::middle);
                    break;
                }
                else
                {
                    cout << "������ �������� ����������" << endl;
                    cout << "������ ���������� ������ �������" << endl;
                    cout << endl;
                    cout << "--------------------------------------------------"
                        << endl;
                    transaction.showState(State::begin);
                    transaction.commit();//����������� ����������
                    cout << "������ ���������� ������ �������" << endl;
                    transaction.showState(State::middle);
                    cout << "������� �������� �������" << endl;
                    break;
                }

                transaction.time1 = getCurrentTime(); // �����������, � ��� ���� ������� getCurrentTime() ��� ��������� �������� �������
                transaction.sum1 = sum;
                file_ << "������ � ����������:" << endl;
                file_ << "����� ����������: " << transaction.time1<< endl;
                file_ << "�����: " << transaction.sum1 << endl;
                transaction_.push_back(make_unique<Transaction<Order>>(transaction));

                file_ << "------------------------------------" << endl;
                file_.close();
                // ���������� ����������
                cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
                cout << "|                                               ������� ���������� ��������                                            |" << endl;
                cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
                */
                // �������� ������� ������������
                if (m >= sum)
                {
                    // ������������ ����� ����������� ������
                    // 
                    // ���������� ������ � ������ �������

                    // ���������� ��������� "�������" ������������
                    it->nalichie = 0; // �������� ����������� ��� ���������������
                    update_car_nalichie_data_file(marka, model, number);
                    // ���������� ������� ������������
                    m -= sum;
                    cout << "�������� ������ : ";
                    cout << m << endl;
                    time_ = getCurrentTime(); // �����������, � ��� ���� ������� getCurrentTime() ��� ��������� �������� �������
                    //order.login = login;
                    order_order.sum = sum;
                    // order_.push_back(order);

                    update_user_order_data_file(order_order);
                    //
                    update_user_data_file2(m, login);

                    // ��������� �� �������� ������������

                    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
                    cout << "|                                                ���� ������ ��������                                                  |" << endl;
                    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
                    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
                    cout << "|                                         �� ������� ������������� �����������                                         |" << endl;
                    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
                    // ���������� ������� ������ � ����
                    //
                    user_work_my_data(login, password);
                    break;
                }
                else
                {
                    // ������������ ������� � ������������
                    cout << "������������ ������� �� �������." << endl;
                }
                break;

            case 2:
                // ������������ ������ �� ����������
                break;

            case 3:
                //
                cout << "+======================================================================================================================+" << endl;
                cout << "|                                       ������� �� ����������� ����������                                              |" << endl;
                cout << "+======================================================================================================================+" << endl;
                //
                exit(0);
                //
                break;
            default:
                cout << "������������ �����. ����������, ���������." << endl;
            }
            //
        }
    }

}

// (������������) ����� ����������
void user_search_car_data()
{
    //
    Car car_view;
    //
    vector<Car> car_view_;
    //
    read_file_data_Car(car_view, car_view_);
    //
    if (car_view_.empty())
    {
        cout << "��� ������ ��� �����������." << endl;
        return;
    }
    //
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        �����        |         ������         |         �����         |       �����       |          �������          |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    for (const auto& rep1 : car_view_)
    {
        cout << "|" << setw(10) << rep1.marka << setw(10) << "|" << setw(10) << rep1.model << setw(10) << "|" << setw(10) << rep1.number << setw(10) << "|" << setw(10) << rep1.tarif << setw(10) << rep1.nalichie << setw(10) << "|" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;

    }
    //
    car_view_.clear();
    //
}

// (������������) ���������� ����������
void user_sort_car_data()
{
    //
    Car car_view;
    //
    vector<Car> car_view_;
    //
    read_file_data_Car(car_view, car_view_);
    //
    if (car_view_.empty())
    {
        cout << "��� ������ ��� �����������." << endl;
        return;
    }
    //
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|        �����        |         ������         |         �����         |       �����       |          �������          |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
    //
    for (const auto& rep1 : car_view_)
    {
        cout << "|" << setw(10) << rep1.marka << setw(10) << "|" << setw(10) << rep1.model << setw(10) << "|" << setw(10) << rep1.number << setw(10) << "|" << setw(10) << rep1.tarif << setw(10) << rep1.nalichie << setw(10) << "|" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;

    }
    //
    car_view_.clear();
    //
}


// (������������) ������ ���������� ������ ������������ 
void user_work_rent_auto(string& login, string& password)
{
    //
    int choose;
    //
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                         �� ����� � ������� ��� ������������                                          |" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                     �����������                                                      |" << endl;
    cout << "+======================================================================================================================+" << endl;
    //
    while (true)
    {
        cout << "+======================================================================================================================+" << endl;
        cout << "|                                                  �������� ��������                                                   |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|      1) ����������� ����                                                                                             |" << endl;
        cout << "|      2) �������� ����                                                                                                |" << endl;
        cout << "|      3) ����� ����                                                                                                   |" << endl;
        cout << "|      4) ���������� ����                                                                                              |" << endl;
        cout << "|      5) ��������� � ���� ������������                                                                                |" << endl;
        cout << "|      6) �����                                                                                                        |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� �������� :" << endl;
        cin >> choose;
        //
        switch (choose)
        {
        case 1:
            user_view_car_data();
            break;
        case 2:
            // taska  !!!
            //
            user_order_car_data_over(login, password);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            user_menu(login, password);
            break;
        case 6:
            //
            cout << "+======================================================================================================================+" << endl;
            cout << "|                                       ������� �� ����������� ����������                                              |" << endl;
            cout << "+======================================================================================================================+" << endl;
            //
            exit(0);
            //
            break;
        default:
            cout << "������������ �����. ����������, ��������� ���� :" << endl;
        }
        //
    }
    //
};




//
//

//

// ������ � ������� (���� ��������������)
int admin_menu_work_data(string& login, string& password)
{
    //
    int choose;
    //
    while (true)
    {
        cout << "+======================================================================================================================+" << endl;
        cout << "|                                               �������� ������ ��� ������                                             |" << endl;
        cout << "+======================================================================================================================+" << endl;
        cout << "|      1) ������ ��������������                                                                                        |" << endl;
        cout << "|      2) ������ ������������                                                                                          |" << endl;
        cout << "|      3) ������ �����������                                                                                           |" << endl;
        cout << "|      4) ������ ��������                                                                                              |" << endl;
        cout << "|      5) ��������� � ���� ��������������                                                                              |" << endl;
        cout << "|      6) �����                                                                                                        |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� �������� :" << endl;
        cin >> choose;
        //
        switch (choose)
        {
        case 1:
            admin_work_admin_data(login, password);
            break;
        case 2:
            admin_work_user_data(login, password);
            break;
        case 3:
            admin_work_car_data(login, password);
            break;
        case 4:
            admin_work_operation_data(login, password);
            break;
        case 5:
            admin_menu(login, password);
            break;
        case 6:
            //
            cout << "+======================================================================================================================+" << endl;
            cout << "|                                       ������� �� ����������� ����������                                              |" << endl;
            cout << "+======================================================================================================================+" << endl;
            //
            exit(0);
            //
            break;
        default:
            cout << "������������ �����. ����������, ��������� ���� :" << endl;
        }
        //
    }
    //
};




// ���� ��������������
int admin_menu(string& login, string& password)
{
    //
    int choose;
    //
    string login_admin;
    string pasword_admin;
    //
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                         �� ����� � ������� ��� �������������                                         |" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                     �����������                                                      |" << endl;
    cout << "+======================================================================================================================+" << endl;
    //
    while (true)
    {
        //
        cout << "+======================================================================================================================+" << endl;
        cout << "|                                                  �������� ��������                                                   |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|      1) ������ � �������                                                                                             |" << endl;
        cout << "|      2) ��������� � �����������                                                                                      |" << endl;
        cout << "|      3) �����                                                                                                        |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� �������� :" << endl;
        cin >> choose;
        //
        switch (choose)
        {
        case 1:
            admin_menu_work_data(login, password);
            break;
        case 2:
            autorisation_total();
            break;
        case 3:
            //
            cout << "+======================================================================================================================+" << endl;
            cout << "|                                       ������� �� ����������� ����������                                              |" << endl;
            cout << "+======================================================================================================================+" << endl;
            //
            exit(0);
            //
            break;
        default:
            cout << "������������ �����. ����������, ��������� ���� :" << endl;
        }
        //
    }
    //
};

// ���� ������������
void user_menu(string& login, string& password)
{
    //
    int choose;
    //
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                         �� ����� � ������� ��� ������������                                          |" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                     �����������                                                      |" << endl;
    cout << "+======================================================================================================================+" << endl;
    //
    while (true)
    {
        cout << "+======================================================================================================================+" << endl;
        cout << "|                                                  �������� ��������                                                   |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|      1) ��� ������                                                                                                   |" << endl;
        cout << "|      2) ���������� ����������                                                                                        |" << endl;
        cout << "|      3) ��������� � �����������                                                                                      |" << endl;
        cout << "|      4) �����                                                                                                        |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� �������� :" << endl;
        cin >> choose;
        //
        switch (choose)
        {
        case 1:
            user_work_my_data(login, password);
            break;
        case 2:
            // taska  !!!
            //
            user_work_rent_auto(login, password);
            break;
        case 3:
            autorisation_total();
            break;
        case 4:
            //
            cout << "+======================================================================================================================+" << endl;
            cout << "|                                       ������� �� ����������� ����������                                              |" << endl;
            cout << "+======================================================================================================================+" << endl;
            //
            exit(0);
            //
            break;
        default:
            cout << "������������ �����. ����������, ��������� ���� :" << endl;
        }
        //
    }
    //
};



// ����������� ��������������
bool autorisation_admin(string& login, string& password)
{
    //
    string login_file, password_file;
    ifstream file; // ������ � ������� ��������� (������)
    //
    //
    int role = 0;
    bool status = false;
    string sr;
    bool fl = 0;
    //
    file.open("Admin.txt"); // ��������� ����
    //
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                ��� ����������� ������� ������                                        |" << endl;
    cout << "+======================================================================================================================+" << endl;
    //
    while (fl == 0)
    {
        //
        cout << "������� ����� : " << endl;
        cin >> login;
        cout << "������� ������ : " << endl;
        cin >> password;
        //
        if (login == "�����")
        {
            break;
            fl = 1; exit(0);
        }
        // �������� � ������, ���� �� �� ����������  
        while (!file.eof())
        {
            // ��������� ������ ��� �������� 
            getline(file, login_file);
            getline(file, password_file);
            //
            if (login_file == login && password_file == password)
            {
                cout << "�������� �����������" << endl;  fl = 1;
                login = login_file;
                password = password_file;
                return fl;
                break;
            }
            else
            {
                // ���������� ������� ��� ��������� �������� ���� �� ���������� ����
                getline(file, sr);

            }
        }
        // ������ �������� ������
        if (fl == 0)
        {
            cout << "�������� ����� ��� ������ , ���������� ��� ���" << endl;
            break;
        }
    }
    //
    return role;
    cin.ignore();
    file.close();
};

// ����������� ������������
bool autorisation_user(string& login, string& password)
{
    //
    string login_file, password_file;
    ifstream file; // ������ � ������� ��������� (������)
    //
    //
    int role = 0;
    bool status = false;
    string sr;
    bool fl = 0;
    //
    file.open("User.txt"); // ��������� ����
    //
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                ��� ����������� ������� ������                                        |" << endl;
    cout << "+======================================================================================================================+" << endl;
    //
    while (fl == 0)
    {
        //
        cout << "������� ����� : " << endl;
        cin >> login;
        cout << "������� ������ : " << endl;
        cin >> password;
        //
        if (login == "�����")
        {
            break;
            fl = 1; exit(0);
        }
        // �������� � ������, ���� �� �� ����������  
        while (!file.eof())
        {
            // ��������� ������ ��� �������� 
            getline(file, login_file);
            getline(file, password_file);
            //
            if (login_file == login && password_file == password)
            {
                cout << "�������� �����������" << endl;  fl = 1;
                login = login_file;
                password = password_file;
                return fl;
                break;
            }
            else
            {
                // ���������� ������� ��� ��������� �������� ���� �� ���������� ����
                getline(file, sr);
                getline(file, sr);

            }
        }
        // ������ �������� ������
        if (fl == 0)
        {
            cout << "�������� ����� ��� ������ , ���������� ��� ���" << endl;
            break;
        }
    }
    //
    return role;
    cin.ignore();
    file.close();
};

// ����������� ��������� (������� ���� ���������)
void autorisation_total()
{
    //
    int choose;
    //
    string login;
    string password;
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                    ������������������ ������� ������ ����������                                      |" << endl;
    cout << "+======================================================================================================================+" << endl;
    cout << "|                                                     �����������                                                      |" << endl;
    cout << "+======================================================================================================================+" << endl;
    //
    while (true)
    {
        //
        cout << "+======================================================================================================================+" << endl;
        cout << "|                                                  �������� ��������                                                   |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|      1) ���������������� ��� �������������                                                                           |" << endl;
        cout << "|      2) ���������������� ��� ������������                                                                            |" << endl;
        cout << "|      3) �����������                                                                                                  |" << endl;
        cout << "|      4) ��������� � ������� ���� �������                                                                             |" << endl;
        cout << "|      5) �����                                                                                                        |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        //
        cout << "������� �������� :" << endl;
        cin >> choose;
        //
        switch (choose)
        {
        case 1:
            if (autorisation_admin(login, password) == 1)
            {
                admin_menu(login, password);
            }
            else
            {
                cout << "�� �� ������ ���������������� :( " << endl;

            }
            break;
        case 2:
            if (autorisation_user(login, password) == 1)
            {
                user_menu(login, password);
            }
            else
            {
                cout << "�� �� ������ ���������������� :( " << endl;
            }
            break;
        case 3:
            registration_user();
            break;
        case 4:
            break;
        case 5:
            //
            cout << "+======================================================================================================================+" << endl;
            cout << "|                                       ������� �� ����������� ����������                                              |" << endl;
            cout << "+======================================================================================================================+" << endl;
            //
            exit(0);
            //
            break;
        default:
            cout << "������������ �����. ����������, ��������� ���� :" << endl;
        }
        //
    }
    // 
};
//

////
//

////




// ������ � ����
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
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������1." << endl;
        return;
    }
    //
    if (!file_2.is_open())
    {
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������2." << endl;
        return;
    }
    //
    if (!file_3.is_open())
    {
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������3." << endl;
        return;
    }
    //
    if (!file_4.is_open())
    {
        cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������4." << endl;
        return;
    }
    //
  //  if (!file_5.is_open())
  //  {
  //  	cout << "������ ��� �������� ����� (-��) ��� � ����� ��� ������5." << endl;
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

   // cout << "������ ������� ���������� � ���������" << endl;

    //
    file_1.close();
    file_2.close();
    file_3.close();
    file_4.close();
    //  file_5.close();
      //
}
*/