#include <cstdio>
#include <queue>
#define N 25

struct Node {
    int x, y;
    Node() {}
    Node(int _x, int _y) : x(_x), y(_y) {}
}door[5];

std::queue<Node > q;
int n, m, sx, sy, gx, gy;
int cnt[5], keys[5];
char map[N][N];
bool exist[N][N], open[5], f, rec[5];

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

inline bool check(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || exist[x][y] ||
     map[x][y] == 'X')
        return false;
    if((map[x][y] >= 'A' && map[x][y] <= 'E')) {
        rec[map[x][y] - 'A'] = true;
        return false;
    }
    return true;
}

void bfs(int x, int y) {
    while(!q.empty()) q.pop();
    q.push(Node(x, y));
    exist[x][y] = true;
    while(!q.empty()) {
        Node now = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + now.x, ny = dy[i] + now.y;
            if(check(nx, ny)) {
                if(nx == gx && ny == gy) {
                    puts("YES");
                    f = 1;
                    return ;
                }
                if(map[nx][ny] >= 'a' && map[nx][ny] <= 'e')
                    keys[map[nx][ny] - 'a']++;
                q.push(Node(nx, ny));
                exist[nx][ny] = true;
            }
        }
    }
    for(int i = 0; i < 5; i++)
        if(cnt[i] != 0 && cnt[i] == keys[i] && !open[i] && rec[i]) {
            open[i] = true;
            bfs(door[i].x, door[i].y);
            break;
        }
}

int main() {
    while(1) {
        scanf("%d%d", &n, &m);
        f = 0;
        if(n == 0 && m == 0) break;
        for(int i = 0; i < 5; i++)
            rec[i] = keys[i] = cnt[i] = open[i] = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                exist[i][j] = false;
        for(int i = 0; i < n; i++)
            scanf("%s", map[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                char c = map[i][j];
                if(c == 'S')
                    sx = i, sy = j;
                else if(c == 'G')
                    gx = i, gy = j;
                else if(c >= 'a' && c <= 'e')
                    cnt[c - 'a']++;
                else if(c >= 'A' && c <= 'E') {
                    door[c - 'A'].x = i;
                    door[c - 'A'].y = j;
                }
            }
        bfs(sx, sy);
        if(!f) puts("NO");
    }
    return 0;
}