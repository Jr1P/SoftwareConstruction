
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int n;
vector<int>to[100010];
int twiceNode[400020];
int reTwiceNode[400020];
int vis[100010];
int tot;
int w[100010];
int m[100010][2];
inline void DFS(int x)
{
	for (int i = 0; i < to[x].size(); i++) {
		if (vis[to[x][i]] == 0) {
			vis[to[x][i]] = 1;
			twiceNode[++tot] = to[x][i];
			if(reTwiceNode[to[x][i]]==0)
				reTwiceNode[to[x][i]] = tot;
			DFS(to[x][i]);
		}
	}
	twiceNode[++tot] = -x;
	reTwiceNode[x+n] = tot;
	return;
}

struct node {
	int l, r;
	node* cl;
	node* cr;
	set<int> ki;
};

inline void build(node* fa, int l, int r)
{
	if (l == r) {
		fa->l = l;
		fa->r = r;
		fa->cl = NULL;
		fa->cr = NULL;
		fa->ki.insert(w[twiceNode[l] > 0 ? twiceNode[l] : -twiceNode[l]]);
		return;
	}
	int mid = (l + r) >> 1;
	node* cl = new node;
	node* cr = new node;
	fa->l = l;
	fa->r = r;
	fa->cl = cl;
	fa->cr = cr;
	build(cl, l, mid);
	build(cr, mid + 1, r);
	fa->ki.insert(cl->ki.begin(), cl->ki.end());
	fa->ki.insert(cr->ki.begin(), cr->ki.end());
	return;
}

inline set<int> query(node* fa, int l, int r)
{
	set <int> kong;
	if (fa->l > r || fa->r < l) return kong;
	if (fa->l >= l && fa->r <= r) return fa->ki;
	set<int>ls = query(fa->cl, l, r);
	set<int>rs = query(fa->cr, l, r);
	kong.insert(ls.begin(), ls.end());
	kong.insert(rs.begin(), rs.end());
	return kong;
}

int main()
{
	//freopen("in", "r", stdin);
	while (scanf("%d", &n) != EOF) {

		memset(m, 0, sizeof(m));
		memset(twiceNode, 0, sizeof(twiceNode));
		memset(reTwiceNode, 0, sizeof(reTwiceNode));
		memset(vis, 0, sizeof(vis));
		tot = 0;
		for (int i = 1; i <= n; i++) {
			to[i].clear();
		}

		for (int i = 2; i <= n; i++) {
			int t;
			scanf("%d", &t);
			m[i - 1][0] = t;
			m[i - 1][1] = i;
			to[i].push_back(t);
			to[t].push_back(i);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &w[i]);
		}
		twiceNode[++tot] = 1;
		reTwiceNode[1] = tot;
		vis[1] = 1;
		DFS(1);
		for (int i = 1; i <= tot; i++) {
			twiceNode[tot + i] = twiceNode[i];
		}
		tot *= 2;
		node* Root = new node;
		build(Root, 1, tot);
		int ans = 0;
		for (int i = 1; i <= n - 1; i++) {
			int l1, r1, l2, r2;
			l1 = reTwiceNode[m[1][1]];
			r1 = reTwiceNode[n+m[1][1]];
			l2 = r1 + 1;
			r2 = l1 + 2 * n - 1;
			set<int>v1;
			set<int>v2;
			v1 = query(Root, l1, r1);
			v2 = query(Root, l2, r2);
			ans = ans > v1.size()+v2.size() ? ans : v1.size() + v2.size();
		}
		printf("%d\n", ans);
	}
}
