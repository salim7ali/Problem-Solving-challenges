// Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.

#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node *left;
    node *right;
};

node* createBalancedBST(int L, int R, &nums){
    if(L==R){

    }
    
    int mid = L + floor((R-L)/2);
    node *currNode = new node();
    currNode->value = nums[mid];

    currNode->left = createBalancedBST(L, mid-1, nums);
    currNode->right = createBalancedBST(mid+1, R, nums);

    return currNode;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};

    node *head = createBalancedBST(0, nums.size()-1, nums);
}