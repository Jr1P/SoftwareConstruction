#include<stdio.h>
#include<math.h>
#include<string>
#include<sstream>

using namespace std;
const int MAXN = 1000000000;
int PP[5050], num = 0;

void find(int x){
	string s;
	stringstream ss;
	ss<<x;
	s = ss.str();
	if(x < 10){
		PP[num] = x;
		num++;
	}
	else{
		int length = s.size(), i = 0, j = length - 1;
		while(i < j){
			if(s[i] != s[j]) return;
			i++;
			j--;
		}
		PP[num] = x;
		num++;
	}
	return;
}

int main(){
	int a, b;
	scanf("%d %d",&a,&b);
	find(a,b);
	for(int i = 0; i < num; i++) 
		printf("%d\n",PP[i]); 
	return 0; 
}
