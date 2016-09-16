#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Examee{
    string id;
    int trial;
    int exam;
};
  
int main()
{
    int N;
    cin >> N;

    vector<Examee> examees(N+1);

    for (int i = 0; i < N; ++i){
        Examee examee;
        cin >> examee.id >> examee.trial >> examee.exam;
        examees[examee.trial] = examee;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i){
        int trial;
        cin >> trial;
        cout << examees[trial].id << " "  << examees[trial].exam << endl;
    }

    return 0;
}

