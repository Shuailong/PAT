/***************************************************\ 
|Author: harmony                                    |
|email: zju_shuailong@163.com                       |
|csdn homepage: http://blog.csdn.net/shuaiilong     |
|pat: http://pat.zju.edu.cn             |
|copyright : harmony 2014.              |
\***************************************************/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct Node{
  int addr;
  int value;
  int next;
};
int main()
{
  int FirstAddr, N, K;
  scanf("%d%d%d", &FirstAddr, &N, &K);


  vector<Node> nodes(100000);
  for(int i = 0; i < N; ++i){
    Node node;
    scanf("%d%d%d", &node.addr, &node.value, &node.next);
    nodes[node.addr] = node;
  }

  if(FirstAddr == -1){
    printf("-1\n");
  }
  else{
    vector<Node> aftersort;
    int NextAddr = FirstAddr;
    while(NextAddr != -1){
      aftersort.push_back(nodes[NextAddr]);
      NextAddr = nodes[NextAddr].next;
    }

    vector<Node> final;
    int lastindex = K-1;
    while(lastindex < aftersort.size()){
      for(int i = lastindex; i > lastindex-K; --i){
        final.push_back(aftersort[i]);
      }
      lastindex += K;
    }
    for(int i = lastindex-K+1; i < aftersort.size(); ++i){
      final.push_back(aftersort[i]);
    }
    for(int i = 0; i < final.size()-1; ++i){
      final[i].next = final[i+1].addr;
    }

    int i;
    for(i = 0; i < final.size()-1; ++i){
      printf("%05d %d %05d\n", final[i].addr, final[i].value, final[i].next);
    }
    printf("%05d %d %d\n", final[i].addr, final[i].value, -1);
  }

  system("pause");
  return 0;
}