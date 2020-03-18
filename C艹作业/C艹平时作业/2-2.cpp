#include <iostream>
using namespace std;
//

int main()
{
	char gender, likeSport, goodDiet;
	float faHeight, moHeight, yourHeight;
	bool sport, diet; // 1 表示爱运动或习惯好
	cout << "Input your gender(m|f|M|F):";
	cin >> gender;
	cout << "Input your father's height(cm):";
	cin >> faHeight;
	cout << "Input your mother's height(cm):";
	cin >> moHeight;
	cout << "Do you like sports?(y|n|Y|N):";
	cin >> likeSport;
	if (likeSport == 'Y' || likeSport == 'y')
		sport = 1;
	else sport = 0;
	cout << "Do you have good diet?(y|n|Y|N):";
	cin >> goodDiet;
	if (goodDiet == 'Y' || goodDiet == 'y')
		diet = 1;
	else diet = 0;
	if (gender == 'm' || gender == 'M')
	{
		yourHeight = (faHeight + moHeight) * 0.54;
		yourHeight *= (1 + sport * 0.02 + diet * 0.015);
	}
	else 
	{
		yourHeight = (faHeight * 0.923 + moHeight) / 2;
		yourHeight *= (1 + sport * 0.02 + diet * 0.015);
	}
	cout << "Your Height will be:" << (int)yourHeight;
	return 0;
}