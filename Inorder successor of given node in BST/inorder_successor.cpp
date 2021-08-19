// Find inorder successor of node in BST. Node need not be root. 

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node *parent;

};

class BinarySearchTree{
    Node *root;

public:
    Node* firstInorderVal(Node *rightChild){
        Node *currPtr = rightChild;
        while(currPtr->left)
            currPtr = currPtr->left;
        return currPtr;
    }

    Node* findInOrderSuccessor(Node *inputNode){
        if(inputNode->right){
            return firstInorderVal(inputNode->right);
        }else{
            Node *currNode = inputNode;
            while(currNode->parent && currNode->parent->right == currNode){
                currNode = currNode->parent;
            }

            // If root
            if(currNode->parent == NULL)
                return currNode;
            
            // Found first parent whose LST we are part of
            return currNode->parent;
        }
    }
};


int main(){

}
