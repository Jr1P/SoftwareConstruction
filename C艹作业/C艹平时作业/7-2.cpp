#include<iostream>
#include<string>
using namespace std;
//Jr.P $

void set_password(string &usename,string &password)
{
    cout<<"please input your name:";
    cin >> usename;
    bool vaild_password = 0;
    do 
    {
        cout<<"please input your password:";
        cin >> password;
        bool f_digit = 0, f_alpha = 0;
        for(unsigned i = 0; i < password.length(); i++)
        {
            if(isdigit(password[i]))
                f_digit = 1;
            else if(isalpha(password[i]))
                f_alpha = 1;
        }
        if(!(f_alpha && f_digit))
        {
            cout<<"your password must include number and letters"<<endl;
            continue;
        }
        if(password.length() < 8)
        {
            cout<<"Password length must be greater than 8"<<endl;
            continue;
        }
        string password1;
        cout<<"please enter your password again:";
        cin >> password1;
        if (password != password1)
        {
            cout<<"the password must be same"<<endl;
            continue;
        }
        else
        {
            cout<<"Register Success!"<<endl;
            vaild_password = 1;
        }
    } while(!vaild_password);
}

void login(const string &usename,const string &password)
{
    //to do
    cout<<"your name is "<<usename<<endl;
    cout<<"input password to login,you have three times:";
    int cnt = 0;
    while(cnt != 3)
    {
        string input_password;
        cin >> input_password;
        cnt++;
        if (input_password == password)
        {
            cout<<"Login Success!"<<endl;
            return ;
        }
        else if(cnt != 3)
            cout<<"your password is not right,please try again:";
    }
    cout<<"Fail to login,time is up!"<<endl;
}

int main()
{
    string usename, password;
    set_password(usename, password);
    login(usename, password);
    return 0;
}