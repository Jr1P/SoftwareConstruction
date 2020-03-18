#include <cstdio>
#include <cmath>
const int MAXN = 100000000+1;
int f[25];
//计算fibo[MAXN以内], 起输出数字的前四位即可, 矩阵快速幂

typedef long long ll;
int main()
{
	int n;
	f[0] = 0; f[1] = 1;
	for(int i = 2; i < 20; i++)
		f[i] = f[i-1] + f[i-2];
	while (scanf("%d", &n) != EOF)
	{
		if (n < 20)
			printf("%d\n", f[n]);
		else 
		{
			double s;
			s = log10(1.0/sqrt(5.0)) + n*log10((sqrt(5.0)+1)/2);
			s = s - (int)s;
			s = pow(10, s);
			while (s < 1000)
				s*=10;
			printf("%d\n", (int)s);
		}
	}
	return 0;
}