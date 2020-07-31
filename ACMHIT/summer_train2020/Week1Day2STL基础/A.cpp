#include <cstdio>
#include <deque>
const int N = 1e5 + 5;

std::deque<int > q;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        char ch[N];
        bool f = false;
        int bal = 0;
        scanf("%s", ch);
        while(!q.empty()) q.pop_front();
        for(int i = 0; ch[i]; i++)
            if(ch[i] == '*') q.push_back(i);
            else if(ch[i] == '(') bal++;
            else bal--;
        while(bal > 0 && !q.empty()) ch[q.back()] = ')', q.pop_back(), bal--;
        if(bal > 0) {
            puts("No solution!");
            continue;
        }
        int l = 0, r = 0;
        for(int i = 0; ch[i]; i++) {
            if(ch[i] == ')') {
                r++;
                if(r - l > 0) {
                    if(q.empty() || q.front() > i) {
                        puts("No solution!");
                        f = true;
                        break;
                    }
                    ch[q.front()] = '(';
                    q.pop_front();
                    bal++;
                    if(bal > 0) {
                        if(q.empty() || q.back() < i) {
                            puts("No solution!");
                            f = true;
                            break;
                        }
                        ch[q.back()] = ')';
                        q.pop_back();
                        bal--;
                    }
                    l++;
                }
            } else if(ch[i] == '(') l++;
        }
        if(!f) {
            for(int i = 0; ch[i]; i++)
                if(ch[i] != '*') putchar(ch[i]);
            puts("");
        }
    }
    return 0;
}