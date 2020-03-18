#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define N 1050
#define K 1050

int n, m, k, tim;
int match[N<<1], state[N<<1];
vector<int > G[N];

bool dfs(int u) {
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(state[v] == tim) continue;
        state[v] = tim;
        if(match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    tim = 0;
    memset(match, -1, sizeof(match));
    memset(state, 0, sizeof(state));
    for(int i = 1; i < n; i++) {
        if(match[i] == -1) {
            ++tim;
            if(dfs(i)) ans++;
        }
    }
    return ans;
}

int main() {
    while(1) {
        scanf("%d", &n);
        if(!n) break;
        scanf("%d%d", &m, &k);
        for(int i = 0; i <= n; i++) G[i].clear();
        for(int i = 0; i < k; i++) {
            int id, u, v;
            scanf("%d%d%d", &id, &u, &v);
            if(u == 0 || v == 0) continue;
            G[u].push_back(v+n);
        }
        printf("%d\n", hungarian());
    }
    return 0;
}