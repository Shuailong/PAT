/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn							|
|copyright : harmony 2014.							|
\***************************************************/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int steps = 0;
	int m = n;
	while (m != 1)
	{
		if (m % 2 == 0)
		{
			m /= 2;
		}
		else
		{
			m = (m * 3 + 1) / 2;
		}
		++steps;
	}
	cout << steps;

	return 0;
}