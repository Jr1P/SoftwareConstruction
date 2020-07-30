#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 101, M = 7;

int map[N], state[1 << M], dp[2][1 << M][1 << M];
int n, m, cnt;

inline int calc(int state) {
    int ans = 0;
    for(; state; state >>= 1)
        if(state & 1) ans++;
    return ans;
}

inline bool check(int row, int state) {
    return (state & map[row]) == state;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 1; i <= n; i++) {
            char ch[10];
            map[i] = 0;
            scanf("%s", ch);
            for(int j = 0; j < m; j++) {
                map[i] <<= 1;
                if(ch[j] == 'P') map[i]++;
            }
        }
        cnt = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < (1 << m); i++) if((i & (i >> 1)) == 0 && (i & (i >> 2)) == 0) state[++cnt] = i;
        for(int i = 1; i <= cnt; i++)
            if(check(1, state[i]))
            dp[1][i][1] = calc(state[i]);
        for(int i = 2; i <= n; i++) {
            int t = i & 1;
            for(int j = 1; j <= (i == 2 ? 1 : cnt); j++) {
                if(!check(i - 2, state[j])) continue;
                for(int k = 1; k <= cnt; k++) {
                    if((state[j] & state[k]) || !check(i - 1, state[k])) continue;
                    for(int l = 1; l <= cnt; l++)
                        if((state[k] & state[l]) == 0 && (state[j] & state[l]) == 0 && check(i, state[l]))
                            dp[t][l][k] = std::max(dp[t][l][k], dp[t ^ 1][k][j] + calc(state[l]));
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= cnt; i++)
            for(int j = 1; j <= cnt; j++)
                ans = std::max(ans, dp[n & 1][i][j]);
        printf("%d\n", ans);
    }
    return 0;
}