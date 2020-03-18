#include <cstdio>
#include <algorithm>
#define N 5050

int l, n, maxx = 0, minn = 0;
int a[N];

inline int max(int x, int y) {return x>y?x:y;}

inline int min(int x, int y) {return x<y?x:y;}

int main() {
    scanf("%d%d", &l, &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    //std::sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++) {
        maxx = max(maxx, max(a[i], l+1-a[i]));
        minn = max(minn, min(a[i], l+1-a[i]));
    }
    printf("%d %d\n", minn, maxx);
    return 0;
}