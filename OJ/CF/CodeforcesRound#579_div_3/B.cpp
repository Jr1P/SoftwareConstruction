#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, q;
int a[500], cnt[10050];

int main() {
    scanf("%d", &q);
    while(q--) {
        bool f = false;
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        for(int i = 1; i <= 4*n; i++){
            int l;
            scanf("%d", &l);
            cnt[l]++;
            a[i] = l;
        }
        sort(a+1, a+4*n+1);
        int sz = unique(a+1, a+4*n+1)-a-1;
        int s = a[1]*a[sz];
        for(int i = 1; i <= sz; i++) {
            if(a[i]*a[sz-i+1] != s) {
                f = true;
                break;
            }
            while(cnt[a[i]] >= 2 && cnt[a[sz-i+1]] >= 2) {
                cnt[a[i]] -= 2;
                cnt[a[sz-i+1]] -= 2;
            }
            if(cnt[a[i]] || cnt[a[sz-i+1]]) {
                f = true;
                break;
            }
        }
        if(f) puts("NO");
        else puts("YES");
    }
    return 0;
}