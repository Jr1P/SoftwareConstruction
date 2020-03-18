#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int a, b;
int m[150];

int input() {
    int ans = 0;
    while(1) {
        string str;
        cin >> str;
        if(str[0] == '+' || str[0] == '=')
            return ans / 10;
        if(str == "two") ans += 2;
        else if(str == "three") ans += 3;
        else if(str == "four") ans += 4;
        else if(str == "five") ans += 5;
        else if(str == "six") ans += 6;
        else if(str == "seven") ans += 7;
        else ans += m[str[0]];
        ans *= 10;
    }
}

int main() {
    m['z'] = 0; m['o'] = 1; m['e'] = 8; m['n'] = 9;
    while(1) {
        a = input();
        b = input();
        if(a == 0 && b == 0) break;
        printf("%d\n", a + b);
    }
    return 0;
}