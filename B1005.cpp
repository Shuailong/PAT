#include <iostream>
#include <string>
using namespace std;

int main()
{
    const string digits[] = { "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine" };

    string n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n.size(); ++i){
        int digit = n[i] - '0';
        sum += digit;
    }

    if (sum < 10){
        cout << digits[sum] << endl;
    }
    else if (sum < 100){
        cout << digits[sum/10] << " " << digits[sum%10] << endl;
    }
    else if (sum < 1000){
        cout << digits[sum / 100] << " " << digits[(sum-100*(sum/100)) / 10]
            << " " << digits[sum % 10] << endl;
    }    

    system("pause");
    return 0;
}