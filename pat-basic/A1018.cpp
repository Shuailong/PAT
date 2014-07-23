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

    int awin = 0;
    int bwin = 0;
    int draw = 0;

    // 'BCJ' <==> times[012]
    int timesa[3] = { 0 };
    int timesb[3] = { 0 };

    for (int i = 0; i < n; ++i){
        char a, b;
        cin >> a >> b;         
        if (a == b){
            ++draw;
        }
        else if (a == 'C' && b == 'J'){
            ++timesa[1];
            ++awin;
        }
        else if (a == 'J' && b == 'B'){
            ++timesa[2];
            ++awin;
        }
        else if (a == 'B' && b == 'C'){
            ++timesa[0];
            ++awin;
        }
        else if (a == 'C' && b == 'B'){
            ++timesb[0];
            ++bwin;
        }
        else if (a == 'J' && b == 'C'){
            ++timesb[1];
            ++bwin;
        }
        else if (a == 'B' && b == 'J'){
            ++timesb[2];
            ++bwin;
        }
    }

    char maxa, maxb;
    int maxta, maxtb;

    maxa = timesa[0] >= timesa[1] ? 'B': 'C';
    maxta = timesa[0] >= timesa[1] ? timesa[0] : timesa[1];
    maxa = maxta >= timesa[2] ? maxa : 'J';

    maxb = timesb[0] >= timesb[1] ? 'B' : 'C';
    maxtb = timesb[0] >= timesb[1] ? timesb[0] : timesb[1];
    maxb = maxtb >= timesb[2] ? maxb : 'J';

    cout << awin << " " << draw << " " << bwin << endl;
    cout << bwin << " " << draw << " " << awin << endl;
    cout << maxa << " " << maxb << endl;

    system("pause");

    return 0;
}