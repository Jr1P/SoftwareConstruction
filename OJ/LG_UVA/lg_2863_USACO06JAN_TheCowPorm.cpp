#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 10010

vector<int > g[N];

bool vis[N];
int stack[N<<1], dfn[N<<1], low[N<<1], color[N], cnt[N];
int n, m, sum = 0, ans = 0, top = 0, tim = 0;

void tarjan(int u)
{
	dfn[u] = low[u] = ++tim;
	vis[u] = true;
	stack[++top] = u;
	int size = g[u].size();
	for(int i = 0; i < size; ++i)
	{
		int v = g[u][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else
		{
			if(vis[v])
				low[u] = min(low[u], low[v]);
		}
	}
	if(dfn[u] == low[u])
	{
		color[u] = ++sum;
		vis[u] = false;
		while(stack[top] != u)
		{
			color[stack[top]] = sum;
			vis[stack[top--]] = true;
		}
		top--;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
	}
	for(int i = 1; i <= n; ++i)
		if(!dfn[i])
			tarjan(i);
	for(int i = 1; i <= n; i++)
		cnt[color[i]]++;
	for(int i = 1; i <= sum; i++)
		if (cnt[i] > 1)
			ans++;
	printf("%d\n", ans);
	return 0;
}