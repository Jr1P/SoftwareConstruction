#include <cstdio>
#include <iostream>
#include <vector>
#define N 100050

int kase = 0;
int ru[N];
bool vis[N], aper[N], flag;
std::vector<int > g[N];

void dfs(int root) {
    vis[root] = true;
    for(int i = 0; i < g[root].size(); i++) {
        if(flag) break ;
        if(vis[g[root][i]]) {
            flag = true;
            printf("Case %d is not a tree.\n", ++kase);
            return ;
        }
        dfs(g[root][i]);
    }
}

int main() {
    while(1) {
        int u, v, ma = 0;
        flag = false;
        scanf("%d%d", &u, &v);
        if(u == -1 && v == -1)
            break;
        while(u != 0 && v != 0) {
            ru[v]++;
            aper[u] = aper[v] = true;
            g[u].push_back(v);
            ma = std::max(ma, u);
            ma = std::max(ma, v);
            scanf("%d%d", &u, &v);
        }
        int root = 0, cnt = 0;
        for(int i = 1; i <= ma; i++) {
            if(ru[i] > 1) {
                cnt = -1;
                break;
            }
            if(!ru[i] && aper[i]) {
                root = i;
                cnt++;
            }
        }
        if(cnt == 1) {
            dfs(root);
            if(!flag) {
                bool f = false;
                for(int i = 1; i <= ma; i++)
                    if(!vis[i] && aper[i]) {
                        printf("Case %d is not a tree.\n", ++kase);
                        f = true;
                        break;
                    }
                if(!f) printf("Case %d is a tree.\n", ++kase);
            }
        } else {
            if(ma == 0)
                printf("Case %d is a tree.\n", ++kase);
            else printf("Case %d is not a tree.\n", ++kase);
        }
        for(int i = 0; i <= ma; i++) {
            g[i].clear();
            vis[i] = aper[i] = false;
            ru[i] = 0;
        }
    }
    return 0;
}