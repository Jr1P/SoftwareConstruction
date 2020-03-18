#include <iostream>
using namespace std;
const double eps = 1e-6;

class Point {
private:
	double coordinateX, coordinateY;//添加代码定义横坐标x

public:
	Point(double tempx, double tempy)
	{
		coordinateX = tempx;
		coordinateY = tempy;
	}//构造函数，形参为坐标值

	Point()
	{
		coordinateX = 0.0f;
		coordinateY = 0.0f;
	}//默认构造函数，无参数

	inline double Getx()
	{
		return coordinateX;
	}//Get方法获取坐标x

	inline double Gety()
	{
		return coordinateY;
	}//Get方法获取坐标y

	void Set(double tempx, double tempy)
	{
		coordinateX = tempx;
		coordinateY = tempy;
	}//Set方法，设置坐标x，坐标y

	void Print()
	{
		cout << '(' << coordinateX << ',' << coordinateY << ')' << '\n'; 
	}//输出点的坐标，格式为(x,y)并输出换行
};

class Circle {
private:
	Point center;//添加代码定义坐标点center，类型为点类型
	double radius;//添加代码定义半径radius

public:
	Circle(Point &p, double r)
	{
		center = p;
		if (r < eps)
		{
			cout << "Error: The radius must be a float number over 0! \n";
			radius = 0;
		}
		else
			radius = r;
	}//构造函数，参数为坐标点p，半径r
//错误时输出：cout << "Error: The radius must be a float number over 0! " << endl;

	inline void GetO()//获取圆心方法，调用圆心point类的print方法
	{
		center.Print();
	}

	inline double GetR()
	{
		return radius;
	}//获取半径，返回r

	inline void Modify(Point &tmp ,double r)
	{
		center = tmp;
		if (r < eps)
			cout << "Error: The radius must be a float number over 0! \n";
		else
			radius = r;
	}
//错误时输出cout << "Error: The radius must be a float number over 0! " << endl;

	inline void print() {
		cout << "List circle information as follows: " << endl;
		cout << "The center is: ";
		GetO();
		cout << "The radius is: " << GetR() << endl;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	double x, y, r;//添加代码定义变量坐标x,坐标y,半径r

	cout << "Please input the x coordinate of the circle center: ";
	cin >> x;
	cout << "Please input the y coordinate of the circle center: ";
	cin >> y;
	cout << "Please input the radius of the circle: ";
	cin >> r;

	Point p(x, y);
	Circle c(p, r);
	//添加代码调用Point类和Circle类构造函数创建实例点p，圆c

	cout << "The center location is: " << "(" << p.Getx() << "," << p.Gety() << ")" << endl;
	cout << "The radius is: " << c.GetR() << endl;

	cout << "Please input the x coordinate of the circle center you want to modify: ";
	cin >> x;
	cout << "Please input the y coordinate of the circle center you want to modify: ";
	cin >> y;
	cout << "Please input the radius of the circle you want to modify: ";
	cin >> r;

	Point tmp(x, y);
	c.Modify(tmp, r);
	c.print();	//输出圆信息

	return 0;
}
