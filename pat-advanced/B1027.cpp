#include <iostream>
#include <vector>
using namespace std;

void toMars(int value)
{
    vector<char> digits;
    while (value){
        int digit = value % 13;
        value /= 13;
        if (digit < 10){
            digits.push_back(digit+'0');
        }
        else if (digit == 10){
            digits.push_back('A');
        }
        else if (digit == 11){
            digits.push_back('B');
        }
        else if (digit == 12){
            digits.push_back('C');
        }
    }

    if (digits.size() == 0){
        cout << "00";
    }
    else if (digits.size() == 1){
        cout << "0" << digits[0];
    }
    else{
        cout << digits[1] << digits[0];
    }

}
int main()
{
    int r, g, b;
    cin >> r >> g >> b;

    cout << "#";

    toMars(r);
    toMars(g);
    toMars(b);

    system("pause");
    return 0;
}