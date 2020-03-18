#include <cstdio>
#define N 1050
#define INF 0x7fffffff

int q[N], num[N][N], max[N][N], min[N][N], _max[N][N], _min[N][N];
int a, b, n, front, back, ans = INF;

inline int __min(int x, int y) {
    return x<y?x:y;
}

int main() {
    scanf("%d%d%d", &a, &b, &n);
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++)
            scanf("%d", &num[i][j]);
    for(int i = 1; i <= a; i++) {
        front = back = 0;
        for(int j = 1; j <= b; j++) {
            if(front != back && j-q[front+1] == n)
                ++front;
            while(front != back && num[i][j] <= num[i][q[back]])
                back--;
            q[++back] = j;
            min[i][j] = num[i][q[front+1]];
        }
        front = back = 0;
        for(int j = 1; j <= b; j++) {
            if(front != back && j-q[front+1] == n)
                ++front;
            while(front != back && num[i][j] >= num[i][q[back]])
                --back;
            q[++back] = j;
            max[i][j] = num[i][q[front+1]];
        }
    }
    for(int j = n; j <= b; j++) {
        front = back = 0;
        for(int i = 1; i <= a; i++) {
            if(front != back && i-q[front+1] == n)
                ++front;
            while(front != back && min[i][j] <= min[q[back]][j])
                --back;
            q[++back] = i;
            _min[i][j] = min[q[front+1]][j];
        }
        front = back = 0;
        for(int i = 1; i <= a; i++) {
            if(front != back && i-q[front+1] == n)
                ++front;
            while(front != back && max[i][j] >= max[q[back]][j])
                --back;
            q[++back] = i;
            _max[i][j] = _max[q[front+1]][j];
        }
    }
    for(int i = n; i <= a; i++)
        for(int j = n; j <= b; j++)
            ans = __min(ans, _max[i][j]-_min[i][j]);
    printf("%d\n", ans);
    return 0;
}