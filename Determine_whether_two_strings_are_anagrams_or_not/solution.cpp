#include<bits/stdc++.h>
using namespace std;

class Anagrams{
    string text1, text2;
    
    Anagrams(string &text1, string &text2){
        this->text1 = text1;
        this->text2 = text2;    
    }

    bool isAnagram(){
        
    }

};

int main(){
    string text1 = "hello";
    string text2 = "olehl";

    Anagrams obj(text1, text2);
    cout<<obj.isAnagram();
    
    return 1;
}