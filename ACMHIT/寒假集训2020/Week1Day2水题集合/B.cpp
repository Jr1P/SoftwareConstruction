#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int t;
string str[2];

int get(string str) {
    
        if(str == "rat") return 1;
        if(str == "ox") return 2;
        if(str == "tiger") return 3;
        if(str == "rabbit") return 4;
        if(str == "dragon") return 5;
        if(str == "snake") return 6;
        if(str == "horse") return 7;
        if(str == "sheep") return 8;
        if(str == "monkey") return 9;
        if(str == "rooster") return 10;
        if(str == "dog") return 11;
        if(str == "pig") return 12;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> str[0] >> str[1];
        int ans = get(str[1]) - get(str[0]);
        if(ans <= 0) ans += 12;
        printf("%d\n", ans);
    }
    return 0;
}