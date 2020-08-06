#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstdlib>
const int N = 60;

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

struct Node {
	int x, y, z, dis;
};

int a, b, c, tim, t;
int map[N][N][N];
bool vis[N][N][N];

inline bool check(int x, int y, int z) {
	return (x >= 0 && x < a && y >= 0 && y < b && z >= 0 && z < c && !map[x][y][z]);
}

int bfs(int x, int y, int z) {
	std::queue<Node > q;
	while(!q.empty()) q.pop();
	q.push((Node){x, y, z, 0});
	vis[x][y][z] = 1;
	while(!q.empty()) {
		Node now = q.front(); q.pop();
		if(now.x == a - 1 && now.y == b - 1 && now.z == c - 1) return now.dis;
		if(now.dis > tim) return -1;
		for(int i = 0; i < 6; i++){
			int x = now.x + dx[i], y = now.y + dy[i], z = now.z + dz[i];
			if(check(x, y, z) && !vis[x][y][z]) {
				q.push((Node){x, y, z, now.dis + 1});
				vis[x][y][z] = 1;
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d%d", &a, &b, &c, &tim);
		for(int i = 0; i < a; i++) 
			for(int j = 0; j < b; j++)
				for(int k = 0; k < c; k++) {
					vis[i][j][k] = 0; 
					scanf("%d", &map[i][j][k]);
				}
		printf("%d\n", bfs(0, 0, 0));
	}
	return 0;
}
