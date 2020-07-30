#include <cstdio>
const int N = 2e5 + 5;

int n;
int men[N];

int main() {
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &men[i]);
    bool d = men[n] == 1;
    for(int i = n - 1; i >= 1; i--)
        if(d && men[i] == 0) {
            printf("%d\n", i);
            break;
        } else if(!d && men[i] == 1) {
            printf("%d\n", i);
            break;
        }
  
    return 0;
}

/*
    while(l <= r) {
        int mid = (l + r) >> 1;
        int mmid = (mid + r) >> 1;

    }
      int l = 1, r = n, ans;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid))
            ans = mid, l = mid + 1;
        else r = mid - 1;
    }

*/