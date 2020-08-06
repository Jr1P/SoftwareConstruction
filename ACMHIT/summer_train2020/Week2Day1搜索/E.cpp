#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 16;

int n, m, v[N << 1], ww[1 << N];

inline bool cmp(int x, int y) {
    return x > y;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        int ans = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        int q = n / 2;
        for(int i = 0; i < (1 << q); i++) {
            ww[i] = 0;
            for(int j = 0; j < q; j++)
                if(i & (1 << j)) ww[i] += v[j];
        }
        std::sort(ww, ww + (1 << q));
        int g = n - q;
        for(int i = 0; i < (1 << g); i++) {
            int w = 0;
            for(int j = 0; j < g; j++)
                if(i & (1 << j)) w += v[j + q];
            if(w > m) continue;
            int pos = std::lower_bound(ww, ww + (1 << q), m - w) - ww;
            while(pos >= (1 << q)) pos --;
            while(pos >= 0 && ww[pos] > m - w) pos--;
            if(pos == -1) continue;
            if(w + ww[pos] > ans) ans = ww[pos] + w;
        }
        printf("%d\n", ans);
    }
    return 0;
}