#include <iostream>
#include <cmath>  //将数学函数库包含进来
using namespace std;
int main()
{
	int a = 0, b = 0, c = 0; //定义3个整型变量a,b,c 并初始化为0。
    float f = 0.0 , p = 0.0; //定义1个单精度浮点型变量f, 并初始化为0。
    //char ch; //定义1个字符型变量ch, 不进行初始化。
    cout<< "a=" << a << endl;          // 输出a的值。
    cout<< "b=" << b << endl;      // 输出b的值。
    cout<< "c=" << c << endl;    // 输出c的值。
    cout<< "f=" << f << endl;     // 输出f的值。
    //cout<< "ch=" << ch << endl;    //输出ch的值。观察未赋值就输出的变量的值。在提交作业前将此行注释掉，否则无法通过测试用例。
    //将三角形的3个边长7，8，9分别赋值给变量a,b,c。
    a = 7;
    b = 8;
    c = 9;
    p = (static_cast <float>(a) + static_cast <float>(b) + static_cast <float>(c)) / 2;
    //cout << p << endl;
      //计算机三角形的面积并存储在变量f中。
    f = sqrt(p*(p-a)*(p-b)*(p-c));
    //输出三角形边长a=X,b=X,c=X
    cout<<"三角形边长分别是："<<"a="<<a<<",b="<<b<<",c="<<c<<endl;
    //输出三角形面积 f = X
    cout<<"三角形面积是："<<"f="<<f<<endl;
}