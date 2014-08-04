#include <iostream>
#include <iomanip>
using namespace std;

double max3(double n1, double n2, double n3)
{
    double res = n1 > n2 ? n1 : n2;
    res = res > n3 ? res : n3;
    return res;
}

int main()
{
    double product = 1.0;
    char bet[3];
    for (int i = 0; i < 3; ++i){
        double w, t, l;
        cin >> w >> t >> l;
        double best = max3(w, t, l);
        if (best == w){
            bet[i] = 'W';
        }
        else if (best == t){
            bet[i] = 'T';
        }
        else{
            bet[i] = 'L';
        }
        product *= best;
    }

    cout << bet[0] << " " << bet[1] << " " << bet[2] << " "
        << fixed << setprecision(2)
        << (product*0.65 - 1) * 2 << endl;

    system("pause");
    return 0;
}