/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn                         |
|copyright : harmony 2014.                          |
\***************************************************/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string tostring(int n){
    string s;
    if (n < 10){
        char cn = n + '0';
        s = "000";
        s += cn;
    }
    else if (n < 100){
        int shi = n / 10;
        int ge = n % 10;
        char cge = ge + '0';
        char cshi = shi + '0';
        s = "00";
        s += cshi;
        s += cge;
    }
    else if (n < 1000){
        int bai = n / 100;
        int shi = (n - bai * 100)/10;
        int ge = n % 10;
        char cge = ge + '0';
        char cshi = shi + '0';
        char cbai = bai + '0';
        s = "0";
        s += cbai;
        s += cshi;
        s += cge;
    }
    else if (n < 10000){
        int qian = n / 1000;
        int bai = (n - qian*1000) / 100;
        int shi = (n - bai * 100 - qian * 1000) / 10;
        int ge = n % 10;        
        char cge = ge + '0';
        char cshi = shi + '0';
        char cbai = bai + '0';
        char cqian = qian + '0';
        s = "";
        s += cqian;
        s += cbai;
        s += cshi;
        s += cge;
    }
    return s;
}

int toint(string s)
{
    int value = 0;
    for (int i = 0; i < s.length(); ++i){
        int digit = s[i] - '0';
        value = value * 10 + digit;
    }

    return value;
}

int main()
{
    int n;
    cin >> n;

    if (n == 6174){
        cout << "7641 - 1467 = 6174" << endl;
    }
    else{
        string s = tostring(n);
        string ss(s);
        while (ss != "6174"){
            string small(ss);
            string big(ss);
            sort(small.begin(), small.end());
            sort(big.rbegin(), big.rend());
            int result = toint(big) - toint(small);
            cout << big << " - " << small << " = " << tostring(result) << endl;
            ss = tostring(result);
            if (ss == "0000"){
                break;
            }
        }
    }
  
    system("pause");
    return 0;
}