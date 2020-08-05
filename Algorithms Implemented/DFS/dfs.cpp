#include <bits/stdc++.h>
using namespace std;

const int SIZE = 10;
bool visited[SIZE] = {false, false, false, false, false, false, false, false, false, false};

//                               a, b, c, d, e, f, g, h, i, j
bool adjMatrix[SIZE][SIZE] = {  {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},//a
                                {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},//b
                                {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},//c
                                {0, 0, 0, 0, 1, 1, 0, 0, 1, 0},//d
                                {0, 1, 1, 1, 0, 1, 0, 0, 0, 1},//e
                                {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},//f
                                {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},//g
                                {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},//h
                                {1, 0, 0, 1, 0, 0, 0, 1, 0, 0},//i
                                {0, 1, 0, 0, 1, 0, 0, 1, 0, 0} //j
                                };

void dfs(int vert){
    cout<<(char)(97+vert)<<" ";

    // pass through all adjacent vertices of vertex "vert"
    for(int i=0; i<SIZE; i++){
        
        // dive depth in
        if(adjMatrix[vert][i] && visited[i] == false){
            visited[i] = true;
            dfs(i);
        }
    }
}
                            
int main(){
    int startVert = 4;

    cout<<"DFS order: ";
    dfs(startVert);
    return 0;
}