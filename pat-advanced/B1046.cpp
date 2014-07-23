#include <iostream>
using namespace std;

// Note: 用常识做题

int main()
{
    int N;
    cin >> N;
    int* dists = new int[N];

    int total = 0;
    for (int i = 0; i < N; ++i){
        int num;  
        cin >> num;
        total += num;
        dists[i] = total;
    }
    
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i){
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 > c2){
            int temp = c1;
            c1 = c2;
            c2 = temp;
        }

        int d;
        if (c1 != 1){
            d = dists[c2 - 2] - dists[c1 - 2];
        }
        else{
            d = dists[c2 - 2];
        }
        int shorter = d < (total - d) ? d : (total - d);
        cout << shorter << endl;
    }

    delete[] dists;
    system("pause");
    return 0;
}