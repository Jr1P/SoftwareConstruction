#include <cstdio>
#include <stack>

int n;
char ch[1001];
std::stack<char > s;

int main() {
    while(~scanf("%s", ch)) {
        while(!s.empty()) s.pop();
        for(int i = 0; ch[i]; i++)
            if(ch[i] == '(')
                s.push('(');
            else if(ch[i] == ')')
                s.pop();
            else {
                printf("%d\n", s.size());
                break;
            }
    }
    return 0;
}