#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct student
{
    int id;
    char name[9];
    int grade;
    bool valid;
    student(){
        valid = false;
    }
};

bool comparename(student stu1, student stu2)
{
    if (strcmp(stu1.name, stu2.name) != 0){
        if (strcmp(stu1.name, stu2.name) < 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return stu1.id < stu2.id;
    }
}

bool comparegrade(student stu1, student stu2)
{
    if (stu1.grade != stu2.grade){
        return stu1.grade < stu2.grade;
    }
    else{
        return stu1.id < stu2.id;
    }
}

bool compareid(student stu1, student stu2)
{
    return stu1.id < stu2.id;
}

int main()
{
    int N, C;
    scanf("%d%d", &N, &C);
   
    vector<student> students;
    for (int i = 0; i < N; ++i){
        student stu;
        scanf("%d%s%d", &stu.id, stu.name, &stu.grade);
        students.push_back(stu);
    }
    if (C == 1){
        sort(students.begin(), students.end(), compareid);
    }
    else if (C == 2){
        sort(students.begin(), students.end(), comparename);
    }
    else{
        sort(students.begin(), students.end(), comparegrade);
    }
    
    for (int i = 0; i < students.size(); ++i){
        printf("%06d %s %d\n", students[i].id, students[i].name, students[i].grade);
    }

  
    system("pause");
    return 0;
}