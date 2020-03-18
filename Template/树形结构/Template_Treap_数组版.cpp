#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long LL;
using namespace std;
#define N 1000500
#define INF 0x7fffffff
//#define ls ch[id][0]
//#define rs ch[id][1]

int n, tot, root;
int ch[N][2], val[N], dat[N], sz[N], cnt[N];
//基本平衡树有以下几个比较重要的函数：新建，插入，删除，旋转
//节点的基本属性有val(值) dat(随机出来的优先级)
//sz编号为i的子树大小,包括自身和自己的副本 cnt结点的副本数量

inline int read() {
    int x = 0;
    char c = getchar();
    bool flag = 0;
    while(c < '0' || c > '9') {
   		if(c == '-')
   			flag = 1;
   		c = getchar();
   	}
    while(c >= '0' && c <= '9') {
    	x = (x << 3) + (x << 1) + (c ^ 48);
    	c = getchar();
    }
    return flag? -x: x;
}

inline int Rand() { 
	static int seed = 703;
	return seed = int(seed*48271LL%(~0u>>1));
}

inline int New(int v) { 
	val[++tot] = v;
	dat[tot] = Rand();
	sz[tot] = 1;
	cnt[tot] = 1;
	return tot;
}

inline void pushup(int id) {
	sz[id] = sz[ch[id][0]]+sz[ch[id][1]]+cnt[id];
}

/*inline void build() {
	root = New(-INF), ch[root][1] = New(INF);
	pushup(root);
}*/

inline void rotate(int &id, int d) { //d为方向 0左旋 1右旋
	int temp = ch[id][d^1];
	ch[id][d^1] = ch[temp][d];
	ch[temp][d] = id;
	id = temp;
	pushup(ch[id][d]);
	pushup(id);
}

void insert(int &id, int v) {
	if(!id) {
		id = New(v);
		return ;
	}
	if(v == val[id]) cnt[id]++;
	else {
		int d = (v < val[id]) ? 0: 1;
		insert(ch[id][d], v);
		if(dat[id] < dat[ch[id][d]])
			rotate(id, d^1);
	}
	pushup(id);
}

void del(int &id, int v) {
	if(!id) return ;
	if(v == val[id]) { 
		if(cnt[id] > 1) {
			cnt[id]--, pushup(id);
			return ;
		}
		if(ch[id][0] || ch[id][1]) {
			if(!ch[id][1] || dat[ch[id][0]] > dat[ch[id][1]])
				rotate(id, 1), del(ch[id][1], v);
			else rotate(id, 0), del(ch[id][0], v);
			pushup(id);
		} else id = 0;
		return ;
	}
	(v < val[id]) ? del(ch[id][0], v) : del(ch[id][1], v);
	pushup(id);
}

int get_rank(int id, int v) {
	if(!id) return 0;
	if(v == val[id])
		return sz[ch[id][0]]+1;
	else if(v < val[id])
		return get_rank(ch[id][0], v);
	else
		return sz[ch[id][0]]+cnt[id]+get_rank(ch[id][1], v);
}
int get_val(int id, int rank) {
	if(!id) return INF;
	if(rank <= sz[ch[id][0]])
		return get_val(ch[id][0], rank);
	else if(rank <= sz[ch[id][0]]+cnt[id])
		return val[id];
	else
		return get_val(ch[id][1], rank-sz[ch[id][0]]-cnt[id]);
}
int get_pre(int v) {
	int id = root, pre;
	while(id) {
		if(val[id] < v)
			pre = val[id], id = ch[id][1];
		else id = ch[id][0];
	}
	return pre;
}
int get_next(int v) {
	int id = root, next;
	while(id) {
		if(val[id] > v)
			next = val[id], id = ch[id][0];
		else id = ch[id][1];
	}
	return next;
}
int main() {
	/*
	1 插入数x
	2 删除数x(若有多个相同的数，因只删除一个)
	3 查询x数的排名(排名定义为比当前数小的数的个数+1。若有多个相同的数，因输出最小的排名)
	4 查询排名为x的数
	5 求xx的前驱(前驱定义为小于x，且最大的数)
	6 求xx的后继(后继定义为大于x，且最小的数)
	*/
	//build();
	n = read();
	for(int i = 1; i <= n; i++) {
		int cmd = read(), x = read();
		switch(cmd) {
			case 1: insert(root, x); break;
			case 2: del(root, x); break;
			case 3: printf("%d\n", get_rank(root, x)); break;
			case 4: printf("%d\n", get_val(root, x)); break;
			case 5: printf("%d\n", get_pre(x)); break;
			case 6: printf("%d\n", get_next(x)); break;
		}
	}
	return 0;
}
