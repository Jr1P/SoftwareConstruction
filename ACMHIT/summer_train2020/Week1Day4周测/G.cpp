#include <cstdio>
#include <stack>
const int N = 1e6 + 5;

int n, p[N];
std::stack<int > s;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    int t;
    scanf("%d", &t);
    while(t--) {
        int q;
        scanf("%d", &q);
        p[q] *= -1;
    }
    while(!s.empty()) s.pop();
    for(int i = n; i; i--) {
        if(p[i] < 0) s.push(p[i]);
        else {
            if(!s.empty() && s.top() + p[i] == 0) s.pop();
            else p[i] = -p[i], s.push(p[i]);
        }
    }
    if(!s.empty()) puts("NO");
    else {
        puts("YES");
        for(int i = 1; i <= n; i++)
            printf("%d ", p[i]);
    }
    return 0;
}