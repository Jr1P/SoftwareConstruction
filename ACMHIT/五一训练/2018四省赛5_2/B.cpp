#include <cstdio>
#include <algorithm>
const int MAXN = 100000+1;
const int M = 1e9+7;
using namespace std;

typedef long long ll;

ll x[60], w, c[60];
int n;
bool f;

int main()
{
	//freopen("Bin","r",stdin);


	for(int i = 0; i < 60; ++i)
	{
		c[i] = ((long long)1 << i);
		//printf("%lld ", c[i]);
	}
	while(scanf("%lld", &x[0]) != EOF)
	{
		f = 1;
		ll ans = 0;
		for(int i = 1; i < 60; ++i)
			scanf("%lld", &x[i]);
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
		{
			scanf("%lld", &w);
			for(int j = 59; j >= 0; j--)
				if(w>=c[j]&&x[j]>0)
				{
					ll temp=w/c[j];
					if(temp>x[j])
						temp=x[j];
					w-=temp*c[j];
					x[j]-=temp;
				}
			//printf("%lld\n", w[i]);
			if(w != 0)
				f = 0;
		}
		//sort(w+1, w+n+1, cmp);
		if (!f)
			printf("-1\n");
		else
		{
			for(int i = 0; i < 60; i++)
				ans += (c[i] % M)*(x[i] % M)%M;
			ans %= M;
			printf("%lld\n", ans);
		}
	}
	return 0;
}