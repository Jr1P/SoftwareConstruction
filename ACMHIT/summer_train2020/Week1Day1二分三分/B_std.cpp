#include <bits/stdc++.h>
using namespace std;

namespace io {
char buf[1<<21], *p1 = buf, *p2 = buf;
inline char gc() {
    if(p1 != p2) return *p1++;
    p1 = buf;
    p2 = p1 + fread(buf, 1, 1 << 21, stdin);
    return p1 == p2 ? EOF : *p1++;
}
#define G gc

#ifndef ONLINE_JUDGE
#undef G
#define G getchar
#endif

template<class I>
inline void read(I &x) {
    x = 0; I f = 1; char c = G();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = G(); }
    while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = G(); }
    x *= f;
}

template<class I>
inline void write(I x) {
    if(x == 0) {putchar('0'); return;}
    I tmp = x > 0 ? x : -x;
    if(x < 0) putchar('-');
    int cnt = 0;
    while(tmp > 0) {
        buf[cnt++] = tmp % 10 + '0';
        tmp /= 10;
    }
    while(cnt > 0) putchar(buf[--cnt]);
}

#define in(x) read(x)
#define outn(x) write(x), putchar('\n')
#define out(x) write(x), putchar(' ')

} using namespace io;

#define ll long long
const int N = 1000100;
const int inf = 1e9;

int n, x;
int a[N];

int posmn[N], posmx[N];
//每个大小的数的最左端点和最右端点
int sufmn[N], premx[N];
//从大到小/从小到大的max和min位置
bool sufcan[N], precan[N];
//保留i到x这段是否合法，保留1到i这段是否合法

bool check(int l, int r) {
    if(!precan[l - 1]) return false;
    if(!sufcan[r + 1]) return false;
    if(sufmn[r + 1] < premx[l - 1]) return false;
    return true;
}

int main() {
    read(n); read(x);
    memset(posmn, 0x3f, sizeof(posmn));
    for(int i = 1; i <= n; ++i) read(a[i]);

    for(int i = 1; i <= n; ++i) {
        posmn[a[i]] = min(posmn[a[i]], i);
        posmx[a[i]] = max(posmx[a[i]], i);
    }
    sufmn[x + 1] = inf;
    for(int i = 1; i <= x; ++i) premx[i] = max(premx[i - 1], posmx[i]);
    for(int i = x; i; --i) sufmn[i] = min(sufmn[i + 1], posmn[i]);
    sufcan[x + 1] = precan[0] = true;
    for(int i = 1; i <= x; ++i) precan[i] = precan[i - 1] && (premx[i - 1] < posmn[i]);
    for(int i = x; i; --i) sufcan[i] = sufcan[i + 1] && (posmx[i] < sufmn[i + 1]);

    ll sum = 0;
    int l = 1, r = 1;
    for(; l <= x; ++l) {
        if(l > r) ++r;
        while(r < x && !check(l, r)) ++r;
        if(check(l, r)) sum += x - r + 1;
    }

    outn(sum);
    return 0;
}