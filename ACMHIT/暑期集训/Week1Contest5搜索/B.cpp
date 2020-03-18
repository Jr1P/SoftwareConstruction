#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define N 30

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct node {
	int x, y;
};

int n, m, sx, sy, ex, ey;
char map[N][N];
int key[5], ge[5], doorx[5], doory[5];
bool vis[N][N], f, open[5], ff, pas[5];
queue<node > q;

inline bool check(int x, int y) {
	if(x > 0 && x <= n && y >= 0 && y < m && map[x][y] != 'X')
		return true;
	return false;
}

void bfs(int x, int y) {
	while(!q.empty())
		q.pop();
	node now;
	now.x = x; now.y = y;
	q.push(now);
	vis[now.x][now.y] = 1;
	while(!q.empty()) {
		now = q.front();
		q.pop();
		if(now.x == ex && now.y == ey) {
			printf("YES\n");
			ff = true;
			break;
		}
		node tmp;
		for(int i = 0; i < 4; i++) {
			tmp.x = now.x+dx[i];
			tmp.y = now.y+dy[i];
			if(check(tmp.x, tmp.y)) {
				if (map[tmp.x][tmp.y] >= 'A' && map[tmp.x][tmp.y] <= 'E')
					pas[map[tmp.x][tmp.y]-'A'] = true;
				else if(!vis[tmp.x][tmp.y]) {
					q.push(tmp);
					vis[tmp.x][tmp.y] = 1;
					if(map[tmp.x][tmp.y] >= 'a' && map[tmp.x][tmp.y] <= 'e')
						ge[map[tmp.x][tmp.y]-'a']++;
				}
			}
		}
	} 
}

int main()
{
	while(1) {
		scanf("%d%d", &n, &m);
		if(n == 0)
			break;
		for(int i = 0; i < 5; i++) {
			open[i] = false;
			key[i] = 0;
			pas[i] = false;
			ge[i] = 0;
			doorx[i] = doory[i] = 0;
		}
		for(int i = 1; i <= n; i++)
			scanf("%s", map[i]);
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < m; j++) {
				vis[i][j] = 0;
				char ch = map[i][j];
				if(ch >= 'a' && ch <= 'e')
					key[ch-'a']++;
				else if(ch == 'S')
					sx = i, sy = j;
				else if(ch == 'G')
					ex = i, ey = j;
				else if(ch >= 'A' && ch <= 'E')
					doorx[ch-'A'] = i, doory[ch-'A'] = j;
			}
		ff = false;
		bfs(sx, sy);
		f = true;
		while(f && !ff) {
			for(int i = 0; i < 5; i++) {
				f = false;
				if(!open[i] && pas[i] && ge[i] == key[i] && key[i]) {
					f = true; open[i] = true;
					bfs(doorx[i], doory[i]);
				}
			}
		}
		if(!ff)
			printf("NO\n");
	}
	return 0;
}