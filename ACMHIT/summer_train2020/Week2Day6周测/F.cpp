#include <cstdio>
const int N = 55;
const int M = 1e6+5;
// const int dir[4] = {} 上右下左 0 1 2 3
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int map[N][N];
int n, m, sx, sy, ex, ey;
bool vis[N][N][4];

struct Node {
    int x, y, dir, dis;
    Node() {}
    Node(int x, int y, int dir, int dis) : x(x), y(y), dir(dir), dis(dis) {}
} q[M];

inline bool check(int x, int y) {
    return x > 0 && x < n && y > 0 && y < m;
}

int bfs(int x, int y, int dir) {
    int head = 0, tail = 0;
    q[tail++] = Node(x, y, dir, 0);
    vis[x][y][dir] = 1;
    while(head != tail) {
        Node now = q[head++];
        if(now.x == ex && now.y == ey) return now.dis;
        for(int i = 0; i < 3; i++) { // move
            int tx = now.x+(i+1)*dx[now.dir], ty = now.y+(i+1)*dy[now.dir], tdir = now.dir;
            if(check(tx, ty) && !vis[tx][ty][tdir] && !map[tx][ty]) {
                vis[tx][ty][tdir] = 1;
                q[tail++] = Node(tx, ty, tdir, now.dis+1);
            }
            if(check(tx, ty) && map[tx][ty]) break;
        }
        // turn
        int tdir = (now.dir+1)%4;
        if(!vis[now.x][now.y][tdir]) {
            vis[now.x][now.y][tdir] = 1;
            q[tail++] = Node(now.x, now.y, tdir, now.dis+1);
        }
        tdir = (now.dir-1+4)%4;
        if(!vis[now.x][now.y][tdir]) {
            vis[now.x][now.y][tdir] = 1;
            q[tail++] = Node(now.x, now.y, tdir, now.dis+1);
        }
    }
    return -1;
}

int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                scanf("%d", &map[i][j]);
                if(map[i][j]) map[i-1][j] = map[i][j-1] = map[i-1][j-1] = 1;
            }
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                for(int k = 0; k < 4; k++)
                    vis[i][j][k] = false;
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        char ch[10];
        int dir;
        scanf("%s", ch);
        switch (ch[0]) {
        case 's': dir = 2; break;
        case 'w': dir = 3; break;
        case 'e': dir = 1; break;
        default: dir = 0; break;
        }
        if(!check(ex, ey) || map[ex][ey]) {
            puts("-1");
            continue;
        }
        int ans = bfs(sx, sy, dir);
        if(ans != -1) printf("%d\n", ans);
        else puts("-1");
    }
    return 0;
}