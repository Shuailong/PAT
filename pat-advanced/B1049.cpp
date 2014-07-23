#include <iostream>
using namespace std;

//dont know why?Think on it later

int main()
{
    int N;
    cin >> N;
    int x = 1;
    int total = 0;
    while (N / x != 0){
        int right = N%x;
        int left = N / (x * 10);
        int current = (N / x) % 10;
        if (current == 0){
            total += left * x;
        }
        else if (current == 1){
            total += left * x + right + 1;
        }
        else{
            total += (left + 1)*x;
        }
        x = x * 10;
    }
    cout << total << endl;

    system("pause");
    return 0;
}