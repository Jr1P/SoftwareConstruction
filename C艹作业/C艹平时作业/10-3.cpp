#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Person
{
public:
    string name, id, sex, position;
    double salary;
    int age;
    Person() {}
    Person(string pname, int page, string pid, string psex, string p)
    {
    	name = pname;
    	age = page;
    	id = pid;
    	sex = psex;
    	position = p;

    }
    void getSalary(double psalary)
    {
    	salary = psalary;
    }
	double getPay()
	{
		return salary;
	}

	void print()
	{
		cout << id << '\n' << name << '\n' << age << '\n' << sex << '\n' << position
        << '\n' << '$' << getPay()  << endl;
	}

};

class Boss:public Person
{
public:
    Boss(string name, int age, string id, string sex, string position = "Boss")
    : Person(name, age, id, sex, position) {}

    virtual double getPay() {
    	return 150000;
    }
    virtual void print()
	{
		cout << id << '\n' << name << '\n' << age << '\n' << sex << '\n' << position
        << '\n' << '$' << getPay()  << endl;
	}
    
};

class Employee:public Person
{
public:
   
    Employee(string name, int age, string id, string sex,  double ebonus=3000, double ebaseSalary = 4500, string position = "Employee")
        :  Person(name, age, id, sex, position), bonus(ebonus), baseSalary(ebaseSalary) {}

	virtual double getPay()
	{
		return bonus+baseSalary;
	}

    virtual void print()
	{
		cout << id << '\n' << name << '\n' << age << '\n' << sex << '\n' << position
        << '\n' << '$' << getPay()  << endl;
	}
	double bonus, baseSalary;

};

class HourlyWorker:public Person
{
public:

	HourlyWorker(string name, int age, string id, string sex,  int hworkHour, double hpieceOfHour = 13, string position = "HourlyWorker")
	: Person(name, age, id, sex, position), workHour(hworkHour), pieceOfHour(hpieceOfHour){}

	virtual double getPay()
	{
		return workHour*pieceOfHour;
	}

	virtual void print()
	{
		cout << id << '\n' << name << '\n' << age << '\n' << sex << '\n' << position
        << '\n' << '$' << getPay()  << endl;
	}
	int workHour;
	double pieceOfHour;

};

class CommWorker : public Person
{
public:
    CommWorker(string name, int age, string id, string sex,  double csalesProfit, double cbaseSalary = 4500, string position = "CommWorker")
    : Person(name, age, id, sex, position), salesProfit(csalesProfit), baseSalary(cbaseSalary){}

    virtual double getPay()
    {
    	return baseSalary+salesProfit*0.15;
    }

    virtual void print()
	{
		cout << id << '\n' << name << '\n' << age << '\n' << sex << '\n' << position
        << '\n' << '$' << getPay()  << endl;
	}
    double salesProfit;
    double baseSalary;

};

int main()
{

	string Position;
	string Name;
	string id;
	int Age;
	string Sex;
	int Money;
	cout<<"Please input position: ";
	cin>>Position;
	cout<<"Please input name: ";
	cin>>Name;
	cout<<"Please input id: ";
	cin>>id;
	cout<<"Please input age: ";
	cin>>Age;
	cout<<"Please input sex: ";
	cin>>Sex;
	if (Position == "Boss"){

		Boss boss(Name, Age, id, Sex);
		boss.print();
	}
	else if (Position == "Employee"){
		Employee employee(Name, Age, id, Sex);
		employee.print();
	}
	else if (Position == "HourlyWorker"){
		cout<<"Please input money: ";
		cin>>Money;
		HourlyWorker hourlyWorker(Name, Age, id, Sex, Money);
		hourlyWorker.print();
	}
	else{
		cout<<"Please input money: ";
		cin>>Money;
		CommWorker commWorker(Name, Age, id, Sex, Money);
		commWorker.print();
	}
	return 0;
}
