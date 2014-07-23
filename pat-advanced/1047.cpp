#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

bool compare(const char* lhs, const char* rhs)
{
    if (strcmp(lhs, rhs) >= 0){
        return false;
    }
    else{
        return true;
    }
}
int main()
{
    int N, K;
    scanf("%d%d", &N, &K);

    vector<char*>* courseinfo = new vector<char*>[K];
    
    int courses;
    int courseid;
    char name[40000][5];
    for (int i = 0; i < N; ++i){
        scanf("%s%d", name[i], &courses);
        for (int j = 0; j < courses; ++j){
            scanf("%d", &courseid);
            courseinfo[courseid - 1].push_back(name[i]);
        }
    }

    for (int i = 0; i < K; ++i){
        printf("%d %d\n", i + 1, courseinfo[i].size());
        sort(courseinfo[i].begin(), courseinfo[i].end(), compare);
        for (int j = 0; j < courseinfo[i].size(); ++j){
            puts(courseinfo[i][j]);
        }
    }

    delete[] courseinfo;
    system("pause");
    return 0;
}