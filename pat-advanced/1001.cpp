#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int sum = a + b;

    int neg = false;
    if (sum < 0){
        sum = -sum;
        neg = true;
    }

    int num = sum;
    vector<int> digits;
    while (num){
        digits.push_back(num % 10);
        num /= 10;
    }

    if (neg){
        cout << "-";
    }

    if (digits.size() <= 3){
        cout << sum;
    }
    else if (digits.size() % 3 == 0){
        vector<int>::const_reverse_iterator crit;
        for (crit = digits.rbegin(); crit != digits.rend(); ++crit){
            cout << *crit;
            if ((crit - digits.rbegin()+1) % 3 == 0
                && crit != digits.rend()-1){
                cout << ",";
            }
        }
    }
    else if(digits.size() % 3 == 1){
        vector<int>::const_reverse_iterator crit;
        cout << *digits.rbegin() << ",";
        for (crit = digits.rbegin()+1; crit != digits.rend(); ++crit){
            cout << *crit;
            if ((crit - digits.rbegin()) % 3 == 0
                && crit != digits.rend() - 1){
                cout << ",";
            }
        }
    }
    else if (digits.size() % 3 == 2){
        vector<int>::const_reverse_iterator crit;
        cout << *digits.rbegin() << *(digits.rbegin()+1) << ",";
        for (crit = digits.rbegin()+2; crit != digits.rend(); ++crit){
            cout << *crit;
            if ((crit - digits.rbegin() + 2) % 3 == 0
                && crit != digits.rend() - 1){
                cout << ",";
            }
        }
    }

    system("pause");
    return 0;
}