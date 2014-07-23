/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn                         |
|copyright : harmony 2014.                          |
\***************************************************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int sum = 0;
	for (int i = 0; i < s.size(); ++i){
		int digit = s[i]-'0';
		sum += digit;
	}

	const string pinyin[10] = {"ling", "yi", "er", "san", "si", "wu", 
        "liu", "qi", "ba", "jiu"};

    if (sum >= 100)
    {
        int bai = sum / 100;
        int shi = (sum - 100 * bai)/10;
        int ge = sum % 10;
        cout << pinyin[bai] << " " << pinyin[shi] << " " << pinyin[ge] << endl;
    }

    else if (sum >= 10)
    {
        int shi = sum / 10;
        int ge = sum % 10;
        cout << pinyin[shi] << " " << pinyin[ge] << endl;
    }

    else{
        cout << pinyin[sum] << endl;
    }


	return 0;
}