#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;
const int N = 55;

struct Item {
    int t, a, b, c, d;
    bool operator < (const Item o) const {
        return t < o.t;
    }
} item[N];

int n, k, T;
int l[N], r[N], next[N];
bool vis[N], typevis[N];
ll suma = 100, sumb = 100, sumc = 100, sumd = 100, ans;

void dfs(int x) {
    if(x == k + 1) {
        ll q = suma * sumb * sumc * sumd;
        if(ans < q) ans = q;
        return ;
    }
    if((suma + 100 * (k + 1 - x)) * ((sumb + 100 * (k + 1 - x))) * (sumc + 100 * (k + 1 - x)) * (sumd + 100 * (k + 1 - x)) < ans) return ;
    for(int i = l[x]; i <= r[x]; i++) {
        suma += item[i].a, sumb += item[i].b, sumc += item[i].c, sumd += item[i].d;
        dfs(next[x]);
        suma -= item[i].a, sumb -= item[i].b, sumc -= item[i].c, sumd -= item[i].d;
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k); ans = 0;
        for(int i = 0; i <= n; i++)
            l[i] = r[i] = next[i] = 0;
        suma = 100, sumb = 100, sumc = 100, sumd = 100;
        for(int i = 1; i <= n; i++)
            scanf("%d%d%d%d%d", &item[i].t, &item[i].a, &item[i].b, &item[i].c, &item[i].d);
        std::sort(item + 1, item + n + 1);
        l[1] = 1;
        int type = 1;
        for(int i = 1; i <= n; i++) {
            if(type != item[i].t) {
                next[type] = item[i].t;
                r[type] = i - 1;
                l[type = item[i].t] = i;
            }
        }
        next[item[n].t] = k + 1;
        r[item[n].t] = n;
        dfs(item[1].t);
        printf("%lld\n", ans);
    }
    return 0;
}