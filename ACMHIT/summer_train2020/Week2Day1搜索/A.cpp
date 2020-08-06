#include <cstdio>
#include <iostream>
const int INF = 0x3fffffff;
const int N = 1e4 + 5;

int n, m;
int ans = 0, mmin = INF;
bool f = true;

void dfs(int V, int cen, int r, int h) {
    if(V == 0 && cen == 0) {
        mmin = std::min(ans, mmin);
        return ;
    }
    if(V <= 0) return ;
    if(ans + cen * (cen + 1) * (2 * cen + 1) / 6 > mmin) return ;
    int tmp = 0;
    for(int k = 1; k <= cen; k++)
        tmp += k * k * k;
    if(tmp > V) return;
    for(int i = r - 1; i >= cen; i--) {
        for(int j = h - 1; j >= cen; j--) {
            if(i * i * j * cen < V) continue;
            if(ans + 2 * V / i > mmin) continue;
            ans += 2 * i * j;
            dfs(V - i * i * j, cen - 1, i, j);
            ans -= 2 * i * j;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = m; i * i <= n; i++) {
        for(int j = std::max(m, n / (i * i * m)); i * i * j <= n; j++) {
            // f = true;
            ans = i * i + 2 * i * j;
            dfs(n - i * i * j, m - 1, i, j);
        }
    }
    if(mmin == INF) mmin = 0;
    printf("%d\n", mmin);
    return 0;
}