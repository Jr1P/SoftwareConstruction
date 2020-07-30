#include <cstdio>
#include <iostream>
const int N = 1e6 + 5;
#define INF 0x3fffffff

int n, x;
int a[N], maxID[N], minID[N], preMaxID[N], suffMinID[N];
bool pre[N], suff[N];

inline bool check(int l, int r) {
    return pre[l - 1] && suff[r + 1] && (preMaxID[l - 1] <= suffMinID[r + 1]);
}

int main() {
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= x; i++) 
        maxID[i] = 0, minID[i] = INF;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        maxID[a[i]] = std::max(maxID[a[i]], i);
        minID[a[i]] = std::min(minID[a[i]], i);
    }
    suffMinID[x + 1] = INF;
    for(int i = 1; i <= x; i++) preMaxID[i] = std::max(preMaxID[i - 1], maxID[i]);
    for(int i = x; i; i--) suffMinID[i] = std::min(suffMinID[i + 1], minID[i]);
    pre[0] = suff[x + 1] = true;
    for(int i = 1; i <= x; i++) pre[i] = pre[i - 1] && (preMaxID[i - 1] < minID[i]);
    for(int i = x; i; i--) suff[i] = suff[i + 1] && (suffMinID[i + 1] > maxID[i]);
    int r = 1;
    long long sum = 0;
    for(int l = 1; l <= x; l++) {
        if(l > r) r = l;
        while(r < x && !check(l, r)) r++;
        if(check(l, r)) sum += x - r + 1;
    }
    printf("%lld\n", sum);
    return 0;
}