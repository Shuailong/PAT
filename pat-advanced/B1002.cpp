#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;



int main()
{
    double coef1[1001];
    memset(coef1, 0, sizeof(double)* 1001);

    int k1;
    cin >> k1;
    for (int i = 0; i < k1; ++i){
        int expo;
        cin >> expo;
        cin >> coef1[expo];
    }

    double coef2[1001];
    memset(coef2, 0, sizeof(double)* 1001);
    int k2;
    cin >> k2;
    for (int i = 0; i < k2; ++i){
        int expo;
        cin >> expo;
        cin >> coef2[expo];
    }

    double coefsum[1001];
    int terms = 0;
    for (int i = 0; i < 1001; ++i){
        coefsum[i] = coef1[i] + coef2[i];
        if (coefsum[i] != 0){
            ++terms;
        }
    }
    cout << terms;
    for (int i = 1000; i >= 0; --i){
        if (coefsum[i] != 0){
            cout << " " << i << " " 
                << setprecision(1) << fixed << coefsum[i];
        }
    }

    system("pause");
    return 0;
}