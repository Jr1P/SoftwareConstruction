#include<cstdio>
int T;
int a[100010];
int main()
{
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int m=-1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(m<a[i]) m=a[i];
		}
		int tot=0;
		for(int i=1;i<=n;i++){
			tot+=m-a[i];
		}
		int flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]-(tot-(m-a[i]))<1){
				flag=0;
				break;
			}
		}
		if(flag){
			printf("%d\n",tot);
		}else{
			printf("-1\n");
		}
	}
}