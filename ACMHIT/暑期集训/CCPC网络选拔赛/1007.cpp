//#include "pch.h"
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int n, t;
string s[15][1050];

int main() {
	scanf("%d", &t);
	s[1][1] = "CC"; s[1][2] = "PC";
	for (int i = 2; i <= 10; i++) {
		for (int j = 1; j <= (1 << (i - 1)); j++)
			s[i][j] = s[i - 1][j] + s[i - 1][j];
		for (int j = (1 << (i - 1)) + 1; j <= (1 << i); j++) {
			for (int k = 0; k < s[i-1][j - (1 << (i - 1))].length(); k++)
				if (s[i-1][j - (1 << (i - 1))][k] == 'C') s[i][j] += 'P';
				else s[i][j] += 'C';
			s[i][j] += s[i - 1][j - (1 << (i - 1))];
		}
	}
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= (1 << n); i++)
			cout << s[n][i] << endl;
	}
	return 0;
}