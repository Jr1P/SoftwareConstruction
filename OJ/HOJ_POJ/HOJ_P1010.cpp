#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const float hourAngle = 30;
const float minuteAngle = 6;

int main(){
	int hour = 1,minute = 1;
	float angle;
	while(hour != 0 || minute != 0){
		cin>>hour>>minute;
		if(hour == 0 && minute == 0) return 0; 
		int h = hour % 12,f;
		float m = (float)minute / 5;
		if(m > h) f = -1;
			else f = 1;
		angle = abs(abs(m-h) * hourAngle + (float)f*minute / 2);
		if(angle > 180) angle = 360 - angle;
		cout.setf(ios::fixed);
		if(minute < 10) cout<<"At "<<hour<<':'<<'0'<<minute<<' '<<"the angle is "<<fixed<<setprecision(1)<<angle<<' '<<"degrees.";
			else cout<<"At "<<hour<<':'<<minute<<" the angle is "<<fixed<<setprecision(1)<<angle<<' '<<"degrees.";
	}
} 
