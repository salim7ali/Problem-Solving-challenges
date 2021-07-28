// Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.

#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node *left;
    node *right;
};

int main(){
    vector<int> nums = {1, 2, 3, 4};

    node *head = createBalancedBST();
}