#include <cstdio>
using namespace std;
#define N 500001

int n, m;
int f[N];
bool in[N << 3];

int main() {
    f[0] = 0;
    in[0] = true;
    for(int i = 1; i < N; i++) {
        int tmp = f[i - 1] - i;
        if(tmp < 0) {
            f[i] = f[i - 1] + i;
            in[f[i]] = true;
            continue;
        }
        if(!in[tmp])
            f[i] = tmp;
        else f[i] = f[i - 1] + i;
        in[f[i]] = true;
    }
    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        printf("%d\n", f[n]);
    }
    return 0;
}