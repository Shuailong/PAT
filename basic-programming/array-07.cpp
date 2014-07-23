#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	int count[10];

	for(int i = 0; i < 10; ++i){
		count[i] = 0;
	}
	cin >> N;
	string num;
	for(int i = 0; i < N; ++i){
		cin >> num;
		for(int j = 0; j < num.size(); ++j){
			++count[num[j]-'0'];
		}
	}

	int max = -1;
	for(int i = 0; i < 10; ++i){
		if(count[i] > max){
			max = count[i];
		}
	}

	cout << max << ":";
	for(int i = 0; i < 10; ++i){
		if(count[i] == max){
			cout << " " << i; 
		}
	}
	cout << endl;


	return 0;
}