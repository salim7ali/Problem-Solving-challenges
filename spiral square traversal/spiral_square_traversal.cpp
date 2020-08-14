// traverse matrix in clockwise spiral starting from index 00 
// https://www.youtube.com/watch?v=_hxAfrslBNw&feature=youtu.be
// implemented video question for square matrix

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void spiralTraverse(vector<vector<char>> letters){
    int i=0, j=0;
    int direction = 0;//0 right, 1 down, 2 left, 3 up 

    cout<<letters[0][0]<<" ";
    for(int outSizeDec = letters.size()-1; outSizeDec>=0; outSizeDec--){
        for(int outSizeIter = 0; outSizeIter<outSizeDec; outSizeIter++){
            
            if(direction == 0){
                for(int col =0; col<outSizeDec; col++){
                    j += 1;
                    cout<<letters[i][j]<<" ";
                }
            }else if(direction == 1){
                for(int row =0; row<outSizeDec; row++){
                    i += 1;
                    cout<<letters[i][j]<<" ";
                }
            }else if(direction == 2){
                for(int col =0; col<outSizeDec; col++){
                    j -= 1;
                    cout<<letters[i][j]<<" ";
                }
            }else{//direction == 3
                for(int row =0; row<outSizeDec; row++){
                    i -= 1;
                    cout<<letters[i][j]<<" ";
                }
            }
            
            direction += 1;
            direction %= 4;
        }
        if(outSizeDec == 0 && direction == 2){
            j -= 1;
            cout<<letters[i][j]<<" ";
        }
    }
}
int main(){
    vector<vector<char>> letters= { {'a', 'b', 'c', 'd'},
                                    {'l', 'm', 'n', 'e'},
                                    {'k', 'p', 'o', 'f'},
                                    {'j', 'i', 'h', 'g'}};

    spiralTraverse(letters);
}
