#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define N 400010

int t, ans = 0, cnt = 0;
int nxt[N], an[N];
char s[N];

void getNext(char* s) {
	int l = strlen(s);
	nxt[0] = nxt[1] = 0;
	for(int i = 1; i < l; i++) {
		int j = nxt[i];
		while(j && s[i] != s[j]) j = nxt[j];
		nxt[i+1] = s[i] == s[j]? j+1: 0;
	}
}

int main() {
    while( scanf("%s", s) != EOF) {
        ans = 0; cnt = 0;
        int l = strlen(s);
        for(int i = 0; i <= l; i++)
            nxt[i] = 0;
        getNext(s);
        int j = l;
        while(nxt[j]) {
            an[++cnt] = nxt[j];
            j = nxt[j];
        }
        for(int i = cnt; i >= 1; i--)
            printf("%d ", an[i]);
        printf("%d\n", l);
        //KMP(s, p);
    }
	
	return 0;
}
