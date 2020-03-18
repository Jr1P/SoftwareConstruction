#include <cstdio>
#include <cstdlib>
#define N 100500

int m, k, top;
bool f[N], flag;
char st[N];


inline int calc(char *s) {
	int ans = 0;
	for(int i = 0; i < k; i++)
		ans += ans*2+s[i]-'0';
	return ans;
}

void dfs() {
	if(flag) return ;
	if(top == m) {
		for(int i = 1; i <= m-k; i++)
			putchar(st[i]);
		for(int i = 1; i <= k; i++)
			putchar('1');
		printf("\n");
		flag = true;
		return ;
	}
	char ch[1000];
	for(int j = top; j > top-k+1; j--) {
		ch[top-j] = st[j];
	}
	ch[k-1] = '0';
	ch[k] = '\0';
	int p = calc(ch);
	if(!f[p]) {
		st[++top] = '0';
		f[p] = 1;
		dfs();
		top--;
		f[p] = 0;
	}
	ch[k-1] = '1';
	p = calc(ch);
	if(!f[p]) {
		st[++top] = '1';
		f[p] = 1;
		dfs();
		top--;
		f[p] = 0;
	}
}

int main() {
	while(scanf("%d", &k) != EOF) {
		flag = false;
		top = 0;
		m = 1<<k;
		printf("%d ", m);
		for(int i = 0; i <= m; i++) f[i] = false;
		for(int i = 1; i < k; i++)
			st[++top] = '0';
		dfs();
	}
	return 0;
}