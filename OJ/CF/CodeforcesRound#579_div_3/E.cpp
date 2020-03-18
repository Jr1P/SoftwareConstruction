#include <cstdio>
#include <algorithm>
using namespace std;
#define N 150050

int a[N], cnt[N];
bool f[N];
int n;

inline int min(int x, int y) {
    return x<y?x:y;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        cnt[a[i]]++;
    }
    sort(a+1, a+n+1);
    int sz = unique(1+a, a+n+1)-a-1;
    int ans = 0;
    for(int i = 1; i <= sz; i++) {
        if(a[i] == 1) {
            if(cnt[1] == 1)
                ans++, f[1] = 1;
            else {
                f[2] = 1;
                f[1] = 1;
                ans += 2;                
            }           
        } else {
            if(!f[a[i]-1] && cnt[a[i]]) {
                ans++;
                cnt[a[i]]--;
                f[a[i]-1] = 1;
            }
            if(!f[a[i]] && cnt[a[i]]) cnt[a[i]]--, ans++, f[a[i]] = 1;
            if(!f[a[i]+1] && cnt[a[i]]) {
                ans++;
                cnt[a[i]]--;
                f[a[i]+1] = 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}