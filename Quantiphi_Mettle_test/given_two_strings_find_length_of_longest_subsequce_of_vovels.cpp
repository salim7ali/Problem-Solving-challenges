#include<bits/stdc++.h>
using namespace std;

int longestVovelSubsequence(char *first, char *second){
    vector<char> first_vov;
    first_vov.push_back('X');//unused 0 index
    vector<char> second_vov;
    second_vov.push_back('X');
    
    for(int i=0; first[i]!='\0'; i++){
        if(first[i] =='a' ||first[i] =='e' ||first[i] =='i' ||first[i] =='o' ||first[i] =='u' ){
            first_vov.push_back(first[i]);
        }
    }
    for(int i=0; second[i]!='\0'; i++){
        if(second[i] =='a' ||second[i] =='e' ||second[i] =='i' ||second[i] =='o' ||second[i] =='u' ){
            second_vov.push_back(second[i]);
        }
    }

    vector<vector<int>> longest_subsequence(first_vov.size(), vector<int> (second_vov.size(), 0));

    for(int i=1; i<first_vov.size(); i++){
        for(int j=1; j<second_vov.size(); j++){
            if(first_vov[i] == second_vov[j]){
                longest_subsequence[i][j] = longest_subsequence[i-1][j-1] + 1;
            }else{
                longest_subsequence[i][j] = max(longest_subsequence[i-1][j], longest_subsequence[i][j-1]);
            }
        }
    }

    return longest_subsequence[longest_subsequence.size()-1][longest_subsequence[0].size()-1];
}

int main(){
    // char first[] = {'s', 'a', 'l', 'i', 'm', 'u', 'k', 'o', 'b'};
    // char second[] = {'f', 'a', 'g', 'u', 'e', 'm', 'o', 'n', 'p', 'a'};
    char first[]="salimukob";
    char second[] ="faguemonpa";
    cout<<longestVovelSubsequence(first, second);
}