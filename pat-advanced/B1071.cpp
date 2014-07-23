#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    getline(cin, line);

    vector<string> words;
    string next;
    for (int i = 0; i < line.size(); ++i){
        if (!isalnum(line[i])){
            if (!next.empty()){
                words.push_back(next);
                next.clear();
            }
        }
        else{
            next += line[i];
        }
    }
    if (!next.empty()){
        words.push_back(next);
    }

    for (int i = 0; i < words.size(); ++i){
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
    }

    map<string, int> times;
    for (int i = 0; i < words.size(); ++i){
        if (times.count(words[i]) == 0){
            times.insert(pair<string, int>(words[i], 1));
        }
        else{
            ++times[words[i]];
        }
    }

    string max = "";
    int maxtime = -1;
    for (map<string, int>::const_iterator cit = times.cbegin();
        cit != times.cend(); ++cit){
        if (cit->second > maxtime){
            max = cit->first;
            maxtime = cit->second;
        }
    }

    cout << max << " " << maxtime << endl;

    system("pause");
    return 0;
}