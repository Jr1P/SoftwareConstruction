#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define N 1000010

int t, ans = 0;
int nxt[N];
char s[N], p[N];
//string s, p;

void getNext(char* p) {
	int l = strlen(p);
	nxt[0] = nxt[1] = 0;
	for(int i = 1; i < l; i++) {
		int j = nxt[i];
		while(j && s[i] != s[j]) j = nxt[j];
		nxt[i+1] = s[i] == s[j]? j+1: 0;
	}
}

void KMP(char* s, char* p) {
	int n = strlen(s), m = strlen(p);
	for(int i  = 0, j = 0; i < n; i++) {
		while(j && s[i] != p[j]) j = nxt[j];
		if(s[i] == p[j]) j++;
		if(j == m) {
            ans++;
		}
	}
}

int main() {
    cin >> t;
	//ios::sync_with_stdio(false);
	//scanf(%s%s", s, p);
    while(t--) {
        ans = 0;
        scanf("%s%s", p, s);
        for(int i = 1; i <= strlen(p); i++) nxt[i] = 0;
        getNext(p);
        KMP(s, p);
        printf("%d\n", ans);
    }
	
	return 0;
}
