#include <cstdio>
#include <deque>
const int N = 8e4 + 5;

struct Cow {
    int h, t;
} cow[N];

int n;
std::deque<Cow > q;

int main() {
    while(~scanf("%d", &n)) {
        while(!q.empty()) q.pop_back();
        for(int i = 1; i <= n; i++)
            scanf("%d", &cow[i].h), cow[i].t = 0;
        q.push_back(cow[n]);
        for(int i = n - 1; i; i--) {
            int cnt = 0;
            while(!q.empty() && cow[i].h > q.back().h)
                cnt += q.back().t + 1, q.pop_back();
            cow[i].t = cnt;
            q.push_back(cow[i]);
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++)
            ans += cow[i].t;
        printf("%lld\n", ans);
    }
    return 0;
}