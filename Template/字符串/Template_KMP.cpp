#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define N 1000010

int nxt[N], ans = 0, extend[N];
char s[N], p[N];

void getNext(char* p) {
	int l = strlen(p);
	nxt[0] = nxt[1] = 0;
	for(int i = 1, j = 0; i < l; i++) {
		while(j && p[i] != p[j]) j = nxt[j];
        if(t[i] == t[j]) j++;
        nxt[i+1] = j;
	}
}

void KMP(char* s, char* p) {
	int n = strlen(s), m = strlen(p);
	for(int i  = 0, j = 0; i < n; i++) {
		while(j && s[i] != p[j]) j = nxt[j];
		if(s[i] == p[j]) j++;
		if(j == m) { // 匹配成功
			ans++;
			printf("%d\n", i+1-j+1);
			j = nxt[j];
		}
	}
}

/**
 * @param s 待匹配串
 * @param p 模式串
 * @e extends s的每一个后缀关于p的最长前缀
 **/
void exKMP(char *s, char *p) {
	int n = strlen(s), m = strlen(p);
	for(int i = 0, j = 0; i < n; i++) {
		if(j && s[i] != p[j]) {
			extend[i-j] = j;
			j = nxt[j];
		}
		if(s[i] == p[j]) j++;
		if(j == m) { // 匹配成功
			extend[i-j] = j;
			j = nxt[j];
		}
	}
	while(i-j < lens) extend[i-j] = j, j = nxt[j];
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
