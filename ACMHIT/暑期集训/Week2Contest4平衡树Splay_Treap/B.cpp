#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
typedef long long LL;
using namespace std;
int Rand() { 
	static int seed=703;
	return seed=int(seed*48271LL%(~0u>>1));
}

const int maxn = 100050,INF = 1e9;

int na;
int ch[maxn][2];
int val[maxn],dat[maxn];
int size[maxn],cnt[maxn];
int tot,root;
int New(int v) { 
	val[++tot] = v;
	dat[tot] = Rand();
	size[tot] = 1;
	cnt[tot] = 1;
	return tot;
}
void pushup(int id) {
	size[id] = size[ch[id][0]] + size[ch[id][1]] + cnt[id];
}
void build() {
	root = New(-INF),ch[root][1] = New(INF);
	pushup(root);
}
void Rotate(int &id,int d) {
	int temp = ch[id][d ^ 1];
	ch[id][d ^ 1] = ch[temp][d];
	ch[temp][d] = id;
	id = temp;
	pushup(ch[id][d]),pushup(id);
}
void insert(int &id,int v) {
	if(!id) {
		id = New(v);
		return ;
	}
	if(v == val[id])cnt[id]++;
	else {
		int d = v < val[id] ? 0 : 1;
		insert(ch[id][d],v);
		if(dat[id] < dat[ch[id][d]])Rotate(id,d ^ 1);
	}
	pushup(id);
}

int get_pre(int v) {
	int id = root,pre;
	while(id) {
		if(val[id] <= v)pre = val[id],id = ch[id][1];
		else id = ch[id][0];
	}
	return pre;
}

int main() {
	int n;
	build();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		char ch = getchar();
		ch = getchar();
		int x;
		scanf("%d", &x);
		if(ch == 'I') insert(root,x);

		else printf("%d\n",get_pre(x));
	}
	return 0;
}
