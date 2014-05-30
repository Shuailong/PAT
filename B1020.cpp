#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct TreeNode;
typedef TreeNode *PtrNode;
typedef TreeNode *Tree;

struct TreeNode{
    int value;
    PtrNode left;
    PtrNode right;
};
Tree buildTree (Tree T, int N, 
     int* postorder, int* inorder)
{
    if (N == 0){
        return NULL;
    }
    if (T == NULL){
        T = (Tree)malloc(sizeof(TreeNode));
        T->value = postorder[N - 1];
        T->left = T->right = NULL;
        int* root = find(inorder, inorder + N, postorder[N - 1]);
        T->left = buildTree(T->left, root - inorder, postorder, inorder);
        T->right = buildTree(T->right, N - (1 + root - inorder),
            postorder + (root - inorder), inorder + (root - inorder)+1);
    }

    return T;
}

void levelorder(Tree T, int* nums)
{
    deque<PtrNode> queue;
    int i = 0;
    queue.push_back(T);
    PtrNode tempNode = T;
    while (tempNode != NULL){
        if (tempNode->left != NULL){
            queue.push_back(tempNode->left);
        }
        if (tempNode->right != NULL){
            queue.push_back(tempNode->right);
        }
        nums[i++] = queue.front()->value;

        queue.pop_front();
        if (!queue.empty()){
            tempNode = queue.front();
        }
        else{
            tempNode = NULL;
        }
    }
}
int main()
{
    int N;
    cin >> N;

    int* postorders = new int[N];
    int* inorders = new int[N];
    for (int i = 0; i < N; ++i){
        cin >> postorders[i];
    }
    for (int i = 0; i < N; ++i){
        cin >> inorders[i];
    }

    Tree T = NULL;
    T = buildTree(T, N, postorders, inorders);
    int* levelorders = new int[N];
    levelorder(T, levelorders);

    cout << levelorders[0];
    for (int i = 1; i < N; ++i){
        cout << " " << levelorders[i];
    }
    cout << endl;

    delete[] postorders;
    delete[] inorders;
    delete[] levelorders;
    system("pause");
    return 0;
}