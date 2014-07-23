/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn                         |
|copyright : harmony 2014.                          |
\***************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
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

    bool* keys = new bool[n];
    memset(keys, true, n*sizeof(bool));

    for (int i = 0; i < n; ++i){
        if (keys[i]){
            int number = nums[i];
            while (number != 1){
                if (number % 2 == 0){
                    number /= 2;
                }
                else{
                    number = (3 * number + 1)/2;
                }
                for (int i = 0; i < n; ++i){
                    if (number == nums[i] && keys[i] == true){
                        keys[i] = false;
                        break;
                    }
                }
            }
        }
    }

    vector<int> realkeys;
    for (int i = 0; i < n; ++i){
        if (keys[i]){
            realkeys.push_back(nums[i]);
        }
    }

    sort(realkeys.rbegin(), realkeys.rend());

    cout << realkeys[0];

    for (int i = 1; i < realkeys.size(); ++i){
        cout << " " << realkeys[i];
    }

    delete[] keys;
    delete[] nums;
    system("pause");

    return 0;
}