#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Note:
// what n1, n2 represnt exactly...
int main()
{
    string s;
    cin >> s;

    int N = s.size();

    int k = floor((N + 2) / 3.0);
    int n2 = N + 2 - 2 * k;
    
    int i;
    for (i = 0; i < k-1; ++i){
        cout << s[i];
        for (int j = 0; j < n2-2; ++j){
            cout << " ";
        }
        cout << s[N - 1 - i] << endl;
    }
    int pos = i;
    for (int i = 0; i < n2; ++i){
        cout << s[pos++];
    }
    cout << endl;

    system("pause");
    return 0;
}