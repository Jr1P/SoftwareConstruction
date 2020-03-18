#include <cstdio>
#include <set>
#define N 10050

int n, m;
std::set<int > a;

int main() {
    while(~scanf("%d%d", &n, &m)) {
        a.clear();
        for(int i = 0; i < n; i++) {
            int sa;
            scanf("%d", &sa);
            a.insert(sa);
        }
        for(int i = 0; i < m; i++) {
            int sb;
            scanf("%d", &sb);
            a.insert(sb);
        }
        for(int i : a) printf("%d ", i);
        puts("");
    }
    return 0;
}