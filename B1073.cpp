#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  string num;
  cin >> num;
  int pos;
  if(num[0]== '+'){
    pos = 1;
  }
  else{
    pos = 0;
  }
  int digit = num[1]-'0';
  int i;
  for(i = 3; i < num.size(); ++i){
    if(num[i] == 'E'){
      break;
    }
  }
  int Epos = i;
  int expopos;
  if(num[i+1] == '+'){
    expopos = 1;
  }
  else{
    expopos = 0;
  }
  stringstream ss;
  for(i += 2;i<num.size(); ++i){
    ss << num[i]-'0';
  }
  int expo;
  ss >> expo;
  
  if(pos == 0){
    cout << "-";
  }
  if(expopos == 0){
    int shift = expo;
    cout << "0."; 
    for(int i = 0; i < shift-1; ++i){
      cout << "0";
    }
    cout << digit;
    for(int i = 3; i < Epos; ++i){
      cout << num[i];
    }
    cout << endl;
  }
  else{
    cout << digit;
    int overflow = 0;

    int i;
    for(i = 0; i < expo; ++i){
      if(3 + i < Epos){
        cout << num[3+i];
      }
      else{
        overflow = 1;
        cout << 0;
      }
    }
    if(overflow == 0 && num[i+3] != 'E'){
      cout << ".";
    }
    for(i = i+3; i < Epos; ++i){
      cout << num[i];
    }

    cout << endl;
  }
  system("pause");
  return 0;
}