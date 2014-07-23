#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct mypair{
    int i;
    int j;
};
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int* D = new int[N+1];
    D[0] = 0;
    for (int i = 1; i < N+1; ++i){
        scanf("%d", &D[i]);
        D[i] += D[i - 1];
    }
    int mini = 0;
    int minj = 0;
    int extra = M;
    vector<mypair> pairs;
    int solutioncount = 0;
    int lastpos = 0;
    for (int i = 0; i < N+1; ++i){
        for (int j = lastpos; j < N+1; ++j){
            int partialsum = D[j] - D[i];
            if (partialsum == M){
                printf("%d-%d\n", i + 1, j);
                ++solutioncount;
                lastpos = j + 1;
                break;
            }
            else if (partialsum > M){
                if (partialsum - M < extra){
                    extra = partialsum - M;
                    mypair mp;
                    mp.i = i + 1;
                    mp.j = j;
                    pairs.clear();
                    pairs.push_back(mp);
                }
                else if (partialsum - M == extra){
                    mypair mp;
                    mp.i = i + 1;
                    mp.j = j;
                    pairs.push_back(mp);
                }
                break;
            }
            lastpos = i + 1;
        }
        
    }
    if (solutioncount == 0){
        for (int i = 0; i < pairs.size(); ++i){
            printf("%d-%d\n", pairs[i].i, pairs[i].j);
        }
    }


    system("pause");
    return 0;
}