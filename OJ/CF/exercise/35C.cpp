#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define N 2010
#define K 10
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

struct node
{
    int x, y;
}ans;

int n, m, k; // n-rows, m-trees
int col[N][N];
bool vis[N][N];

void bfs(int x, int y)
{
    queue<node> q;
    node temp;
    temp.x = x; temp.y = y;
    q.push(temp);
    vis[x][y] = true;
    col[x][y] = 0;
    while(!q.empty())
    {
        node now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int tmpx = now.x+dx[i], tmpy = now.y+dy[i];
            if(!vis[tmpx][tmpy] && tmpx > 0 && tmpy > 0 && tmpx <= n && tmpy <= m && (col[tmpx][tmpy] == 0 || col[tmpx][tmpy] > col[now.x][now.y]+1))
            {
                temp.x = tmpx, temp.y = tmpy;
                q.push(temp);
                vis[tmpx][tmpy] = true;
                col[tmpx][tmpy] = col[now.x][now.y]+1;
            }
        }
    }
    col[x][y] = -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int d = 0;
    scanf("%d", &k);
    while(k--)
    {
        int x0, y0;
        scanf("%d%d", &x0, &y0);
        memset(vis, false, sizeof(vis));
        bfs(x0, y0);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if (col[i][j] > d)
            {
                d = col[i][j];
                ans.x = i;
                ans.y = j;
            }
    printf("%d %d\n", ans.x, ans.y);
    return 0;
}
