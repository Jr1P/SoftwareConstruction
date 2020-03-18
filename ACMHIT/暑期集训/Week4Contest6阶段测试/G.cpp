#include<cstdio>
using namespace std;
#define N 10050

int n, k;
int SG[N];

void xwlj(){
    SG[0] = 0;
    for(int i = 1; i < N; i++) {
        if(i & 1) SG[i] = (SG[i-1] == 0);
        else {
            int a = SG[i-1], b;
            if(k & 1) b = SG[i/2];
            else b = 0;
            for(int j = 0; ; j++)
                if(a != j && b != j) {
                    SG[i] = j;
                    break;
                }
        }
    }
}
 
int getSG(int x) {
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(k & 1) {
        if(x == 2) return 0;
        if(x == 3) return 1;
        if(x == 4) return 2;
        if(x & 1) return 0;
        return getSG(x/2) == 1 ? 2 : 1;
    }
    else {
        if(x == 2) return 2;
        if(x & 1) return 0;
        return 1;
    }
}
 
int main(){
    scanf("%d%d", &n, &k);
    //xwlj();
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        ans ^= getSG(x);
    }
    if(ans) puts("Kevin");
    else puts("Nicky");
    return 0;
}