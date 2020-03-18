#include <iostream>
#include <string>
using namespace std;

void encrypt( string &e )
{
    for (unsigned i = 0; i < e.length(); i++)
        e[i]++;
}

void decrypt( string &e )
{
    for (unsigned i = 0; i < e.length(); i++)
        e[i]--;
}

int main()
{
    string s = "this is a secret!";
    encrypt( s );
    cout << "Encrypt string is: " << s << "\n";
    decrypt( s );
    cout << "Decrypt string is: " << s << endl;

    return 0;
}