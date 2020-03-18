#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3fffffff
const int N = 155;
int k, ma[N][N], node[N];
map<string, int> mm, V;

void init() {
    for (int i = 0; i < N; i++) {
        node[i] = INF;
        for (int j = 0; j < N; j++)
            if(i != j) ma[i][j] = INF;
            else ma[i][j] = 0;
    }
}

void dijkstra(int m) {
    bool vis[N] = {0};
    int tm = m;
    vis[m] = true;
    node[m] = 0;
    for (int j = 1; j < k; j++) {
        int mmin = INF;
        for (int i = 0; i < k; i++)
            if (!vis[i]) {
                if (node[i] > node[tm] + ma[tm][i])
                    node[i] = node[tm] + ma[tm][i];
                if (mmin > node[i]) {
                    mmin = node[i];
                    m = i;
                }
            }
        vis[m] = 1;
        tm = m;
    }
}

int main() {
    bool flag;
    int t, n;
    while (scanf("%d", &n), n != -1) {
        flag = 0;
        mm.clear();
        V.clear();
        init();
        char start[N], end[N];
        k = 2;
        scanf("%s%s", start, end);
        if (strcmp(start, end) == 0)
            flag = 1;
        if (!n) {
            printf("-1\n");
            continue;
        }
        mm[start] = 0; mm[end] = 1;
        while (n--) {
            char s[N], e[N];
            scanf("%s%s%d", s, e, &t);
            if (!V[s]) {
                V[s] = 1;
                mm[s] = k++;
            }
            if (!V[e]) {
                V[e] = 1;
                mm[e] = k++;
            }
            if (ma[mm[s]][mm[e]] > t)
                ma[mm[s]][mm[e]] = ma[mm[e]][mm[s]] = t;
        }
        if (flag) {
            printf("0\n");
            continue;
        }
        dijkstra(mm[start]);
        if (node[mm[end]] == INF)
            printf("-1\n");
        else
            printf("%d\n", node[mm[end]]);
    }
    return 0;
}