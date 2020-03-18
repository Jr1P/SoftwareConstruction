#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, b) memset(a, b, sizeof(a))
#define N 10050
#define MAXN 10050
#define BASE 10009
const int MOD = 1e9+7; 
using namespace std;

int SG[MAXN], f[15] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
bool S[MAXN];//S为后继状态集合
int n, q, k;

void getSG(int n) {
    mem(SG, 0);
    for(int i = 1; i <= n; i++) {
        mem(S, 0);
        for(int j = 0; f[j] <= i && j < 10; j++)
            S[SG[i-f[j]]] = 1;
        for(int j = 0; ; j++)
            if(!S[j]) {
                SG[i] = j;
                break;
            }
    }
}

int main() {
    getSG(1000);
    while(scanf("%d", &n) != EOF) {
        if(SG[n] == 0) puts("Cici");
        else puts("Kiki");
    }
    return 0;
}