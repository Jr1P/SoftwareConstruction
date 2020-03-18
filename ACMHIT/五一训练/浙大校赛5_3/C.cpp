#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int K = 1e6;
const int N = 670;

typedef long long ll;

char grid[N][N];
char s[250];

inline int calc(int i, int j)
{
	return (3 * (grid[i][j]-48) + (grid[i-1][j] - 48)) * 27 + (3 * (grid[i + 1][j]-48) + (grid[i][j - 1]-48)) * 3 + grid[i][j + 1]-48;
}

int main()
{
	ios::sync_with_stdio(false);
	int t, n, m, cnt, a, b;
	ll k;
	scanf("%d", &t);
	while (t--)
	{
		//bool vis[N][N];
		int tot = 0;
		scanf("%d%d", &n, &m);
		scanf("%d%d%lld", &a, &b, &k);
		scanf("%s", s);
		getchar();
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j) {
				char c = getchar();
				grid[i][j] = c;
				if(c == '2')
					tot++;
			}
			getchar();
		}
		int x = a, y = b;
		char c = '3';
		cnt = 0;
		//memset(vis,0,sizeof(vis));
		for (int i = 1; i <= k && i <= K; i++)
		{
			c = s[calc(x, y)];
			if (c == 'U')
			{
				if (grid[x - 1][y] == '1')//||vis[x-1][y])
					break;
				else{
					//vis[x-1][y]=1;
					x -= 1;
				}
			}
			else if (c == 'D')
			{
				if (grid[x + 1][y] == '1')//||vis[x+1][y])
					break;
				else{
					//vis[x+1][y]=1;
					x += 1;
				}
			}
			else if (c == 'L')
			{
				if (grid[x][y - 1] == '1')//||vis[x][y-1])
					break;
				else{
					//vis[x][y-1]=1;
					y -= 1;
				}
			}
			else if (c == 'R')
			{
				if (grid[x][y + 1] == '1')//||vis[x][y+1])
					break;
				else{
					//vis[x][y+1]=1;
					y += 1;
				}
			}
			else if (c == 'I')
				break;
			else //'P'
			{
				if (grid[x][y] == '2')
				{
					cnt++;
					if(cnt==tot){
						break;
					}
					grid[x][y] = '0';
					//memset(vis,0,sizeof(vis));
				}else{
					break;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}