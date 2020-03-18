#include <iostream>
#include <cmath>
using namespace std;
//preg.
int getPower(int x, int y);

double getPower(double x, int y);

int main()
{
	int a = 10, m = 3;
    double b = 10;
	cout<<getPower(a,m)<<endl;   //调用int getPower
    cout<<getPower(b,m)<<endl;   //调用double getPower
    cout<<getPower(a,-m)<<endl;  //调用int getPower
    cout<<getPower(b,-m)<<endl;  //调用double getPower
	return 0;
}

int getPower(int x, int y)
{
	if (y < 0)
		return 0;
	else 
		return pow(x, y);
}

double getPower(double x, int y)
{
	return pow(x, y);
}