#include <cstdio>
#include <algorithm>
const int N = 100; 


int n, m;
int a[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        bool f = true;
        scanf("%d", &n);
        for(int i = 1; i<= n; i++) scanf("%d", a + i);
        std::sort(a + 1, a + n + 1);
        for(int i = 1; i < n; i++)
            if(a[i + 1] - a[i] > 1) {
                puts("NO");
                f = false;
                break;
            }
        if(f) puts("YES");
    }
    return 0;
}