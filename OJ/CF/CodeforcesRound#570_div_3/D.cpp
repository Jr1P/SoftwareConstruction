#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
#define N 200050

int q, n;
int a[N], fail[N];
bool f[N];
stack <int > s;

int main()
{
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		//memset(f, false, sizeof(f));
		int id, ans = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &id);
			a[id]++;
		}
		sort(a+1, a+1+n);
		for(int i = 1; i <= a[n]; i++)
			fail[i] = i;
		for(int i = 1; i <= n; i++)
			if(a[i] && fail[a[i]])
			{
				ans += fail[a[i]];
				fail[a[i]] = fail[a[i]-1];
				
			}
		printf("%d\n", ans);
	}
	return 0;
}