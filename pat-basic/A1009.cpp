/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn                         |
|copyright : harmony 2014.                          |
\***************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    vector<string> sentence;
    string line;
    getline(cin, line);
    stringstream ss(line);

    while (!ss.eof()){
        string word;
        ss >> word;
        sentence.push_back(word);
    }

    vector<string>::const_reverse_iterator rit;
    cout << *(sentence.rbegin());
    for (rit = sentence.rbegin()+1; rit != sentence.rend(); ++rit){
        cout << " " << *rit;
    }

    return 0;
}