#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>

unsigned int start_time =  clock();

using namespace std;

class Employee{

    public:

    string firstName;
    string secondName;
    static int count;
    int serialNumber;
    double MonthSalary;

    Employee(const Employee &object) : MonthSalary(object.MonthSalary), firstName(object.firstName), secondName(object.secondName) {
    }

    Employee(double salary = 0, string firstN = "Null", string secondN = "Null") : MonthSalary(salary), firstName(firstN), secondName(secondN) {
        count++;
        serialNumber = count;
    }

    virtual ~Employee(){}

    virtual double getMonthSalary () = 0;
    virtual void setMonthSalary(double salary) { MonthSalary = salary; }

    string getFirstName () const { return firstName; }
    void setFirstName (string firstN) { firstName = firstN; }

    string getSecondName () const { return secondName; }
    void setSecondName (string secondN) { secondName = secondN; }

    virtual double getPayment () const { return 0; }
    virtual void setPayment(double){}

    static int getCount () { return count; }
    int getSerialNumber () const { return serialNumber; }

    void displayEmployee() {
       cout << this-> getSerialNumber () << " ";
       cout << this-> getMonthSalary() << " ";
       cout << this-> getFirstName() << " ";
       cout << this-> getSecondName() << " ";
       cout << this-> getPayment() << endl;
    }
};

class EmplHourly : public Employee
{
    private:
    double hourlyRate;

    public:

    EmplHourly(const EmplHourly &object) : Employee(object), hourlyRate(object.hourlyRate) {
    }

    EmplHourly(double hourlyR = 0) : hourlyRate(hourlyR) {
    }

    EmplHourly(double salary, string firstN, string secondN, double hourlyR = 0) : Employee(salary, firstN, secondN), hourlyRate(hourlyR) {
    }

    double getMonthSalary () {
        MonthSalary = 20.8 * 8 * hourlyRate;
        return MonthSalary;
    }

    double getPayment () const { return hourlyRate; }

    void setPayment (double value) { hourlyRate = value; }

};

class EmplFixed : public Employee
{
    private:
    double fixPayment;

    public:

    EmplFixed(const EmplFixed &object) : Employee(object), fixPayment(object.fixPayment) {
    }

    EmplFixed(double fixPay = 0) : fixPayment(fixPay) {
    }

    EmplFixed(double salary, string firstN, string secondN, double fixPay = 0) : Employee(salary, firstN, secondN), fixPayment(fixPay) {
    }

    double getMonthSalary () {
        MonthSalary = fixPayment;
        return MonthSalary;
    }

    double getPayment () const { return fixPayment; }

    void setPayment (double value) { fixPayment = value; }
};

class compareMonthSalary{
    public:

    bool operator()(Employee* ptr1, Employee* ptr2)const {
        return (ptr1 -> getMonthSalary()) < (ptr2 -> getMonthSalary());
    }
};

class compareFirstNameEmployee {
    public:
        bool operator()(const Employee* ptr1, const Employee* ptr2)const{
            return (ptr1-> getFirstName()) < (ptr2-> getFirstName());
    }
};

int Employee :: count = 0;

