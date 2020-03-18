#include<iostream>
#include<fstream>
#include<string>
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
}

void Staff::showAffiliation()
{
	cout<<"����Ժϵ��"<<staff_affiliation<<endl;
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

class Teacher:public Staff   //������ʦ��
{
public:
	void showNumber()
	{
		cout<<"��ʦ�Ĺ����ǣ�"<<staff_number<<endl;
	}  //�������ض����麯��
	void showName()
	{
		cout<<"��ʦ�������ǣ�"<<staff_name<<endl;
	}  //�������ض����麯��
};

class Student:public Staff   //����ѧ����
{
public:
   	void showNumber()
	{
		cout<<"ѧ����ѧ���ǣ�"<<staff_number<<endl;
	}  //�������ض����麯��
	void showName()
	{
		cout<<"ѧ���������ǣ�"<<staff_name<<endl
	}  //�������ض����麯��
};

int main()
{
	ifstream in("data.txt");
    //���������ļ����� in
    //�ڴ˴����ļ�data.txt
    if(in.fail())
    {
        cout<<"���ļ�data.txtʧ��"<<endl;
        return 1;
    }

    Staff *p_teacher, *p_student;  //ָ���������ָ��

    string cname, cno, caff;
    int teacher_number = 0;            //��ʦ����
    int student_number = 0;           //ѧ������

    in>>teacher_number;   //���ļ��ж����ʦ����

    p_teacher = new Teacher[teacher_number];   //���ݽ�ʦ����Ϊ��ʦ�������������ڴ�ռ�

	for(int i = 0; i< teacher_number; i++)      //���ļ��ж�����Щ��ʦ�Ļ�����Ϣ
    {
		in >> cno >> cname >> caff;
        if(!in.eof())
            p_teacher[i].setProfile(cno, cname, caff);   //���ý�ʦ��š�����������Ժϵ
        else
        {
                cout<<"�����ʦ��Ϣ����"<<endl;
                break;
        }
    }

	in >> stduent_number;
	p_student = new Student[student_number];
	for (int i = 0; i < student_number; i++)
	{
		in >> cno >> cname >> caff;
		if (!in.eof())
			p_student[i].setProfile(cno, cname, caff);   //���ý�ʦ��š�����������Ժϵ
		else
		{
			cout << "����ѧ����Ϣ����" << endl;
			break;
		}
	}
	in.close();

    //��ʾ�û���ѯ����

    int counter  = 0;
    cout<<"��ӭʹ�ý�ʦ��ѧ����Ϣ��ѯϵͳ"<<endl;
    cout<<"��������Ҫ���ҵĹؼ��ֱ�š���������Ժϵ(����-1����)��";
    
    string searchString;
	cin >> searchString;
	while (searchString != "-1")
	{
		for(int i = 0; i<teacher_number; i++)
		{
			 if(p_teacher[i].getNo() == searchString || p_teacher[i].getName() == searchString || p_teacher[i].getAffiliation() == searchString)
			 {
				 p_teacher[i].showNumber();
				 p_teacher[i].showName();
				 p_teacher[i].showAffiliation();
				 counter++;
			 }
		}
	   //��Ӵ�����ҷ��Ϲؼ��ֵ�ѧ����Ϣ
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
		cout<<"���ҵ�"<< counter <<"��������Ϣ����Ա��"<<endl;
		cout<<endl;

	}
   
    delete[] p_student;
    delete[] p_teacher;
    //�ͷ����ж�������ڴ�

    return 0;
}
