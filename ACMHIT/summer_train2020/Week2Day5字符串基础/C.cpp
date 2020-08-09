#include <cstdio>
#include <cstring>
typedef long long ll;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int N = 1e5 + 5;

char table[200], s[200], t[N];
ll hash1[N], hash2[N], dh1[N], dh2[N];

inline int cal(char c) {
    return c - 'a' + 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s%s", s, t);
        for(int i = 0; s[i]; i++)
            table[s[i]] = 'a' + i;
        int l, tlen = strlen(t);
        if(tlen & 1) l = tlen / 2 + 1;
        else l = tlen / 2;
        hash1[0] = hash2[0] = cal(table[t[0]]);
        for(int i = 1; i < l; i++) {
            char tmp = table[t[i]];
            hash1[i] = (hash1[i - 1] * 26 + cal(tmp)) % MOD1;
            hash2[i] = (hash2[i - 1] * 26 + cal(tmp)) % MOD2;
        }
        dh1[tlen - 1] = dh2[tlen - 1] = cal(t[tlen-1]);
        ll base1 = 26, base2 = 26;
        for(int i = tlen - 2; i >= l; i--) {
            dh1[i] = (dh1[i + 1] + 1ll * cal(t[i]) * base1) % MOD1;
            base1 = base1 * 26 % MOD1;
            dh2[i] = (dh2[i + 1] + 1ll * cal(t[i]) * base2) % MOD2;
            base2 = base2 * 26 % MOD2;
        }
        int len;
        for(len = tlen - l; len; len--)
            if(hash1[len-1] == dh1[tlen - len] && hash2[len-1] == dh2[tlen - len]) break;
        printf("%s", t);
        for(int i = len; i < tlen-len; i++)
            putchar(table[t[i]]);
        puts("");
    }
    return 0;
}