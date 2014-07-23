#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    bool* subchars = new bool[128];
    memset(subchars, false, sizeof(bool)* 128);

    for (int i = 0; i < s2.size(); ++i){
        subchars[s2[i]] = true;
    }
    for (int i = 0; i < s1.size(); ++i){
        if (!subchars[s1[i]]){
            cout << s1[i];
        }
    }

    delete[] subchars;
    system("pause");
    return 0;
}