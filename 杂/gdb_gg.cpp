/***
* homework1_迷宫
* 1180800916_陶子康
* grid[n][m]为迷宫, 如果grid[i][j] == '.'表示该位置可以走, 为'*'否则不能走
* 数据保证grid[0][0] 和grid[n-1][m-1]为'.', 即入口和出口必然可走
* 第一行输入的最后一个数代表是否手动输入, 等于0时自动生成, 等于1时手动输入
***/
#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 55
#define mem(a, b) memset(a, b, sizeof(a))

int n, m;
char grid[N][N];
bool vis[N][N];

struct Node {
	int x, y;
	Node() {}
	Node(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

Node pre[N][N];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

inline void init() { //初始化
	mem(vis, 0);
	mem(pre, 0);
}

void rand_grid() { //随机生成迷宫
	grid[0][0] = grid[n-1][m-1] = '.';
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if((i == 0 && j == 0) || (i == n-1 && j == m-1))
				continue;
			int q = rand();
			if(q & 0x1)
				grid[i][j] = '.';
			else
				grid[i][j] = '*';
		}
}

inline bool check(int x, int y) {
	if(vis[x][y] || x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '*')
		return false;
	return true;
}

inline void print(int x, int y) { //打印路径
	if(x == 0 && y == 0) {
		printf("(%d,%d)->", x, y);
		return ;
	}
	print(pre[x][y].x, pre[x][y].y);
	if(x == n-1 && y == m-1)
		printf("(%d,%d)\n", x, y);
	else printf("(%d,%d)->", x, y);
}

bool dfs(int x, int y) { //递归求解, 找到一条路径
	vis[x][y] = true;
	if(x == n-1 && y == m-1) {
		print(x, y);
		return true;
	}
	for(int i = 0; i < 8; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(check(nx, ny)) {
			pre[nx][ny].x = x;
			pre[nx][ny].y = y;
			if(!dfs(nx, ny))
				vis[nx][ny] = false;
			else return true;
		}
	}
	return false;
}

bool bfs(int x, int y) { //非递归求解, 找到一条路径
	queue<Node> q;
	while(!q.empty()) q.pop();
	vis[x][y] = true;
	Node now(x, y);
	q.push(now);
	while(!q.empty()) {
		Node tmp = q.front();
		q.pop();
		for(int i = 0; i < 8; i++) {
			now.x = tmp.x+dx[i];
			now.y = tmp.y+dy[i];
			if(check(now.x, now.y)) {
				pre[now.x][now.y].x = tmp.x;
				pre[now.x][now.y].y = tmp.y;
                if(now.x == n-1 && now.y == m-1) {
                    print(now.x, now.y);
                    return true;
                }
				q.push(now);
				vis[now.x][now.y] = true;
			}
		}
	}
    return false;
}

void dfs_all_path(int x, int y) { //非递归求解, 找到所有路径
	vis[x][y] = true;
	if(x == n-1 && y == m-1) {
		print(x, y);
		return ;
	}
	for(int i = 0; i < 8; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(check(nx, ny)) {
			pre[nx][ny].x = x;
			pre[nx][ny].y = y;
			dfs_all_path(nx, ny);
			vis[nx][ny] = false;
		}
	}
}

int depth[N][N];

void bfs_all_shortest_path(int x, int y) { //非递归求解, 找到一条路径
	int shortest_length;
	queue<Node> q;
	while(!q.empty()) q.pop();
	vis[x][y] = true;
	depth[x][y] = 1;
	Node now(x, y);
	q.push(now);
	while(!q.empty()) {
		Node tmp = q.front();
		if(depth[tmp.x][tmp.y] >= shortest_length) return ;
		q.pop();
		for(int i = 0; i < 8; i++) {
			now.x = tmp.x+dx[i];
			now.y = tmp.y+dy[i];
			if(check(now.x, now.y)) {
				pre[now.x][now.y].x = tmp.x;
				pre[now.x][now.y].y = tmp.y;
                if(now.x == n-1 && now.y == m-1) {
                    print(now.x, now.y);
					shortest_length = depth[n-1][m-1];
					continue;
                }
				q.push(now);
				depth[now.x][now.y] = depth[tmp.x][tmp.y]+1;
				vis[now.x][now.y] = true;
			}
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	srand(time(0));
	int way; //迷宫输入方式, 如果way == 1 手动输入, 否则随机生成
	scanf("%d%d%d", &n, &m, &way);
	if(way == 1)  //手动输入时请严格按照输入格式输入, 否则程序将会出错
		for(int i = 0; i < n; i++)
			scanf("%s", grid[i]);
	else rand_grid();
	puts("The maze is shown below:");
	for(int i = 0; i < n; i++)
		printf("%s\n", grid[i]);
	
	init();
	if(!dfs(0, 0)) {
		puts("There is no path from entrance to exit");
		return 0;
	}

	init();
	bfs(0, 0);

	init();
	puts("All pathes:");
	dfs_all_path(0, 0);

	bfs_all_shortest_path(0, 0);

	return 0;
}