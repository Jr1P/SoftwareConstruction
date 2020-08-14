#include <cstdio>
const int INF = 0x1f1f1f1f;
const int N = 205;
const int M = 1e4;

int dis[N][N], mc[N][N];
int n, m, mm;
inline int min(int x, int y) { return x < y ? x : y; }

void floyed() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i < k; i++)
            for(int j = i+1; j < k; j++)
                mm = min(mm, dis[i][j]+mc[i][k]+mc[k][j]);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][k]+dis[k][j], dis[i][j]);
    }
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        int x, y, w;
        mm = INF;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = mc[i][j] = INF;
        for(int i = 1; i <= m; i++) {
            scanf("%d%d%d", &x, &y ,&w);
            mc[x][y] = mc[y][x] = dis[x][y] = dis[y][x] = min(w, dis[x][y]);
        }
        floyed();
        if(mm == INF) puts("It's impossible.");
        else printf("%d\n", mm);
    }
    return 0;
}