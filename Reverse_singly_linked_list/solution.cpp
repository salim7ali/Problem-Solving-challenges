// https://leetcode.com/problems/reverse-linked-list/
#include<bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    void recursiveCall(ListNode* prevNode, ListNode* currNode, ListNode* head){
        // no node edge case
        if(currNode == NULL)
            return;
        if(currNode->next == NULL){
            recursiveCall(currNode, currNode->next, head);
        }else{  //  reached tail
            head = currNode;
        }

        currNode->next = prevNode;
    }

    ListNode* reverseList(ListNode* head) {
        recursiveCall(NULL, head, head);
        return head;
    }
};