// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> stringToVector(string text){
    vector<char> result;
    result.push_back('@');
    for(int i=0; i<text.length(); i++){
        result.push_back(text[i]);
    }
    return result;
}

int LCS(string first, string second){
    vector<char> FIRST = stringToVector(first);
    vector<char> SECOND = stringToVector(second);

    vector<vector<int>> resultVec(FIRST.size(), vector<int> (SECOND.size())); 

    for(int i=0; i<resultVec.size(); i++){
        for(int j=0; j<resultVec[0].size(); j++){

            if(i == 0 || j == 0)
                resultVec[i][j] =0;
            else if(FIRST[i] == SECOND[j])
                resultVec[i][j] = resultVec[i-1][j-1] + 1; 
            else if(FIRST[i] != SECOND[j])
                resultVec[i][j] = max(resultVec[i][j-1], resultVec[i-1][j]);
        }
    }

    return resultVec[resultVec.size()-1][resultVec[0].size()-1];
}

int main(){
    string first = "AGGTAB";
    string second = "GXTXAYB";
    cout<<"Longest Common Subsequence between "<<first<<" and "<<second<<" is of length "<<LCS(first, second);
}
