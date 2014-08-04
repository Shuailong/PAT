/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn             |
|copyright : harmony 2014.              |
\***************************************************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int freq[10];
  for(int i= 0; i < 10; ++i){
    freq[i] = 0;
  }
  for(int i = 0; i < s.size(); ++i){
    ++freq[s[i]-'0'];
  }

  for(int i = 0; i < 10; ++i){
    if(freq[i]!=0){
      cout << i << ":"<<freq[i]<<endl;
    }
  }

  return 0;
}