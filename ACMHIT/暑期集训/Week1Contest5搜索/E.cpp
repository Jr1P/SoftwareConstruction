#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define N 1030

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

struct node{
	int x, y;
};

int n, m, t, sx, sy, ex, ey;
char map[N][N];
int ans[N][N];
bool vis[N][N];

inline bool check(int x, int y) {
	if(x > 0 && x <= n && y >= 0 && y < n)
		return true;
	return false;
}

void bfs(int x, int y) {
	queue<node > q;
	node now;
	now.x = x; now.y = y;
	q.push(now);
	while(!q.empty()) {
		now = q.front();
		q.pop();
		node tmp;
		for(int i = 0; i < 4; i++) {
			tmp.x = now.x+dx[i];
			tmp.y = now.y+dy[i];
			if(check(tmp.x, tmp.y))
		}
	} 
}

int main() {
	while(1) {
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0)
			break;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				ans[i][j] = 0;
				vis[i][j] = 0;
				scanf("%s", map[i]);
			}
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		bfs(sx, sy);
	}
	return 0;
}