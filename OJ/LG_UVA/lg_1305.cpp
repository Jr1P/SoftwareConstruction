#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define N 30

string s[N];
char ls[N], rs[N];
int n;

void search(char c)
{
	cout << c;
	int id = c-'a';
	if (ls[id] != '*')
		search(ls[id]);
	if (rs[id] != '*')
		search(rs[id]);
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		int id = s[i][0]-'a';
		ls[id] = s[i][1];
		rs[id] = s[i][2];
	}
	search(s[1][0]);
	return 0;
}