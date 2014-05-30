#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
    string id;
    int C;
    int M;
    int E;
    int A;
    int rank_c;
    int rank_m;
    int rank_e;
    int rank_a;
};

bool comp_c(student s1, student s2)
{
    return s1.C < s2.C;
}
bool comp_m(student s1, student s2)
{
    return s1.M < s2.M;
}
bool comp_e(student s1, student s2)
{
    return s1.E < s2.E;
}
bool comp_a(student s1, student s2)
{
    return s1.A < s2.A;
}

int min4(int n1, int n2, int n3, int n4)
{
    int res = n1 < n2 ? n1 : n2;
    res = res < n3 ? res : n3;
    res = res < n4 ? res : n4;

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<student> students;
    for (int i = 0; i < n; ++i){
        student stu;
        cin >> stu.id >> stu.C >> stu.M >> stu.E;
        stu.A = stu.C + stu.M + stu.E;
        students.push_back(stu);
    }
    sort(students.rbegin(), students.rend(), comp_a);
    for (int i = 0; i < n; ++i){
        students[i].rank_a = i + 1;
        if (i > 0 && students[i].A == students[i-1].A){
            students[i].rank_a = students[i-1].rank_a;
        }
    }
    sort(students.rbegin(), students.rend(), comp_c);
    for (int i = 0; i < n; ++i){
        students[i].rank_c = i + 1;
        if (i > 0 && students[i].C == students[i - 1].C){
            students[i].rank_c = students[i - 1].rank_c;
        }
    }
    sort(students.rbegin(), students.rend(), comp_m);
    for (int i = 0; i < n; ++i){
        students[i].rank_m = i + 1;
        if (i > 0 && students[i].M == students[i - 1].M){
            students[i].rank_m = students[i - 1].rank_m;
        }
    }
    sort(students.rbegin(), students.rend(), comp_e);
    for (int i = 0; i < n; ++i){
        students[i].rank_e = i + 1;
        if (i > 0 && students[i].E == students[i - 1].E){
            students[i].rank_e = students[i - 1].rank_e;
        }
    }

    for (int i = 0; i < m; ++i){
        string id;
        cin >> id;
        int j;
        for (j = 0; j < n; ++j){
            if (students[j].id == id){
                int minrank = min4(students[j].rank_a, students[j].rank_c, 
                    students[j].rank_m, students[j].rank_e);
                if (minrank == students[j].rank_a){
                    cout << minrank << " " << 'A' << endl;
                    break;
                }
                else if (minrank == students[j].rank_c){
                    cout << minrank << " " << 'C' << endl;
                    break;
                }
                else if (minrank == students[j].rank_m){
                    cout << minrank << " " << 'M' << endl;
                    break;
                }
                else{
                    cout << minrank << " " << 'E' << endl;
                    break;
                }                
            }
        }
        if (j == n){
            cout << "N/A" << endl;
        }
    }

    system("pause");
    return 0;
}