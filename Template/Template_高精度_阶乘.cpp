#include<cstdio>
const int MAXN = 10001;
const int MAXW = 100001;

int main(){
	int n, i, j;
	int num[MAXW];
	while (scanf("%d", &n) != EOF)
	{
		int p = 1, add = 0;
		num[1] = 1;
		if(n == 0)
		{
			printf("1\n");
			continue;
		}
		for (i = 2; i < n + 1; i++)
		{
			for (j = 1; j < p + 1; j++)
			{
				num[j] = num[j] * i + add;
				add = num[j] / 10;
				num[j] %= 10;
			}
			while(add > 0)
			{
				num[j] = add % 10;
				add /= 10;
				j++;
			}
			p = j - 1;
			add = 0;
		}
		for (i = p; i > 0; i--)
			printf("%d", num[i]);
		printf("\n");
	}
	return 0;
} 
