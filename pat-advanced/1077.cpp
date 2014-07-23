#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string commonsuffix(string s1, string s2)
{
    string::const_reverse_iterator i1;
    string::const_reverse_iterator i2; 

    string res = "";
    for (i1 = s1.crbegin(),i2 = s2.crbegin(); i1 != s1.crend() && i2 != s2.crend();
        ++i1, ++i2){
        if (*i1 != *i2){
            break;
        }
        res = *i1 + res;
    }

    return res;
}

int main()
{
    int N;
    cin >> N;
    getchar();

    string line;
    vector<string> lines;
    for (int ca = 0; ca < N; ++ca){
        getline(cin, line);
        lines.push_back(line);
    }

    string suffix = lines[0];
    for (int i = 1; i < N; ++i){
        suffix = commonsuffix(suffix, lines[i]);
    }

    if (suffix.size() != 0){
        cout << suffix << endl;
    }
    else{
        cout << "nai" << endl;
    }

    system("pause");

    return 0;
}
