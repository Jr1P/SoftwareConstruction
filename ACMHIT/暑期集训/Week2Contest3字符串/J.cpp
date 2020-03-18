#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
using namespace std;
#define N 100150
#define SZ 26
#define L 30

int tot, n, m, cnt = 0;
bool e[N];
string str1, str2;
map<string, string> mp;

int main(){
	while(1) {
		str1 = ""; str2 = "";
		char c = getchar();
		if(c == '\n') break;
		while (c != ' ') {
			str1 += c;
			c = getchar();
		}
		c = getchar();
		while (c != '\n') {
			str2 += c;
			c = getchar();
		}
		mp[str2] = str1;
	}
	string str; //
	while(cin >> str) {
		if(mp.count(str))
			cout << mp[str] << endl;
		else puts("eh");
	}
	return 0;
}