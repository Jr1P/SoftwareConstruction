#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 200050

char str[N];
int n, m;
char f[126], g[126];

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", str);
    for(int i = 'a'; i <= 'z'; i++) f[i] = g[i] = i;
    for(int i = 1; i <= m; i++) {
        getchar();
        char c1 = getchar(), c2;
        getchar(); c2 = getchar();
        if(c1 == c2) continue;
        f[g[c1]] = c2; f[g[c2]] = c1;
        std::swap(g[c1], g[c2]);
    }
    for(int i = 0; str[i]; i++) {
        putchar(f[str[i]]);
    }
    return 0;
}