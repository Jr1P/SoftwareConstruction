#include <cstdio>
#include <cstring>
#include <unordered_map>
typedef unsigned long long ull;
const int N = 1e5+5;
const int seed = 29;

ull hash[N], base[N];
int m, l;
char s[N];

ull _hash(int l, int r) {
    return hash[r]-hash[l-1]*base[r-l+1];
}

int main() {
    base[0] = 1;
    for(int i = 1; i < N; i++) base[i] = base[i-1]*seed;
    while(~scanf("%d%d", &m, &l)) {
        int ans = 0;
        scanf("%s", s+1);
        int len = strlen(s+1);
        hash[0] = 0;
        for(int i = 1; i <= len; i++)
            hash[i] = hash[i-1]*seed+s[i]+'a'-1;
        for(int i = 1; i <= l && i <= len-m*l; i++) {
            std::unordered_map<ull, int> ma;
            ma.clear();
            int j = i;
            for(; j < i+m*l; j += l) {
                ull tmp = _hash(j, j+l-1);
                ma[tmp]++;
            }
            if(ma.size() == m) ans++;
            for(; j+l-1 <= len; j += l) {
                ull tmp = _hash(j, j+l-1);
                ma[tmp]++;
                tmp = _hash(j-m*l, j-m*l+l-1);
                ma[tmp]--;
                if(ma[tmp] == 0) ma.erase(tmp);
                if(ma.size() == m) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}