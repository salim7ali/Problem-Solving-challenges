#include<bits/stdc++.h>
using namespace std;

class Node{
    int value;
    Node *left, *right;
public:
    Node(){
        this->left = NULL;
        this->right = NULL;
    }

    void setLeft(Node *left){
        this->left = left;
    }

    void setRight(Node *right){
        this->right = right;
    }

}; 

void printLeftView(Node* currNode){
    queue<pair<Node*, int>> bfsQueue;
    bfsQueue.push({currNode, 1});

    
}

int main(){
    
    
    return 0;
}