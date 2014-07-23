/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn                         |
|copyright : harmony 2014.                          |
\***************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct mooncake
{
    double stock;
    double money;
};

bool compare(mooncake lhs, mooncake rhs)
{
    return lhs.money / lhs.stock < rhs.money / rhs.stock;
}

int main()
{
    int n, d;
    cin >> n >> d;

    vector<mooncake> cakes;
    for (int i = 0; i < n; ++i){
        mooncake mk;
        cin >> mk.stock;
        cakes.push_back(mk);
    }
    for (int i = 0; i < n; ++i){
        cin >> cakes[i].money;
    }

    sort(cakes.rbegin(), cakes.rend(), compare);

    double profit = 0;

    for (int i = 0; i < n; ++i){
        d -= cakes[i].stock;
        if (d == 0){
            profit += cakes[i].money;
            break;
        }
        else if (d < 0){
            d += cakes[i].stock;
            profit += d * cakes[i].money/cakes[i].stock;
            d = 0;
            break;
        }
        else{
            profit += cakes[i].money;
        }
    }

    cout << setprecision(2) << fixed << profit << endl;

    system("pause");
    return 0;
}