#include<stdio.h>
#include<math.h>
#include<string>
#include<sstream>

using namespace std;
const int MAXN = 1000000000;
int PP[5050], num = 0;

/*void check(int x){
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
}*/

int findPrime(int l, int r){
	int flag = 1; 
	for(int i = l; i < r + 1; i++){
		for(int j = 2; j < (int)sqrt(i) + 1 ; j++)
			if(i % j == 0 ){
				flag = 0;
				break;
			}
		//if(flag == 1) check(i);
		if(flag) printf("%d ",i);
		flag = 1;
	}
	return 0;
}

int main(){
	int a, b;
	scanf("%d %d",&a,&b);
	findPrime(a,b);
	//for(int i = 0; i < num; i++) 
	//	printf("%d\n",PP[i]); 
	return 0; 
}
