#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000500

clock_t start, stop;
float a[N], p[N];
double duration = 0.0;

void psum(float a[], float p[], long n) {
	long i;
	float tmp0, tmp1, tmp2, tmp3, tmp4 = 0.0f, tmp;
	for(i = 0; i < n-3; i += 4) {
		tmp0 = a[i];
		tmp1 = a[i+1];
		tmp2 = a[i+2];
		tmp3 = a[i+3];
		tmp = tmp0+tmp1;

		p[i] = tmp4+tmp0;
		p[i+1] = tmp4+tmp;
		p[i+2] = tmp4+(tmp+tmp2);
		p[i+3] = (tmp4+tmp)+(tmp2+tmp3);

		tmp4 += tmp+(tmp2+tmp3);
	}
	for(; i < n; i++)
		p[i] = p[i-1]+a[i];
}

void psum4(float a[], float p[], long n) {
	long i;
	float tmp, tmp1, tmp2, tmp3 = 0;

	for (i = 0; i < n - 3; i += 4) {
		tmp = tmp3 + a[i];
		tmp1 = tmp + a[i + 1];
		tmp2 = tmp1 + a[i + 2];
		tmp3 = tmp2 + a[i + 3];

		p[i] = tmp;
		p[i + 1] = tmp1;
		p[i + 2] = tmp2;
		p[i + 3] = tmp3;
	}

	for (; i < n; i++) {
		tmp3 += a[i];
		p[i] = tmp3;
	}
}

void psum1(float a[], float p[], long n) {
	long i;
	p[0] = a[0];
	for(i = 1; i < n; i++)
		p[i] = p[i-1]+a[i];
}

void psum2(float a[], float p[], long n) {
	long i;
	float last_val, val;
	last_val = p[0] = a[0];
	for(i = 1; i < n; i++) {
		val = last_val+a[i];
		p[i] = val;
		last_val = val;
	}
}

void psum_xyt(float a[], float p[], long n)
{
    long i;
    float last_val, val;
    last_val = p[0] = a[0];
    for (i=1;i<n-1;i+=2)
    {
        val = last_val + a[i];
        p[i] = val;
        last_val = val + a[i+1];
        p[i+1] = last_val;
       
    }
    for (;i<n;i++)
    {
        val = last_val + a[i];
        p[i] = val;
        last_val = val;
    }
}

void init() {
	for(int i = 0; i < N; i++)
		a[i] = 1.0;
}

int main() {

	init();
	puts("Begin");

	start = clock();
	psum1(a, p, N-1);
	stop = clock();
	duration = (double)(stop-start)/CLOCK_TAI;
	printf("pusm1 : %f\n", duration);

	start = clock();
	psum(a, p, N-1);
	stop = clock();
	duration = (double)(stop-start)/CLOCK_TAI;
	printf("pusm_TZK : %f\n", duration);

	start = clock();
	psum2(a, p, N-1);
	stop = clock();
	duration = (double)(stop-start)/CLOCK_TAI;
	printf("pusm2 : %f\n", duration);

	start = clock();
	psum4(a, p, N-1);
	stop = clock();
	duration = (double)(stop-start)/CLOCK_TAI;
	printf("pusm4 : %f\n", duration);

	start = clock();
	psum_xyt(a, p, N-1);
	stop = clock();
	duration = (double)(stop-start)/CLOCK_TAI;
	printf("pusm_XYT : %f\n", duration);

	return 0;
}