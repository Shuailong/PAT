#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    int N, L;

    scanf("%d%d", &N, &L);

    vector<vector<int>> fans(N);
    for (int i = 0; i < N; ++i){
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; ++j){
            int followee;
            scanf("%d", &followee);
            fans[followee-1].push_back(i);
        }
    }
    
    int K;
    scanf("%d", &K);    
    for (int i = 0; i < K; ++i){
        bool* hasfoward = new bool[N];
        for (int i = 0; i < N; ++i){
            hasfoward[i] = false;
        }

        int blogger;
        scanf("%d", &blogger);
        hasfoward[blogger - 1] = true;

        deque<int> queue;
        queue.push_back(blogger - 1);        
        int currentlevel = 0;
        int last = blogger - 1;
        int endOfLevel = queue.back();
        while (!queue.empty()){ 
            int front = queue.front();
            queue.pop_front();  

            hasfoward[front] = true;
            for (int j = 0; j < fans[front].size(); ++j){
                if (!hasfoward[fans[front][j]]){
                    queue.push_back(fans[front][j]);
                    hasfoward[fans[front][j]] = true;
                    
                }
            }
            if (front == endOfLevel)
            {
                endOfLevel = queue.back();
                ++currentlevel;
            }

            if (currentlevel >= L){
                break;
            }            
        }

        int fowards = 0;
        for (int i = 0; i < N; ++i){
            if (hasfoward[i]){
                ++fowards;
            }
        }

        printf("%d\n", fowards-1);
        delete[] hasfoward;
    } 
   
    system("pause");
    return 0;
}