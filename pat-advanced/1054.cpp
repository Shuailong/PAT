#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    map<int, int> times;

    for (int i = 0; i < M*N; ++i){
        int pixel;
        //cin >> pixel;
        scanf("%d", &pixel);

        if (times.count(pixel) == 0){
            times.insert(pair<int, int>(pixel, 1));
        }
        else{
            ++times[pixel];
        }
    }

    int max = -1;
    for (map<int, int>::const_iterator cit = times.begin();
        cit != times.end();  ++cit){
        if (cit->second > max && cit->second > M*N/2){
            max = cit->first;
        }
    }

    cout << max << endl;
    system("pause");
    return 0;
}