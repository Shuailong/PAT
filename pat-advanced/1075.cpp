#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct User{
    int id;
    int scores[5];
    int totalscore;
    int rank;
    bool valid;
    int perfect;
    int submits;
    User(){
        valid = false;
        rank = 0;
        totalscore = 0;
        for (int i = 0; i < 5; ++i){
            scores[i] = -1;
        }
        perfect = 0;
        submits = 0;
    }
};

bool compare(User u1, User u2){
    if (u1.totalscore != u2.totalscore){
        return u1.totalscore > u2.totalscore;
    }
    else{
        if (u1.perfect != u2.perfect){
            return u1.perfect > u2.perfect;
        }
        else{
            return u1.id < u2.id;
        }
    }

}
int main()
{
    int N, K, M;
    scanf("%d%d%d", &N, &K, &M);
    int *p = new int[K];
    for (int i = 0; i < K; ++i){
        scanf("%d", &p[i]);
    }
    vector<User> users(10001);
    for (int i = 0; i < M; ++i){
        int user_id, problem_id, partial_score;
        scanf("%d%d%d", &user_id, &problem_id, &partial_score);
        users[user_id].id = user_id;
        users[user_id].valid = true;
        if (partial_score == -1){
            partial_score = 0;
        }
        else{
            ++users[user_id].submits;
        }
        if (partial_score > users[user_id].scores[problem_id - 1]){
            users[user_id].scores[problem_id - 1] = partial_score;
            if (partial_score == p[problem_id - 1]){
                ++users[user_id].perfect;
            }
        }
    }
    
    vector<User> dense;
    for (int i = 0; i < 10001; ++i){
        if (users[i].valid){
            for (int j = 0; j < K; ++j){
                if (users[i].scores[j] != -1){
                    users[i].totalscore += users[i].scores[j];
                }
            }
            if (users[i].submits > 0){
                dense.push_back(users[i]);
            }
        }
    }

    sort(dense.begin(), dense.end(), compare);

    dense[0].rank = 1;
    for (int i = 1; i < dense.size(); ++i){
        dense[i].rank = i + 1;
        if (dense[i].totalscore == dense[i-1].totalscore){
            dense[i].rank = dense[i-1].rank;
        }
    }

    for (int i = 0; i < dense.size(); ++i){
        printf("%d %05d %d", dense[i].rank, dense[i].id, dense[i].totalscore);
        for (int j = 0; j < K; ++j){
            if (dense[i].scores[j] != -1){
                printf(" %d", dense[i].scores[j]);
            }
            else{
                printf(" -");
            }
        }
        printf("\n");
    }

    delete[] p;
    system("pause");
    return 0;
}