#include <cstdio>
#include <cstring>
const int N = 366;
const int STATE = 2500;
const int POS = 9;
const int D = 7;
const int dx[] = {-1, -2, 0, 0, 1, 2, 0, 0, 0};
const int dy[] = {0, 0, 1, 2, 0, 0, -1, -2, 0};
const int ds[] = {-1, -2, -3, -6, 3, 6, 1, 2, 0};

int n;
char map[N][4][4], mem[N][POS][STATE];
int sta[D][D][D][D];
bool vis[N][POS][STATE], f;

inline bool check(int x, int y, int day) {
    return x >= 0 && x < 3 && y >= 0 && y < 3 && !map[day][x+1][y+1] &&
    !map[day][x][y] && !map[day][x+1][y] && !map[day][x][y+1];
}

bool dfs(int day, int pos, int lu=1, int ru=1, int ld=1, int rd=1) {
    if(day == n-1) return true;
    if(vis[day][pos][sta[lu][ru][ld][rd]]) return false;
    for(int i = 0; i < POS; i++) {
        int x = pos%3+dx[i], y = pos/3+dy[i], npos = x+3*y;
        if(check(x, y, day+1)) {
            int p1=lu+1, p2=ru+1, p3=ld+1, p4=rd+1;
            switch (npos) {
            case 0: p1 = 0; break;
            case 2: p3 = 0; break;
            case 6: p2 = 0; break;
            case 8: p4 = 0; break;
            default: break;
            }
            if(p1 > 6 || p2 > 6 || p3 > 6 || p4 > 6) continue;
            if(!vis[day+1][npos][sta[p1][p2][p3][p4]]) {
                if(dfs(day+1, npos, p1, p2, p3, p4)) return true;
                vis[day+1][npos][sta[p1][p2][p3][p4]] = 1;
            }
        }
    }
    return false;
}

int main() {
    for(int i = 0; i < D; i++)
        for(int j = 0; j < D; j++)
            for(int k = 0; k < D; k++)
                for(int l = 0; l < D; l++)
                    sta[i][j][k][l] = ((((i*D)+j)*D)+k)*D+l;
    while(~scanf("%d", &n) && n) {
        f = false;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 16; j++) {
                int a;
                scanf("%d", &a);
                map[i][j/4][j%4] = a;
            }
        if(map[0][1][1] || map[0][1][2] || map[0][2][1] || map[0][2][2]) {
            puts("0");
            continue;
        }
        for(int i = 0; i < n; i++) 
            memset(mem[i], 0, sizeof(mem[i])),
            memset(vis[i], 0, sizeof(vis[i]));
        vis[0][4][0] = 1;
        if(dfs(0, 4)) puts("1");
        else puts("0");
    }
    return 0;
}