#include <cstdio>
const int MAXN = 1e4+1; //maximum number of nodes
const int MAXQ = 2e5+1; //maximum number of queries
int father[MAXN], n ,q;

inline void init() // intialize
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

int main()
{
	scanf("%d %d", &n, &q);
	init();
	for(int i = 1; i <= q; i++)
	{
		int x, y, ch;
		scanf("%d %d %d", &ch, &x, &y);
		if (ch == 1)
			_unino(x, y);
		else
			if (find(x) == find(y))
				printf("Y\n");
			else
				printf("N\n");
	}
	return 0;
}