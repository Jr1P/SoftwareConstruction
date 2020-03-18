#include<iostream>
using namespace std;
//Jr_P

//函数说明：查找所有的考试成绩中的最高分
//参数说明：指针 *pScore 指向第一个考生第一门课的考试成绩（列指针）;m 考生人数;n考试科目;指针 *prow 用于返回最高分所在的行；指针  *pcol 用于返回最高分所在的列。
void FindMax(float *pScore, int m, int n, int *prow, int *pcol)
{
	float max_score = 0.0f;
	//int max_col = 1, max_row = 1;
	for(int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			if(*(pScore+i*n+j) > max_score)
			{
				*prow = i;
				*pcol = j;
				max_score = *(pScore+i*n+j);
			}
		}
};

int main(){
    //score学生成绩;m考生人数;n考试科目;
    //num考生编号;name考生姓名;prow用于返回最高分所在的行;pcol:用于返回最高分所在的列

    int m = 0, n = 0;
    cin >> m >> n;
    string *course = new string[n];
    for(int i = 0; i < n; ++i)
    	cin >> *(course+i);
    long *num = new long[m];
    string *name = new string[m];
    float *score = new float[m * n];
    int *prow = new int(0), *pcol = new int(0);
    for(int i = 0; i < m; ++i)
    {
    	cin >> *(num+i) >> *(name+i);
    	for(int j = 0; j < n; ++j)
    		cin >> *(score+i*n+j);
    }

    FindMax(score, m, n, prow, pcol);
    cout << "Grade\tNumber\tName\tCourse" << endl;
    cout<< *(score + (*prow)*n + (*pcol)) << '\t' << *(num + *prow) << '\t' << *(name + *prow) << '\t' << *(course + *pcol);
    return 0;
}