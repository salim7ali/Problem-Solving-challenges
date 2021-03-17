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
    Node* pivotPtr;
    int llSize=1;
public:
    void resetPairs(Node *r){
        Node *temp=this->left;
        this->left->next = r;

        if(r==pivotPtr && llSize%2==0){
            r->next = NULL;
            return;
        }
        r->next=temp;
        this->left=temp;
        if(r==pivotPtr)//size%2==1
            left->next=NULL;
    }

    Node* getPivot(Node* ptr){
        Node *slowPtr=ptr, *fastPtr=ptr->next;

        while(fastPtr->next != NULL && fastPtr->next->next !=NULL){
            llSize += 1;
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next->next;
        }
        if(fastPtr->next == NULL)
            llSize *=2;
        else
            llSize = (llSize*2)-1;
        pivotPtr=slowPtr->next;
        return pivotPtr;
    }

    Node* foldLL(Node* head){
        this->left = head;
        Node* right = getPivot(head);

        resetPairs(right);
    }

};


int main(){
    // Node head = 

    LLOperation obj;
    obj.foldLL(head);
}
