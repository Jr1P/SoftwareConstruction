#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define N 35
#define L 25

int n;
char str[N][L];

bool find1(char ch) {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < strlen(str[i]); j++)
			if(str[i][j] == ch) return 1;
	}
	return 0;
}

bool find2(char ch1, char ch2) {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < strlen(str[i])-1; j++)
			if(str[i][j] == ch1 && str[i][j+1] == ch2)
				return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%s", str[i]);
	for(int i = 0; i < 26; i++)
		if(!find1(i+'a')) {
			printf("%c\n", i+'a');
			return 0;
		}
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			if(!find2(i+'a', j+'a')) {
				printf("%c%c\n", i+'a', j+'a');
				return 0;
			}
	return 0;
}
