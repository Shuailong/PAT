#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
    string id;
    int grade;
    int finalrank;
    int localrank;
    int location;
};

bool compare(student stu1, student stu2)
{
    if (stu1.grade != stu2.grade){
        return stu1.grade < stu2.grade;
    }
    else{
        return stu1.id > stu2.id;
    }
}


int main()
{
    int n;
    cin >> n;

    vector<student>* locations = new vector<student>[n];
    vector<student> total;
    for (int i = 0; i < n; ++i){
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j){
            student stu;
            cin >> stu.id >> stu.grade;
            stu.location = i + 1;
            locations[i].push_back(stu);
        }
        sort(locations[i].rbegin(), locations[i].rend(), compare);
        for (int j = 0; j < K; ++j){
            locations[i][j].localrank = j + 1;
            if (j >= 1 &&
                locations[i][j].grade == locations[i][j - 1].grade){
                locations[i][j].localrank = locations[i][j - 1].localrank;
            }
            total.push_back(locations[i][j]);
        }
    }

    sort(total.rbegin(), total.rend(), compare);
    for (int i = 0; i < total.size(); ++i){
        total[i].finalrank = i + 1;
        if (i >= 1 &&
            total[i].grade == total[i - 1].grade){
            total[i].finalrank = total[i - 1].finalrank;
        }
    }

    cout << total.size() << endl;
    for (int i = 0; i < total.size(); ++i){
        cout << total[i].id << " " << total[i].finalrank << " "
            << total[i].location << " " << total[i].localrank << endl;
    }

    system("pause");
    return 0;
}