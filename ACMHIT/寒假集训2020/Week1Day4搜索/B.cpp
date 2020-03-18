#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#define N 1050

struct Node {
	int x, y;
};

int n, m, t, tim, ans1 = 0, ans2 = 0;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int map[N][N];
bool vis[N][N], flag, fflag;

bool check(int x, int y) {
	if(x > 0 && x <= n && y > 0 && y <= n)
		return true;
	return false;
}

void bfs(int x, int y) {
	std::queue<Node > q;
	Node now;
	now.x = x; now.y = y;
	q.push(now);
	while(!q.empty()) {
		Node tmp;
		now = q.front();
		vis[now.x][now.y] = 1;
		q.pop();
		for(int i = 0; i < 8; i++){
			tmp.x = now.x + dx[i];
			tmp.y = now.y + dy[i];
			if(check(tmp.x, tmp.y) && map[now.x][now.y] < map[tmp.x][tmp.y])
				fflag = 0;
			if(check(tmp.x, tmp.y) && !vis[tmp.x][tmp.y]) {
				if(map[now.x][now.y] == map[tmp.x][tmp.y]) {
					q.push(tmp);
					vis[tmp.x][tmp.y] = 1;
				}
			}
		}
	}
}

void bfs2(int x, int y) {
	std::queue<Node > q;
	Node now;
	now.x = x; now.y = y;
	q.push(now);
	while(!q.empty()) {
		Node tmp;
		now = q.front();
		vis[now.x][now.y] = 1;
		q.pop();
		for(int i = 0; i < 8; i++){
			tmp.x = now.x+dx[i];
			tmp.y = now.y+dy[i];
			if(check(tmp.x, tmp.y) && map[now.x][now.y] > map[tmp.x][tmp.y])
				fflag = 1;
			if(check(tmp.x, tmp.y) && !vis[tmp.x][tmp.y]) {
				if(map[now.x][now.y] == map[tmp.x][tmp.y]) {
					q.push(tmp);
					vis[tmp.x][tmp.y] = 1;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			if (!vis[i][j]) {
				fflag = 1;
				bfs(i, j);
				if(fflag == 1)
					ans1++;
			}
		}
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			if (!vis[i][j]) {
				fflag = 0;
				bfs2(i, j);
				if(fflag == 0)
					ans2++;
			}
		}
	printf("%d %d\n", ans1, ans2);
	return 0;
}