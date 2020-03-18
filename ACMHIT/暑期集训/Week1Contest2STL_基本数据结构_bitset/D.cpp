#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

stack<char > s;
int n;
string s1, s2;

int main()
{
	while(cin >> n >> s1 >> s2)
	{
		while(!s.empty())
			s.pop();
		int h = 0, p = 0;
		s.push(s1[p]);
		while(p != n)
		{
			if(p == n-1 && h == n)
				break;
			if(s.empty())
				s.push(s1[++p]);
			if(s.top() != s2[h]) {
				p++;
				s.push(s1[p]);
			}
			else {
				s.pop();
				h++;
			}
		}
		if(h != n) {
			printf("No.\nFINISH\n");
			continue;
		}
		while(!s.empty())
			s.pop();
		printf("Yes.\n");
		h = 0, p = 0;
		s.push(s1[p]);
		printf("in\n");
		while(1)
		{
			if(p == n-1 && h == n)
				break;
			if(s.empty())
			{
				s.push(s1[++p]);
				printf("in\n");
			}
			if(s.top() != s2[h]) {
				p++;
				s.push(s1[p]);
				printf("in\n");
			}
			else {
				s.pop();
				h++;
				printf("out\n");
			}
		}
		printf("FINISH\n");
	}
	return 0;
}