#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int N = 50;

double exch[N][N];
char s[N][N];
int n, m, kase, x, y;

bool floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (exch[i][j] < exch[i][k] * exch[k][j])
                    exch[i][j] = exch[i][k] * exch[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (exch[i][i] > 1.0) return true;
    }
    return false;
}

int main() {
    while (1) {
        scanf("%d", &n);
        if(!n) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) exch[i][j] = 1.0;
                else exch[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        cin >> m;
        double c;
        char a[N], b[N];
        for (int i = 1; i <= m; i++) {
            cin >> a >> c >> b;
            for (int j = 1; j <= n; j++) {
                if (strcmp(s[j], a) == 0) {
                    x = j;
                    break;
                }
            }
            for (int j = 1; j <= n; j++) {
                if (strcmp(s[j], b) == 0) {
                    y = j;
                    break;
                }
            }
            exch[x][y] = c;
        }
        if(floyd())
            printf("Case %d: Yes\n", ++kase);
        else
            printf("Case %d: No\n", ++kase);
    }
    return 0;
}