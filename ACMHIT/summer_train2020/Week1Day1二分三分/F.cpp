#include <cstdio>
#include <cstring>
const int N = 105;

int n, m, t;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        char ch[N];
        scanf("%s", ch);
        if(n < 11) {
            puts("NO");
            continue;
        }
        int i = 0;
        for(; i < n; i++)
            if(ch[i] == '8') break;
        if(n - i >= 11)
            puts("YES");
        else puts("NO");
    }
    return 0;
}