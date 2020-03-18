#include <cstdio>
#include <queue>
#define N 20050

struct INT {
    long long val;
    bool operator < (const INT a) const {
        return val > a.val;
    }
}a[N];

int n, m, t;
long long ans;

std::priority_queue<INT> q;

int main() {
    
    while(!q.empty()) q.pop();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i].val);
        q.push(a[i]);
    }
    while(!q.empty()) {
        INT a = q.top(); q.pop();
        if(q.empty()) break;
        INT b = q.top(); q.pop();
        INT tmp;
        tmp.val = a.val + b.val;
        ans += tmp.val;
        q.push(tmp);
    }
    printf("%lld\n", ans);
    
    return 0;
}