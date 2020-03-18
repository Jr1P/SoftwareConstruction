
#include <stdio.h>
using namespace std;
const int MAXN = 1000005;

int main()
{
	short num[MAXN];
	int N, T;
	long long sub_num = 0, max_sum; 
	bool flag; //0-
	scanf("%d", &T);
	for(int i = 1; i < T + 1; i++)
	{
		scanf("%d", &N);
		max_sum = 0;
		flag = 0;
		sub_num = 0;
		for(int j = 0; j < N; j++)
		{
			scanf("%hd", &num[j]);
			if (num[j] > 0)
			{
				max_sum += num[j];
				flag = 1;
			}
			else if (num[j] < 0)
			{
				if (flag)
				{
					sub_num++;
					flag = 0;
				}
				else
					continue;
			}
		}
		if (flag)
			sub_num++;
		printf("Case %d:\n", i);
		printf("%lld %lld\n", sub_num, max_sum);
		if (i != T)
			printf("\n");
	}
	return 0;
}