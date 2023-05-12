#include<bits/stdc++.h>
using namespace std;

class Anagrams{
    string text1, text2;
public:
    Anagrams(string &text1, string &text2){
        this->text1 = text1;
        this->text2 = text2;    
    }

    bool isAnagram(){
        map<char, int> textLetters;

        if(text1.length() != text2.length())
            return false;

        char currChar;
        for(int i=0; i<text1.length(); i++){
            currChar = text1[i];

            // not seen previously
            if(textLetters.find(currChar) == textLetters.end()){
                textLetters[currChar] = 1;
            }else{  // seen previously
                textLetters[currChar] += 1;
            }
        }

        for(int i=0; i<text2.length(); i++){
            currChar = text2[i];

            // searching for char not present in text1
            if(textLetters.find(currChar) == textLetters.end()){
                return false;
            }

            textLetters[currChar] -=1;    
        }

        for(auto currChar: textLetters){
            if(currChar.second != 0)
                return false;
        }
        return true;
    }

};

int main(){
    string text1 = "helmo";
    string text2 = "omehl";

    Anagrams obj(text1, text2);
    cout<<obj.isAnagram();
    
    return 1;
}