#include <iostream>
#include <map>
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
        if (n%i == 0){
            return false;
        }
    }

    return true;
}
int main()
{
    long int Number;
    cin >> Number;

    int N = Number;
    vector<int> factors;
    while (N != 1){
        for (int i = 2; i <= N; ++i){
            if (isPrime(i) && N%i == 0){
                N /= i;
                factors.push_back(i);
                break;
            }
        }
    }

    map<int, int> mymap;
    for (int i = 0; i < factors.size(); ++i){
        int j;
        if (mymap.count(factors[i]) == 1){
            ++mymap[factors[i]];
        }
        else{
            mymap.insert(pair<int, int>(factors[i], 1));
        }       
    }

    cout << Number << "=";
    if (Number == 1){
        cout << 1 << endl;
    }
    else{
        for (map<int, int>::const_iterator cit = mymap.begin();
            cit != mymap.end(); ++cit){
            cout << cit->first;
            if (cit->second > 1){
                cout << "^" << cit->second;
            }
            if (cit != --mymap.end()){
                cout << "*";
            }
        }
        cout << endl;
    }
    system("pause");
    return 0;
}