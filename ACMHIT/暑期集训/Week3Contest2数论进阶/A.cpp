#include <cstdio>

int m[3] = {23, 28, 33};
int d[3], d0, x, y;
int ans;

int exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exgcd(b, a%b, x, y);
	int x2 = x, y2 = y;
	x = y2;
	y = x2-(a/b)*y2;
	return gcd;
}

int main() {
    int kase = 0;
    while(1) {
        ans = 0;
        for(int i = 0; i < 3; i++)
            scanf("%d", &d[i]);
        scanf("%d", &d0);
        if(d[1] == -1 && d[0] == -1 && d[2] == -1 && d0 == -1) break;
        int Mul = 23*28*33;
        for(int i = 0; i < 3; i++) {
            int tp = Mul/m[i];
            exgcd(tp, m[i], x, y);
            x = (x%m[i]+m[i])%m[i];
            ans = (ans+tp*x*d[i])%Mul;
        }
        ans = (ans%Mul+Mul)%Mul;
        ans += 21252;
        ans -= d0;
        ans %= 21252;
        if(ans == 0) ans = 21252;
        
        printf("Case %d: the next triple peak occurs in %d days.\n", ++kase, ans);
    }
    return 0;
}
