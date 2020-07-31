#include <cstdio>
#include <queue>
const int N = 5005;

int t, n;
std::queue<int > q1, q2;

int main() {
    scanf("%d", &t);
    while(t--) {
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) q1.push(i);
        while(!(q1.size() <= 3 && q2.size() <= 3)) {
            int sz = q1.size();
            for(int i = 0; i < sz; i++) {
                if(!(i & 1)) q2.push(q1.front());
                q1.pop();
            }
            sz = q2.size();
            if(sz <= 3) break;
            for(int i = 0; i < sz; i++) {
                if(i % 3 != 2) q1.push(q2.front());
                q2.pop();
            }
        }
        if(q1.empty()) {
            printf("%d", q2.front()); q2.pop();
            while(!q2.empty())
                printf(" %d", q2.front()), q2.pop();
        } else {
            printf("%d", q1.front()); q1.pop();
            while(!q1.empty())
                printf(" %d", q1.front()), q1.pop();
        }
        puts("");
    }
    return 0;
}