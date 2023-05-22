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
    int getValue(){
        return this->value;
    }
    Node* getLeft(){
        return this->left;
    }
    Node* getRight(){
        return this->right;
    }

}; 

void printLeftView(Node* parentNode){
    queue<pair<Node*, int>> bfsQueue;
    bfsQueue.push({parentNode, 1});

    pair<Node*, int> currNodeAndLevel;
    int levelNeeded = 1;
    while (bfsQueue.empty() == false){
        currNodeAndLevel = bfsQueue.front();
        bfsQueue.pop();

        if(currNodeAndLevel.second == levelNeeded){
            cout<<currNodeAndLevel.first->getValue();
            levelNeeded +=1;
        }

        Node* currNode = currNodeAndLevel.first;
        bfsQueue.push({currNode->getLeft(), currNodeAndLevel.second+1});
        bfsQueue.push({currNode->getRight() , currNodeAndLevel.second+1});
    }
    
}

int main(){
    
    
    return 0;
}