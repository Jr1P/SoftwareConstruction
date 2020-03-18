#include <cstdio>
#include <algorithm>
#include <string>
#define N 500050
#define K 30
// #define X 10^18
typedef long long ll;

char str[N];
// std::string s[N];
char s[N][K];
int n, m, cnt;
int pos[N];
ll x, k;

int main() {
    scanf("%d%d%lld%lld", &n, &m, &k, &x);
    scanf("%s", str);
    for(int i = 0; str[i]; i++)
        if(str[i] == '#') pos[++cnt] = i;
    for(int i = 1; i <= m; i++) {
        scanf("%s", s[i]);
        std::sort(s[i], s[i] + k);
    }
    x--;
    while(m) {
        ll mod = x % k;
        str[pos[m]] = s[m][mod];
        x /= k;
        m--;
    }
    puts(str);
    return 0;
}