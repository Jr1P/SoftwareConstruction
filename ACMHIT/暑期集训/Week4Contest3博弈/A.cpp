#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, b) memset(a, b, sizeof(a))
#define N 10050
#define MAXN 10050
#define BASE 10009
const int MOD = 1e9+7; 
using namespace std;

int SG[MAXN], f[105];
bool S[105];//S为后继状态集合
int n, q, k;

void getSG(int n) {
    mem(SG, 0);
    for(int i = 1; i <= n; i++) {
        mem(S, 0);
        for(int j = 0; f[j] <= i && j < k; j++)
            S[SG[i-f[j]]] = 1;
        for(int j = 0; ; j++)
            if(!S[j]) {
                SG[i] = j;
                break;
            }
    }
}

int main() {
    while(1) {
        int cnt = 0;
        scanf("%d", &k);
        if(!k) break;
        for(int i = 0; i < k; i++)
            scanf("%d", &f[i]);
        sort(f, f+k);
        getSG(10000);
        scanf("%d", &q);
        int a;
        while(q--) {
            int l, p;
            scanf("%d", &l);
            a = 0;
            for(int i = 1; i <= l; i++) {
                scanf("%d", &p);
                a ^= SG[p];
            }
            if(a == 0) printf("L");
            else printf("W");
        }
        printf("\n");
    }
    return 0;
}