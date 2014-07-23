#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int NC;
    cin >> NC;
    vector<int> poscoupon;
    vector<int> negcoupon;
    int value;
    for (int i = 0; i < NC; ++i){
        cin >> value;
        if (value > 0){
            poscoupon.push_back(value);
        }
        else if(value < 0){
            negcoupon.push_back(value);
        }
    }
    vector<int> posproduct;
    vector<int> negproduct;
    int NP;
    cin >> NP;
    
    for (int i = 0; i < NP; ++i){
        cin >> value;
        if (value > 0){
            posproduct.push_back(value);
        }
        else if(value < 0){
            negproduct.push_back(value);
        }
    }
    sort(poscoupon.begin(), poscoupon.end());
    sort(negcoupon.begin(), negcoupon.end());
    sort(posproduct.begin(), posproduct.end());
    sort(negproduct.begin(), negproduct.end());

    int total = 0;
    vector<int>::const_reverse_iterator it1 = poscoupon.rbegin();
    vector<int>::const_reverse_iterator it2 = posproduct.rbegin();
    while (it1 != poscoupon.rend() && it2 != posproduct.rend()){
        total += *it1 * *it2;
        ++it1; ++it2;
    }

    vector<int>::const_iterator it3 = negcoupon.begin();
    vector<int>::const_iterator it4 = negproduct.begin();
    while (it3 != negcoupon.end() && it4 != negproduct.end()){
        total += *it3 * *it4;
        ++it3; ++it4;
    }

    cout << total << endl;
    system("pause");
    return 0;
}