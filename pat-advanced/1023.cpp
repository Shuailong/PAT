#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string d(s);
    int carry = 0;
    for (int i = s.size() - 1; i >= 0; --i){
        d[i] = (2 * (s[i] - '0') + carry) % 10 + '0';
        carry = (2 * (s[i] - '0') + carry) / 10;
    }
    if (carry != 0){
        d.insert(d.begin(), carry + '0');
        cout << "No" << endl;
    }
    else{
        int digitfreqs1[10] = { 0 };
        int digitfreqs2[10] = { 0 };
        for (int i = 0; i < s.size(); ++i){
            ++digitfreqs1[s[i] - '0'];
            ++digitfreqs2[d[i] - '0'];
        }

        if (memcmp(digitfreqs1, digitfreqs2, sizeof(int)*10) == 0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    cout << d << endl;

    system("pause");
    return 0;
}