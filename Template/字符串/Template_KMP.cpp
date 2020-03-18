/*** KMP
* luogu_3375
***/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define N 1000010

int nxt[N], ans = 0;
char s[N], p[N];

void getNext(char* p) {
	int l = strlen(p);
	nxt[0] = nxt[1] = 0;
	for(int i = 1; i < l; i++) {
		int j = nxt[i];
		while(j && p[i] != p[j]) j = nxt[j];
		nxt[i+1] = p[i] == p[j]? j+1: 0;
	}
}

void KMP(char* s, char* p) {
	int n = strlen(s), m = strlen(p);
	for(int i  = 0, j = 0; i < n; i++) {
		while(j && s[i] != p[j]) j = nxt[j];
		if(s[i] == p[j]) j++;
		if(j == m) {
			ans++;
			printf("%d\n", i+1-j+1);	
		}
	}
}

int main() {
	scanf("%s%s", s, p);
	getNext(p);
	KMP(s, p);
	int q = strlen(p);
	for(int i = 1; i <= q; i++)
		printf("%d ", nxt[i]);
	printf("\n");
	return 0;
}
