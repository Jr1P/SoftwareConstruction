#include<stdio.h>

int s = 1,d = 1;//s is initial time; d is the coin type
int time[60];
int dfs(int cc, int depth){
	if(cc == 0) return depth;
	if((depth > 1 && cc == s) /*|| (depth > 500)*/) return -1;
	cc += cc * d;
	cc %= 60; 
	dfs(cc,depth + 1);
}
int main(){
	int current,ans;
	while(s != 0 || d != 0){
		scanf("%d %d\n",&s,&d);
		if(s == 0 && d == 0) return 0;
		current = s;
		ans = dfs(current,0);
		if(ans== -1) printf("Impossible");
		else printf("%d\n",ans);
	}
	return 0;
} 
