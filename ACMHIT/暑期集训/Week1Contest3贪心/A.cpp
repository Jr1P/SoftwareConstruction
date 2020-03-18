#include <cstdio>
#include <cmath>
#include<algorithm>
using namespace std;
#define N 20000
const double D = 4.5;

int n;
double tim[N];

struct RR
{
	double v, tim;
}st[N];

bool cmp(RR a, RR b){
	return a.v < b.v;
}


int main()
{
	while(1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		for(int i = 1; i <= n; i++)
		{
			scanf("%lf%lf", &st[i].v, &st[i].tim);
			tim[i] = D*3600.0/st[i].v+st[i].tim;
			if(st[i].tim < 0)
				tim[i] = 10000000000.00;
		}
		sort(tim+1, tim+n+1);

		int ans = ceil(tim[1]);
		printf("%d\n", ans);
	}
	return 0;
}