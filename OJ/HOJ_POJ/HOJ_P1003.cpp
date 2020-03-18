#include<stdio.h>
const int MAXN = 200000, MAXM = 5000;
int  price[MAXM + 50], amount[MAXM + 50];

void swap(int *x, int *y){
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
void quickSort(int l, int r){
	int i = l, j = r, mid = price[(l + r) / 2];
	while(i <= j){
		while(price[i] < mid) i++;
		while(price[j] > mid) j--;
		if(i <= j){
			swap(&price[i],&price[j]);
			swap(&amount[i],&amount[j]);
			i++;
			j--;
		}
	}
	if(i < r) quickSort(i,r);
	if(j > l) quickSort(l,j);
} 

int main(){
	int n, m, now = 0, expense = 0, k = 0;
	scanf("%d %d\n",&n,&m);
	for(int i = 0; i < m; i++) 
		scanf("%d %d\n",&price[i],&amount[i]);
	quickSort(0,m-1);
	while(now < n){
		if(now + amount[k] > n) expense += price[k] * (n - now);
		else expense += price[k] * amount[k];
		now += amount[k];
		k++;  
	}
	printf("%d",expense);
	/*for(int i = 0; i < m; i++)
		printf("%d %d\n",amount[i],price[i]);*/
	return 0;
} 
