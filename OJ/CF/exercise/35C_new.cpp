#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct point
{
    int x, y;
} pt[11];
const int maxn = 2500;
int mp[maxn][maxn];

inline int min(int x, int y)
{return x<y?x:y;}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m, k;
    cin >> n >> m >>k;
    for(int i = 1; i <= k ; i++)
        cin >> pt[i].x >> pt[i].y;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            mp[i][j] = 1e6;

    for(int l = 1 ; l <= k ; l++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
            {
                int _x = abs(i - pt[l].x);
                int _y = abs(j - pt[l].y);
                mp[i][j] = min(_x+_y, mp[i][j]);
            }
    int ans = INT_MIN;
    int ans_x, ans_y;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1; j <= m ; j++)
            if(ans < mp[i][j])
            {
                ans = mp[i][j];
                ans_x = i;
                ans_y = j;
            }
    cout << ans_x << " " << ans_y << endl;
    return 0;
}
