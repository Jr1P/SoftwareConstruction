#include <cstdio>
#include <cstring>
const int N = 1e5+1;

typedef long long ll;
ll a[110],b[110];
int main()
{
	int n, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&b[i]);
		}
		ll tmp=0,flag=1;
		for(int i=n;i>=1;i--){
			if(b[i]<a[i]){
				if(b[i]+tmp<a[i]){
					flag=0;
					break;
				}
				else
					tmp-=(a[i]-b[i]);
			}
			else{
				tmp+=b[i]-a[i];
			}
		}
		if(flag){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}