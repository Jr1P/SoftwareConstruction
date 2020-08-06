#include <cstdio>
#include <cstring>
#include <vector>
const int N = 2e5 + 5;

std::vector<int > v0, v1;
int n, m, pre[2][N], block[N];
char ch[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        scanf("%s", ch);
        v0.clear(); v1.clear();
        for(int i = 0; i <= n; i++) pre[0][i] = pre[1][i] = -1, block[i] = 0;
        int pos0 = -1, pos1 = -1;
        for(int i = 0; i < n; i++)
            if(ch[i] == '0') {
                v0.push_back(i);
                pos0 = i;
                if(v1.size()) {
                    pre[1][i] = *(--v1.end());
                    v1.pop_back();
                }
            } else {
                v1.push_back(i);
                pos1 = i;
                if(v0.size()) {
                    pre[0][i] = *(--v0.end());
                    v0.pop_back();
                }
            }
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(block[i]) continue;
            cnt++;
            int pos = i, tt = ch[i] - '0';
                while(1) {
                    block[pos] = cnt;
                    tt ^= 1;
                    pos = pre[tt][pos];
                    if(pos == -1) break;
                }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < n - 1; i++)
            printf("%d ", block[i]);
        printf("%d\n", block[n - 1]);
    }
    return 0;
}