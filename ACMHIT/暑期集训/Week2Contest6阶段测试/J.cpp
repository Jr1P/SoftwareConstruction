#include <cstdio>
#include <cstring>
#define N 1e9
#define M 25
typedef long long ll;

int n, m, MOD, res;
char ch[M];
int nxt[M];

struct Mat {
	int m[M][M];
}ans, e, a, ini;

void kmp(char *s) {
	int l = strlen(s);
	nxt[0] = nxt[1] = 0;
	for(int i = 1; i < l; i++) {
		int j = nxt[i];
		//a.m[i][j]++;
		while(j && s[i] != s[j]) j = nxt[j];
		nxt[i+1] = s[i] == s[j]? j+1: 0;
	}
}

void pre() {
	for(int i = 0; i < m; i++)
		for(int j = 0; j <= 9; j++) {
			int t = i;
			while(t && ch[t]-'0' != j) t = nxt[t];
			if(ch[t]-'0' == j) t++;	
			a.m[i][t]++;
		}
}

Mat Mul(Mat a, Mat b) {
	Mat tmp;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			tmp.m[i][j] = 0;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < m; k++)
				tmp.m[i][j] = (tmp.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
	return tmp;
}

Mat qsm(Mat a, ll b) {
	Mat ans = e;
	ans.m[0][0] = 1;
	while(b) {
		if(b&1) ans = Mul(ans, a);
		a = Mul(a, a);
		b >>= 1;
	}
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &MOD);
	scanf("%s", ch);
	kmp(ch); pre();
	ans = qsm(a, n);
	for(int i = 0; i < m; i++)
		res = (res+ans.m[0][i])%MOD;
	printf("%d\n", res);
	return 0;
}