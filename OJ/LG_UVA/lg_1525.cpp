#include <cstdio>
#include <algorithm>
const int MAXN = 2e4+1;
const int MAXM = 1e5+1;
int n, m, father[MAXN], enemy[MAXN];

struct Edge
{
	int anger, u, v;
}e[MAXM];

inline int cmp(Edge a, Edge b)
{
    return a.anger > b.anger;
}

/*inline void _swap(Edge* a, Edge* b)
{
	Edge temp;
	temp = *a;
	*a = *b;
	*b = temp;
}*/

inline void init()
{
	for(int i = 1; i <= n; i++)
		father[i] = i;
}

inline int find(int x)
{
	if (x != father[x])
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

/*void QuickSort(int l, int r)
{
	int i = l, j = r, mid = e[(i+j)>>1].anger;
	while(i <= j)
	{
		while(e[i].anger > mid) i++;
		while(e[j].anger < mid) j--;
		if(i <= j)
		{
			Edge* p1 = &e[i];
			Edge* p2 = &e[j];
			_swap(p1, p2);
			i++; j--;
		}
	}
	if (i < r) QuickSort(i, r);
	if (j > l) QuickSort(l, j);
}*/

int main()
{
	scanf("%d%d", &n, &m);
	init();
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].anger);
	std::sort(e+1, e+m+1, cmp);
	for(int i = 1; i <= m; i++)
	{
		if (find(e[i].u) == find(e[i].v))
		{
			printf("%d", e[i].anger);
			return 0;
		}
		if (!enemy[e[i].u] && !enemy[e[i].v])
		{
			enemy[e[i].u] = e[i].v;
			enemy[e[i].v] = e[i].u;
		}
		else if (enemy[e[i].u] && !enemy[e[i].v])
		{
			_union(enemy[e[i].u], e[i].v);
			enemy[e[i].v] = e[i].u;
		}
		else if (!enemy[e[i].u] && enemy[e[i].v])
		{
			enemy[e[i].u] = e[i].v;
			_union(enemy[e[i].v], e[i].u);
		}
		else if (enemy[e[i].u] && enemy[e[i].v])
		{
			_union(enemy[e[i].u], e[i].v);
			_union(enemy[e[i].v], e[i].u);
		}
	}
	printf("0");
	return 0;
}