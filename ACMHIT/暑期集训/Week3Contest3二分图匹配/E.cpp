#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 55
//Hungarian O(V*E)

int n, m, e;
int match[N*N]; //match[i]=j, 表示i与j配对
bool check[N*N];
char mp[N][N];
bool edge[N*N/2][N*N/2];
int num1[N][N], num2[N][N];
int tot1 = 0, tot2 = 0;
int tot = 0;

bool dfs(int u) {
    for (int v = 1; v <= tot; ++v) {
        if (edge[u][v] && !check[v]) { // 要求不在交替路中
            check[v] = true; // 放入交替路
            if (match[v] == -1 || dfs(match[v])) { 
                // 如果是未盖点，说明交替路为增广路，则交换路径，并返回成功
                match[v] = u;
                return true;
            }
        }
    }
    return false; // 不存在增广路，返回失败
}

int hungarian() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= tot; i++) { 
        memset(check, false, sizeof(check));
        if (dfs(i)) ans++;
    }
    return ans;
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        memset(edge, 0, sizeof(edge));
        tot1 = 0; tot2 = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s", mp[i]);
            for(int j = 0; j < m; j++) {
                if(mp[i][j] == '*') {
                    if(!num1[i+1][j])
                        num1[i+1][j+1] = ++tot1;
                    else num1[i+1][j+1] = num1[i+1][j];
                    if(!num2[i][j+1])
                        num2[i+1][j+1] = ++tot2;
                    else num2[i+1][j+1] = num2[i][j+1];
                }
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mp[i][j] == '*')
                    edge[num1[i+1][j+1]][num2[i+1][j+1]] = 1;
        tot = tot1>tot2?tot1:tot2;
        printf("%d\n", hungarian());
    }
    return 0;
}
