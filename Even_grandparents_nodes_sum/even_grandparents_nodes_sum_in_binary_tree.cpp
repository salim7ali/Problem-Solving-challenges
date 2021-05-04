// https://www.youtube.com/watch?v=NcsZouBdd0c

void dfs(Node* node){
    node->visited = true;

    if(node->left->visited == false)
        dfs(node->left);
    if(node->left->visited == false)
        dfs(node->left);
}

int get_even_grandparents_nodes_sum(Node* head){

    pair<int, int> ancestors;


}