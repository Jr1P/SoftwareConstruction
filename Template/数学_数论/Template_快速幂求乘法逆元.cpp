#include<cstdio>
#define N 300030
//lg_3811,快速幂求乘法逆元,求单个数乘法逆元复杂度为logn
//快速幂会T
typedef long long ll;

ll n, p;

ll quickP(ll a, ll b)
{
	ll ans = 1;
	while(b)
	{
		if (b&1) ans = ans*a%p;
		a = a*a%p;
		b >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%lld%lld", &n, &p);
	printf("1\n");
	for(int i = 2; i <= n; i++)
		printf("%lld\n", quickP(i, p-2)); // 求[1, n]区间内所有整数的乘法逆元
	return 0;
}