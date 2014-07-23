#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// reference: http://www.2cto.com/kf/201311/254415.html

struct Node
{
    int addr;
    int value;
    int next;
    bool valid;
    bool operator < (const Node& n)const{
        return this->value < n.value;
    }
    Node(){
        valid = false;
    }
};

int main()
{
    const int MAX = 100000;

    int N;
    int HeadAddr;
    scanf("%d%d", &N, &HeadAddr);

    vector<Node> nodes(MAX);
    for (int i = 0; i < N; ++i){
        Node node;
        scanf("%d%d%d", &node.addr, &node.value, &node.next);
        node.valid = true;
        nodes[node.addr] = node;
    }

    vector<Node> list;
    int NextAddr;
    NextAddr = HeadAddr;
    while (true){
        if (NextAddr == -1){
            break;
        }
        if (nodes[NextAddr].valid){
            list.push_back(nodes[NextAddr]);
            NextAddr = nodes[NextAddr].next;
        }
        else{
            break;
        }
    }

    if (list.empty()){
        if (HeadAddr == -1){
            printf("0 -1\n");
        }
        else{
            printf("0 %05d\n", HeadAddr);
        }
    }
    else{
        sort(list.begin(), list.end());
        HeadAddr = list[0].addr;

        for (int i = 0; i < list.size() - 1; ++i){
            list[i].next = list[i + 1].addr;
        }

        printf("%d %05d\n", list.size(), list[0].addr);
        int i;
        for (i = 0; i < list.size() - 1; ++i){
            printf("%05d %d %05d\n", list[i].addr, list[i].value, list[i].next);
        }
        printf("%05d %d %d\n", list[i].addr, list[i].value, -1);
    }

    system("pause");
    return 0;
}