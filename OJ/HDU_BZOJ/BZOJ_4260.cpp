#include <cstdio>
#include <iostream>
#include <cstring>
#define N 400050
#define WORD 31
#define SZ 2

int n, tot;
int a[N], pre[N], suf[N], dp[N], trie[N * WORD][SZ], val[N * WORD];

void insert(int x, int root = 0) {
    int id;
    for(int i = WORD; i >= 0; i--) {
        id = (x >> i) & 1;
        if(!trie[root][id])
            trie[root][id] = ++tot;
        root = trie[root][id];
    }
    val[root] = x;
}

int query(int x, int root = 0) {
    int id;
    for(int i = WORD; i >= 0; i--) {
        id = (x >> i) & 1;
        if(trie[root][!id])
            root = trie[root][!id];
        else root = trie[root][id];
    }
    return val[root] ^ x;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] ^ a[i];
    for(int i = n; i > 0; i--)
        suf[i] = suf[i + 1] ^ a[i];
    insert(pre[0]);
    for(int i = 1; i <= n; i++) {
        dp[i] = std::max(dp[i - 1], query(pre[i]));
        insert(pre[i]);
    }
    int ans = 0;
    tot = 0;
    memset(trie, 0, sizeof(trie));
    insert(suf[n + 1]);
    for(int i = n; i > 0; i--) {
        ans = std::max(query(suf[i]) + dp[i - 1], ans);
        insert(suf[i]);
    }
    printf("%d\n", ans);
    return 0;
}