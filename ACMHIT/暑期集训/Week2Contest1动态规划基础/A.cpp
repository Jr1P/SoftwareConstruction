#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000050

int n, m, mm = N, ans;
int num[N];
int dp[N][3][3];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        //if(a < mm) mm = a;
        num[a]++;
    }
    dp[0][0][0] = 0;
    for(int i = 1; i <= m; i++)
        for(int l = 0; l <= 2; l++)
            for(int j = 0; j <= 2; j++)
                for(int k = 0; k <= 2 && l+j+k <= num[i]; k++)
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][l][j]+k+(num[i]-j-k-l)/3);
    printf("%d\n", dp[m][0][0]);
    return 0;
}