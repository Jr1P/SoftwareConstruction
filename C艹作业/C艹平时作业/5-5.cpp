#include <iostream>
using namespace std;
//Jr.P

/*inline void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}*/

int Input (long num[], float score[][3]){
    int cnt = 1;
    //cout<<"Enter the student number and the score:"<<endl;
    cin >> num[cnt];
    while (cnt <= 30 && num[cnt] >= 0)
    {
    	cin >> score[cnt][0] >> score[cnt][1] >> score[cnt][2];
    	cnt++;
    	cin >> num[cnt];
    }
    return --cnt;
}

void Total1(float score[][3], float sum[], float aver[], int n){
    for (int i = 1; i <= n; i++)
    {
    	sum[i] = score[i][0] + score[i][1] + score[i][2];
    	aver[i] = sum[i] / 3;
    }
}

void Total2(float score[][3], float sum[], float aver[], int n){
    for(int i = 1; i <= n; i++)
    {
    	sum[0] += score[i][0];
    	sum[1] += score[i][1];
    	sum[2] += score[i][2];
    }
    if (n != 0) 
    {
	  	aver[0] = sum[0] / n;
	  	aver[1] = sum[1] / n;
	  	aver[2] = sum[2] / n;
  	}
}

void Total3(long num[],float score[][3],float sum[],float aver[],int n){
    for (int i = 1; i <= n; i++)
    {
    	int k = i;
    	for (int j = n; j > i; j--)
    		if (sum[j] > sum[k])
    			k = j;
    	swap(num[k], num[i]);
    	swap(score[k][0], score[i][0]);
    	swap(score[k][1], score[i][1]);
    	swap(score[k][2], score[i][2]);
    	swap(sum[k], sum[i]);
   		swap(aver[k], aver[i]);
	}
}

void Print(long num[],float score[][3],float sum1[],float aver1[],float sum2[],float aver2[],int n){
    cout<<"Pos\tNumber\tGrad1\tGrad2\tGrad3\tSum1\tAver1"<<endl;
    for (int i = 1; i <= n; i++)
    	cout << i << '\t' << num[i] << '\t' << score[i][0] << '\t' << score[i][1] << '\t' << score[i][2] << '\t' << sum1[i] << '\t' << aver1[i] << '\n';
    cout<<"No\tSum2\tAver2"<<endl;
    for (int i = 0; i < 3; i++)
    	cout << i + 1 << '\t' << sum2[i] << '\t' << aver2[i] << '\n';
}

int main(){
	const int MAX = 30+5; 
	long num[MAX];
	float score[MAX][3], sum1[MAX] = {0};
	float sum2[3] = {0}, aver1[MAX] = {0}, aver2[3] = {0};
	int number = Input(num, score);
	Total1(score, sum1, aver1, number);
	Total2(score, sum2, aver2, number);
	Total3(num, score, sum1, aver1, number);
	Print(num, score, sum1, aver1, sum2, aver2, number);
	return 0;
}