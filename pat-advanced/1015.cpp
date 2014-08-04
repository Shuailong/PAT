#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n < 2){
        return false;
    }
    if (n == 2){
        return true;
    }
    for (int i = 2; i <= sqrt(n); ++i){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    int N, D;
    while (cin >> N, N >= 0){
        cin >> D;
        int num = N;
        vector<int> digits;
        while (num != 0){
            int digit = num % D;
            digits.push_back(digit);
            num /= D;
        }

        int reverse = 0;
        for (vector<int>::const_iterator cit = digits.begin();
            cit != digits.end(); ++cit){
            reverse = reverse*D + *cit;
        }
        if (isPrime(reverse) && isPrime(N)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    system("pause");
    return 0;
}