#include <iostream>
#include <cmath>
using namespace std;
const double PI=3.141592653;

class Ponit
{
public:
	Ponit(double x = 0, double y = 0)
	{
		X = x;
		Y = y;
	}

    void getXY(){
        cout<<"Please input X:";
        cin>>X;
        cout<<"Please input Y:";
        cin>>Y;
    }
    void showCoordinate()  {
        cout<<"The coordinate of the point is:("<<X<<','<<Y<<")."<<endl;
    }

protected:
	double X, Y;

};
//Cone(double x=0,double y=0,double r=0,double h=0):Circle(x,y,r)

class Circle:public Ponit
{
    protected:
        double radius;
    public:
        Circle(double x = 0, double y = 0, double r = 0)
        {
        	X = x;
        	Y = y;
        	radius = r;
        }
     
        void setXYradius()  {
            Circle::getXY();
            cout<<"Please input radius:";
            cin>>radius;
        }
        double getArea()   {
            return PI*radius*radius;
        }
};

class Cylinder:protected Circle
{
protected:
	double height;

public:
	Cylinder(double x = 0, double y = 0, double r = 0, double h = 0)
	{
		X = x;
		Y = y;
		radius = r;
		height = h;
	}

    void setData()
    {
        Circle::setXYradius();
        cout<<"Please input the cylinder's height:";
        cin>>height;
    }

    double getArea()
    {
    	return PI*radius*radius*2+2*PI*radius*height;
    }

    double getVolume()
    {
    	return PI*radius*radius*height;
    }

};

class Cone:public Circle
{
   
protected:
	double height;
public:
    
    Cone(double x=0,double y=0,double r=0,double h=0):Circle(x,y,r)
    {
    	X = x;
    	Y = y;
    	radius = r;
    	height = h;
    }

    void setData()
    {
        Circle::setXYradius();
        cout<<"Please input the cone's height:";
        cin>>height;
    }

    double getArea(){
        return PI*radius*radius+sqrt(height*height+radius*radius)*PI*radius;
    }

    double getVolume(){
    	return PI*radius*radius*height/3;
    }
};

int main() {
    Circle _circle;
    Cylinder _cylinder;
    Cone _cone;
    _circle.setXYradius();
    _cylinder.setData();
    _cone.setData();
    /*call function to initialize and input the variables of object _circle,_cylinder and _cone */
    //write code here

    /*print messages*/
    _circle.showCoordinate();
    cout<<"The area of the circle is:"<<_circle.getArea()<<endl;
    cout<<"The area of the cylinder is:"<<_cylinder.getArea()<<endl;
    cout<<"The volume of the cylinder is:"<<_cylinder.getVolume()<<endl;
    cout<<"The area of the cone is:"<<_cone.getArea()<<endl;
    cout<<"The volume of the cone is:"<<_cone.getVolume()<<endl;
    return 0;
}
