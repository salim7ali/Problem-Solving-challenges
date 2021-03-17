// https://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next=NULL;
};

class LLOperation{
private:
    Node* left;
public:
    void setPairs(Node *r){
        Node *temp=this->left;
        this->left->next = r;

        if(r==mid && size%2==0){
            r->next = NULL;
            return;
        }

        r->next=temp;
        this->left=temp;
        if(r==mid)//size%2==1
            left->next=NULL;
    }

    Node* foldLL(Node* head){
        this->left = head;
        Node* right = getMid(head);

        setPairs(right);
    }

};


int main(){
    // Node head = 

    LLOperation obj;
    // obj.foldLL(head);
}
