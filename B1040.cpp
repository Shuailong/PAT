#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int max1 = 1;
    for (int i = 1; i < s.size(); ++i){
        int delta = 0;
        while (i - delta >= 0 && i + delta <= s.size() - 1){
            if (s[i - delta] != s[i + delta]){
                break;
            }
            ++delta;
        }

        if (2 * delta + 1 > max1){
            max1 = 2 * delta -1;
        }
    }

    int max2 = 1;
    for (int i = 1; i < s.size(); ++i){
        int delta = 0;
        while (i - delta >= 0 && i+1 + delta <= s.size() - 1){
            if (s[i - delta] != s[i+1 + delta]){
                break;
            }
            ++delta;
        }

        if (2 * delta> max2){
            max2 = 2 * delta;
        }
    }

    int max = max1 > max2 ? max1 : max2;
    cout << max << endl;

    system("pause");
    return 0;
}