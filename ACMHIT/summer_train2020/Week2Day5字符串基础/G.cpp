#include <cstdio>
#include <unordered_map>
const int N = 5e3 + 50;
const int M = 1e6 + 5;

int query[N];
std::unordered_map<int, int > num, mm;

int get(char* ch) {
    int ans = 0;
    for(int i = 0; ch[i]; i++)
        ans = ans * 10 + mm[ch[i]];
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    mm['a'] = mm['b'] = mm['c'] = 2;
    mm['d'] = mm['e'] = mm['f'] = 3;
    mm['g'] = mm['h'] = mm['i'] = 4;
    mm['j'] = mm['k'] = mm['l'] = 5;
    mm['m'] = mm['n'] = mm['o'] = 6;
    mm['p'] = mm['q'] = mm['s'] = mm['r'] = 7;
    mm['t'] = mm['u'] = mm['v'] = 8;
    mm['w'] = mm['x'] = mm['y'] = mm['z'] = 9;
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        num.clear();
        for(int i = 1; i <= n; i++)
            scanf("%d", &query[i]);
        while(m--) {
            char ch[10];
            scanf("%s", ch);
            int val = get(ch);
            num[val]++;
        }
        for(int i = 1; i <= n; i++)
            printf("%d\n", num[query[i]]);
    }
    return 0;
}