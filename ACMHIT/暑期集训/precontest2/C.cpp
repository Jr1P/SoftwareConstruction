#include<cstdio>
#include<cmath>

int r, t;
double PI = acos(-1.0);

int main()
{

	scanf("%d", &t);
	int cnt = 0;
	while(t--)
	{
		scanf("%d", &r);
		float s = 0.250000f*r*r;
		printf("Case %d: %.4f\n", ++cnt, s);
	}
	return 0;
}