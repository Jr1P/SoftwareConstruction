#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 5e5+5;
const int SZ = 26;

int n, m, len;
std::vector<int > vec[N][SZ], G[N];
int l[N], r[N];
char str[N];

void dfs(int u, int dep) {
    l[u] = ++len;
    vec[dep][str[u]-'a'].push_back(len);
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        dfs(v, dep+1);
    }
    r[u] = ++len;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 2; i <= n; i++) {
        int u; scanf("%d", &u);
        G[u].push_back(i);
    }
    scanf("%s", str+1);
    dfs(1, 1);
    while(m--) {
        int v, h, odd = 0;
        scanf("%d%d", &v, &h);
        for(int i = 0; i < SZ; i++) {
            int number = std::upper_bound(vec[h][i].begin(), vec[h][i].end(), r[v])
                        - std::lower_bound(vec[h][i].begin(), vec[h][i].end(), l[v]);
            if(number&1) odd++;
            if(odd > 1) break;
        }
        if(odd <= 1) puts("Yes");
        else puts("No");
    }
    return 0;
}














// void dfs(int deep,int num) {
//     now++;
//     ans[deep][str[num]-'a'].push_back(now);
//     start[num]=now;
//     vector<int>::iterator it;
//     for(it=tree[num].begin(); it!=tree[num].end(); it++) {
//         dfs(deep+1,*it);
//     }
//     endd[num]=now;
// }
// int main() {
//     scanf("%d%d",&n,&m);
//     int tmp;
//     for(int i=2; i<=n; i++) {
//         scanf("%d",&tmp);
//         tree[tmp].push_back(i);
//     }
//     getchar();
//     scanf("%s",str+1);
//     dfs(1,1);
//     int v,h, ttt,rel=0;
//     for(int i=0; i<m; i++) {
//         rel=0;
//         scanf("%d%d",&v,&h);
//         for(int i=0; i<26; i++) {
//             ttt=upper_bound(ans[h][i].begin(),ans[h][i].end(),endd[v])-lower_bound(ans[h][i].begin(),ans[h][i].end(),start[v]);
//             if(ttt&1) {
//                 rel+=1;
//                 if(rel>1)
//                     break;
//             }
//         }
//         if(rel>1) printf("No\n");
//         else printf("Yes\n");
//     }
// }