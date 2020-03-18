#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Staff
{
public:
	string staff_number, staff_name, staff_affiliation;

	virtual void showNumber() = 0;
	virtual void showName() = 0;
	void showAffiliation();
	void setProfile(string no, string cname, string aff);
	string getNo();
	string getName();
	string getAffiliation();
};

void Staff::showAffiliation()
{
	cout << "所属院系：" << staff_affiliation << endl;
}
void Staff::setProfile(string no, string cname, string aff)
{
	staff_number = no;
	staff_name = cname;
	staff_affiliation = aff;
}

string Staff::getNo()
{
	return staff_number;
}

string Staff::getName()
{
	return staff_name;
}

string Staff::getAffiliation()
{
	return staff_affiliation;
}

class Teacher : public Staff //派生教师类
{
public:
	void showNumber()
	{
		cout << "教师的工号是：" << staff_number << endl;
	} //派生类重定义虚函数
	void showName()
	{
		cout << "教师的姓名是：" << staff_name << endl;
	} //派生类重定义虚函数
};

class Student : public Staff //派生学生类
{
public:
	void showNumber()
	{
		cout << "学生的学号是：" << staff_number << endl;
	} //派生类重定义虚函数
	void showName()
	{
		cout << "学生的姓名是：" << staff_name << endl;
	} //派生类重定义虚函数
};

int main()
{
	ifstream in("data.txt");
	//创建输入文件对象 in
	//在此处打开文件data.txt
	if (in.fail())
	{
		cout << "打开文件data.txt失败" << endl;
		return 1;
	}

	Staff *p_teacher, *p_student; //指向基类对象的指针

	string cname, cno, caff;
	int teacher_number = 0; //教师人数
	int student_number = 0; //学生人数

	in >> teacher_number; //从文件中读入教师人数

	p_teacher = new Teacher[teacher_number]; //根据教师人数为教师类对象数组分配内存空间

	for (int i = 0; i < teacher_number; i++) //从文件中读入这些教师的基本信息
	{
		in >> cno >> cname >> caff;
		if (!in.eof())
			p_teacher[i].setProfile(cno, cname, caff); //设置教师编号、姓名和所属院系
		else
		{
			cout << "读入教师信息错误！" << endl;
			break;
		}
	}

	in >> student_number;
	p_student = new Student[student_number];
	for (int i = 0; i < student_number; i++)
	{
		in >> cno >> cname >> caff;
		if (!in.eof())
			p_student[i].setProfile(cno, cname, caff); //设置教师编号、姓名和所属院系
		else
		{
			cout << "读入学生信息错误！" << endl;
			break;
		}
	}
	in.close();

	//显示用户查询界面

	int counter = 0;
	cout << "欢迎使用教师和学生信息查询系统" << endl;
	cout << "请输入您要查找的关键字编号、姓名或者院系(输入-1结束)：";

	string searchString;
	cin >> searchString;
	while (searchString != "-1")
	{
		for (int i = 0; i < teacher_number; i++)
		{
			if (p_teacher[i].getNo() == searchString || p_teacher[i].getName() == searchString || p_teacher[i].getAffiliation() == searchString)
			{
				p_teacher[i].showNumber();
				p_teacher[i].showName();
				p_teacher[i].showAffiliation();
				counter++;
			}
		}
		//添加代码查找符合关键字的学生信息
		for (int i = 0; i < student_number; i++)
		{
			if (p_student[i].getNo() == searchString || p_student[i].getName() == searchString || p_student[i].getAffiliation() == searchString)
			{
				p_student[i].showNumber();
				p_student[i].showName();
				p_student[i].showAffiliation();
				counter++;
			}
		}
		cout << "共找到" << counter << "个符合信息的人员！" << endl;
		cout << endl;
		counter = 0;
		cout << "请输入您要查找的关键字编号、姓名或者院系(输入-1结束)：";
		cin >> searchString;
	}

	delete[] p_student;
	delete[] p_teacher;
	//释放所有动申请的内存

	return 0;
}
