#include <cstdio>
#include <stack>
const int N = 1001;

int n, a[N], num;
std::stack<int > s;

int main() {
    bool b = false;
    while(~scanf("%d", &n)) {
        if(!n) break;
        if(b) puts("");
        b = true;
        while(1) {
            num = 0;
            while(!s.empty()) s.pop();
            bool f = false;
            scanf("%d", &a[1]);
            if(!a[1]) break;
            for(int i = 2; i <= n; i++) scanf("%d", &a[i]);
            for(int i = 1; i <= n; i++) {
                if(s.empty() || a[i] > s.top()){
                    for(int j = num; j < a[i]; j++) s.push(j);
                    num = a[i] + 1;
                } else if(a[i] < s.top()) {
                    puts("No");
                    f = true;
                    break;
                } else s.pop();
            }
            if(!f) puts("Yes");
        }
    }
    return 0;
}