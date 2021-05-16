#include<bits/stdc++.h>
using namespace std;

int longestVovelSubsequence(char *first, char *second){
    vector<char> first_vov;
    first_vov.push_back('X');//unused 0 index
    vector<char> second_vov;
    second_vov.push_back('X');
    
    for(int i=0; first[i]!=NULL; i++){
        if(first[i] =='a' ||first[i] =='e' ||first[i] =='i' ||first[i] =='o' ||first[i] =='u' ){
            first_vov.push_back(first[i]);
        }
    }
    for(int i=0; second[i]!=NULL; i++){
        if(second[i] =='a' ||second[i] =='e' ||second[i] =='i' ||second[i] =='o' ||second[i] =='u' ){
            second_vov.push_back(second[i]);
        }
    }

    vector<vector<int>> longest_subsequence(first_vov.size(), vector<int> (second_vov.size(), 0));

    for(int i=1; i<first_vov.size(); i++){
        for(int j=1; j<second_vov.size(); j++){
            if(first_vov[i] == second_vov[j]){
                longestVovelSubsequence[i][j] += longestVovelSubsequence[i-1][j-1];
            }else{
                longestVovelSubsequence[i][j] = max(longestVovelSubsequence[i-1][j], longestVovelSubsequence[i][j-1]);
            }
        }
    }

    return longestVovelSubsequence[longestVovelSubsequence.size()][longestVovelSubsequence[0].size()];
}

int main(){
    char first[] = {'s', 'a', 'l', 'i', 'm', 'u', 'k', 'o', 'b'};
    char second[] = {'f', 'a', 'g', 'u', 'e', 'm', 'o', 'n', 'p', 'a'};
    cout<<longestVovelSubsequence(first, second);
}