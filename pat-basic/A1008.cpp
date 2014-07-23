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
    int m, n;
    cin >> n >> m;
    int* nums = new int[n];

    for (int i = 0; i < n; ++i){
        cin >> nums[i];
    }

    int offset = m % n;

    if (offset == 0){
        cout << nums[0];
        for (int i = 1; i < n; ++i){
            cout << " " << nums[i];
        }
    }

    else{
        cout << nums[n - offset];
        for (int i = 1; i < offset; ++i){
            cout << " " << nums[i + n - offset];
        }

        for (int i = 0; i < n - offset; ++i){
            cout << " " << nums[i];
        }
    }

    return 0;
}