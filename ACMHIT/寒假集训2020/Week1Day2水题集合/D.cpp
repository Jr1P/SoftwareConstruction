#include <cstdio>
#include <cstring>
using namespace std;
#define N 30 

int x;
int sum[N];

int main() {
    for(int i = 1; i < N; i += 2) sum[i] = (i * i + 1) / 2;
    scanf("%d", &x);
    if(x == 3) {
        printf("5\n");
        return 0;
    }
    for(int i = 1; i < N; i += 2) {
        if(sum[i] >= x) {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}