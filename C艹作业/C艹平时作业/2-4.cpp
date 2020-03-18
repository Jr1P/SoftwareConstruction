#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
//

int main()
{
	char X[2], ans[15];
	int x_asc, type;
	//type 代表类型,下划线为0，odd为1，even为2，大写字母3，小写字母4，空白符5，其他字符6;
	cout << "please input your character:";
	cin.getline(X, 3, '\n');
	x_asc = int(X[0]);
	//cout << x_asc << endl;
	if (x_asc == int('_'))
		type = 0;
	else if ((x_asc == 32) || (x_asc == 10) || (x_asc == 9) || (x_asc == 0)) //32为空格,10为换行符,9为Tab,0为null
		type = 5;
	else if ((x_asc >= 48) && (x_asc <= 57))
		{
			if ((x_asc & 1) == 1)
				type = 1;
			else
				type = 2;
		}
	else if ((x_asc >= 65) && (x_asc <= 90))
		type = 3;
	else if ((x_asc >= 97) && (x_asc <= 122))
		type = 4;
	else
		type = 6;
	switch (type)
	{
		case 0:
			strcpy(ans, "underlined");
			break;
		case 1:
			strcpy(ans, "odd number");
			break;
		case 2:
			strcpy(ans, "even number");
			break;
		case 3:
			strcpy(ans, "upper case");
			break;
		case 4:
			strcpy(ans, "lower case");
			break;
		case 5:
			strcpy(ans, "blank");
			break;
		case 6:
			strcpy(ans, "others");
			break;
		default:
			cout << "Invaild number!";
	}
	cout << "the character is:" << ans << endl;
	return 0;
}
