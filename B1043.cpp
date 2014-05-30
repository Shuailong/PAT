#include <iostream>
#include <vector>
using namespace std;

struct TreeNode;
typedef TreeNode *PtrNode;
typedef TreeNode *Tree;

struct TreeNode{
    int value;
    PtrNode left;
    PtrNode right;
};

Tree insertBST(int value, Tree T)
{
    if (T == NULL){
        T = (Tree)malloc(sizeof(TreeNode));
        T->value = value;
        T->left = T->right = NULL;
    }
    else{
        if (value >= T->value){
            T->right = insertBST(value, T->right);
        }
        else{
            T->left = insertBST(value, T->left);
        }
    }

    return T;
}

Tree insertIMBST(int value, Tree T)
{
    if (T == NULL){
        T = (Tree)malloc(sizeof(TreeNode));
        T->value = value;
        T->left = T->right = NULL;
    }
    else{
        if (value < T->value){
            T->right = insertIMBST(value, T->right);
        }
        else {
            T->left = insertIMBST(value, T->left);
        }
    }

    return T;
}

vector<int> preorder(Tree T)
{
    vector<int> res;
    if (T != NULL){
        res.push_back(T->value);
        vector<int> left = preorder(T->left);
        for (int i = 0; i < left.size(); ++i){
            res.push_back(left[i]);
        }
        vector<int> right = preorder(T->right);
        for (int i = 0; i < right.size(); ++i){
            res.push_back(right[i]);
        }
    }

    return res;
}

vector<int> postorder(Tree T)
{
    vector<int> res;
    if (T != NULL){
        vector<int> left = postorder(T->left);
        for (int i = 0; i < left.size(); ++i){
            res.push_back(left[i]);
        }
        vector<int> right = postorder(T->right);
        for (int i = 0; i < right.size(); ++i){
            res.push_back(right[i]);
        }
        res.push_back(T->value);
    }
    return res;
}

int main()
{
    int N;
    cin >> N;

    vector<int> Nums;
    int num;
    for (int i = 0; i < N; ++i){
        cin >> num;
        Nums.push_back(num);
    }

    Tree T = NULL;
    if (Nums[1] < Nums[0]){
        //left child less than root, BST        
        for (int i = 0; i < N; ++i){
            T = insertBST(Nums[i], T);
        }
    }
    else{
        // left child no less than root, IMBST
        for (int i = 0; i < N; ++i){
            T = insertIMBST(Nums[i], T);
        }
    }

    if (preorder(T) == Nums){
        cout << "YES" << endl;
        vector<int> post = postorder(T);
        cout << post[0];
        for (int i = 1; i < post.size(); ++i){
            cout << " " << post[i];
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }


    system("pause");
    return 0;
}