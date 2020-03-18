#include <cstdio>
#include <queue>
#define N 5050

long long n, r;
int ru[N], link[N];

struct Node {
    long long val;
    int id;
    bool operator < (const Node a) const {
        return val > a.val;
    }
}node[N];

std::priority_queue<Node> q;

int main() {
    long long ans;
    while(1) {
        ans = 0L;
        scanf("%lld%lld", &n, &r);
        if(n == 0 && r == 0) break;
        for(int i = 1; i <= n; i++) {
            link[i] = 0;
            ru[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &node[i].val);
            node[i].id = i;
        }
        for(int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            link[v] = u;
            ru[u]++;
        }
        while(!q.empty()) q.pop();
        for(int i = 1; i <= n; i++)
            if(!ru[i])
                q.push(node[i]);
        while(!q.empty()) {
            Node tmp = q.top();
            q.pop();
            ans += tmp.val * n; n--;
            if(!link[tmp.id]) continue;
            ru[link[tmp.id]]--;
            if(!ru[link[tmp.id]])
                q.push(node[link[tmp.id]]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}