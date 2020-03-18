#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define K 11
#define N 100010
#define M 200020

vector<int> g[N][K];

int n, k, u, v, m, ans;
int a[N], father[N][K];

inline int find(int x)
{
	if (x == father[x])
		father[x] = find(father[x]);
	return father[x];
}

inline void _union(int x, int y)
{
	int f1 = find(x);
	int f2 = find(y);
	if (f1 != f2)
		father[f2] = f1;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int j = 1; j <= k; j++)
		for(int i = 1; i <= n; i++)
			father[i][j] = i;
	int id = 0;
	while(id <= k)
	{
		id++;
		int m;
		scanf("%d", &m);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d", &u, &v);
			_union(u, v);
			g[u][id].push_back(v);
		}
	}
	for(int i = 1; i <= )
	return 0;
}