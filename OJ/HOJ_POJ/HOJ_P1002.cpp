#include<stdio.h>

int main(){
	long long a,b,c,ans;
	while(scanf("%I64d %I64d %I64d ",&a,&b,&c) == 3){
		ans = a + b + c; 
		printf("%I64d\n",ans);
	}
	return 0;
}
