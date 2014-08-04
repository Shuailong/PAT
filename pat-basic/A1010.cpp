/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn                         |
|copyright : harmony 2014.                          |
\***************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct term{
    int coef;
    int expo;
};

int main()
{
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<term> poly;
    while (!ss.eof()){
        term t;
        ss >> t.coef >> t.expo;
        poly.push_back(t);
    }
    vector<term>::const_iterator it = poly.begin();
    if (it->expo != 0){
        cout << it->coef * it->expo << " " << it->expo - 1;
    }
    else{
        cout << "0 0" << endl;
    }
    for (it = poly.begin()+1; it != poly.end(); ++it){
        if (it->expo != 0){
            cout << " " << it->coef * it->expo << " " << it->expo - 1;
        }
    }
    

    return 0;
}
