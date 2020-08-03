#include <bits/stdc++.h>
using namespace std;

const int SIZE = 10;
bool visited[SIZE] = {false, false, false, false, false, false, false, false, false, false};
vector<int> Q;

void dispVisited(){
    for(int i=0; i<SIZE; i++){
        cout<<char(97+i)<<" ";
    }
    cout<<"\n";
    for(int i=0; i<SIZE; i++){
        cout<<visited[i]<<" ";
    }
    cout<<"\n---\n";
}

int main(){
    int startVert = 3;//             a, b, c, d, e, f, g, h, i, j
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

    visited[startVert] = true;
    int curVertex = startVert;
    while(1){
        cout<<"curVertex: "<<(char)(97+curVertex)<<"\n";
        visited[curVertex] = true;

        // pass through all edged of vertex 
        for(int col= 0; col<SIZE; col++){
            if(adjMatrix[curVertex][col]){

                if(visited[col] == false){
                    cout<<(char)(97+col);
                    visited[col] = true;
                    Q.push_back(col);
                }
            }
        }
        cout<<"\n";
        if( Q.size() == 0) 
            return 0;
        else{
            curVertex = Q[0];//deque
            Q.erase(Q.begin());
        }
        dispVisited();
    }
    
    return 0;
}