#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct Node
{
    int Addr;
    char Ch;
    int Next;
    bool valid;
    Node(){
        valid = false;
    }
};
int main()
{
    int head1, head2, N;
    scanf("%d%d%d", &head1, &head2, &N);
    vector<Node> nodes(100000);
    for (int i = 0; i < N; ++i){
        Node node;
        scanf("%d %c %d", &node.Addr, &node.Ch, &node.Next);
        node.valid = true;
        nodes[node.Addr] = node;
    }

    if (head1 == -1 || head2 == -1){
        printf("-1\n");
    }
    else if (head1 == head2){
        printf("%05d\n", head1);
    }
    else{
        vector<Node> word1;
        vector<Node> word2;
        int nextAddr = head1;
        while (nextAddr != -1){
            if (!nodes[nextAddr].valid){
                break;
            }
            word1.push_back(nodes[nextAddr]);
            nextAddr = nodes[nextAddr].Next;
        }

        nextAddr = head2;
        while (nextAddr != -1){
            if (!nodes[nextAddr].valid){
                break;
            }
            word2.push_back(nodes[nextAddr]);
            nextAddr = nodes[nextAddr].Next;
        }
        vector<Node>::reverse_iterator rit1 = word1.rbegin();
        vector<Node>::reverse_iterator rit2 = word2.rbegin();
        bool alsame = false;
        while (true){ 
            if (rit1 == word1.rend() || rit1 == word1.rend()){
                break;
            }                
            if (rit1->Addr == rit2->Addr && rit1->Ch == rit2->Ch){
                ++rit1;
                ++rit2;
                continue;
            }
            else{
                if (rit1->Next != -1){
                    printf("%05d\n", rit1->Next);
                }
                else{
                    printf("-1\n");
                }
                break;
            }
        }
    }
    system("pause");
    return 0;
}