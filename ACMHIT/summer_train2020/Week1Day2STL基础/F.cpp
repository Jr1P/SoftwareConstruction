#include <cstdio>
#include <stack>
const int N = 1e5 + 5;
typedef long long ll;

int n;
ll a[N],l[N],r[N];
std::stack <int> s;

int main() {
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        ll ans = 0;
        for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        while(!s.empty()) s.pop();
        for(int i = 1; i <= n; i++) {
            while(!s.empty() && a[s.top()] >= a[i]) s.pop();
            if(s.empty()) l[i] = 0;
            else l[i] = s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n; i >= 1; i--) {
            while(!s.empty() && a[s.top()] >= a[i]) s.pop();
            if(s.empty()) r[i] = n;
            else r[i] = s.top() - 1;
            s.push(i);
        }
        for(int i = 1; i <= n; i++)
            ans = std::max(ans, (r[i] - l[i]) * a[i]);
        printf("%lld\n",ans);
    }
    return 0;
}