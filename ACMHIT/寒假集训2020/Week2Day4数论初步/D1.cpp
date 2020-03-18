#include<cstdio>
#include<cstdlib>
#include<cstring>

#define MAX 1005
#define INF 0x3f3f3f3f
#define MOD 1000000007

typedef long long ll;

int b[5][MAX];
int n;
ll ans;

void dfs(int s){
    int i, j;
    if(s == 4 * n) {
        ans++;
        return;
    }
    for(i = 1; i <= 4; i++) {
        for(j = 1; j <= n; j++) {
            if(b[i][j] == 0){
                if(i + 1 <= 4){
                    if(b[i + 1][j] == 0) {
                        b[i][j] = 1;
                        b[i + 1][j] = 1;
                        dfs(s + 2);
                        b[i][j] = 0;
                        b[i + 1][j] =0;
                    }
                }
                if(j + 1 <= n) {
                    if(b[i][j + 1] == 0) {
                        b[i][j] = 1;
                        b[i][j + 1] = 1;
                        dfs(s + 2);
                        b[i][j] = 0;
                        b[i][j + 1] = 0;
                    }
                }
                return;
            }
        }
    }
}

int main() {
    int i;
    while(~scanf("%d", &n)){
        memset(b, 0, sizeof(b));
        ans = 0;
        dfs(0);
        printf("%lld\n", ans);    
    }
    return 0;
}