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
    ListNode* recursiveHelper(ListNode* curr, ListNode* prev){
        ListNode* newHead;
        if(curr->next != NULL){
            newHead = recursiveHelper(curr->next, curr);
        }else{  // at tail
            newHead = curr;
        }

        curr->next = prev;

        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        return recursiveHelper(head, NULL);
    }
};