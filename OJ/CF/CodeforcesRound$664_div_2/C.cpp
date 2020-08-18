#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
const int N = 205;
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for(int i = (a); i <= (n); i++)
#define drep(i, n, a) for(int i = (n); i >= (a); i--)

int n, m;
int a[N], b[N], cnt[N];
std::set<int > ans[N];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        for(int j = 1; j <= n; j++) ans[j].insert(i);
    }
    int ans0 = 0;
    for(int l = 10; l>=0; l--) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++) {
            for(int j : ans[i])
                if((a[i]&b[j] >> l)&1) cnt[i]++;
        }
        int tp = 0;
        for(int i = 1; i <= n; i++) if(cnt[i] == m) tp++;
        if(tp) ans0 |= (1 << l);
        else {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++)
                    if((a[i]&b[j] >> l)&1) ans[i].erase(j);
            }
        }
    }
    printf("%d\n", ans0);
    return 0;
}