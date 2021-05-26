#include<bits/stdc++.h>
using namespace std;

#define v2d vector<vector<int>>


class MazeSolver{
    v2d maze;
    v2d currently_visited;

    pair<int, int> START_INDICES = {0, 0};
    pair<int, int> END_INDICES;
    
    vector<pair<int, int>> directions= {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    MazeSolver(v2d &maze){
        this->maze = maze;

        this->END_INDICES = {maze.size()-1, maze[0].size()-1};

        this->currently_visited = maze;
        for(int i=0; i<this->currently_visited.size(); i++)
            for(int j=0; j<this->currently_visited[0].size(); j++)
                this->currently_visited[i][j] =0;
    }

    bool isValidNode(int i, int j, v2d &maze){
        if(i>=0 && i<maze.size() && j>=0 && j<maze[0].size)
            return true;
        return false;
    }

    void disp_matrix(v2d &matrix){
        for(int i=0; i< matrix.size(); i++){
            for(int j=0; j< matrix[0].size(); j++){
                cout<<matrix[i][j]<<" ";
            }cout<<"\n";
        }
    }

    void dfs(int i, int j){
        currently_visited[i][j] = 1;
        if(i==END_INDICES.first && j==END_INDICES.second){
            disp_matrix(currently_visited);
            currently_visited[i][j] = 0;
            return;
        }

        for(int k=0; k<4; k++){
            int neighbour_i = i + directions[k].first; 
            int neighbour_j = j + directions[k].second; 
            if(isValidNode(neighbour_i, neighbour_j, maze) && currently_visited[neighbour_i][neighbour_j]==0){
                dfs(neighbour_i, neighbour_j);
            }
        }
        currently_visited[i][j] = 0;
    }

    int generate_paths(){
        
        dfs(START_INDICES.first, START_INDICES.second);
    }

};

int main(){
    v2d grid = {{1, 1, 1},
                {1, 1, 0},
                {1, 1, 1}};
    MazeSolver obj(grid);
    obj.generate_paths();

}