#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))

int n, a[55];
int f[55], SG[55], S[55];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int b = 1;
    sort(a+1, a+n+1);
    a[n+1] = -1;
    for(; ;)
        if(a[++b] != a[1]) break;
    b--;
    if(b <= n/2)
        puts("Alice");
    else puts("Bob");
    
    return 0;
}