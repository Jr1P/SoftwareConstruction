#include <cstdio>
#include <cstring>
#include <queue>
const int N = 20;
const int K = 10;

struct Node {
    int x, y;
    int key;
    int dis;
};

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

char map[N][N];
bool vis[N][N][1 << K];
int n, m, t, sx, sy, ex, ey;

std::queue<Node > q;

inline bool check(int x, int y, int key) {
    bool b = x >= 0 && x < n && y >= 0 && y < m && map[x][y] != '*' && !vis[x][y][key];
    if(!b) return false;
    if(map[x][y] <= 'J' && map[x][y] >= 'A')
        if((key & (1 << (map[x][y] - 'A'))) == 0) return false;
    return true;
}

int bfs() {
    while(!q.empty()) q.pop();
    q.push((Node){sx, sy, 0, 0});
    vis[sx][sy][0] = true;
    while(!q.empty()) {
        Node now = q.front(); q.pop();
        if(now.dis >= t) return -1;
        if(now.x == ex && now.y == ey) return now.dis;
        for(int i = 0; i < 4; i++) {
            int x = now.x + dx[i], y = now.y + dy[i], kk = now.key;
            if(check(x, y, kk)) {
                if(map[x][y] >= 'a' && map[x][y] <= 'j')
                    kk = kk | (1 << (map[x][y] - 'a'));
                q.push((Node{x, y, kk, now.dis + 1}));
                vis[x][y][kk] = true;
            }
        }
    }
    return -1;
}

int main() {
    while(~scanf("%d%d%d", &n, &m, &t)) {
        for(int i = 0; i < n; i++) {
            scanf("%s", map[i]);
            for(int j = 0; map[i][j]; j++)
                if(map[i][j] == '@')
                    sx = i, sy = j;
                else if(map[i][j] == '^')
                    ex = i, ey = j;
        }
        memset(vis, 0, sizeof(vis));
        int ans = bfs();
        printf("%d\n", ans);
    }

    return 0;
}