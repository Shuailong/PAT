#include <iostream>
using namespace std;

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;

struct AVLNode
{
    int value;
    AVLTree left;
    AVLTree right;
    int height;
};

int Height(Position P)
{
    if (P == NULL){
        return -1;
    }
    else{
        return P->height;
    }
}

Position SingleRotateWithLeft(Position K2)
{
    Position K1 = K2->left;

    K2->left = K1->right;
    K1->right = K2;

    K2->height = Height(K2->left) > Height(K2->right) ? Height(K2->left) : Height(K2->right);
    ++K2->height;
    K1->height = Height(K1->left) > K2->height ? Height(K1->left) : K2->height;
    ++K1->height;

    return K1;
}

Position SingleRotateWithRight(Position K1)
{
    Position K2 = K1->right;

    K1->right = K2->left;
    K2->left = K1;

    K1->height = Height(K1->left) > Height(K1->right) ? Height(K1->left) : Height(K1->right);
    ++K1->height;
    K2->height = Height(K2->right) > K1->height ? Height(K1->right) : K1->height;
    ++K2->height;

    return K2;
}

Position DoubleRotateWithLeft(Position K3)
{
    K3->left = SingleRotateWithRight(K3->left);
    return SingleRotateWithLeft(K3);
}


Position DoubleRotateWithRight(Position K4)
{
    K4->right = SingleRotateWithLeft(K4->right);
    return SingleRotateWithRight(K4);
}

AVLTree insert(int X, AVLTree T)
{
    if (T == NULL){
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->height = 0;
        T->left = T->right = NULL;
        T->value = X;
    }
    else if (X < T->value){
        T->left = insert(X, T->left);
        if (Height(T->left) - Height(T->right) >= 2){
            if (X < T->left->value){
                T = SingleRotateWithLeft(T);
            }
            else{
                T = DoubleRotateWithLeft(T);
            }
        }
    }
    else if (X > T->value){
        T->right = insert(X, T->right);
        if (Height(T->right) - Height(T->left) >= 2){
            if (X > T->right->value){
                T = SingleRotateWithRight(T);
            }
            else{
                T = DoubleRotateWithRight(T);
            }
        }
    }

    T->height = Height(T->left)>Height(T->right) ? Height(T->left) : Height(T->right);
    ++T->height;

    return T;
}
int main()
{
    int n;
    cin >> n;
    AVLTree T = NULL;
    for (int i = 0; i < n; ++i){
        int num;
        cin >> num;
        T = insert(num, T);
    }
    cout << T->value << endl;

    system("pause");
    return 0;
}