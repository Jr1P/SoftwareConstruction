#include<cstdio>
using namespace std;
#define N 1000050

int n, t;
int q[N], stack[N];

int main() {
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &q[i]);
    int pos;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        scanf("%d", &pos);
        q[pos] = -q[pos];
    }
    int top = 0;
    for(int i = n; i > 0; i--) {
        if(q[i] < 0)
            stack[++top] = q[i];
        else {
            if(top && q[i]+stack[top] == 0)
                top--;
            else {
                q[i] = -q[i];
                stack[++top] = q[i];
            }
        }
    }
    if(top)
        printf("NO\n");
    else {
        printf("YES\n");
        for(int i = 1; i < n; i++)
            printf("%d ", q[i]);
        printf("%d\n", q[n]);
    }
    return 0;
}
