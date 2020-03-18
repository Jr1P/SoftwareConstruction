#include <cstdio>
#define N 100
const int M = 650050;

int n, d, c, sum = 0;
bool dp[M];

int main()
{
	dp[0] = true;
	scanf("%d%d", &n, &d);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &c);
		sum += c;
		for(int j = sum; j >= c; j--)
			if(dp[j-c]) dp[j] = true;
	}
	int day = 0, o = 0, pp;
	while(1) {
		o += d;
		pp = d;
		for(int i = 0; i < d; i++) {
			if(dp[o-i]){
				pp = i;
				day++;
				break;
			}
		}
		if(pp == d)
			break;
		o -= pp;
	}
	o -= d; // 
	printf("%d %d\n", o, day);
	return 0;
}