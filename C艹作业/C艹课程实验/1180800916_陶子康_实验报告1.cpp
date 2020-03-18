#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const char c1[] = "Right!";
const char c2[] = "Not correct!";
const char operate[] = "+-*/";

int CreatingExpression(int &a, int &b, char &op);
//随机生成算术表达式,返回表达式值
bool ValidatingUserAnswer(int a, int b, char op, int answer);
//输出算术表达式，让用户输入答案并判断答案是否正确,根据答案进行反馈

int main()
{
	int score = 0, t = 10; //连续产生10次算术表达式
	srand(time(NULL)); //设置随机数种子
	while (t--)
	{
		int a = rand() % 10 + 1, b = rand() % 10 + 1;
		char op = operate[rand() % 4];
		int ans = CreatingExpression(a, b, op);
		if (ValidatingUserAnswer(a, b, op, ans))
		{
			cout << c1 << '\n';
			score++;
		}
		else
			cout << c2 << '\n';
	}
	cout << "you got " << score*10 << " scores, you made " << 10 - score << " mistake";
	if (score == 9 || score == 10)
		cout << ".\n"; //mistake单数形式
	else 
		cout << "s.\n"; //mistake复数形式
	return 0;
}

int CreatingExpression(int &a, int &b, char &op)
{
	int ans;
	if (op == '-')
		while (a < b)
		{
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
		}
	else if (op == '/')
		while (a % b != 0)
		{
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
		}
	switch (op)
	{
		case '+':
			ans = a+b;
			break;
		case '-':
			ans = a-b;
			break;
		case '*':
			ans = a*b;
			break;
		case '/':
			ans = a/b;
			break;
	}
	return ans;
}

bool ValidatingUserAnswer(int a, int b, char op, int answer)
{
	int myAns;
	cout << a << op << b << '=';
	cin >> myAns;
	if (myAns == answer)
		return true;
	else
		return false;
}