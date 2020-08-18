#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 65;
const int L = 10050;
const int INF = 0x3f3f3f3f;

int match[N], ex0[N], ex1[N], val[N][N], slack[N];
bool vis0[N], vis1[N];
int map0[N*2], map1[N*2];

int n, m, k;
char ans[L];

inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }

bool dfs(int u) {
    vis0[u] = true;
    for(int v = 1; v <= k; v++) {
        if(vis1[v]) continue;
        int gap = ex0[u]+ex1[v]-val[u][v];
        if(!gap) {
            vis1[v] = true;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        } else slack[v] = min(slack[v], gap);
    }
    return false;
}

int KM() {
    mem(match, -1); mem(ex1, 0);
    for(int i = 1; i <= k; i++) {
        ex0[i] = val[i][0];
        for(int j = 1; j <= k; j++) ex0[i] = max(ex0[i], val[i][j]);
    }
    for(int i = 1; i <= k; i++) {
        if(!ex0[i]) continue;
        mem(slack, 0x3f);
        while(1) {
            mem(vis0, false); mem(vis1, false);
            if(dfs(i)) break;
            int d = INF;
            for(int j = 1; j <= k; j++) if(!vis1[j]) d = min(d, slack[j]);
            for(int j = 1; j <= k; j++) {
                if(vis0[j]) ex0[j] -= d;
                if(vis1[j]) ex1[j] += d;
                else slack[j] -= d;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= k; i++)
        ans += val[match[i]][i];
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &k, &m);
        int id0 = 0, id1 = 0;
        mem(map0, 0);
        for(int i = 1; i <= n; i++) {
            char a[2];
            scanf("%s", a);
            ans[i] = a[0];
            if(!map0[ans[i]]) map0[ans[i]] = ++id0;
        }
        while(m--) {
            mem(val, 0); id1 = 0;
            mem(map1, 0);
            for(int i = 1; i <= n; i++) {
                char a[2];
                scanf("%s", a);
                if(!map1[a[0]]) map1[a[0]] = ++id1;
                // printf("%d ", map1[a[0]]);
                val[map0[ans[i]]][map1[a[0]]]++;
            }
                
            printf("%.4f\n", 1.0*KM()/n);
        }
    }
    return 0;
}