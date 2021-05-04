// https://www.youtube.com/watch?v=NcsZouBdd0c

void dfs(Node* node){
    node->visited = true;

    if(node->left->visited == false){
        node->left->visited = true;
        dfs(node->left);
    }
    if(node->right->visited == false){
        node->right->visited = true;
        dfs(node->right);
    }
}

int get_even_grandparents_nodes_sum(Node* head){

//   <parent, grandparent>
    pair<int, int> ancestors = {INT_MIN, INT_MIN};

    

}