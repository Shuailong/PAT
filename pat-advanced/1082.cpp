#include <iostream>
#include <string>

using namespace std;

int main()
{
	const string digits[] = {"ling", "yi", "er", "san", "si", "wu", 
		"liu", "qi", "ba", "jiu"};
	const string units[] = {" ", "Shi", "Bai", "Qian"};
	string number;
	cin >> number;

	if(number[0] == '-'){
		cout << "Fu ";
		number = number.substr(1);
	}

	cout << number;

	int size = number.size();

	if(size <= 4){
		for(int i = 0; i < size; ++i){
			cout << digits[number[i]] << " " << units[number.size()-i-1];
		}
	}

	return 0;
}