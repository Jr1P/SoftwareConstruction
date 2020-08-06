#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 12;
typedef long long ll;
/***
 * 横的标记11, 竖的上面标0，下面标1
 * 用dfs预处理出可以接受的上下行转移
 * 枚举时枚举预处理出的上下行可转移状态进行转移
 * 最后的答案是 dp[n][(1 << m) - 1]，因为不管怎么填格子，最后的状态都是11...11
 * */

int n, m, cnt, state[1 << 16][2];
ll dp[N][1 << N];

void dfs(int col, int pre, int suc) {
    if(col > m) return ;
    if(col == m) {
        state[cnt][0] = pre;
        state[cnt++][1] = suc;
        return ; 
    }
    dfs(col + 1, pre << 1, suc << 1 | 1);
    dfs(col + 1, pre << 1 | 1, suc << 1);
    dfs(col + 2, pre << 2 | 3, suc << 2 | 3);
}

int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        cnt = 0;
        if(n < m) std::swap(n, m);
        memset(dp, 0, sizeof(dp));
        dfs(0, 0, 0);
        dp[0][(1 << m) - 1] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < cnt; j++)
                dp[i][state[j][1]] += dp[i - 1][state[j][0]];
        }
        printf("%lld\n", dp[n][(1 << m) - 1]);
    }
    return 0;
}