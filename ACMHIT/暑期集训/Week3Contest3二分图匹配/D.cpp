#include <cstdio>
#include <vector>
#include <cstring>
#define N 2000
using namespace std;

int n, m, num, cnt;
bool f[50][50];
vector<int > G[N];

int match[N<<1]; //match[i]=j, 表示i与j配对
bool check[N<<1];

bool dfs(int u) {
    for (unsigned i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (!check[v]) {
            check[v] = true;
            if (match[v] == -1 || dfs(match[v])) { 
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= n*m; i++) {
        if (match[i] == -1) {
            memset(check, false, sizeof(check));
            if (dfs(i))
                ans++;
        }
    }
    return ans;
}

int main(){
    scanf("%d%d%d", &n, &m, &num);
    //memset(color, -1, sizeof(color));
    for(int i = 1; i <= num; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        f[b][a] = true;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(f[i][j]) continue;
            if(!f[i][j+1] && j+1 <= m)
                G[(i-1)*m+j].push_back((i-1)*m+j+1+n*m);
            if(!f[i+1][j] && i+1 <= n)
                G[(i-1)*m+j].push_back(i*m+j+m*n);
            if(!f[i][j-1] && j >= 2)
                G[(i-1)*m+j].push_back((i-1)*m+j-1+m*n);
            if(!f[i-1][j] && i >= 2)
                G[(i-1)*m+j].push_back((i-2)*m+j+m*n);
        }
    if(n*m-num == hungarian())
        puts("YES");
    else puts("NO");
    return 0;
}