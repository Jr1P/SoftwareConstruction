#include <cstdio>
#define N 200050
#define K 30

int n, k;
char str[N], va[K];
long long dis = 0, ans = 0;

inline bool check(char a) {
    for(int i = 0; i < k; i++)
        if(a == va[i]) return true;
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", str);
    char c = getchar();
    for(int i = 0; i < k; i++) {
        scanf("%c", &va[i]);
        c = getchar();
    }
    for(int i = 0; str[i]; i++) {
        if(!check(str[i])) {
            ans += (((dis + (long long)1) * dis) >> 1);
            dis = 0;
        } else dis++;
    }
    if(dis) ans += (((dis + 1) * dis) >> 1);
    printf("%lld\n", ans);
    return 0;
}