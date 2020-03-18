#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define N 200050

int n;
char str[N];
stack<char> s;

int main() {
    int flag = 0;
    scanf("%d", &n);
    scanf("%s", str);
    if(n&1) {
        puts("No");
        return 0;
    }
    while(!s.empty()) s.pop();
    for(int i = 0; i < n; i++) {
        if(str[i] == '(') {
            s.push('(');
        }
        else if(str[i] == ')') {
            if(!s.empty())
                s.pop();
            else
                flag++;
        }
    }
    if(flag <= 1 && s.size() <= 1) puts("Yes");
    else puts("No");
    return 0;
}