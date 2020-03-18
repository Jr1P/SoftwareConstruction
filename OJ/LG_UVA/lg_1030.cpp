#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define N 10

string c1, c2, c3;

void bef(string m, string r)
{
	int l1 = m.length(), l2 = r.length();
	if (l1 > 0)
	{
		char ch = r[l2-1];
		cout << ch;
		int k = m.find(ch);
		bef(m.substr(0, k), r.substr(0, k));
		bef(m.substr(k+1), r.substr(k, l2-k-1));
	}
}

int main()
{
	cin >> c1 >> c2;
	bef(c1, c2);
	return 0;
}