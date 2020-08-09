#include <cstdio>
#include <cstring>
#define L 11000050

char s[L << 1];
int r[L << 1], l, len; //s字符串:以下标为中心的 回文串的最大半径，单个字符半径为一
inline int min(int x, int y) { return x < y ? x : y; }

void manacher() {
    int ctr = 0, right = 0, ans = 0;
    //ctr 目前匹配到的最远字符串的中心, right 最远字符串的右端下标
    for(int i = 0; i < len; i++) {
        r[i] = (right > i) ? min(r[ctr+ctr-i], right-i+1): 1;
        //r[ctr+ctr-i]+ctr不能超过字符串最大长度
        while(i-r[i] >= 0 && i+r[i] < len && s[i+r[i]] == s[i-r[i]])
            r[i]++;
        if(s[i+r[i]-1] == '#') r[i]--;
        if(r[i] > ans) ans = r[i];
        if(i+r[i]-1 > right) {
            right = i+r[i]-1;
            ctr = i;
        }
    }
    printf("%d\n", ans);
}

int main() {
    for(char c = getchar(); c != '\n' && c != EOF; c = getchar())
        s[len++] = '#', s[len++] = c;
    s[len++] = '#';
    // printf("%s", s);
    manacher();
    return 0;
}
