#include <cstdio>
#include <iostream>
#include <cstring>
#define N 1000050
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

char str[N];
int pos1, pos2, l;

inline ll calc(int l, int r) {
    ll ans = 0;
    for(int i = l; i <= r; i++)
        ans = (ans*10+str[l]-'0')%MOD;
    return ans;
}

int main() {
    scanf("%s", str);
    int l = strlen(str);
    bool f = false;
    pos2 = 2*l/3;
    pos1 = l/3;
    for(int i = l/2; i <= pos2+1 && i < l-1; i++) {
        if(f) break;
        for(int j = 0; j <= pos1+1; j++) {
            if(i <= j) continue;
            ll p1 = calc(0, j), p2 = calc(j+1, i), p3 = calc(i+1, l-1);
            if((p1+p2)%MOD == p3) {
                pos1 = j;
                pos2 = i;
                f = true;
                break;
            }
        }
    }
    for(int i = 0; i < l; i++) {
        printf("%c", str[i]);
        if(i == pos1)
            printf("+");
        else if(i == pos2)
            printf("=");
    }
    return 0;
}