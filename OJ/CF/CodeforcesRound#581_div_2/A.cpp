#include <cstdio>
#include <cstring>
char s[200];

int main() {
    scanf("%s", s);
    if(s[0] == '0' && strlen(s) == 1) puts("0");
    else if(s[0] == '1' && strlen(s) == 1) puts("0");
    else {
        int cnt = 0;
        for(int i = 0; i < strlen(s); i++){
            if(s[i] == '1')
                cnt++;
        }
        if(cnt == 1) printf("%d\n", strlen(s)/2);
        else {
            if(strlen(s) % 2 == 1)
                printf("%d\n", (strlen(s)-1)/2+1);
            else printf("%d\n", strlen(s)/2);
        }
    }
    return 0;
}