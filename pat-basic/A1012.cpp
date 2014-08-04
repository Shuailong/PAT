/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn                         |
|copyright : harmony 2014.                          |
\***************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* nums = new int[n];
    for (int i = 0; i < n; ++i){
        cin >> nums[i];
    }

    int a[5];
    int counta[5];
    memset(a, 0, sizeof(int)* 5);
    memset(counta, 0, sizeof(int)* 5);

    int flag = 1;

    for (int i = 0; i < n; ++i){
        int re = nums[i] % 5;
        switch (re){
        case 0:
            if (nums[i] % 2 == 0){
                ++counta[0];
                a[0] += nums[i];
            }
            break;
        case 1:
            ++counta[1];
            a[1] += flag*nums[i];
            flag = (-flag);
            break;
        case 2:
            ++counta[2];
            ++a[2];
            break;
        case 3:
            ++counta[3];
            a[3] += nums[i];
            break;
        case 4:
            ++counta[4];
            if (nums[i] > a[4]){
                a[4] = nums[i];
            }
            break;
        }
    }

    if (counta[0] == 0){
        cout << "N";
    }
    else{
        cout << a[0];
    }

    for (int i = 1; i < 5; ++i){
        if (counta[i] == 0){
            cout << " N";
        }
        else{
            if (i == 3){
                cout << " " << setprecision(1) << fixed << a[i] / (float)counta[i];
            }
            else{
                cout << " " << a[i];
            }
        }
    }

    delete[] nums;
    return 0;
}