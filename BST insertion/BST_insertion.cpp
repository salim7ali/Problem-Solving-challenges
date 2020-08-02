#include <bits/stdc++.h>
using namespace std;

struct BSTNode{
    int value;
    BSTNode* left; //in C: struct BSTNode* left;
    BSTNode* right;
};

void insertUsingPointerToPoiner(BSTNode** rootPointer, int value){
    BSTNode* temp;
    if(*rootPointer == NULL){//root is NULL
        *rootPointer = (BSTNode*)malloc(sizeof(BSTNode));//in C++: *rootPointer = new BSTNode();
        temp = *rootPointer;
        temp->value = value;
    }
    else{
        temp = *rootPointer;
        while(temp->left != NULL && temp->right != NULL){
            if(value<temp->value){
                temp = temp->left;//same as temp = (*temp).left;
            }else{
                temp = temp->right;
            }
        }

        BSTNode* newNode = new BSTNode();
        if(value<temp->value){
            temp->left = newNode;
            temp->left->value = value;
        }else{
            temp->right = newNode;
            temp->right->value = value;
        }
    }
}

int main(){
    BSTNode* root;
    int n, value;

    cout<<"Enter no of elements to insert\n";
    cin>>n;
    while(n--){
        cin>>value;
        insertUsingPointerToPoiner(&root, value);
    }
}