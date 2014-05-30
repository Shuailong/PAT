#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    int* Values = new int[N];
    int* coin = new int[1000];
    memset(coin, 0, sizeof(int)* 1000);
    for (int i = 0; i < N; ++i){
        scanf("%d", &Values[i]);
        ++coin[Values[i]];
    }
    sort(Values, Values + N);

    int i;
    for (i = 0; i < N; ++i){
        --coin[Values[i]];
        if (coin[M - Values[i]] > 0){
            printf("%d %d\n", Values[i], M - Values[i]);
            break;
        }
        ++coin[Values[i]];
    }
    if (i == N){
        printf("No Solution\n");
    }

    delete[] Values;
    delete[] coin;
    system("pause");
    return 0;
}