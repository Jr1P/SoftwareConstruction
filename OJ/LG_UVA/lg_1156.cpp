#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define G 105

struct Trash {
    int t, f, h;
}trash[G];

int d, g, maxlive;
int h[G], t[G], f[G];

inline int max(int x, int y) { return x > y ? x : y; }
inline bool cmp(Trash a, Trash b) {
    return a.t < b.t;
}

void dfs(int h, int livespan, int x) {
    if(h >= d) {
        printf("%d\n", trash[x].t);
        exit(0);
    }
    if(x >= g) return ;
    if(livespan >= trash[x + 1].t)
        dfs(h + trash[x + 1].h, livespan, x + 1);
    maxlive = max(maxlive, livespan);
    dfs(h, livespan + trash[x + 1].f, x + 1);
}

int main() {
    scanf("%d%d", &d, &g);
    for(int i = 1; i <= g; i++)
        scanf("%d%d%d", &trash[i].t, &trash[i].f, &trash[i].h);
    std::sort(trash + 1, trash + g + 1, cmp);
    dfs(0, 10, 0);
    printf("%d\n", maxlive);
    return 0;
}