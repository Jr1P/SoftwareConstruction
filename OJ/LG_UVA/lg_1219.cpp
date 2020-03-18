#include <cstdio>
#include <cstring>
#define N 15

int n, ans = 0, cnt = 0;
int row[N], col[N];
bool l[N<<1], r[N<<1];

void init()
{
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(l, false, sizeof(l));
	memset(r, false, sizeof(r));
	return ;
}

void dfs(int x, int y, int depth)
{
	row[x] = y;
	col[y] = x;
	r[x+y] = true;
	l[n+x-y] = true;
	if (depth == n)
	{
		cnt++;
		ans++;
		if (cnt <= 3)
		{
			for(int i = 1; i <= n; i++)
				printf("%d ", row[i]);
			printf("\n");
		}
		row[x] = 0;
		col[y] = 0;
		r[x+y] = false;
		l[n+x-y] = false;
		return ;
	}
	for(int i = 1; i <= n; i++)
		if(col[i] == 0 && !l[n+x+1-i] && !r[x+1+i])
			dfs(x+1, i, depth+1);
	row[x] = 0;
	col[y] = 0;
	r[x+y] = false;
	l[n+x-y] = false;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1 ; i <= n; i++)
		dfs(1, i, 1);
	printf("%d", ans);
	return 0;
}