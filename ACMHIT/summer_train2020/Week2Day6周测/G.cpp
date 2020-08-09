#include <cstdio>
#include <cstring>
const int N = 1e5+5;
const int MOD = 1e9+7;
typedef long long ll;

int n, m;
ll fi[N];

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &m);
        fi[0] = fi[1] = 1;
        char ch[12];
        scanf("%s", ch);
        for(int i = 2; i <= m; i++) {
            char ch2[12];
            scanf("%s", ch2);
            if(strcmp(ch, ch2) == 0)
                fi[i] = fi[i-1];
            else fi[i] = (fi[i-1] + fi[i-2]) % MOD;
            strcpy(ch, ch2);
        }
        printf("%lld\n", fi[m]);
    }
    return 0;
}