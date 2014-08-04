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

int main()
{
    string a, b;
    char da, db;
    cin >> a >> da >> b >> db;

    int numa = 0;
    int basea = da - '0';
    for (int i = 0; i < a.length(); ++i){
        if (a[i] == da){
            numa = numa*10+basea;
        }
    }

    int numb = 0;
    int baseb = db - '0';
    for (int i = 0; i < b.length(); ++i){
        if (b[i] == db){
            numb = 10*numb+baseb;
        }
    }

    cout << numa + numb << endl;

    system("pause");
    return 0;
}