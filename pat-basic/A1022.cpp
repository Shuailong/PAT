/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn             |
|copyright : harmony 2014.              |
\***************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  int d;
  cin >> d;
  int c = a+b;

  if(c == 0){
    cout << 0 << endl;
  }
  else{
  vector<int> digits;
  while(c){
    int digit = c % d;
    c /= d;
    digits.push_back(digit);
  }
  for(int i = digits.size()-1; i >=0; --i){
    cout << digits[i];
  }
  cout << endl;
  }


  return 0;
}