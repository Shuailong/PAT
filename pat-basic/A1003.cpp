/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn                         |
|copyright : harmony 2014.                          |
\***************************************************/
#include <iostream>
#include <string>
using namespace std;

bool onlyA(const string& s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != 'A'){
            return false;
        }
    }

    return true;
}

bool pass(const string& s)
{
    if (!(s.find('P') != string::npos && s.find('A') != string::npos 
        && s.find('T') != string::npos))
    {
        return false;
    }

    if (s.find("PAT") != string::npos)
    {
        size_t pos = s.find("PAT");
        string head = s.substr(0, pos);
        string tail = s.substr(pos + 3);
        if (head == tail && onlyA(head)){
            return true;
        }
        else{
            return false;
        }
    }

    size_t pPos = s.find('P');
    size_t tPos = s.find('T');

    if (pPos != string::npos && tPos != string::npos
        && pPos < tPos){
        string head = s.substr(0, pPos);
        string middle = s.substr(pPos+1, tPos-pPos-1);
        string tail = s.substr(tPos+1);

        if (onlyA(head) && onlyA(middle) && onlyA(tail)){
            if (tail.length() == middle.length() * head.length()){
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;

        if (pass(s))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}