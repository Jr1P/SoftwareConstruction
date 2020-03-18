#include <cstdio>

int p[500];
int n, q;

int main() {
    scanf("%d", &q);
    while(q--) {
        bool f1 = true, f2 = true;
        int pos1, pos2;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", p+i);
            p[i+n] = p[i];
            if(p[i] == 1) {
                pos1 = i;
                pos2 = i+n;
            }
        }
        for(int i = pos1; i < pos1+n; i++) {
            if(p[i] != i-pos1+1) {
                f1 = false;
                break;
            }
        }
        for(int i = pos2; i > pos2-n; i--) {
            if(p[i] != pos2-i+1) {
                f2 = false;
                break;
            }
        }
        if(!f1 && !f2) puts("NO");
        else puts("YES");
    }
    return 0;
}