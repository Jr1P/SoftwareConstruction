#include<cstdio>
#define ll long long
int main()
{
	int T;
	scanf("%d",&T);
	ll n;
	while(T--){
		ll x,y;
		scanf("%lld",&n);
		if(n==1){
			x=20;
			y=21;
		}else{
			x=2*n;
			y=3*n;
		}
		printf("%lld %lld\n",x,y);
	}
}