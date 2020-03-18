#include <cstdio>

int f[15];

int main()
{
	double e = 0;
	printf("n e\n- -----------\n");
	f[0] = 1;
	for(int i = 1; i < 10; ++i)
		f[i] = f[i-1]*i;

	for(int i = 0; i < 10; ++i)
	{
		e += ((double)1)/(double)f[i];
		printf("%d %lf\n", i, e);
	}
	return 0;
}