#include <cstdio>
#include <ctime>
#include <cstdlib>
// #define PRESENT 1
const int N = 1e7 + 5;

int a[N];
int n;
double duration;
clock_t begin, end;

inline void Rand() {
	for(int i = 1; i <= n; i++)
		a[i] = rand() % 501;
}

int normal() {
	int sum = 0;
	for(int i = 1; i <= n; i++)
		sum += a[i];
	return sum;
}

int k2_1() {
	int sum = 0, i;
	for(i = 1; i <= n - 1; i += 2) {
		sum += a[i];
		sum += a[i + 1];
	}
	for(; i <= n; i++)
	sum += a[i];
	return sum;
}

int k3_1() {
	int sum = 0, i;
	for(i = 1; i <= n - 2; i += 3) {
		sum += a[i];
		sum += a[i + 1];
		sum += a[i + 2];
	}
	for(; i <= n; i++)
		sum += a[i];
	return sum;
}

int k2_2() {
	int i, sum0 = 0, sum1 = 0;
	for(i = 1; i <= n - 1; i += 2) {
		sum0 += a[i];
		sum1 += a[i + 1];
	}
	for(i; i <= n; i++)
		sum0 += a[i];
	return sum0 + sum1;
}

int k5_5() {
	int i, sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	for(i = 1; i <= n - 4; i += 5) {
		sum0 += a[i];
		sum1 += a[i + 1];
		sum2 += a[i + 2];
		sum3 += a[i + 3];
		sum4 += a[i + 4];
	}
	for(i; i <= n; i++)
		sum0 += a[i];
	return sum0 + sum1 + sum2 + sum3 + sum4;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	srand(time(NULL));
	int t = 50; 
	while(t--) {
		Rand();
		int sum;
		/*
		begin = clock();
		sum = normal();
		end = clock();
		duration = (double)(end - begin) / CLOCK_TAI;
		#ifdef PRESENT
			printf("1*1: sum = %d\t duration = %f\n", sum, duration);
		#else
			printf("%f\n", duration);
		#endif
		
		begin = clock();
		sum = k2_1();
		end = clock();
		duration = (double)(end - begin) / CLOCK_TAI;
		#ifdef PRESENT
			printf("2*1: sum = %d\t duration = %f\n", sum, duration);
		#else
			printf("%f\n", duration);
		#endif
		
		begin = clock();
		sum = k3_1();
		end = clock();
		duration = (double)(end - begin) / CLOCK_TAI;
		#ifdef PRESENT
			printf("3*1: sum = %d\t duration = %f\n", sum, duration);
		#else
			printf("%f\n", duration);
		#endif
				
		begin = clock();
		sum = k2_2();
		end = clock();
		duration = (double)(end - begin) / CLOCK_TAI;
		#ifdef PRESENT
			printf("2*2: sum = %d\t duration = %f\n", sum, duration);
		#else
			printf("%f\n", duration);
		#endif
		*/
		begin = clock();
		sum = k5_5();
		end = clock();
		duration = (double)(end - begin) / CLOCK_TAI;
		#ifdef PRESENT
			printf("5*5: sum = %d\t duration = %f\n", sum, duration);
		#else
			printf("%f\n", duration);
		#endif

	}
	return 0;
}
