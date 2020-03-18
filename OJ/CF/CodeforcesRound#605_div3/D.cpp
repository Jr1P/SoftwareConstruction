#include <cstdio>
#define N 200050

int n;
int a[N], p[N], len, ma, cnt;

struct qujian {
    int l, r;
    inline int len() { return r - l + 1; }
}seq[N];

inline int max(int x, int y) { return x > y ? x : y; }

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        p[i] = 1;
    }
    int pos = 1, ans = 0;
    seq[1].l = 1; cnt = 1;
    for(int i = 1; i < n; i++) {
        if(a[i + 1] > a[i])
            continue;
        seq[cnt++].r = i;
        ans = max(seq[cnt - 1].len(), ans);
        seq[cnt].l = i + 1;
    }
    if(!seq[cnt].r) seq[cnt].r = n;
    // if(p[n] == 0) p[n] = 1;
    // pos = 1;
    // int i = 1;
    // while (i < n) {
    //     while(p[i] == 1) i++;
    //     pos = i;
    //     while(p[i] != 1 && p[i] != 0) i++;
    //     if(p[i + 1] != 1 && a[i - 1] < a[i + 1]) {
    //         ans = max(ans, p[pos] + p[i + 1] - 1);
    //         pos = i + 1;
    //     }

    // }
    for(int i = 0; i < cnt; i++) {
        if(seq[i].len() == 1) continue;
        if(a[seq[i].r - 1] < a[seq[i + 1].l] && seq[i + 1].len() != 1)
            ans = max(ans, seq[i].len() + seq[i+2].len());
    }
    printf("%d\n", ans);
    return 0;
}