//#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
//Jr_P

//指针 *pScore指向第一个考生第一门课的考试成绩(列指针);
//m 考生人数;n考试科目;指针 *prow 用于返回最高分所在的行;指针 *pcol 用于返回最高分所在的列
float FindMax(float *pScore, int m, int n, string course, string *pCourse, int *prow, int *pcol)
{
	float max_score = 0.0f;
	int col = 0;
	for (int i = 0; i < n; ++i)
		if (*(pCourse + i) == course)
		{
			col = i;
			break;
		}
	*pcol = col;
	for (int i = 0; i < m; ++i)
		if (*(pScore + i * n + col) > max_score)
		{
			*prow = i;
			max_score = *(pScore + i * n + col);
		}
	return max_score;
};

bool FindStudent(long num, long *pNum, int m, int *prow)
{
	for (int i = 0; i < m; ++i)
		if (*(pNum + i) == num)
		{
			*prow = i;
			return true;
		}
	return false;
};

float  AverageScore(string course, string *pCourse, float *pScore, int  m, int n)
{
	float average = 0.0f;
	int col = 0;
	for (int i = 0; i < n; ++i)
		if (*(pCourse + i) == course)
		{
			col = i;
			break;
		}
	for (int i = 0; i < m; ++i)
		average += *(pScore + i * n + col);
	average /= m;
	return average;
};

int main() {
	//score学生成绩;m考生人数;n考试科目;
	//num考生编号;name考生姓名;prow用于返回最高分所在的行;pcol:用于返回最高分所在的列
	ios::sync_with_stdio(false);
	int m = 0, n = 0;
	cin >> m >> n;
	string *course = new string[n];
	for (int i = 0; i < n; ++i)
		cin >> *(course + i);
	long *num = new long[m];
	string *name = new string[m];
	float *score = new float[m * n];
	int *prow = new int(0), *pcol = new int(0);
	for (int i = 0; i < m; ++i)
	{
		cin >> *(num + i) >> *(name + i);
		for (int j = 0; j < n; ++j)
			cin >> *(score + i * n + j);
	}

	int q;
	long find_num;
	string find_course;
	while (1)
	{
		cout << "1.按考号查找某人\n2.查找某门课的成绩最高的人\n3.显示某门课的平均成绩\n0.退出\n";
		cin >> q;
		if (!q)
			break;
		if (q == 1)
		{
			cin >> find_num;
			if (FindStudent(find_num, num, m, prow))
			{
				cout << "Number\tName";
				for (int i = 0; i < n; ++i)
					cout << '\t' << *(course + i);
				cout << '\n';
				cout << find_num << '\t' << *(name + *prow);
				for (int i = 0; i < n; ++i)
					cout << '\t' << *(score + *prow*n + i);
				cout << '\n';
			}
			else
				cout << "Not Found!\n";
		}
		else if (q == 2)
		{
			cin >> find_course;
			FindMax(score, m, n, find_course, course, prow, pcol);
			cout << "Grade\tNumber\tName\tCourse\n";
			cout << *(score + *prow*n + *pcol) << '\t' << *(num + *prow) << '\t' << *(name + *prow) << '\t' << *(course + *pcol) << '\n';
		}
		else
		{
			cin >> find_course;
			cout << "Course\tAverageScore\n";
			cout << find_course << '\t' << AverageScore(find_course, course, score, m, n) << '\n';
		}
	}

	delete[] num;
	delete[] name;
	delete[] score;
	delete[] course;
	delete prow;
	delete pcol;
	return 0;
}