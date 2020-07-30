#include <cstdio>
#include <cstring>
#include <iostream>
const int Q = 5e5 + 5;
typedef long long ll;
#define eps 1e-7

int q, n;
double a[Q];
double sum[Q];

inline double calc(int r) {
    return (double)(a[n] * r - sum[r]) / (r + 1);
}

int main() {
    scanf("%d", &q);
    while(q--) {
        int cmd;
        scanf("%d", &cmd);
        if(cmd == 1) {
            n++;
            scanf("%lf", &a[n]);
            sum[n] = sum[n - 1] + a[n];
        } else {
            int l = 1, r = n - 1;
            while(l < r - 1) {
                int mid = (l + r) >> 1;
                int mmid = (mid + r) >> 1;
                if(calc(mid) >= calc(mmid))
                    r = mmid;
                else l = mid;
            }
            printf("%.10f\n", std::max(calc(l), calc(r)));
        }   
    }

    return 0;
}