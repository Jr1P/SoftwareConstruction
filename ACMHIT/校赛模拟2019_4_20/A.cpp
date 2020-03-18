#include <cstdio>
const int MAXN = 100000+5;
typedef long long ll;
const char f[] = "front";
const char both[] = "both";
const char ba[] = "back";
const char none[] = "none";

int n, t, l[MAXN], g[MAXN];
bool f1 = true, f2 = true;

inline void init()
{
	for(int i = 1; i <= n; i++)
		scanf("%d", &l[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &g[i]);
}

void work()
{
	f1 = true, f2 = true;
	for (int i = 1; i <= n; i++)
	{
		if(l[i] > g[i])
			f1 = false;
		if(l[i] > g[n-i+1])
			f2 = false;
	}
}


int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		init();
		work();
		if (f1 && f2)
			printf("%s\n", both);
		else if (f1 && !f2)
			printf("%s\n", f);
		else if (!f1 && f2)
			printf("%s\n", ba);
		else
			printf("%s\n", none);
	}

	return 0;
}