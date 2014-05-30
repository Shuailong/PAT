#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> times;
    map<int, int> orders;
    for (int i = 0; i < n; ++i){
        int num;
        cin >> num;
        if (times.count(num) == 0){
            times.insert(pair<int, int>(num, 1));
        }
        else{
            ++times[num];
        }
        if (orders.count(num) == 0){
            orders.insert(pair<int, int>(num, i));
        }

    }
    vector<int> distincts;
    map<int, int>::const_iterator cit = times.cbegin();
    for (; cit != times.cend(); ++cit){
        if (cit->second == 1){
            distincts.push_back(cit->first);
        }
    }

    if (distincts.size() == 0){
        cout << "None" << endl;
    }
    else{
        int min = 10001;
        int minorder = n;
        for (int i = 0; i < distincts.size(); ++i){
            if (orders[distincts[i]] < minorder){
                minorder = orders[distincts[i]];
                min = distincts[i];
            }
        }
        cout << min << endl;
    }

    system("pause");
    return 0;
}