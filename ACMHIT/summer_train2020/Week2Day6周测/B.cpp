#include <cstdio>
#include <cstring>
const int N = 5e4+5;

char s[N], t[N];
int nxt[N];

void getnext(char* t) {
    nxt[0] = nxt[1] = 0;
    int len = strlen(t);
    for(int i = 1, j = 0; i < len; i++) {
        while(j && t[i] != t[j]) j = nxt[j];
        if(t[i] == t[j]) j++;
        nxt[i+1] = j;
    }
}

int KMP(char* s, char* p) {
	int n = strlen(s);
	for(int i = 0, j = 0; i < n; i++) {
		while(j && s[i] != p[j]) j = nxt[j];
		if(s[i] == p[j]) j++;
		if(i == n-1) return j;
	}
    return 0;
}

int main() {
    while(~scanf("%s%s", s, t)) {
        getnext(s);
        int ans = KMP(t, s);
        if(ans == 0) puts("0");
        else {
            for(int i = 0; i < ans; i++) putchar(s[i]);
            printf(" %d\n", ans);
        }
    }
    return 0;
}

// #include <cstdio>
// #include <cstring>
// const int N = 5e4 + 5;
// char s[N], t[N];
// int nex[N];

// void nex(char *t) {
//     nex[0] = nex[1] = 0;
//     int len = strlen(t);
//     for(int i = 1, j = 0; i < len; i++)
//     {
//         while(j > 0 && t[j] != t[i]) j = nex[j];
//         if(t[j+1] == t[i]) j++;
//         nex[i] = j;
//     }
// }
// int solve(char *s) {
//     int j = 0;
//     for(int i = 0; i < len; i++) {
//         while(j > 0 && t[j+1] != s2[i]) j = nex[j];
//         if(t[j+1] == s2[i]) j++;
//         if(i == len) return j;
//     }
//     return 0;
// }
// int main() {
//     while(scanf("%s%s", s, t)!=EOF) {
//         int len = (int)strlen(t);
//         ex(t);
//         int ans = solve((int)strlen(s2 + 1));
//         if(ans == 0) { printf("0\n");   continue; }
//         for(int i=1; i<=ans; i++) printf("%c", t[i]);
//         printf(" %d\n", ans);
//     }
//     return 0;
// }