#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 155
using namespace std;
#define INF 0x7fffffff
    
int val[N*10][N*10];   
int ex_girl[N], ex_boy[N];  
bool vis_girl[N], vis_boy[N]; 
int match[N];   
int slack[N];  
char map[N][N];

struct Point {
    int x, y;
}M[N*10], H[N*10];

int n, m;
    
inline int _abs(int x) {
    return x < 0? -x: x;
}

bool dfs(int u) {
    vis_girl[u] = true;
    for (int v = 0; v < n; ++v) {
        if(vis_boy[v]) continue; 
        int gap = ex_girl[u] + ex_boy[v] - val[u][v];
        if (gap == 0) {  
            vis_boy[v] = true;
            if (match[v] == -1 || dfs(match[v])) { 
                match[v] = u;
                return true;
            }
        } else
            slack[v] = min(slack[v], gap);
    }
    return false;
}
    
int KM() {
    memset(match, -1, sizeof match);
    memset(ex_boy, 0, sizeof ex_boy);
    for (int i = 0; i < n; ++i) {
        ex_girl[i] = val[i][0];
        for (int j = 1; j < n; ++j)
            ex_girl[i] = max(ex_girl[i], val[i][j]);
    }
    for (int i = 0; i < n; ++i) {
        memset(slack, 127, sizeof(slack));
        while (1) {
            memset(vis_girl, false, sizeof vis_girl);
            memset(vis_boy, false, sizeof vis_boy);
            if (dfs(i)) break;
            int d = INF;
            for (int j = 0; j < n; ++j)
                if (!vis_boy[j]) d = min(d, slack[j]);
            for (int j = 0; j < n; ++j) {
                if (vis_girl[j]) ex_girl[j] -= d;
                if (vis_boy[j]) ex_boy[j] += d;
                else slack[j] -= d;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
        res += val[match[i]][i];
    return res;
}
    
int main() {
    while (1) {
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0) break;
        int ren = 0, fang = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%s", map[i]);
            for(int j = 0; j < m; j++)
                if(map[i][j] == 'H') {
                    H[fang].x = i;
                    H[fang++].y = j+1;
                } else if(map[i][j] == 'm') {
                    M[ren].x = i;
                    M[ren++].y = j+1;
                }
        }
        for(int i = 0; i < fang; i++) {
            for(int j = 0; j < ren; j++) {
                val[i][j] = _abs(H[i].x-M[j].x)+_abs(H[i].y-M[j].y);
                val[i][j] = -val[i][j];
            }
        }
        n = ren;
        printf("%d\n", -KM());
    }
    return 0;
}        