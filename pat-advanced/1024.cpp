#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Note: long long can not represent N, need string

bool isPalim(string n)
{
    string m = n;

    reverse(n.begin(), n.end());
    if (n == m){
        return true;
    }
    else{
        return false;
    }    
}

string add(string n1, string n2)
{
    int carry = 0;
    for (int i = n1.size()-1; i >= 0; --i){
        int thisdigit = n1[i] - '0';
        n1[i] = (n1[i]-'0' + n2[i]-'0' + carry) % 10 + '0';
        carry = (thisdigit + n2[i]-'0' + carry) / 10;
    }
    if (carry != 0){
        n1.insert(n1.begin(), '1');
    }
    return n1;
}

int main()
{
    string N;
    int K;
    cin >> N >> K;

    int i;
    for (i = 0; i < K; ++i){
        if (isPalim(N)){
            break;
        }
        string M = N;
        reverse(N.begin(), N.end());
        N = add(N, M);
    }

    cout << N << endl << i << endl;

    system("pause");
    return 0;
}