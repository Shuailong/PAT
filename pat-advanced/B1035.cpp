#include <iostream>
#include <string>
#include <vector>
using namespace std;

string modify(string pw)
{
    for (int i = 0; i < pw.size(); ++i){
        switch (pw[i]){
        case '1': pw[i] = '@'; break;
        case 'l': pw[i] = 'L'; break;
        case '0': pw[i] = '%'; break;
        case 'O': pw[i] = 'o'; break;
        }
    }

    return pw;
}

struct user{
    string id;
    string pw;
};
int main()
{
    int N;
    cin >> N;

    int count = 0;
    vector<user> modified;
    for (int i = 0; i < N; ++i){
        user usr;
        cin >> usr.id >> usr.pw;
        if (modify(usr.pw) != usr.pw){
            ++count;
            usr.pw = modify(usr.pw);
            modified.push_back(usr);
        }
    }

    if (modified.size() == 0){
        if (N > 1){
            cout << "There are " << N << " accounts and no account is modified" << endl;
        }
        else{
            cout << "There is 1 account and no account is modified" << endl;
        }
    }
    else{
        cout << count << endl;
        for (int i = 0; i < modified.size(); ++i){
            cout << modified[i].id << " " << modified[i].pw << endl;
        }
    }

    system("pause");
    return 0;
}