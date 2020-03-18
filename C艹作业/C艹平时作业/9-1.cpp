#include <iostream>
#include <cmath>
using namespace std;
const float pi = 3.1415;

class CAngle
{
public:
	//CAngle();
	//~CAngle();
	void SetValue(double v);
	void GetCos();
private:
	double value;
};

void CAngle::SetValue(double v)
{
	value = v;
}

void CAngle::GetCos()
{
	cout << cos(value/180*pi) << '\n';
}

int main()
{
	CAngle deg;
	double iv;
	cout<<"输入角度：";
	cin >> iv;
	deg.SetValue(iv);
	cout<<"角度的余弦为" ;
	deg.GetCos();

	return 0;
}