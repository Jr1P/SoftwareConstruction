#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define L 11000050

string in, s; //in为读入字符串, s为预处理后的字符串
int r[L<<1], l; //s字符串:以下标为中心的 回文串的最大半径，单个字符半径为一

void manacher()
{
    int ctr = 0, right = 0, len = 0;
    int ll = s.length();
    //ctr 目前匹配到的最远字符串的中心, right 最远字符串的右端下标
    for(int i = 0; i < ll; i++)
    {
        r[i] = (right > i) ? min(r[ctr+ctr-i], right-i+1): 1;
        //r[ctr+ctr-i]+ctr不能超过字符串最大长度
        while(i-r[i] >= 0 && i+r[i] < ll && s[i+r[i]] == s[i-r[i]])
            r[i]++;
        if(s[i+r[i]-1] == '#') r[i]--;
        if(r[i] > len) len = r[i];
        if(i+r[i]-1 > right)
        {
            right = i+r[i]-1;
            ctr = i;
        }
    }
    printf("%d\n", len);
}

int main()
{
    for(char c = getchar(); c != '\n' && c != EOF; c = getchar())
        in += c;
    l = in.length();
    for(int i = 0; i < l-1; i++)
        s += in[i], s += '#';
    s += in[l-1];
    manacher();
    return 0;
}
