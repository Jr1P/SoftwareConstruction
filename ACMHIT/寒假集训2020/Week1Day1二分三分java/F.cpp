#include <cstdio>
#include <algorithm>
#define N 50050

int l, n, m;
int d[N];

bool check(int ans) {
    int cnt = 0, pre = 0;
    for(int i = 1; i <= n + 1; i++)
        if(d[i] - pre < ans)
            cnt++;
        else pre = d[i];
    if(cnt > m) return false;
    else return true;
}

int main() {
    scanf("%d%d%d", &l, &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &d[i]);
    std::sort(d + 1, d + n + 1);
    d[0] = 0; d[n + 1] = l;
    int le = 0, r = l;
    while(le < r - 1) {
        int mid = (le + r) >> 1;
        if(check(mid)) le = mid;
        else r = mid - 1;
    }
    if(check(le + 1)) le = le + 1;
    printf("%d\n", le);
    return 0;
}