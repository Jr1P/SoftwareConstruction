#include<stdio.h>
const int MAXN = 1000000000;

int main(){
	int T, N, now = 5, ans = 0;
	scanf("%d\n",&T);
	for(int i = 0; i < T; i++){
		scanf("%d\n",&N);
		now = 5;
		while(now <= N){
			ans += N / now;
			now *= 5;
		}
		printf("%d\n",ans);
		ans = 0;
	}
	return 0;
} 
