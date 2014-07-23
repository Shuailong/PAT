#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct mytime{
    int hour;
    int minute;
    int second;
};
struct student{
    string id;
    mytime in;
    mytime out;
};

bool compin(student lhs, student rhs)
{
    if (lhs.in.hour != rhs.in.hour){
        return lhs.in.hour < rhs.in.hour;
    }
    else if (lhs.in.minute != rhs.in.minute){
        return lhs.in.minute < rhs.in.minute;
    }
    else{
        return lhs.in.second < rhs.in.second;
    }
}

bool compout(student lhs, student rhs)
{
    if (lhs.out.hour != rhs.out.hour){
        return lhs.out.hour < rhs.out.hour;
    }
    else if (lhs.out.minute != rhs.out.minute){
        return lhs.out.minute < rhs.out.minute;
    }
    else{
        return lhs.out.second < rhs.out.second;
    }
}
int main()
{
    int m;
    cin >> m;
    
    vector<student> students;
    for (int i = 0; i < m; ++i){
        student stu;
        char str[15];
        scanf("%s %d:%d:%d %d:%d:%d", str, &stu.in.hour,
            &stu.in.minute, &stu.in.second, &stu.out.hour, &stu.out.minute, &stu.out.second);
        stu.id = str;
        students.push_back(stu);
    }

    sort(students.begin(), students.end(), compin);
    cout << students.begin()->id << " ";
    sort(students.begin(), students.end(), compout);
    cout << (students.end()-1)->id << endl;
    system("pause");
    return 0;
}