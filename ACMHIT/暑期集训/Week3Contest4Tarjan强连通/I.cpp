#include<cstdio>
#include<cstring>
#include<queue>
#include <vector>
using namespace std;

int n, m; 
int rdu[505], cp[505];
vector<int > G[505];
queue<int> q;

bool topo() {
    while(!q.empty()) q.pop();
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(!cp[i]) q.push(i), cnt++;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if(cp[v]) {
                cp[v]--;
                if(!cp[v]) q.push(v), cnt++;
            }
        }
    }
    return cnt == n;
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        int u, v;
        bool flag = false;
        for(int i = 1; i <= n; i++) G[i].clear();
        memset(rdu, 0, sizeof(rdu));
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            rdu[v]++;
        }
        for(int i = 1; i <= n; i++) {
            if(rdu[i]) {
                memcpy(cp, rdu, sizeof(rdu));
                cp[i]--;
                if(topo()) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}