// Program to generate all permutations of a char vector. Will generate multiple copies if all chars aren't unique
#include<bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;

// Passing text by reference as we don't intend to modify it. We also pass reference of count
void genPermutations(vector<char> &text, vector<char> result, int &count){

    // Handling for stop condition
    if(text.size() == result.size()){
        for(int i=0; i<result.size(); i++){
            cout<<result[i]<<" ";
        }cout<<"\n";
        count += 1;
        return;
    }

    sort(text.begin(), text.end());
    vector<char> resultSorted = result; //Using a copy of result as we don't intend to modify result
    sort(resultSorted.begin(), resultSorted.end());
    vector<char> remaining;
    // set difference requires both vectors to be sorted. Thus we sort both text and resultSorted. We store result in remaining
    set_difference(text.begin(), text.end(), resultSorted.begin(), resultSorted.end(), back_inserter(remaining));

    vector<char> temp = result;
    for(int i=0; i<remaining.size(); i++){
        // push ith char, genPermutations and then pop it out befor i++ 
        temp.push_back(remaining[i]);
        genPermutations(text, temp, count);
        temp.pop_back();
    }
}

int main(){
    vector<char> text = {'c', 'a', 't'};
    // vector<char> text = {'b', 'o', 'o', 'k'};
    vector<char> result;
    int count = 0;

    genPermutations(text, result, count);
    cout<<count;
}