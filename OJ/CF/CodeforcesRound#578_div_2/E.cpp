#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define N 1000500

int n;
int nxt[N];
char add[N];
char ans[N];

inline int max(int x, int y) {
	return x > y? x: y;
}

void getNext(char* p) {
	int l = strlen(p);
	nxt[0] = nxt[1] = 0;
	for(int i = 1; i < l; i++) {
		int j = nxt[i];
		while(j && p[i] != p[j]) j = nxt[j];
		nxt[i+1] = p[i] == p[j]? j+1: 0;
	}
}

int main() {
	scanf("%d", &n);
	char c = getchar();
	c = getchar();
	int l = 0;
	for(; c != ' '; c = getchar())
		ans[l++] = c;
	ans[l] = '\0';
	for(int i = 2; i <= n; i++) {
		l = 0;
		c = getchar();
		for(; c != ' ' && c != '\n'; c = getchar()) {
			add[l++] = c;
		}
		add[l] = '\0';
		int la = strlen(ans), lb = strlen(add);
		int h = max(la-lb, 0), j = 0;
		getNext(add);
		for(int i = h; i < la; i++) {
			while(j && ans[i] != add[j]) j = nxt[j];
			if(ans[i] == add[j])
				j++;
		}		
		for(int i = la; i < la+lb-j; i++)
			ans[i] = add[i-la+j];
		ans[la+lb-j] = '\0';
	}
	for(int i = 0; ans[i] != '\0'; i++)
		putchar(ans[i]);
	return 0;
}
