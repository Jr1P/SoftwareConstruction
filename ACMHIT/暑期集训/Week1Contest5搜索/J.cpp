#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 60
struct node {
	int x, y;
};

int n, m, t, tim, ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string map[N];
bool vis[N][N];

bool check(int x, int y) {
	if(x > 0 && x <= n && y >= 0 && y < m && (map[x][y] == 'L' || map[x][y] == 'C'))
		return true;
	return false;
}

void bfs(int x, int y) {
	queue<node > q;
	node now;
	now.x = x; now.y = y;
	q.push(now);
	while(!q.empty()) {
		node tmp;
		now = q.front();
		vis[now.x][now.y] = 1;
		q.pop();
		for(int i = 0; i < 4; i++){
			tmp.x = now.x+dx[i];
			tmp.y = now.y+dy[i]; 
			if(check(tmp.x, tmp.y) && !vis[tmp.x][tmp.y]) {
				q.push(tmp);
				vis[tmp.x][tmp.y] = 1;
			}
		}
	}
	
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		cin >> map[i];
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < m; j++) {
			if (map[i][j] == 'L' && !vis[i][j]) {
				ans++;
				bfs(i, j);
			}
		}
	printf("%d\n", ans);
	return 0;
}