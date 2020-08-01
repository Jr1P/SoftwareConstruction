#include <cstdio>
#include <algorithm>
#include <queue>
const int N = 2e5 + 5;
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
	inline bool operator < (const Computer& o) const {
		if (c != o.c) return c > o.c;
		if (v != o.v) return v < o.v;
		return charge > o.charge;
	}
} student[N];

std::priority_queue<Computer > q;

bool check(ll mid) {
	for(int i = 0; i < k; i++) {
		if(q.empty()) return true;
		Computer now = q.top();
		q.pop();
		if(now.charge - now.v * i < 0)
			return false;
		now.charge += mid;
		now.c = now.charge/now.v;
		if(now.c < k) q.push(now);
		if(q.empty())
			return true;
	}
	return true;
}

void divide() {
	while(l < r) {
		ll mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
		while(!q.empty()) q.pop();
		for(int i = 1; i <= n; i++)
			if(student[i].c < k)
				q.push(student[i]);
	}
	if(l >= R - 1) printf("-1");
	else printf("%lld", l);
}

int main() {
	n = read();
	k = read();
	for(int i = 1; i <= n; i++)
		student[i].charge = read();
	for(int i = 1; i <= n; i++) {
		student[i].v = read();
		student[i].c = student[i].charge / student[i].v;
		if(student[i].c < k)
			q.push(student[i]);
	}
	divide();
	return 0;
}