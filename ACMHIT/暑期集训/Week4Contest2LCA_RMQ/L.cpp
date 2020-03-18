#include <cstdio>
#include <cmath>
#define INF 0x7fffffff
#define N 255

int dp_max[N][N][10], dp_min[N][N][10];
int n, b, k;

inline int max(int x, int y) {
    return x > y? x: y;
}

inline int min(int x, int y) {
    return x < y? x: y;
}

void ST() {
    for(int q = 1; q <= n; q++)
        for(int j = 1; (1<<j) <= n; j++)
            for(int i = 1; i+(1<<j)-1 <= n; i++) {
                dp_max[q][i][j] = max(dp_max[q][i][j-1], dp_max[q][i+(1<<(j-1))][j-1]);
                dp_min[q][i][j] = min(dp_min[q][i][j-1], dp_min[q][i+(1<<(j-1))][j-1]);
            }
}

int RMQ(int x, int y) {
    int l = y, r = y+b-1;
    int k = log2(b);
    int _max = -1, _min = INF;
    for(int i = x; i <= x+b-1; i++) {
        _max = max(_max, max(dp_max[i][l][k], dp_max[i][r-(1<<k)+1][k]));
        _min = min(_min, min(dp_min[i][l][k], dp_min[i][r-(1<<k)+1][k]));
    }
    return _max-_min;
}

int main() {
    scanf("%d%d%d", &n, &b, &k);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            scanf("%d", &dp_max[i][j][0]);
            dp_min[i][j][0] = dp_max[i][j][0];
        }
    ST();
    while(k--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", RMQ(x, y));
    }
    return 0;
}