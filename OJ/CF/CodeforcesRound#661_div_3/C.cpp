#include <cstdio>
const int N = 55;

int n, m, ans, tmp, a[N];
int num[N];

inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        ans = 0;
        for(int i = 1; i <= 51; i++) num[i] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]), num[a[i]]++;
        for(int i = 2; i <= n * 2; i++) {
            tmp = 0;
            for(int j = max(1, i - n); j <= i / 2; j++)
                if(i == 2 * j) tmp += num[j] / 2;
                else tmp += min(num[j], num[i - j]);
            ans = max(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}