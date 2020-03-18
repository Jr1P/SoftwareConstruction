#include <cstdio>
#define N 100050

int n, t;
char str[N];
int l, r, u, d;

inline int min(int x, int y) { return x < y ? x : y; }

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%s", str);
        l = r = u = d = 0;
        for(int i = 0; str[i]; i++) {
            if(str[i] == 'L') l++;
            else if(str[i] == 'R') r++;
            else if(str[i] == 'U') u++;
            else if(str[i] == 'D') d++;
        }
        if(min(u, d) == 0) {
            if(l == 0) r = 1;
            else l = 1;
        }
        if(min(l, r) == 0) {
            if(u == 0) d = 1;
            else u = 1;
        }
        int ans = min(l, r) + min(u, d);
        ans <<= 1;
        printf("%d\n", ans);
        for(int i = 0; i < min(l, r); i++)
            putchar('L');
        for(int i = 0; i < min(u, d); i++)
            putchar('D');
        for(int i = 0; i < min(l, r); i++)
            putchar('R');
        for(int i = 0; i < min(u, d); i++)
            putchar('U');
        putchar('\n');
    }
    return 0;
}