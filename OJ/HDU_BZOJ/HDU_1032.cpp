#include <cstdio>
const int MAXN = 1e7;
short f[MAXN];

short work(int x)
{
	short len = 0;
	while(x != 1)
	{
		if(x < MAXN && f[x]) return len+f[x];
		else if (x&1)
			x = x+(x<<1|1);
		else
			x >>= 1;
		len++;
	}
	return ++len;
}

int main()
{
	int l, r;
	while(scanf("%d%d", &l, &r) != EOF)
	{
		int max = 0;
		int ll, rr;
		if (l > r)
		{
			rr = l;
			ll = r;
		}
		else
		{
			rr = r;
			ll = l;
		}
		for(int i = ll; i <= rr; i++)
		{
			f[i] = work(i);
			if (max < f[i])
				max = f[i];
		}
		printf("%d %d %d\n", l, r, max);
	}
	return 0;
}