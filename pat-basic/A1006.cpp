/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn                         |
|copyright : harmony 2014.                          |
\***************************************************/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n >= 100){
        int bai = n / 100;
        int shi = (n - 100 * bai) / 10;
        int ge = n % 10;
        for (int i = 0; i < bai; ++i){
            cout << 'B';
        }
        for (int i = 0; i < shi; ++i){
            cout << 'S';
        }
        for (int i = 0; i < ge; ++i){
            cout << i+1;
        }
    }

    else if (n >= 10){
        int shi = n / 10;
        int ge = n % 10;
        for (int i = 0; i < shi; ++i){
            cout << 'S';
        }
        for (int i = 0; i < ge; ++i){
            cout << i + 1;
        }
    }
    else{
        for (int i = 0; i < n; ++i){
            cout << i + 1;
        }
    }


    return 0;
}