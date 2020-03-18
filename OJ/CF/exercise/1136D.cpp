#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 300030
#define M 500050

vector<int> g[N];

int n, m, ans;
int p[N];
bool vis[N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    	scanf("%d", &p[i]);
    for(int i = 1; i <= m; i++)
    {
    	int u, v;
    	scanf("%d%d", &u, &v);
    	g[u].push_back(v);
    }
    vis[p[n]] = 1;
    for(int i = n-1; i > 0; i--)
    {
    	int cnt = 0;
    	for(unsigned j = 0; j < g[p[i]].size(); j++)
    	{
    		int v = g[p[i]][j];
    		if (vis[v])
    			cnt++;
    	}
    	if(cnt+ans+i == n)
    		ans++;
    	else
    		vis[p[i]] = 1;
    }
    printf("%d\n", ans);
    return 0;
}
