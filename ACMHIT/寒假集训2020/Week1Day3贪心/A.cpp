#include <cstdio>
#include <queue>
#define N 1050

struct INT {
    int val;
    bool operator < (const INT a) const {
        return val > a.val;
    }
}a[N];

int n, m, t;
int ans;

std::priority_queue<INT> q;

int main() {
    scanf("%d", &t);
    while(t--) {
        ans = 0;
        while(!q.empty()) q.pop();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i].val);
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
        printf("%d\n", ans);
    }
    return 0;
}