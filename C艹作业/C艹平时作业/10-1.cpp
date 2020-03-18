#include <iostream>
using namespace std;

class vehicle
{
public:
	vehicle()
	{
		weight = 0;
		wheel = 0;
	}
	void set(int we, int wh)
	{
		weight = we;
		wheel = wh;
	}
	void display()
	{
		cout << "The weight is " << weight << '\n';
		cout << "The wheel is " << wheel << '\n';
	}
	
protected:
	int weight, wheel;
	
};

class car:public vehicle
{
public:
	void set1(int we, int wh, int m)
	{
		weight = we;
		wheel = wh;
		busload = m;
	}

	void display()
	{
		cout << "The weight is " << weight << endl;
		cout << "The wheel is " << wheel << endl;
		cout << "The busload is " << busload << endl;
	}

protected:
	int busload;

};

class truck:public vehicle
{
public:
	void set2(int we, int wh, int m)
	{
		weight = we;
		wheel = wh;
		deadweight = m;
	}
	void display()
	{
		cout << "The weight is " << weight << '\n';
		cout << "The wheel is " << wheel << '\n';
		cout << "The deadweight is " << deadweight << '\n';
	}

protected:
	int deadweight;

};    

int main(){
	vehicle v1;
	car car1;
	truck truck1;
	int weight, wheel, busload, deadweight;
	cout << "Input the weight: " ;
	cin >> weight;
	cout << "Input the wheel: " ;
	cin >> wheel;
	cout << "Input the the busload: " ;
	cin >> busload;
	cout << "Input the deadweight: " ;
	cin >> deadweight;
	v1.set(weight, wheel);
	car1.set1(weight, wheel, busload);
	truck1.set2(weight, wheel, deadweight);
	cout<<"The vehicle: "<<endl;
	v1.display();
	cout<<"The car: "<<endl;
	car1.display();
	cout<<"The truck: "<<endl;
	truck1.display();
	return 0;
}
