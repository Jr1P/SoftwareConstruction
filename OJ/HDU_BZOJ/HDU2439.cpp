#include <cstdio>
#include <algorithm>
const int N = 1e5 + 5;
const int M = 1e6 + 5;

int n, m;
int cap[N], grade[M];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        int ans = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &cap[i]);
        for(int i = 1; i <= m; i++) {
            scanf("%d", &grade[i]);
            if(cap[grade[i]])
                cap[grade[i]]--, ans++, grade[i] = M + 1;
        }
        int p = 1;
        grade[m + 1] = M + 1;
        std::sort(grade + 1, grade + m + 1);
        for(int i = 1; grade[i] < M; i++) {
            while(!cap[p] && p <= n) p++;
            if(p <= grade[i]) {
                cap[p]--;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}