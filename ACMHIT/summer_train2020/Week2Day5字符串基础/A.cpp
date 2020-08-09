#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
const int N = 5e5 + 5;

int nxt[N];
char s[N], t[N];
int num[2];

void getNext(char* p) {
	int l = strlen(p);
	nxt[0] = nxt[1] = 0;
	for(int i = 1, j = 0; i < l; i++) {
		while(j && p[i] != p[j]) j = nxt[j];
		if(p[i] == p[j]) j++;
        nxt[i+1] = j;
	}
}

int main() {
    scanf("%s%s", s, t);
    if(strlen(t) > strlen(s)) puts(s);
    else {
        getNext(t);
        int slen = strlen(s), tlen = strlen(t);
        for(int i = 0; s[i]; i++) num[s[i]-'0']++;
        for(int i = 0, j = 0; i < slen; i++) {
            if(!num[0]) putchar('1');
            else if(!num[1]) putchar('0');
            else {
                putchar(t[j]);
                num[t[j]-'0']--;
                if(j == tlen - 1) j = nxt[tlen];
                else j++; 
            }
        }
    }
	return 0;
}