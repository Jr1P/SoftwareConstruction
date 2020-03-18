#include <iostream>
#include <string>
//#include <algorithm>
using namespace std;

string remove_punct(const string &s, const string &punct)
{
    string no_punct = "";
    int s_length = s.length();
    for(int i = 0; i < s_length; i++)
        if (punct.find(s[i]) == -1)
            no_punct += s[i];
    //cout << no_punct <<'\n';
    return no_punct;
}


string make_lower(const string &s)
{
    string lower_str(s);
    for (unsigned i = 0; i < lower_str.length(); i++)
        lower_str[i] = tolower(lower_str[i]);
    //cout << lower_str <<'\n';
    return lower_str;
}

string reverse(const string &s)
{
    string reverse_str = s;
    for (int i = s.length()-1; i >= 0; i--)
        reverse_str[s.length()-i-1] = s[i];
    //cout << reverse_str << '\n';
    return reverse_str;
}

bool is_pal(const string &s)
{
    string punct(",;:.?!'\" ");
    string no_punct = remove_punct(s, punct);
    string lowercase = make_lower(no_punct);
    string reverse_str = reverse(lowercase);
    if( reverse_str == lowercase )
        return true;
    else
        return false;
}


int main()
{
    string str;

    cout<<"Enter a candidate for palindrome test:"<<endl;
    getline(cin, str, '\n');
    if(is_pal(str))
        cout<<"\""<<str<<"\" is a palindrome.";
    else
        cout<<"\""<<str<<"\" is not a palindrome.";

    return 0;
}
