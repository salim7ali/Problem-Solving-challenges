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
        vector<int> state(26, 0);

        if(text1.length() != text2.length())
            return false;

        int alphabetToCorrespondingIndex;
        for(int i=0; i<text1.length(); i++){
            alphabetToCorrespondingIndex = text1[i]-97;
            state[alphabetToCorrespondingIndex] += 1;
        }

        for(int i=0; i<text2.length(); i++){
            alphabetToCorrespondingIndex = text2[i]-97;

            if(state[alphabetToCorrespondingIndex] == 0)
                state[alphabetToCorrespondingIndex] = -1;
            else if(state[alphabetToCorrespondingIndex] == 1)
                state[alphabetToCorrespondingIndex] = 2;
        }

        for(int i=0; i<state.size(); i++){
            if(state[i] == -1 || state[i] == 1)
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