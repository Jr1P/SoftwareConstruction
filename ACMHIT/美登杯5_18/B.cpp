#include <cstdio>
#include <cstring>
#define N 110
#define SZ 26

int n, cnt = 0;
char c[N][N];
bool exist[SZ][SZ][SZ];

int main()
{
	scanf("%d", &n);
	memset(exist, false, sizeof(exist));
	for(int i = 1; i <= n+1; i++)
		scanf("%s", c[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n-i+1; j++)
			for(int k = 0; k < j; k++)
			{
				int a = c[j][k]-'a';
				int b = c[j+i][k]-'a';
				int d = c[j+i][k+i]-'a';
				if (!exist[a][b][d])
				{
					exist[a][b][d] = true;
					exist[a][d][b] = true;
					exist[b][a][d] = true;
					exist[b][d][a] = true;
					exist[d][a][b] = true;
					exist[d][b][a] = true;
					cnt++;
				}
			}
	for(int i = 1; i <= n/2; i++)
		for(int j = i+1 ; j <= n-i+1; j++)
			for(int k = 0; k < j-i; k++)
			{
				int a = c[j][k]-'a';
				int b = c[j+i][k+i]-'a';
				int d = c[j][k+i]-'a';
				if (!exist[a][b][d])
				{
					exist[a][b][d] = true;
					exist[a][d][b] = true;
					exist[b][a][d] = true;
					exist[b][d][a] = true;
					exist[d][a][b] = true;
					exist[d][b][a] = true;
					cnt++;
				}
			}
	printf("%d\n", cnt);
	return 0;
}