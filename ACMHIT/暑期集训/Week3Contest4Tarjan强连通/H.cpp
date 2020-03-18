#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define N 300050

int color[N], cnt[N], dfn[N], low[N], stack[N<<1];
int sum, n, tim, top, m, ans;
char str[N];
bool vis[N];
vector<int > G[N];
int rdu[N], ma[N][26];

void init() {
    tim = 0; top = 0; sum = 0;
    for(int i = 1; i <= n; i++) {
        G[i].clear();
        dfn[i] = 0; low[i] = 0;
        cnt[i] = 0; color[i] = 0;
        //rdu[i] = 0; cdu[i] = 0;
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

queue<int > q;

void bfs(int s) {
    q.push(s);
    ma[s][str[0]-'a'] = 1;
    while(!q.empty()) {
        int u = q.front();
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            q.push(v);
            for(int j = 0; j <= 25; j++)
                if(str[v-1]-'a' == j) {
                    ma[v][j] = ma[u][j]+1;
                    ans = max(ma[v][j], ans);
                } else {
                    ma[v][j] = ma[u][j];
                }
        }
        q.pop();
    }
}

void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    vis[u] = true;
    stack[++top] = u;
    int sz = G[u].size();
    for(int i = 0; i < sz; i++) {
        int v = G[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else {
            if(vis[v])
                low[u] = min(low[u], low[v]);
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
    scanf("%d%d", &n, &m);
    init();
    scanf("%s", str);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        //if(u == v) continue;
        G[u].push_back(v);
        rdu[v]++;
        //G[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i);
    if(sum != n || (n == 1 && sum == 1)) printf("-1\n");
    else {
        int u;
        for(u = 1; u <= n; u++)
            if(rdu[u] == 0) break;
        bfs(u);
        printf("%d\n", ans);
    }
    return 0;
}