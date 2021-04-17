// https://www.youtube.com/watch?v=JHzX-57dgn0&t=1707s
#include<bits/stdc++.h>
using namespace std;


int permutationsContainedInString(string bigString, string smallString){
    unordered_map<char, int> smallCharCount;
    unordered_map<char, int> bigCharCount;

    for(int i=0; i<smallString.length(); i++){
        smallCharCount[smallString[i]] += 1;
    }

    //bigstring initial window 
    int currBSMatchCount = 0;
    int totBSMatchCount = 0;
    int windowSize = smallString.length();
    for(int i=0; i<windowSize; i++){
        if(smallCharCount[bigString[i]] == bigCharCount[bigString[i]]){
            currBSMatchCount -= 1;
            bigCharCount[bigString[i]] += 1;
        }else{ //smallCharCount[bigString[i]] != bigCharCount[bigString[i]]
            bigCharCount[bigString[i]] += 1;
            if(smallCharCount[bigString[i]] == bigCharCount[bigString[i]])
                currBSMatchCount += 1;
        }
    }
    if(currBSMatchCount == windowSize)
        totBSMatchCount += 1;
    
// win =11
    for(int i=1; i+windowSize<=bigString.length(); i++){
        if((bigString[i-1] == bigString[i+windowSize-1])){
            if(currBSMatchCount == windowSize)
                totBSMatchCount += 1;
            continue;
        }

        // bigString[i-1] != bigString[i+windowSize-1]
        // removing left char
        if(smallCharCount[bigString[i-1]] == bigCharCount[bigString[i-1]]){
            currBSMatchCount -= 1;
            bigCharCount[bigString[i-1]] -= 1;
        }else{ //smallCharCount[bigString[i]] != bigCharCount[bigString[i]]
            bigCharCount[bigString[i-1]] -= 1;
            if(smallCharCount[bigString[i-1]] == bigCharCount[bigString[i-1]])
                currBSMatchCount += 1;
        }

        // adding right char
        if(smallCharCount[bigString[i-1]] == bigCharCount[bigString[i-1]]){
            currBSMatchCount -= 1;
            bigCharCount[bigString[i-1]] += 1;
        }else{ //smallCharCount[bigString[i]] != bigCharCount[bigString[i]]
            bigCharCount[bigString[i-1]] += 1;
            if(smallCharCount[bigString[i-1]] == bigCharCount[bigString[i-1]])
                currBSMatchCount += 1;
        }
        
        if(currBSMatchCount == windowSize)
            totBSMatchCount += 1;
        
    }
    return totBSMatchCount;
}

int main(){
    string bigString="cbabcacabca";
    string smallString="abc";

    cout<<permutationsContainedInString(bigString, smallString);
}