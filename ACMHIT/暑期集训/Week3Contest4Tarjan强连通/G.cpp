#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define N 1005

vector<int > G[N];
//vector<pair<int ,int > > ans;
int nod, tim;
int dfn[N], low[N];
bool iscut[N], vis[N];

inline void init() {
    for(int i = 1; i < N; i++) {
        G[i].clear();
        dfn[i] = low[i] = 0;
        tim = nod = 0;
        iscut[i] = false;
    }
}

inline int max(int x, int y) {
    return x>y?x:y;
}

inline int min(int x, int y) {
    return x<y?x:y;
}

int tarjan(int u, int fa) {
    int lowu = dfn[u] = ++tim;
    int sz = G[u].size(), child = 0;
    for(int i = 0; i < sz; i++) {
        int v = G[u][i];
        if(!dfn[v]) {
            child++;
            int lowv = tarjan(v, u);
            lowu = min(lowv, lowu);
            if(lowv >= dfn[u]) iscut[u] = true;
        } else if(v != fa && dfn[v] < dfn[u])
            lowu = min(lowu, dfn[v]);
    }
    if(fa < 0 && child == 1) iscut[u] = false;
    low[u] = lowu;
    return lowu;
}

queue<int > q;

void bfs(int s) {
    while(!q.empty()) q.pop();
    q.push(s);
    vis[s] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int j = 0; j < G[u].size(); j++) {
            int v = G[u][j];
            if(!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int main() {
    int kase = 0, u, v;
    while(1) {
        scanf("%d", &u);
        if(!u) break;
        init();
        scanf("%d", &v);
        G[u].push_back(v); G[v].push_back(u);
        while(1) {
            scanf("%d", &u);
            if(!u) break;
            scanf("%d", &v);
            nod = max(nod, u);
            nod = max(nod, v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1; i <= nod; i++)
            if(!dfn[i]) tarjan(i, -1);
        printf("Network #%d\n", ++kase);
        bool f = false;
        int ans;
        for(int i = 1; i <= nod; i++) {
            if(iscut[i]) {
                f = true; ans = 0;
                memset(vis, false, sizeof(vis));
                vis[i] = true;
                int sz = G[i].size();
                for(int j = 0; j < sz; j++) {
                    int v = G[i][j];
                    if(!vis[v]) {
                        ans++;
                        bfs(v);
                    }
                }
                printf("  SPF node %d leaves %d subnets\n", i, ans);
            }
        }
        if(!f) printf("  No SPF nodes\n");
        printf("\n");
    }
    return 0;
}