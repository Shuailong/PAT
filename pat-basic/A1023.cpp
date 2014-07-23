/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn             |
|copyright : harmony 2014.              |
\***************************************************/
#include <iostream>
using namespace std;

int main()
{
  int nums[10];
  for(int i = 0; i < 10; ++i){
    cin >> nums[i];
  }
  int i;
  for(i = 1; i < 10; ++i){
    if(nums[i]>0){
      --nums[i];
      break;
    }
  }
  if(i < 10){
  cout << i;
  }
  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < nums[i]; ++j){
      cout << i;
    }
  }
  cout << endl;

  return 0;
}