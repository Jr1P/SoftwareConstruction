#include <cstdio>
#include <queue>
#include <cstring>
const int N = 1e4+5;
const int L = 50;
const int SZ = 26;
const int M = 1000005;

int n, tot;
int trie[N*L][SZ], fail[N*L], cnt[N*L];
char t[L], s[M];

inline void push(int root) {
    for(int i = 0; i < SZ; i++)
        trie[root][i] = 0;
}

void insert(int root=0) {
    for(int i = 0; t[i]; i++) {
        int id = t[i]-'a';
        if(!trie[root][id]) {
            trie[root][id] = ++tot;
            push(tot);
        }
        root = trie[root][id];
    }
    cnt[root]++;
}

void getFail() {
    std::queue<int > q;
    int root = 0;
    for(int i = 0; i < SZ; i++)
        if(trie[root][i]) {
            fail[trie[root][i]] = 0;
            q.push(trie[root][i]);
        }
    while(!q.empty()) {
        root = q.front(); q.pop();
        for(int i = 0; i < SZ; i++)
            if(trie[root][i]) {
                fail[trie[root][i]] = trie[fail[root]][i];
                q.push(trie[root][i]);
            } else trie[root][i] = trie[fail[root]][i];
    }
}

int query() {
    int sum = 0, root = 0;
    for(int i = 0; s[i]; i++) {
        int id = s[i]-'a';
        root = trie[root][id];
        for(int j = root; j && cnt[j] != -1; j = fail[j])
            sum += cnt[j], cnt[j] = -1;
    }
    return sum;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        tot = 0;
        scanf("%d", &n);
        for(int i = 0; i < SZ; i++) trie[0][i] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%s", t);
            insert();
        }
        getFail();
        scanf("%s", s);
        printf("%d\n", query());
    }
    return 0;
}