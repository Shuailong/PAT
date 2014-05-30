#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int lastlevel = 0;
    int level;
    int time = 0;
    for (int i = 0; i < N; ++i){        
        cin >> level;
        time += 5;
        if (level - lastlevel > 0){
            time += 6 * (level - lastlevel);
        }
        else{
            time += -4 * (level - lastlevel);
        }
        lastlevel = level;
    }
    cout << time;

    system("pause");
    return 0;
}