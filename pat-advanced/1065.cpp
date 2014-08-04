#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i){
        long double a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << i + 1 << ": ";
        if (a + b>c){
            cout << "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
    }

    system("pause");

    return 0;
}