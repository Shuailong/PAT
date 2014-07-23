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
    string a;
    int b;
    cin >> a >> b;

    string q = "";

    int r = 0;
    for (int i = 0; i < a.length(); ++i){
        int d = a[i] - '0';
        int digit = 10 * r + d;
        int iq = digit / b;
        char cq = iq + '0';
        if (!(cq == '0' && i == 0)){
            q += cq;
        }
        r = digit % b;
    }
    if (q == ""){
        cout << 0 << " " << r << endl;
    }
    else{
        cout << q << " " << r << endl;
    }


    return 0;
}