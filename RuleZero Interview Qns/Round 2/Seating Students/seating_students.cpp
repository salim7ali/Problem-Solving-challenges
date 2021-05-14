#include<bits/stdc++.h>
using namespace std;

int SeatingStudents(int arr[], int arrLength){
    int const DESKS = arr[0];
    int const ROWS = arr[0]/2;
    // false = open
    // true = occupied
    vector<vector<bool>> tables(ROWS, vector<bool> (2, false));

    // fixing tables
    for(int i=1; i<arrLength; i++){
        int ele_row = ceil(arr[i]/2) -1;
        int ele_col = (arr[i]+1)%2;

        tables[ele_row][ele_col]=true; 
    }

    int totalPairs =0;
    // first column
    for(int row=0; row<ROWS-1; row++){
        if((tables[row][0]==false) && (tables[row+1][0]==false))
            totalPairs +=1;
    }
    // second column
    for(int row=0; row<ROWS-1; row++){
        if((tables[row][1]==false) && (tables[row+1][1]==false))
            totalPairs +=1;
    }
    // rows
    for(int row=0; row<ROWS; row++){
        if((tables[row][0]==false) && (tables[row][1]==false))
            totalPairs += 1;
    }
    return totalPairs;
}

int main(){
    int arr[]= {12, 2, 6, 7, 11};
    cout<<SeatingStudents(arr, 5);
}