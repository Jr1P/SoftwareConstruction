#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int maxn = 100010;
vector<int> G[maxn];
vector<int> ans;
int limit;
int deg[maxn], s[maxn];
queue<int> q;
struct edge {
    int x, y, val, id;
};
edge a[maxn];
void add(int x, int y) {
    G[x].push_back(y);
    deg[y]++;
}
int n, m;
bool topsort() {
    ans.clear();
    int tot = 0;
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= n; i++)
        G[i].clear();
    for (int i = 1; i <= m; i++) {
        if(a[i].val > limit) {
            add(a[i].x, a[i].y);
        }
    }
    for (int i = 1; i <= n; i++)
        if(deg[i] == 0) {
            q.push(i);
            s[i] = ++tot;
        }
    while(q.size()) {
        int x = q.front();
        q.pop();
        for (int y : G[x]) {
            deg[y]--;
            if(deg[y] == 0) {
                q.push(y);
                s[y] = ++tot;
            }
        }
    }
    for (int i = 1; i <= n; i++) if(deg[i] > 0) return 0;
    for (int i = 1; i <= m; i++) {
        if(a[i].val <= limit) {
            if(s[a[i].x] > s[a[i].y])
                 ans.push_back(a[i].id);
        }
    }
    return 1;
}
int main() {
    int x, y, z;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        a[i] = (edge){x, y, z, i};
    }
    int l = 0, r = 1e9;
    while(l < r) {
        limit = (l + r) >> 1;
        bool flag = topsort();
        if(!flag) l = limit + 1;
        else r = limit;
    }
    limit = l;
    topsort();
    printf("%d %d\n", l, ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
}