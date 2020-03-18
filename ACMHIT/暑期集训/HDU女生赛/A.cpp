#include<cstdio>

#define eps 0

int n;
float a[1050];
float sum = 0;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%f", &a[i]);
		if(sum-100 < eps)
			sum += a[i];
		else if(sum-150 < eps)
			sum += a[i]*0.8;
		else if(sum-400 < eps)
			sum += a[i]*0.5;
		else
			sum += a[i];
	}
	printf("%.2f\n", sum);
	return 0;
}