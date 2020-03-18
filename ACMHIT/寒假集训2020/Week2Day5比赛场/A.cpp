#include <cstdio>
#include <string>
#include <iostream>
int n;
std::string s1, s2, s3;

int main() {
    scanf("%d", &n);
    std::cin >> s1 >> s2;
    for(int i = 0; i < n; i++) {
        if(s1[i] == 'R' && s2[i] != 'S') {
            putchar('P');
            continue;
        }
        if(s1[i] == 'R' && s2[i] == 'S') {
            putchar('R');
            continue;
        }
        if(s1[i] == 'S' && s2[i] != 'P') {
            putchar('R');
            continue;
        }
        if(s1[i] == 'S' && s2[i] == 'P') {
            putchar('S');
            continue;
        }
        if(s1[i] == 'P' && s2[i] != 'R') {
            putchar('S');
            continue;
        }
        if(s1[i] == 'P' && s2[i] == 'R') {
            putchar('P');
            continue;
        }
    }
    return 0;
}