#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define N 205

int color[N], cnt[N], dfn[N], low[N], vis[N], rdu[N], cdu[N], stack[N<<1];
int sum, n, tim, top;
vector<int > G[N];

void init() {
    tim = 0; top = 0; sum = 0;
    for(int i = 1; i <= n; i++) {
        G[i].clear();
        dfn[i] = 0; low[i] = 0;
        cnt[i] = 0; color[i] = 0;
        rdu[i] = 0; cdu[i] = 0;
        vis[i] = false;
    }
    memset(stack, 0, sizeof(stack));
}

inline int min(int x, int y) {
    return x<y?x:y;
}

inline int max(int x, int y) {
    return x>y?x:y;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    vis[u] = true;
    stack[++top] = u;
    int size = G[u].size();
    for(int i = 0; i < size; i++) {
        int v = G[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else {
            if(vis[v])
                low[u] = min(low[u],low[v]);
        }
    }
    if(dfn[u] == low[u]) {
        color[u] = ++sum;
        vis[u] = false;
        while(stack[top] != u) {
            color[stack[top]] = sum;
            vis[stack[top--]] = false;
        }
        top--;
    }
}

int main() {
    while(scanf("%d", &n) != EOF) {
        init();
        for(int i = 1; i <= n; i++) {
            int v;
            scanf("%d", &v);
            for(; v; scanf("%d", &v))
                G[i].push_back(v);
        }
        for(int i = 1; i <= n; i++)
            if(!dfn[i]) tarjan(i);
        for(int i = 1; i <= n; i++) {
            int sz = G[i].size();
            for(int j = 0; j < sz; j++) {
                int v = G[i][j];
                if(color[i] != color[v]) {
                    cdu[color[i]]++;
                    rdu[color[v]]++;
                }
            }
            cnt[color[i]]++;
        }
        if(sum == 1) {
            printf("1\n0\n");
            continue;
        }
        int num1 = 0, num = 0;
        for(int i = 1; i <= sum; i++) {
            if(rdu[i] == 0) num1++;
            if(cdu[i] == 0) num++;
        }
        printf("%d\n%d\0", num1, max(num, num1));
    }
    return 0;
}