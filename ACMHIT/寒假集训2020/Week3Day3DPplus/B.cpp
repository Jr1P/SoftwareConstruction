#include <cstdio>
#include <cstring>
const int L = 105;

char a[L], b[L];
int ma[L][L], f[L][L];

void LCS() {
    int la = strlen(a + 1), lb = strlen(b + 1);
    for(int i = 1; i <= la; i++) ma[i][0] = 1;
    for(int i = 1; i <= lb; i++) ma[0][i] = -1;
    for(int i = 1; i <= la; i++)
        for(int j = 1; j <= lb; j++) {
            if(a[i] == b[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
                ma[i][j] = 0;
            }
            else if(f[i - 1][j] >= f[i][j - 1]) {
                f[i][j] = f[i - 1][j];
                ma[i][j] = 1;
            } else {
                f[i][j] = f[i][j - 1];
                ma[i][j] = -1;
            }
        }
}

void print(int i, int j) {
    if(!i && !j) return ;
    if(ma[i][j] == 0) {
        print(i - 1, j - 1);
        putchar(a[i]);
    } else if(ma[i][j] == 1) {
        print(i - 1, j);
        putchar(a[i]);
    } else {
        print(i, j - 1);
        putchar(b[j]);
    }
}

int main() {
    while(~scanf("%s%s", a + 1, b + 1)) {
        memset(f, 0, sizeof(f));
        LCS();
        print(strlen(a + 1), strlen(b + 1));
        puts("");
    }
    return 0;
}