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
    int m, n;
    cin >> m >> n;

    int no = 0;
    int count = 0;
    for (int i = 2; i <= 104729; ++i){
        if (isPrime(i)){
            ++no;
            if (no >= m && no <= n){
                if (count % 10 == 0){
                    cout << i;
                }
                else{
                    cout << " " << i ;
                }
                ++count;
                if (count % 10 == 0){
                    cout << endl;
                }
            }
        }
    }

    return 0;
}