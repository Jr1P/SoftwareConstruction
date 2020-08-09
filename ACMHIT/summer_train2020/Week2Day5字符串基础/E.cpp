#include <cstdio>
#include <cstring>
#include <vector>
const int L = 20050;

char s[L << 1], ch[L];
int r[L << 1], len;
std::vector<int > ll, rr;

inline int min(int x, int y) { return x < y ? x : y; }

void manacher() {
    int ctr = 0, right = 0;
    for(int i = 0; i < len; i++) {
        r[i] = (right > i) ? min(r[ctr+ctr-i], right-i+1): 1;
        while(i-r[i] >= 0 && i+r[i] < len && s[i+r[i]] == s[i-r[i]]) {
            if(i+r[i] == len-1) rr.push_back(i);
            if(i-r[i] == 0) ll.push_back(i);
            r[i]++;
        }
        if(s[i+r[i]-1] == '#') r[i]--;
        if(i+r[i]-1 > right) {
            right = i+r[i]-1;
            ctr = i;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        bool f = false;
        scanf("%s", ch);
        len = 0;
        for(int i = 0; ch[i]; i++)
            s[len++] = '#', s[len++] = ch[i];
        s[len++] = '#';
        for(int i = 0; i <= len; i++) r[i] = 0;
        ll.clear(), rr.clear();
        manacher();
        for(int i : ll) {
            for(int j : rr) {
                int l = i + r[i] + 1, ri = j - r[j] - 1;
                if(l > ri) continue;
                int mi = ri + l >> 1;
                if(r[mi] >= mi-l) {
                    puts("Yes");
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
        if(!f) puts("No");
    }
    return 0;
}
