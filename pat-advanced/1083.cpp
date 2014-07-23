#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Record
{
	string name;
	string id;
	int grade;
};

bool compare(Record r1, Record r2)
{
	return r1.grade > r2.grade;
}

int main()
{
	int N;
	vector<Record> students;

	cin >> N;

	for(int i = 0; i < N; ++i){
		Record r;
		cin >> r.name >> r.id >> r.grade;
		students.push_back(r);
	}

	int grade1, grade2;
	cin >> grade1 >> grade2;

	vector<Record> selected;
	for(int i = 0; i < students.size(); ++i){
		if(students[i].grade >= grade1 && students[i].grade <= grade2){
			selected.push_back(students[i]);
		}
	}

	if(selected.size() == 0){
		cout << "NONE" << endl;
	}
	else {
		sort(selected.begin(), selected.end(), compare);
		for(int i = 0; i < selected.size(); ++i){
			cout << selected[i].name << " " << selected[i].id << endl;
		}
	}

	return 0;
}