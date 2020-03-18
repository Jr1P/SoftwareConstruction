#include <cstdio>
#include <cmath>
#define pi 3.1415926

float M, D, V;
int t;

int main()
{
	scanf("%d", &t);
	int cnt = 0;
	while(t--)
	{
		scanf("%f%f", &M, &D);
		float S;
		S = pow((M*3/(D*pi*4)), 0.6666667)*pi*4;
		printf("Case %d: %.4f\n", ++cnt, S);
	}
	return 0;
}