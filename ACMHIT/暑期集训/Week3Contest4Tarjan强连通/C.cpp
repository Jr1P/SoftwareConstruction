#include <cstdio>
#include <vector>
using namespace std;
#define N 205

vector<int > G[N];
int dfn[N], low[N];
bool iscut[N];
int tim, n, m, ans;

inline int min(int x, int y) {
    return x<y?x:y;
}

int tarjan(int u, int fa) {
    int child = 0, lowu;
    lowu = dfn[u] = ++tim;
    int sz = G[u].size();
    for(int i = 0; i < sz; i++) {
        int v = G[u][i];
        if(!dfn[v]) {
            child++;
            int lowv = tarjan(v, u);
            lowu = min(lowv, lowu);
            if(lowv >= dfn[u]) 
                iscut[u] = true;
        } else if(dfn[v] < dfn[u] && v != fa){
            lowu = min(lowu, dfn[v]);
        }
    }
    if(fa < 0 && child == 1) iscut[u] = false;
    low[u] = lowu;
    return lowu;
}

int main() {
    char c;
    int u, v;
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = 1; i <= n; i++) {
            G[i].clear();
            iscut[i] = false;
            dfn[i] = low[i] = 0;
        }
        while(1) {
            scanf("%d", &u);
            if(u == 0) break;
            c = getchar();
            while(1) {
                if(c == '\n') break;
                scanf("%d", &v);
                G[u].push_back(v);
                G[v].push_back(u);
                c = getchar();
            }
        }
        for(int i = 1; i <= n; i++)
            if(!dfn[i]) tarjan(i, -1);
        ans = 0;
        for(int i = 1; i <= n; i++)
            if(iscut[i]) ans++;
        printf("%d\n", ans);  
    }
    return 0;
}