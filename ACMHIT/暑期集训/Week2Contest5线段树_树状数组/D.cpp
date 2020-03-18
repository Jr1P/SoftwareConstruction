#include <iostream>
#include <cstdio>
using namespace std;
#define N 300050
#define MAX 10000010
typedef long long ll;

int n, m, tot, t, cnt, l, r;
ll phi[MAX], prime[MAX/10];
ll ans;
bool check[MAX];

struct Node{
    int l, r;
    ll w, x;
}node[N << 2];

/*inline ll read() {
    ll x = 0;
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x;
}*/


void get_phi(ll x) {
    check[1] = true;
    phi[1] = 1;
	for(ll i = 2; i <= x; i++)	{
		if(!check[i]) {
			prime[++tot] = i;
			phi[i] = i-1;
		}
		for(ll j = 1; j <= tot && i*prime[j] <= x; j++) {
            check[i*prime[j]] = 1;
			if(i % prime[j]) 
				phi[i*prime[j]] = phi[i]*(prime[j]-1);
			else {
				phi[i*prime[j]] = phi[i]*prime[j];
				break;
			} 
		}
	}
}

inline void push_up(int k) {
    node[k].w = node[k<<1].w+node[k<<1|1].w;
    if(node[k<<1].x == node[k<<1|1].x)
        node[k].x = node[k<<1].x;
    else node[k].x = 0;
}

void build(int l, int r, int k) {
    node[k].l = l; node[k].r = r;
    if(l == r) {
        scanf("%lld", &node[k].w);
        node[k].x = node[k].w;
        return ;
    }
    int mid = (l+r)>>1;
    build(l, mid, k<<1);
    build(mid+1, r, k<<1|1);
    push_up(k);
}

inline void down(int k) {
    int ls = k<<1;
    int rs = k<<1|1;
    node[ls].x = node[rs].x = node[k].x;
    node[ls].w = node[ls].x*1LL*(node[ls].r-node[ls].l+1);
    node[rs].w = node[rs].x*1LL*(node[rs].r-node[rs].l+1);
    node[k].x = 0;
}

void Modify(int k, ll x = 0) {
    if(x == 0) {
        if(node[k].x && node[k].l >= l && node[k].r <= r) {
            node[k].x = phi[node[k].x];
            node[k].w = node[k].x*1LL*(node[k].r-node[k].l+1);
            return ;
        }
        if(node[k].x) down(k);
        ll mid = (node[k].l + node[k].r) >> 1;
        if(l <= mid) Modify(k<<1);
        if(r > mid) Modify(k<<1|1);
        push_up(k);
    } else {
        if (node[k].l >= l && node[k].r <= r) {
            node[k].w = x*1LL*(node[k].r-node[k].l+1);
            node[k].x = x;
            return ;
        }
        if (node[k].x) down(k);
        ll mid = (node[k].l+node[k].r) >> 1;
        if (l <= mid) Modify(k<<1, x);
        if (r > mid) Modify(k<<1|1, x);
        push_up(k);
    }
}

void Inquiry(int k) {
    if ((node[k].l >= l) && (node[k].r <= r)) {
		ans += node[k].w;
		return ;
	}
    if(node[k].x) down(k);
	ll mid = (node[k].l+node[k].r) >> 1;
	if (l <= mid) Inquiry(k<<1);
	if (r > mid) Inquiry(k<<1|1);
}

int main() {
    get_phi(MAX);
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        build(1, n, 1);
        while(m--) {
            int type;
            long long xx;
            scanf("%d%d%d", &type, &l, &r);
            if(type == 1) {
                Modify(1);
            } else if(type == 2) {
                scanf("%lld", &xx);
                Modify(1, xx);
            } else {
                ans = 0;
                Inquiry(1);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}