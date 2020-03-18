#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define NM 100050

struct Node {
    int x, y;
};

int n, m;
int depth[NM];
bool vis[NM];
string mp[NM];

const int dx[2] = {0, 1};
const int dy[2] = {1, 0};

inline int min(int x, int y) {
    return x < y ? x : y;
}

inline int calc(int x, int y) {
    return (x-1)*m+y;
}

queue<Node> q;

void bfs(int x, int y) {
    while(!q.empty()) q.pop();
    Node u;
    u.x = x; u.y = y;
    q.push(u);
    vis[calc(x, y)] = 1;
    depth[calc(x, y)] = 0;
    while(!q.empty()) {
        Node now = q.front();
        q.pop();
        for(int i = 0; i < 2; i++) {
            Node tmp;
            tmp.x = now.x+dx[i];
            tmp.y = now.y+dy[i];
            if(tmp.x > n || tmp.y > m || tmp.x <= 0 || tmp.y <= 0)
                continue;
            if(mp[tmp.x][tmp.y-1] == '#') {
                vis[calc(tmp.x, tmp.y)] = 1;
                continue;
            }
            depth[calc(tmp.x, tmp.y)] = depth[calc(now.x, now.y)]+1;
            q.push(tmp);
            vis[calc(tmp.x, tmp.y)] = 1;
        }
    }
}
 

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        cin >> mp[i];
    int ans = 2;
    bfs(1, 1);
    for(int i = 2; i < n+m-1; i++) {
        int x, y, cnt = 0, cntf = 0;
        if(i <= n) {
            x = i, y = 1;
            while(x >= 1 && y <= m) {
                if(mp[x][y-1] == '#')
                    cntf++;
                if(vis[calc(x, y)]) cnt++;
                x--, y++;
            }
        } else {
            x = n; y = i-n+1;
            while(x >= 1 && y <= m) {
                if(mp[x][y-1] == '#')
                    cntf++;
                cnt++;
                x--, y++;
            }
        }
        ans = min(ans, cnt-cntf);
        if(!ans) break;
    }
    printf("%d\n", ans);
    return 0;
}