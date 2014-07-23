/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn                         |
|copyright : harmony 2014.                          |
\***************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct student{
    string name;
    string id;
    int grade;
};

bool compare(student lhs, student rhs)
{
    return lhs.grade < rhs.grade;
}

int main()
{
    int n;
    cin >> n;
    vector<student> students;

    for (int i = 0; i < n; ++i){
        student stu;
        cin >> stu.name >> stu.id >> stu.grade;
        students.push_back(stu);
    }
    
    sort(students.begin(), students.end(), compare);

    vector<student>::const_iterator begin = students.begin();
    vector<student>::const_iterator end = students.end()-1;
    cout << end->name << " " << end->id << '\n'
        << begin->name << " " << begin->id << endl;

    return 0;
}