#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
#define N 205
#define INF 0x7fffffff

queue<int> q;

int n, a, b, cnt = 0;
bool visited[N];
int dis[N], k[N];

inline void add(int node)
{
	visited[node] = true;
	q.push(node);
}

void bfs()
{
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		int next = k[now]+now;
		if(next <= n && !visited[next])
		{
			add(next);
			dis[next] = dis[now]+1;
		}
		next = now-k[now];
		if(next > 0 && !visited[next])
		{
			add(next);
			dis[next] = dis[now]+1;
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	for(int i = 1; i <= n; i++)
	{
		dis[i] = INF;
		visited[i] = false;
		scanf("%d", k+i);
	}
	q.push(a);
	visited[a] = true;
	dis[a] = 0;
	bfs();
	if (dis[b] == INF)
		printf("-1\n");
	else
		printf("%d\n", dis[b]);
	return 0;
}