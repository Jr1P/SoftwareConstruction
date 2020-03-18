#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
const int MAXN = 405;
const int xx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int yy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int step[MAXN][MAXN], n, m, x0, y0;
bool exist[MAXN][MAXN];

struct node
{
	int x, y;
};

queue<node> q;

void init()
{
	memset(step, -1, sizeof(step));
	memset(exist, false, sizeof(exist));
}

void bfs()
{
	node temp;
	while (!q.empty())
	{
		int x = q.front().x, y = q.front().y;
		q.pop();
		exist[x][y] = 1;
		for (int i = 0; i < 8; i++)
		{
			temp.x = x+xx[i];
			temp.y = y+yy[i];
			if ((temp.x <= n) && (temp.y <= m) && (temp.x > 0) && (temp.y > 0) && !exist[temp.x][temp.y])
			{
				exist[temp.x][temp.y] = 1;
				step[temp.x][temp.y] = step[x][y]+1;
				q.push(temp);
			}
		}
	}
}

int main()
{
	node temp;
	init();
	ios::sync_with_stdio(false);
	cin >> n >> m >> x0 >> y0;
	step[x0][y0] = 0;
	temp.x = x0;
	temp.y = y0;
	q.push(temp);
	bfs();
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < m; j++)
			cout << setw(5) << left << step[i][j];
		cout << step[i][m] << '\n';
	}
	return 0;
}