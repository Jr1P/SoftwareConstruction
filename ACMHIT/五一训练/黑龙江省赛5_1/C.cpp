#include <cstdio>
//max x,y = 1e5 
#define M 1000000007

//WA
typedef long long ll;

int T;
ll x1, y1, x2, y2, ans;

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		ll p1 = 1, p2 = 1, p3 = 1, p4 = 1;
		scanf("%lld%lld%lld%lld", &x1, &x2, &y1, &y2);
		for(int i = 1; i <= x1; i++)
		{
			p1 = (p1*(y1+i)/i)%M;
			p3 = (p3*(y2+i)/i)%M;
		}
		for(int i = 1; i <= x2; i++)
		{
			p2 = (p2*(y2+i)/i)%M;
			p4 = (p4*(y1+i)/i)%M;
		}
		
		printf("%lld\n", ans);
	}
	return 0;
}