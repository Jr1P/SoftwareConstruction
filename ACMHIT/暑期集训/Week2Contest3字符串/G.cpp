#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
//const ll MOD = 1000000000000037;
const ull base = 99991;
const char ans1[] = "Twin snowflakes found.";
const char ans2[] = "No two snowflakes are alike.";

int n, cnt = 0;
ull a[12], now, ma = 0;
map<ull, int> mp;
bool f = false;

inline ull read() {
    ull x = 0;
    char c = getchar();
    while(c < '0' || c > '9')
   		c = getchar();
    while(c >= '0' && c <= '9') {
    	x = (x << 3) + (x << 1) + (c ^ 48);
    	c = getchar();
    }
    return x;
}

inline ull calc(int x) {
    ull ans = 0;
    for(int i = x; i <= x+5; i++)
        ans = ans*base+a[i];
    return ans;
}

inline ull r_calc(int x) {
    ull ans = 0;
    for(int i = x; i >= x-5; i--)
        ans = ans*base+a[i];
    return ans;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 6; j++) {
            a[j] = read();
            a[j+6] = a[j];
        }
        ma = 0;
        if(f) break;
        for(int j = 0; j <= 11; j++) {
            if(j < 6) {
                now = calc(j);
                if(now > ma) ma = now;
            }
            else if(j > 5) {
                now = r_calc(j);
                if(now > ma) ma = now;
            }
        }
        if(!mp.count(ma))
            mp.insert(make_pair(ma, i));
        else {
            if(mp[ma] != i) {
                f = true;
                break;
            }
        }
    }
    if(!f) puts(ans2);
    else puts(ans1);
    return 0;
}