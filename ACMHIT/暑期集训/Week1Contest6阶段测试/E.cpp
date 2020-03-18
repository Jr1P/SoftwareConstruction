#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
#define N 200050
typedef long long ll;
const ll R = 2e12;

ll n, k, mmax = 0;
ll l = 0, r = R;

inline ll read() {
    ll x = 0;
    char c = getchar();
    while(c < '0' || c > '9')
   		c = getchar();
    while(c >= '0' && c <= '9') {
    	x = (x << 3) + (x << 1) + (c ^ 48);
    	c = getchar();
    }
    return x;
}

struct Computer {
	ll charge, v;
	ll c;
	inline bool operator < (const Computer& rhs) const {
		if (c != rhs.c) return c > rhs.c;
		if (v != rhs.v) return v < rhs.v;
		return charge > rhs.charge;
	}
}student[N];

priority_queue<Computer > q;

inline bool work(ll mid) {
	for(register int i = 0; i < k; i++) {
		if(q.empty()) return true;
		Computer nowcmp = q.top();
		q.pop();
		if(nowcmp.charge-nowcmp.v*i < 0)
			return false;
		nowcmp.charge += mid;
		nowcmp.c = nowcmp.charge/nowcmp.v;
		if(nowcmp.c < k) q.push(nowcmp);
		if(q.empty())
			return true;
	}
	return true;
}

inline void divide() {
	while(l < r) {
		ll mid = (l+r)>>1;
		if(work(mid)) r = mid;
		else l = mid+1;
		while(!q.empty())
			q.pop();
		for(register int i = 1; i <= n; i++)
			if(student[i].c < k)
				q.push(student[i]);
	}
	if(l >= R-1) printf("-1");
	else printf("%I64d", l);
}

int main() {
	n = read();
	k = read();
	for(register int i = 1; i <= n; i++)
		student[i].charge = read();
		
	for(register int i = 1; i <= n; i++) {
		student[i].v = read();
		student[i].c = student[i].charge/student[i].v;
		if(student[i].c < k)
			q.push(student[i]);
	}
	divide();
	return 0;
}