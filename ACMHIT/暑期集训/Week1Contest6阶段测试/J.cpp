#include<cstdio>
#include<cstring>
#define N 10050
using namespace std;

int ch[N], num[N];
char str1[N], str2[N];
int n, m, t;

void change(char *str1,char *str2) {
    int len, k;
    len = strlen(str1);
    for(int i = len; i >= 0; i--)
        ch[len-1-i] = str1[i]-(str1[i] < 58 ? 48 : str1[i] < 97 ? 55 : 61);
    for(k = 0; len; ) {
        for(int i = len; i >= 1; i--) {
            ch[i-1] += ch[i]%m*n;
            ch[i] /= m;
        }
        num[k++] = ch[0]%m;
        ch[0] /= m;
        while(len > 0 && ch[len-1] == 0)
            len--;
    }
    str2[k] = '\0';
    for(int i = 0; i < k; i++)
        str2[k-1-i] = num[i]+(num[i] < 10 ? 48 : num[i] < 36 ? 55 : 61);
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%s", &n, &m, str1);
        change(str1, str2);
        printf("%d %s\n", n, str1);
        printf("%d %s\n", m, str2);
        if(t) printf("\n");
    }
}