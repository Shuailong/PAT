#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

//Note: 
//map会超时，vector不会

int getHashkey(const char* name)
{
    int key = (name[0] - 'A') * 26 * 26 * 10
        + (name[1] - 'A') * 26 * 10
        + (name[2] - 'A') * 10
        + (name[3] - '0');

    return key;
}
int main()
{
    const int MAX = 26 * 26 * 26 * 10;
    int N, K;
    cin >> N >> K;

    // register students to courses
    vector<vector<int>> reginfo(MAX + 1);
    char name[5];
    int courseid, students;
    for (int i = 0; i < K; ++i){
        scanf("%d%d", &courseid, &students);
        for (int j = 0; j < students; ++j){
            scanf("%s", name);
            reginfo[getHashkey(name)].push_back(courseid);
        }
    }

    vector<int> courses;
    for (int i = 0; i < N; ++i){
        scanf("%s", name);
        courses = reginfo[getHashkey(name)];
        sort(courses.begin(), courses.end());
        printf("%s %d", name, courses.size());
        for (int j = 0; j < courses.size(); ++j){
            printf(" %d", courses[j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}