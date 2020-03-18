#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define N 1000010

int nxt[N], ans = 0;
char s[N], p[N];

inline int max(int x, int y) {
    return x>y?x:y;
}

int main() {
	cin >> s >> p;
    int l1 = strlen(s), l2 = strlen(p);
    int ans = 0;
    int p1, p2;
    int j = 0;
	for(int i = 0; i < l1; i++) {
        if(s[i] == p[j]) {
            if(j == 0) p1 = i;
            j++;
            if(j == l2) p2 = i;
        }
        if(j == l2) {
            ans = max(p1, ans);
            ans = max(l1-p2-1, ans);
            break;
        }
    }
    j = l2-1;
    for(int i = l1-1; i >= 0; i--) {
        if(s[i] == p[j]) {
            if(j == l2-1) p2 = i;
            j--;
            if(j == -1) p1 = i;
        }
        if(j == -1) {
            ans = max(p1, ans);
            ans = max(l1-p2-1, ans);
            break;
        }
    }
	printf("%d\n", ans);
	return 0;
}
