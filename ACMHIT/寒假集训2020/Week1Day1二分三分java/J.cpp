#include <cstdio>
#include <cmath>
#define N 205

struct Node {
    int x, y;
    inline double dist(Node v) {
        return sqrt((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y));
    }
}nodes[N];

int n;
double dis[N][N];

void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = ;
}

int main() {
    int kase = 0;
    while(1) {
        scanf("%d", &n);
        if(!n) break;
        for(int i = 1; i <= n; i++)
            scanf("%d%d", nodes[i].x, nodes[i].y);

        printf("Scenario #%d\n", ++kase);
        printf("Frog Distance = %.3f", dis[1][2]);
    }

    return 0;
}