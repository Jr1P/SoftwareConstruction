#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 305;
const int M = 1e5;

int n, m, cnt;
int head[N], match[N];
bool check[N];
int ans1[N], ans2[N];

struct Edge {
    int v, nxt;
} e[M];

inline void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}

bool dfs(int u) {
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(!check[v]) {
            check[v] = true;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungrian() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for(int i = 1; i <= n; i++) {
        memset(check, false, sizeof(check));
        ans += dfs(i);
    }
    return ans;
}
int main() {
    while(~scanf("%d", &n)) {
        memset(head, -1, sizeof(head));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                int a;
                scanf("%d", &a);
                if(a) add(i, j+n);
            }
        if(hungrian() != n) puts("-1");
        else {
            int count = 0;
            for(int i = n+1; i <= n+n; i++) {
                if(match[i] == i-n) continue;
                ans1[++count] = i-n;
                ans2[count] = match[i];
                int j = i+1;
                for(; j <= n+n; j++)
                    if(match[j] == i-n) break;
                match[j] = match[i];
            }
            printf("%d\n", count);
            for(int i = 1; i <= count; i++)
                printf("R %d %d\n", ans1[i], ans2[i]);
        }
    }
    return 0;
}