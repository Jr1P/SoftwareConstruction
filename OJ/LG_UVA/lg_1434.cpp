#include<iostream>
#include<cstdio>
using namespace std;
#define N 105
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int r, c, t, ans;
int map[N][N], f[N][N];

int search(int x,int y)
{
    int t = 1, tmp;
    if (f[x][y]>0)
        return f[x][y];
    for(int i = 0; i < 4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx > 0 && nx <= r && ny>=1 && ny<=c && map[x][y] < map[nx][ny])
        {
            tmp = search(nx,ny)+1;
            if(tmp > t)
                t = tmp;
        }
    }
    f[x][y] = t;
   return t;
}
int main()
{
    scanf("%d%d", &r, &c);
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            scanf("%d", &map[i][j]);
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
        {
            t = search(i,j);
            f[i][j] = t;
            if(t > ans)
                ans = t;
        }
    printf("%d\n", ans);
    return 0;
    }