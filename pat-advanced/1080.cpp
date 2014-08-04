#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
    int ge;
    int gi;
    int total;
    int* prefers;
    int id;
    int index;

    Person(int K){
        ge = 0;
        gi = 0;
        total = 0;
        prefers = new int[K];
        index = -1;
        id = -1;
    }
    //~Person(){
    //    delete[] prefers;
    //}
};

bool compare(Person p1, Person p2)
{
    if (p1.total != p2.total){
        return p1.total > p2.total;
    }
    else{
        return p1.ge > p2.ge;
    }
}

bool compareid(Person p1, Person p2)
{
    return p1.id < p2.id;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int* quotas = new int[M];
    for (int i = 0; i < M; ++i){
        cin >> quotas[i];
    }
    vector<Person> total;

    vector<Person> * admits = new vector<Person>[M];
    for (int i = 0; i < N; ++i){
        Person p(K);
        cin >> p.ge >> p.gi;
        for (int j = 0; j < K; ++j){
            cin >> p.prefers[j];
        }
        p.total = p.ge + p.gi;
        p.id = i;
        total.push_back(p);
    }
   
    sort(total.begin(), total.end(), compare);
    total[0].index = 0;
    for (int j = 1; j < total.size(); ++j){
        total[j].index = j;
        if ((total[j].total == total[j - 1].total) 
            && (total[j].ge == total[j-1].ge)){
            total[j].index = total[j - 1].index;
        }
    }

    for (int i = 0; i < N; ++i){
        // for each student from top to down
        for (int j = 0; j < K; ++j){
            // for each graduate school
            int size = admits[total[i].prefers[j]].size();
            bool notFull = size < quotas[total[i].prefers[j]];
            Person last(K);
            if (size > 0){
                last = *admits[total[i].prefers[j]].rbegin();
            }
            bool tie = ((last.index == total[i].index) && !notFull);
            if (notFull || tie){
                admits[total[i].prefers[j]].push_back(total[i]);
                break;
            }
        }
    }
    for (int i = 0; i < M; ++i){
        sort(admits[i].begin(), admits[i].end(), compareid);
        if (admits[i].size() >= 1){
            cout << admits[i][0].id;
            for (int j = 1; j < admits[i].size(); ++j){
                cout << " " << admits[i][j].id;
            }
        }
        cout << endl;
    }


    delete[] quotas;
    delete[] admits;

    system("pause");
    return 0;
}