#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define N 510

int n, m;
int a[N][N], b[N][N], da[N<<1][N], db[N<<1][N]; //da 为a的对角线
vector<int > va[N<<1], vb[N<<1];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            va[i+j-1].push_back(a[i][j]);
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &b[i][j]);
            vb[i+j-1].push_back(b[i][j]);
        }
    for(int i = 1; i < n+m+1; i++)
    {
        sort(va[i].begin(), va[i].end());
        sort(vb[i].begin(), vb[i].end());
        for(int j = 0; j < va[i].size(); j++)
            if(va[i][j] != vb[i][j])
            {
                printf("NO\n");
                return 0;
            }
    }
    printf("YES\n");
    // for(int i = 1; i <= n; i++)
    //     for(int j = 1; j <= i && j <= m; j++)
    //     {
    //         da[i][j] = a[j][i-j+1];
    //         db[i][j] = b[j][i-j+1];
    //     }
    // for(int i = n+1; i < n+m; i++)
    //     for(int j = 1; j <= n+m-i; j++)
    //     {
    //         da[i][j] = a[n+n-i+1][j+1];
    //         db[i][j] = b[n+n-i+1][j+1];
    //     }
    // for(int i = 2; i <= n; i++)
    // {
    //     sort(da[i]+1, da[i]+i);
    //     sort(db[i]+1, db[i]+i);
    // }
    // for(int i = n+1; i < n+m-1; i++)
    // {
    //     sort()
    // }
    return 0;
}
