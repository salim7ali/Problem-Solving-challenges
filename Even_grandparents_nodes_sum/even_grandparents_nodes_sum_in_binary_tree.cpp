// https://www.youtube.com/watch?v=NcsZouBdd0c
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *left, *right;
    bool visited;
    int value;
};

bool isEven(int num){
    if(num%2)
        return false;
    return true;
}

void dfs(Node* node, pair<int, int> ancestors, int &result_sum){
    node->visited = true;

    if(isEven(ancestors.second)){
        result_sum += node->value;
    }

    if(node->left->visited == false){
        node->left->visited = true;
        dfs(node->left, {node->value, ancestors.first}, result_sum);
    }
    if(node->right->visited == false){
        node->right->visited = true;
        dfs(node->right, {node->value, ancestors.first}, result_sum);
    }
}

int get_even_grandparents_nodes_sum(Node* head){

//   <parent, grandparent>
    pair<int, int> ancestors = {INT_MIN, INT_MIN};

    int result_sum =0;
    dfs(head, ancestors, result_sum);

}