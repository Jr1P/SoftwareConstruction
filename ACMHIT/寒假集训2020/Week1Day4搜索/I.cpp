#include <cstdio>
#include <queue>
#include <cstring>
#define N 15

struct Node {
    int x, y, tim, dire;
    Node() {}
    Node(int _x, int _y, int _tim, int _dire) : x(_x), y(_y), tim(_tim), dire(_dire) {}
}door[5];

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

std::queue<Node > q;

int n, m;
int cnt[5];
char map[N][N];
bool exist[N][N], erased;

inline bool check(int x, int y, char ch) {
    if(!exist[x][y] && map[x][y] == '*') return true;
    if(x < 0 || x > n || y < 0 || y > m || exist[x][y] || map[x][y] != ch) return false;
    return true;
}

void bfs(int x, int y, char ch) {
    while(!q.empty()) q.pop();
    q.push(Node(x, y, -1, -1));
    exist[x][y] = true;
    while(!q.empty()) {
        Node now = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + now.x, ny = dy[i] + now.y;
            if(check(nx, ny, ch)) {
                int time = now.tim;
                if(i != now.dire) time++;
                if(time > 2) continue;
                if(map[nx][ny] == ch) {
                    cnt[ch - 'A'] -= 2;
                    map[x][y] = map[nx][ny] = '*';
                    erased = true;
                    return ;
                }
                q.push(Node(nx, ny, time, i));
                exist[nx][ny] = true;
            }
        }
    }
}

int main() {
    while(1) {
        bool f = false;
        scanf("%d%d", &n, &m);
        if(n == 0) break;
        memset(map, 0, sizeof(map));
        for(int i = 0; i < 5; i++)
            cnt[i] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%s", map[i] + 1);
            map[i][0] = map[i][m + 1] = '*';
        }
        for(int i = 0; i <= m + 1; i++) map[0][i] = map[n + 1][i] = '*';
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                char c = map[i][j];
                if(c >= 'A' && c <= 'E') {
                    cnt[c - 'A']++;
                }
            }
        for(int i = 0; i < 5; i++)
            if(cnt[i] % 2) {
                puts("no");
                f = true;
                break;
            }
        if(f) continue;
        erased = true;
        while(erased) {
            erased = false;
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++) {
                    if(map[i][j] >= 'A' && map[i][j] <= 'E') {
                        memset(exist, false, sizeof(exist));
                        bfs(i, j, map[i][j]);
                    }
                }
        }
        bool fa = false;
        for(int i = 0; i < 5; i++)
            if(cnt[i]) {
                fa = true;
                puts("no");
                break;
            }
        if(!fa) puts("yes");
    }
    return 0;
}