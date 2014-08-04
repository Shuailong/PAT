/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn                         |
|copyright : harmony 2014.                          |
\***************************************************/
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n < 2){
        return false;
    }
    if (n == 2){
        return true;
    }

    for (int i = 2; i <= sqrt(n); ++i){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    int count = 0;
    for (int i = 2; i <= n-2; ++i){
        if (isPrime(i) && isPrime(i + 2)){
            ++count;
        }
    }
    cout << count << endl;;

    return 0;
}