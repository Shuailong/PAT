#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string cards[54];
    for (int i = 0; i < 13; ++i){
        cards[i] = "S";
        if (i < 9){
            cards[i] += '0' + i + 1;
        }
        else{
            cards[i] += '1';
            cards[i] += '0' + i - 9;
        }
    }
    for (int i = 0; i < 13; ++i){
        int index = i + 13;
        cards[index] = "H";
        if (i < 9){
            cards[index] += '0' + i + 1;
        }
        else{
            cards[index] += '1';
            cards[index] += '0' + i - 9;
        }
    }
    for (int i = 0; i < 13; ++i){
        int index = i + 26;
        cards[index] = "C";
        if (i < 9){
            cards[index] += '0' + i + 1;
        }
        else{
            cards[index] += '1';
            cards[index] += '0' + i - 9;
        }
    }
    for (int i = 0; i < 13; ++i){
        int index = i + 39;
        cards[index] = "D";
        if (i < 9){
            cards[index] += '0' + i + 1;
        }
        else{
            cards[index] += '1';
            cards[index] += '0' + i - 9;
        }
    }
    cards[52] = "J1";
    cards[53] = "J2";

    int order[54];
    for (int i = 0; i < 54; ++i){
        cin >> order[i];
    }

    string newcards[54];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 54; ++j){
            newcards[order[j]-1] = cards[j];
        }

        for (int j = 0; j < 54; ++j){
            cards[j] = newcards[j];
        }
    }

    cout << cards[0];
    for (int i = 1; i < 54; ++i){
        cout << " " << newcards[i];
    }
    cout << endl;

    system("pause");
    return 0;
}