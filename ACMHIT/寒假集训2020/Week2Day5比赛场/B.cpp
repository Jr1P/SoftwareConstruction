#include <cstdio>
#include <cstring>
#include <iostream>
const int L = 3000005;

int n, m;
char str[L];

int main() {
    while(~scanf("%s", &str)) {
        int len = strlen(str);
        int ans = 0, cnt = 1, flag = 0;;
        for(int i = 0; i < len - 1; i++) {
            if(str[i] < str[i + 1]) {
                ans += cnt;
                cnt = 1;
                flag = 1;
            }
            else if(str[i] > str[i + 1]) {
                cnt = 1;
                flag = 1;
            }
            else cnt++;
        }
        // if(!flag) ans += cnt - 1;
        printf("%d\n", ans);
    }
    return 0;
}