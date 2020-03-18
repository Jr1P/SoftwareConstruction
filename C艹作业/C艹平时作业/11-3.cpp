#include <iostream>
#define eps 1e-6
#define PI 3.14159      //定义pi

using namespace std;

class Shape
{
public:
	virtual void GetArea() = 0;
	virtual void GetPerim() = 0;
};

class Rectangle: public Shape
{
public:
	Rectangle(double length, double width)
	{
		_length = length;
		_width = width;
	}
	void GetArea();		//带参数的构造函数声明 —— 重载
	void GetPerim();
private:
    double _length, _width;    //长和宽
};

class Circle: public Shape
{
public:
	Circle(double radius)
	{
		_radius = radius;
	}
	void GetArea();	//带参数的构造函数声明 —— 重载
	void GetPerim();
private:
    double _radius;    //圆的半径
};

void Rectangle:: GetArea()      //计算矩形面积
{
    cout<<"矩形的面积是："<<_length * _width<<endl;
}

void Rectangle:: GetPerim()     //计算矩形周长
{
    cout<<"矩形的周长是："<<(_length + _width) * 2<<endl;
}

void Circle:: GetArea()     //计算圆形面积
{
    cout<<"圆形的面积是："<<PI* _radius * _radius<<endl;
}

void Circle:: GetPerim()        //计算圆形周长
{
    cout<<"圆形的周长是："<<2 * PI * _radius<<endl;
}

void result(Shape &cs)
{
	cs.GetArea();
	cs.GetPerim();
}

int main()
{
	double len, wid, r;
	cout<<"输入矩形的长：";
	cin >> len;
	cout<<"输入矩形的宽：";
	cin >> wid;
	cout<<"输入圆的半径：";
	cin >> r;
	if (len < -eps || wid < -eps || r < -eps)
		cout<<"请输入正数！"<<endl;//
	else
	{
		Rectangle R(len, wid);
		Circle C(r);
		Shape* ptr = &R;
		result(*ptr);
		ptr = &C;
		result(*ptr);
	}
    return 0;
}
