#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//Note:
// leading zeros
// zeros
string transform(string s, int precision)
{
    string res = "0.";

    int nonzeropos = -1;
    for (int pos = 0; pos < s.size(); ++pos){
        if (s[pos] != '0' && s[pos] != '.'){
            nonzeropos = pos;
            break;
        }
    }

    int i;
    int dotpos = -1;
    for (i = 0; i < s.size(); ++i){
        if (s[i] == '.'){
            dotpos = i;
            break;
        }
    }
    if (i == s.size()){
        //do not have a decimal point
        int digitnum = 0;
        for (int pos = 0; pos < s.size(); ++pos){
            if (s[pos] == '0'){
                continue;
            }
            res += s[pos];
            ++digitnum;
            if (digitnum == precision){
                break;
            }
        }
        if (digitnum < precision){
            for (int count = 0; count < precision - digitnum; ++count){
                res += "0";
            }
        }
        res += "*10^";
        int expo;
        if (nonzeropos == -1){
            expo = 0;
        }
        else{
            expo = s.size() - nonzeropos;
        }

        stringstream ss;
        ss << expo;
        res += ss.str();

        return res;
    }
    else{
        // have a decimal point
        for (int pos = nonzeropos; pos < nonzeropos + precision; ++pos){
            if (pos < s.size()){
                if (s[pos] != '.'){
                    res += s[pos];
                }
                else{
                    ++precision;
                }
            }
            else{
                res += "0";
            }
        }
        res += "*10^";
        int expo = 0;
        if (nonzeropos == -1){
            expo = 0;
        }
        else if (nonzeropos < dotpos){
            expo = dotpos - nonzeropos;
        }
        else{
            expo = dotpos - nonzeropos+1;
        }
        stringstream ss;
        ss << expo;
        res += ss.str();

        return res;
    }




    return res;
}
int main()
{
    int N;
    string a, b;
    cin >> N >> a >> b;
    if (transform(a, N) == transform(b, N)){
        cout << "YES " << transform(a, N) << endl;
    }
    else{
        cout << "NO " << transform(a, N) << " " 
            << transform(b, N) << endl;
    }

    system("pause");
    return 0;
}