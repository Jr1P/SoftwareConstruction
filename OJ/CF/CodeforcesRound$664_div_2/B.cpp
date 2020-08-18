#include <cstdio>
#include <cstring>
#include <iostream>
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for(int i = (a); i <= (n); i++)
#define drep(i, n, a) for(int i = (n); i >= (a); i--)

int n, m, sx, sy;

int main() {
    scanf("%d%d%d%d", &n, &m, &sx, &sy);
    printf("%d %d\n", sx, sy);
    for(int i = sy-1; i; i--) printf("%d %d\n", sx, i);
    for(int i = sy+1; i <= m; i++) printf("%d %d\n", sx, i);
    for(int i = sx-1; i; i--) printf("%d %d\n", i, m);
    for(int i = sx+1; i <= n; i++) printf("%d %d\n", i, m);
    int up = 1, down = n, le = 1, r = m-1;
    while(up <= down && le <= r) {
        if(down == sx) down++;
        if(up == sx) up--;
        for(int i = r; i >= le; i--) printf("%d %d\n", down, i);
        for(int i = down-1; i >= up; i--) if(i != sx) printf("%d %d\n", i, le);
        for(int i = le+1; i <= r; i++) printf("%d %d\n", up, i);
        for(int i = up+1; i < down; i++) if(i != sx) printf("%d %d\n", i, r);
        r--; down--; le++; up++;
    }
    return 0;
}