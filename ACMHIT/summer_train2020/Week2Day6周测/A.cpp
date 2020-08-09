#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 2000;

int n, cc, ans;
int cnt[60];

struct Node {
    int start, gap, times;
    inline bool operator < (Node o) const {
        return times > o.times;
    }
} a[N];

inline int check(int i, int j) {
    int ans = 0;
    for(; i < 60; i += j, ans++)
        if(!cnt[i]) return -1;
    return ans;
}

void dfs(int now, int num, int t) {
    if(num == n) {
        if(ans > t) ans = t;
        return ;
    }
    for(int i = now; i <= cc; i++) {
      
        if(t + (n-num) / a[i].times >= ans) return ;
        if(check(a[i].start, a[i].gap) > 0) {
            for(int j = a[i].start; j < 60; j += a[i].gap) cnt[j]--;
            dfs(i, num+a[i].times, t+1);
            for(int j = a[i].start; j < 60; j += a[i].gap) cnt[j]++;
        }
    }
    return ;
}

int main() {
    while(~scanf("%d", &n)) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            cnt[a]++;
        }
        cc = 0;
        for(int i = 0; i < 30; i++)
            for(int j = i + 1; j < 60-i; j++) {
                int c = check(i, j);
                if(c > 0) a[++cc].start = i, a[cc].gap = j, a[cc].times = c;
            }
        std::sort(a+1, a+cc+1);
        ans = 17;
        dfs(1, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}