#include <cstdio>
#include <cstring>
const int MOD1 = 1e9+7;
const int MOD2 = 1e9+9;
const int base = 29;
const int N = 1e6+5;
typedef long long ll;

char s[N], t[N];
int num[2], lens, lent;
ll hash1[N], hash2[N];

inline ll pow(ll a, ll b, ll mod) {
    ll ans = 1;
    while(b) {
        if(b&1) ans = ans*a%mod;
        a = a*a%mod; b>>=1;
    }
    return ans;
}

int main() {
    scanf("%s%s", s, t);
    lens = strlen(s), lent = strlen(t);
    for(int i = 0; s[i]; i++) num[s[i]-'0']++;
    for(int i = 1; i <= lent; i++)
        hash1[i] = (hash1[i-1]*base+t[i-1]-'a'+1)%MOD1,
        hash2[i] = (hash2[i-1]*base+t[i-1]-'a'+1)%MOD2;
    ll ans = 0;
    if(num[0] == 0 || num[1] == 0) {
        puts("0");
        return 0;
    }
    for(int i = 1; i <= lent/num[0]; i++) {
        ll hash[2][2] = {0, 0, 0, 0};
        ll sumhash[2] = {0, 0};
        bool f = true;
        if((lent-i*num[0])%num[1] != 0) continue;
        int j = (lent-i*num[0])/num[1];
        if(!j) break;
        for(int pos = 0, sp = 0; sp < lens; pos += (s[sp] == '0') ? i : j, sp++) {
            ll tmp[2][2];
            int d = s[sp] == '0' ? 0 : 1, ll = s[sp] == '0' ? i : j;
            tmp[d][0] = (hash1[pos+ll]-hash1[pos]*pow(base, ll, MOD1)%MOD1+MOD1)%MOD1;
            tmp[d][1] = (hash2[pos+ll]-hash2[pos]*pow(base, ll, MOD2)%MOD2+MOD2)%MOD2;
            if(hash[d][0] == 0)
                hash[d][0] = tmp[d][0], hash[d][1] = tmp[d][1];
            else if(hash[d][0] != tmp[d][0] || hash[d][1] != tmp[d][1]) {
                f = false;
                break;
            }
            sumhash[0] = (sumhash[0]*pow(base, ll, MOD1)+hash[d][0])%MOD1;
            sumhash[1] = (sumhash[1]*pow(base, ll, MOD2)+hash[d][1])%MOD2;
        }
        if((i == j) && (hash[0][0] == hash[1][0]) && (hash[0][1] == hash[1][1])) continue;
        if(f && sumhash[0] == hash1[lent] && sumhash[1] == hash2[lent])
            ans++;
    }
    printf("%lld\n", ans);
    return 0;
}