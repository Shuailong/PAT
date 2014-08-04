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
    for (int i = 0; i < n; ++i){
        long long a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << i + 1 << ": ";
        
        if (a + b > c){
            cout << "true\n";
        }
        else{
            cout << "false\n";
        }
    }

    return 0;
}