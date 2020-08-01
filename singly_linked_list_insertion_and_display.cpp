#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* next;//in c: struct Node* left
};

int main(){
    // input values to singly linked list
    cout<<"Enter no of elements";
    int a, val;
    Node* temp;
    cin>>a;
    Node* head = NULL;
    while(a--){
        cin>>val;
        temp = new Node(); //in c: Node* temp = (Node*)malloc(sizeof(Node));
        temp->next = head; //in c: (*temp).next = head;
        temp->value = val;
        head = temp;
        // free(temp);
    }

    // display linked list
    // Node* temp = new Node();//Node* temp = (Node)malloc(sizeof(Node));
    temp = head;
    while(temp){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
}