#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct student
{
    string name;
    char gender;
    string id;
    int grade;
};

bool comp(student stu1, student stu2)
{
    return stu1.grade < stu2.grade;
}
int main()
{
    int N;
    cin >> N;
    vector<student> boys;
    vector<student> girls;
    for (int i = 0; i < N; ++i){
        student stu;
        cin >> stu.name >> stu.gender >> stu.id >> stu.grade;
        if (stu.gender == 'F'){
            girls.push_back(stu);
        }
        else{
            boys.push_back(stu);
        }
    }
    sort(boys.begin(), boys.end(), comp);
    sort(girls.begin(), girls.end(), comp);

    if (girls.size() == 0){
        cout << "Absent" << endl;
    }
    else{
        cout << (*(girls.end() - 1)).name << " " << (*(girls.end() - 1)).id << endl;
    }

    if (boys.size() == 0){
        cout << "Absent" << endl;
    }
    else{
        cout << (*boys.begin()).name << " " << (*boys.begin()).id << endl;
    }

    if (girls.size() == 0 || boys.size() == 0){
        cout << "NA" << endl;
    }
    else{
        cout << (*(girls.end() - 1)).grade - (*boys.begin()).grade << endl;
    }

    system("pause");

    return 0;
}