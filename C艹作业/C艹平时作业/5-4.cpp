#include <iostream>
using namespace std;
//jr.P
float average;
int Input (long num[], float score[]);

void Total1(long num[], float score[], int n);

void Total2(long num[], float score[], int n);

int main()
{
	const int MAX = 30 + 50;
	long num[MAX] = {0};
	float score[MAX] = {0};
	int number = Input(num, score);
	Total1(num, score, number);
	Total2(num, score, number);
    return 0;
}

int Input (long num[], float score[])
{
	int cnt = 1;
	float sum = 0;
    cout<<"Enter the student number and the score:"<<endl;
    do
    {
    	cin >> num[cnt] >> score[cnt];
    	sum += score[cnt];
    	cnt++;
    } while (cnt <= 30 && score[cnt-1] >= 0);
    cin.ignore(80, '\n');
    if (cnt != 31) cnt -= 2;
    else cnt--;
    average = sum/static_cast<float>(cnt); 
    return cnt;
};

void Total1(long num[], float score[], int n)
{
    int total = 0;
    for (int i = 1; i <= n; i++)
    	if (score[i] < 60)
    	{
    		cout << num[i] << '\n';
    		total++;
    	}
    cout<<"The score<60 is:"<<total<<endl;
};
void Total2(long num[], float score[], int n)
{
    int total = 0;
	for (int i = 1; i <= n; i++)
    	if (score[i] >= average)
    	{
    		cout << num[i] << '\n';
    		total++;
    	}
    cout<<"The score>=average is:"<<total<<endl;
};
