#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 60

int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

struct node {
	int x, y, z;
};

int a, b, c, tim, t;
int map[N][N][N];
bool vis[N][N][N];
int ans[N][N][N];

bool check(int x, int y, int z) {
	if(x >= 0 && x < a && y >= 0 && y < b && z >= 0 && z < c && !map[x][y][z])
		return true;
	else
		return false;
}

void bfs(int x, int y, int z) {
	queue<node > q;
	while(!q.empty()) q.pop();
	node now;
	now.x = x; now.y = y; now.z = z;
	q.push(now);
	ans[now.x][now.y][now.z] = 0;
	while(!q.empty()) {
		node tmp;
		now = q.front();
		vis[now.x][now.y][now.z] = 1;
		q.pop();
		for(int i = 0; i < 6; i++){
			tmp.x = now.x+dx[i];
			tmp.y = now.y+dy[i]; 
			tmp.z = now.z+dz[i];
			if(check(tmp.x, tmp.y, tmp.z) && !vis[tmp.x][tmp.y][tmp.z]) {
				q.push(tmp);
				vis[tmp.x][tmp.y][tmp.z] = 1;
				ans[tmp.x][tmp.y][tmp.z] = ans[now.x][now.y][now.z] + 1;
			}
			if(tmp.x == a-1 && tmp.y == b-1 && tmp.z == c-1)
				return ;
		}
	}
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d%d", &a, &b, &c, &tim);
		for(int i = 0; i < a; i++) 
			for(int j = 0; j < b; j++)
				for(int k = 0; k < c; k++) {
					ans[i][j][k] = 0;
					vis[i][j][k] = 0; 
					scanf("%d", &map[i][j][k]);
				}
		bfs(0, 0, 0);
		if(ans[a-1][b-1][c-1] > tim || ans[a-1][b-1][c-1] == 0)
			printf("-1\n");
		else printf("%d\n", ans[a-1][b-1][c-1]);
	}
	return 0;
}