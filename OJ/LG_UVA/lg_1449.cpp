#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
const int MAXL = 1e3+5;

stack<int > s;

int main()
{
	char instr[MAXL];
	cin >> instr;
	int len = strlen(instr);
	int i = 0; 
	while (i < len)
	{	 
		if(instr[i] >= '0' && instr[i] <= '9')
		{
			int num = 0;
			while(instr[i] != '.')
			{
				num = num*10+instr[i]-'0';
				i++;
			}
			s.push(num);
			continue;
		}
		else if(instr[i] == '@')
			break;
		else if(instr[i] == '.')
		{
			i++;
			continue;
		}
		else //if(instr[i] != '.')
		{
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			switch(instr[i])
			{
				case '+':
					s.push(a+b);
					break;
				case '*':
					s.push(a*b);
					break;
				case '-':
					s.push(b-a);
					break;
				case '/':
					s.push(b/a);
					break;
				default:;
			}
			i++;
		}
	}
	cout << s.top() << '\n';
	return 0;
}