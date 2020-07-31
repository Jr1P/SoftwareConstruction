#include <cstdio>
#include <stack>
#include <queue>

int t, n;
char ch[10];
std::stack<int > s;
std::queue<int > q;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%s", &n, ch);
        if(ch[2] == 'F') {
            while(!q.empty()) q.pop();
            while(n--) {
                char cmd[5];
                scanf("%s", cmd);
                if(cmd[0] == 'I') {
                    int tmp;
                    scanf("%d", &tmp);
                    q.push(tmp);
                } else {
                    if(!q.empty()) {
                        printf("%d\n", q.front());
                        q.pop();
                    } else puts("None");
                }
            }
        } else {
            while(!s.empty()) s.pop();
            while(n--) {
                char cmd[5];
                scanf("%s", cmd);
                if(cmd[0] == 'I') {
                    int tmp;
                    scanf("%d", &tmp);
                    s.push(tmp);
                } else {
                    if(!s.empty()) {
                        printf("%d\n", s.top());
                        s.pop();
                    } else puts("None");
                }
            }
        }
    }
    return 0;
}