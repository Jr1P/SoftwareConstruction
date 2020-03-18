#include <iostream>
#include <cmath> //将数学库函数包含进来
using namespace std;
const float PI = 3.14159; //定义圆周率常量PI，取值为3.14159

int main()
{
	double x = 0, y = 0; //定义双精度型变量 x和y。
	x = 60.0 / 360.0 * 2.0 * PI; //将60度角转换成弧度赋给变量x;
	y = sin(x); //使用sin()函数将x的正弦值赋给变量y
	cout<<"y="<<y<<endl; //输出y
	cout<<"y的平方根="<< sqrt(y) <<endl; //输出y的平方根
	cout<< '\a' << endl; //在电脑上响铃一次, 然后输出回车。
}