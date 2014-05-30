#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
// Note:
// use cursor to calculate intersect
// do not use set merge
int main()
{
    int N;
    scanf("%d", &N);

    set<int>* sets = new set<int>[N];
    for (int i = 0; i < N; ++i){
        int M;
        scanf("%d", &M);
        for (int j = 0; j < M; ++j){
            int number;
            scanf("%d", &number);
            sets[i].insert(number);
        }
    }

    double simi[50][50];
    for (int i = 0; i < 50; ++i){
        for (int j = 0; j < 50; ++j){
            simi[i][j] = -1.0;
        }
    }

    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; ++i){
        int set1, set2;
        scanf("%d%d", &set1, &set2);

        if (simi[set1 - 1][set2 - 1] != -1.0){
            printf("%.1lf%%\n", simi[set1 - 1][set2 - 1] * 100);
        }
        else{
            int size1 = sets[set1 - 1].size();
            int size2 = sets[set2 - 1].size();

            int common = 0;
            set<int>::const_iterator cit1 = sets[set1 - 1].cbegin();
            set<int>::const_iterator cit2 = sets[set2 - 1].cbegin();
            while( cit1 != sets[set1 - 1].cend() && cit2 != sets[set2 - 1].cend()){
                if (*cit1 == *cit2){
                    ++common;
                    ++cit1; ++cit2;
                }
                else if (*cit1 < *cit2){
                    ++cit1;
                }
                else{
                    ++cit2;
                }
            }
            double similarity = (double)(common)
                / (double)(size1+size2-common);

            simi[set1 - 1][set2 - 1] = simi[set2 - 1][set1 - 1] = similarity;
            printf("%.1lf%%\n", similarity * 100);
        }
    }

    delete[] sets;
    system("pause");
    return 0;
}