int main() {

    srand((unsigned int)time(0));

    vector<Employee*> arr;
    vector <Employee*>::iterator iter;
    vector <Employee*>::iterator iterEnd;
    int triger;
    int value;
    int size;
    int count;
    char option;
    char temp[50];
    string FirstName;
    string SecondName;
    ofstream fout("cppstudio.txt", ios_base::app);
    ifstream fin("cppstudio.txt", ios_base::in);

    cout << "Enter data? (Y/N): ";
    cin >> option;

    while( option == 'Y' || option == 'y') {
        //triger = rand() % 2 + 1;
        triger = 1;
        switch(triger){
            case 1:
                cout << "Enter FirstName: ";
                cin.ignore();
                getline (cin, FirstName);

                cout << "Enter SecondName: ";
                cin.clear();
                getline (cin, SecondName);

                cout << "Enter hourlyRate: ";
                cin >> value;

                arr.push_back(new EmplHourly());
                iter = arr.end();

                (*(iter-1))-> setFirstName(FirstName);
                (*(iter-1))-> setSecondName(SecondName);
                (*(iter-1))-> setPayment(value);

                cout << "Continue enter data? (Y/N): ";
                cin >> option;
                break;
            case 2:
                cout << "Enter FirstName: ";
                cin.ignore();
                getline (cin, FirstName);

                cout << "Enter SecondName: ";
                cin.clear();
                getline (cin, SecondName, '\n');

                cout << "Enter fixPayment: ";
                cin >> value;

                arr.push_back(new EmplFixed());
                iter = arr.end();

                (*(iter-1))-> setFirstName(FirstName);
                (*(iter-1))-> setSecondName(SecondName);
                (*(iter-1))-> setPayment(value);

                cout << "Continue enter data? (Y/N): ";
                cin >> option;
                break;
        }
    }

    size = arr.size();
    count = size - 3;
    if (count < 0) {
        count = 0;
    }

    sort(arr.begin(), arr.end(), compareMonthSalary());

    for(int j = 0, i = 1; i < size; i++, j++){

        if (arr[i]-> getMonthSalary() == arr[j]-> getMonthSalary()){
            iter = arr.begin() + j;

            for(; i < size && arr[i]-> getMonthSalary() == arr[j]-> getMonthSalary(); j++, i++){}

            iterEnd = arr.begin() + i;
            sort(iter, iterEnd, compareFirstNameEmployee());
        }
    }

    cout << endl;
    cout << "Save file..." << endl;

    for(int i = 0; i < size; i++) {
        fout << arr[i]-> getSerialNumber() << " ";
        fout << arr[i]-> getMonthSalary() << " ";
        fout << arr[i]-> getFirstName()<< " ";
        fout << arr[i]-> getSecondName()<< " ";
        fout << arr[i]-> getPayment() << endl;
    }

    cout << endl;
    cout << "All..." << endl;

    for(int i = 0; i < size; i++){
        arr[i]-> displayEmployee();
    }

    cout << endl;
    cout << "The first five..." << endl;

    for(int i = 0; i < size && i < 5; i++){
        arr[i]-> displayEmployee();
    }

    cout << endl;
    cout << "The last three..." << endl;

    for(int i = count; i < size; i++){
        arr[i]-> displayEmployee();
    }

    cout << endl;
    cout << "Reading from a file..." << endl;

    while(fin.good()){
        fin.getline(temp, 50);
        cout << temp << endl;
    }

    arr.clear();
    fout.close();
    fin.close();

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    cout << search_time/1000 << endl;

    cout << "HAPPY END!)" << endl;

    return 0;
}

/*
Построить три класса (базовый и 2 потомка), описывающих некоторых работников с
почасовой оплатой (один из потомков) и фиксированной оплатой (второй потомок).
ќписать в базовом классе абстрактный метод дл€ расчета среднемес€чной заработной
платы. ƒл€ Ђповременщиковї формула дл€ расчета такова: Ђсреднемес€чна€
заработна€ плата = 20.8 * 8 * почасовую ставкуї, дл€ работников с фиксированной
оплатой Ђсреднемес€чна€ заработна€ плата = фиксированной мес€чной оплатеї.

a) ”пор€дочить всю последовательность работников по убыванию
среднемес€чного заработка. ѕри совпадении зарплаты Ц упор€дочивать данные по
алфавиту по имени. ¬ывести идентификатор работника, им€ и среднемес€чный
заработок дл€ всех элементов списка.
b) ¬ывести первые 5 имен работников из полученного в пункте а) списка.
c) ¬ывести последние 3 идентификатора работников из полученного в пункте а)
списка.
d) ќрганизовать запись и чтение коллекции в/из файл.
e) ќрганизовать обработку некорректного формата входного файла.
*/
