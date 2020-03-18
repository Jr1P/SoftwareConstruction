#include <cstdio>
#include <cstdlib>
#define N 20050
#define M 60050
#define Q 500050

typedef long long ll;

inline int Rand() {
	static int seed = 703;
	return seed = int(seed * 48271LL % (~0u >> 1));
}

struct Node {
	int pr, val, sz, dup;
	Node *ch[2];

	Node() { sz = dup = pr = 0; }
	Node(int v) : val(v) { ch[0] = ch[1] = NULL; pr = Rand(); sz = dup = 1; }
	inline int cmp(int x) {
		if(x == val) return -1;
		return x < val ? 0 : 1;
	}

	inline void pushup() {
		sz = dup;
		if(ch[0] != NULL) sz += ch[0]->sz;
		if(ch[1] != NULL) sz += ch[1]->sz;
	}
} *root[N];

struct Query {
	char type;
	int x, val;
} query[Q];

inline int read() {
	int x = 0;
	bool flag = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') flag = 1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return flag ? -x : x;
}

inline void rotate(Node* &node, int d) {
	Node* x = node->ch[d^1];
	node->ch[d^1] = x->ch[d];
	x->ch[d] = node;
	node = x;
	node->ch[d]->pushup();
	node->pushup();
}

void insert(Node* &root, int val) {
	if(root == NULL)
		root = new Node(val);
	else {
		int d = val < root->val ? 0 : 1;
		insert(root->ch[d], val);
		if(root->pr < root->ch[d]->pr)
			rotate(root, d^1);
	}
	root->pushup();
}

void del(Node* &root, int val) {
	if(root == NULL) return ;
	int d = root->cmp(val);
	if(d == -1) {
		Node* u = root;
		if(root->dup > 1) {
			root->dup--;
			root->pushup();
		} else {
			if(root->ch[0] == NULL) root = root->ch[1], delete u;
			else if(root->ch[1] == NULL) root = root->ch[0], delete u;
			else {
				if(root->ch[0]->pr > root->ch[1]->pr)
					rotate(root, 1), del(root->ch[1], val);
				else rotate(root, 0), del(root->ch[0], val);
			}
		}
	} else
		del(root->ch[d], val);
	if(root != NULL) root->pushup();
}

inline int Kth(Node* root, int k) {
	if(root == NULL || k > root->sz || k <= 0) return 0;
	int s = root->ch[1] == NULL ? 0 : root->ch[1]->sz;
	if(k <= s)
		return Kth(root->ch[1], k);
	if(k <= s + root->dup)
		return root->val;
	return Kth(root->ch[0], k - s - root->dup);
}

int t, n, m;
int fa[N], weight[N], from[M], to[M], cnt;
ll sum;
bool removed[M];

inline int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge(Node* &x, Node* &y) {
	if(x->ch[0] != NULL) merge(x->ch[0], y);
	if(x->ch[1] != NULL) merge(x->ch[1], y);
	insert(y, x->val);
	delete x;
	x = NULL;
} // x合并到y里

inline void removetree(Node* &root) {
	if(root->ch[0] != NULL) removetree(root->ch[0]);
	if(root->ch[1] != NULL) removetree(root->ch[1]);
	delete root;
	root = NULL;
}

inline void add_edge(int x) {
	int u = find(from[x]), v = find(to[x]);
	if(u != v) {
		if(root[u]->sz < root[v]->sz) fa[u] = v, merge(root[u], root[v]);
		else fa[v] = u, merge(root[v], root[u]);
	}
}

inline void qquery(int x, int k) {
	cnt++;
	sum += Kth(root[find(x)], k);
}

inline void change_weight(int x, int val) {
	int u = find(x);
	del(root[u], weight[x]);
	insert(root[u], val);
	weight[x] = val;
}

int main() {
	int kase = 0;
	while(1) {
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0) break;
		cnt = 0; sum = 0;
		for(int i = 1; i <= n; i++) weight[i] = read();
		for(int i = 1; i <= m; i++) {
			from[i] = read();
			to[i] = read();
			removed[i] = false;
		}
		int q = 0;
		while(1) {
			char type;
			int x, val = 0;
			scanf("%c", &type);
			if(type == 'E') break;
			x = read();
			if(type == 'D') removed[x] = true;
			else if(type == 'Q') val = read();
			else {
				val = read();
				int a = weight[x];
				weight[x] = val;
				val = a;
			}
			query[++q] = (Query){ type, x, val };
		}
		for(int i = 1; i <= n; i++) {
			fa[i] = i;
			if(root[i] != NULL) removetree(root[i]);
			root[i] = new Node(weight[i]);
		}
		for(int i = 1; i <= m; i++) if(!removed[i]) add_edge(i);
		for(int i = q; i; i--){
			if(query[i].type == 'D') add_edge(query[i].x);
			else if(query[i].type == 'Q') qquery(query[i].x, query[i].val);
			else change_weight(query[i].x, query[i].val);
		}
		printf("Case %d: %.6f\n", ++kase, (double)sum / (double)cnt);
	}
	return 0;
}
