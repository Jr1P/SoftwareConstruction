#include <cstdio>

int n;

bool check(int x) {
	if (x % 2 == 0) return false;
	for(int i = 3; i*i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int main() {
	scanf("%d", &n);
	//for(int i = 3; i <= 100000; i++) {
		//printf("n == %d\n", n); //
		if(check(n))
			printf("1\n%d\n", n);
		else {
			printf("3\n");
			int d = n/3;
			while(!check(d)) d--;
			n -= d;
			int p = n/2;
			while(!check(p) || !check(n-p)) p--;
			n-=p;
			printf("%d %d %d\n", d, p, n);
		}
	//}
	//}
	return 0;
}