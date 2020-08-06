#include <cstdio>
#include <algorithm>
const int N = 1e5 + 5;

int n, m, len;
int a[N], d[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    d[1] = a[1]; len = 1;
    for(int i = 2; i <= n; i++) {
        if(d[len] <= a[i])
            d[++len] = a[i];
        else {
            int j = std::lower_bound(d + 1, d + len + 1, a[i]) - j;
            
        }
    }
    return 0;
}