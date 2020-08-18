#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = 205;
const int M = 1e6+5;
const int SZ = 26;

int trie[M][SZ], fail[M], pos[N], q[M];
ll cnt[M];
int n, tot, head, tail;

void insert(char *t, int i, int root=0) {
    for(int i = 0; t[i]; i++) {
        int id = t[i]-'a';
        if(!trie[root][id]) trie[root][id] = ++tot;
        root = trie[root][id];
        cnt[root]++;
    }
    pos[i] = root;
}

void getFail() {
    int root = 0;
    for(int i = 0; i < SZ; i++)
        if(trie[root][i]) {
            q[tail++] = trie[root][i];
            fail[trie[root][i]] = 0;
        }
    while(head != tail) {
        root = q[head++];
        for(int i = 0; i < SZ; i++)
            if(trie[root][i]) {
                q[tail++] = trie[root][i];
                fail[trie[root][i]] = trie[fail[root]][i];
            } else trie[root][i] = trie[fail[root]][i];
    }
}

int main() {
    scanf("%d", &n);
    char s[M];
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        insert(s, i);
    }
    getFail();
    for(int i = tail; i >= 0; i--) cnt[fail[q[i]]] += cnt[q[i]];
    for(int i = 1; i <= n; i++)
        printf("%lld\n", cnt[pos[i]]);
    return 0;
}