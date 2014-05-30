#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, b;
    cin >> N >> b;

    vector<int> digits;
    while (N != 0){
        int digit = N % b;
        N /= b;
        digits.push_back(digit);
    }
    if (digits.size() == 0){
        cout << "Yes\n0" << endl;
    }
    else if (digits.size() == 1){
        cout << "Yes\n" << digits[0] << endl;
    }
    else{
        int i,j;
        for (i = 0, j = digits.size() - 1; i < digits.size(), j >= 0; ++i, --j){
            if (digits[i] != digits[j]){
                break;
            }
        }
        if (i == digits.size()){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        vector<int>::const_reverse_iterator cit = digits.rbegin();
        cout << *cit;
        for (++cit; cit != digits.rend(); ++cit){
            cout << " " << *cit;
        }
    }

    system("pause");
    return 0;
}