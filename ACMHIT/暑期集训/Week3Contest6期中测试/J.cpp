#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
#define N 5550
typedef long long ll;

int t, n, tim;
ll a, b;
vector<ll > G[N];
map<ll, int> mp;
map<ll, int> state;

bool dfs(ll u) {
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(state.count(v) && state[v] == tim)
            continue;
        state[v] = tim;
        map<ll, int>::iterator it = mp.find(v);
        int p = it->second;
        if(!p || dfs(p)) {
            mp[v] = u;
            return true;
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    tim = 0;
    mp.clear(); state.clear();
    for(int i = 1; i <= n; i++) {
        ++tim;
        if(dfs(i)) ans++;
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i <= n; i++) {
            scanf("%lld%lld", &a, &b);
            G[i].push_back(a+b);
            G[i].push_back(a-b);
            G[i].push_back(a*b);
        }
        printf("%d\n", hungarian());
    }
    return 0;
}