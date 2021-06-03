#include<bits/stdc++.h>
using namespace std;

class Versioning{

    vector<string> versions;
public:
    Versioning(vector<string> versions){
        this->versions = versions;
    }

    int map_char_to_number_line(string version){
        if(version[2]>=49 && version[2]<=57){//x  1 - 9
            return 10 * (version[0] - 97) + 1;
        }else{ // x  y
            return (-26*26) + (26 * (version[0] - 97));
        }
    }

    vector<string> gen_lexicographical_order(){
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> min_heap;

        for(int i=0; i<versions.size(); i++){
            min_heap.push({map_char_to_number_line(versions[i]), versions[i]});
        }

        vector<string> result;
        while(min_heap.empty() == false){
            pair<int, string> element = min_heap.top();
            min_heap.pop();

            result.push_back(element.second);
        }
        return result;
    }

};

int main(){
    vector<string> versions = {"a a", "c b", "z z", "b 1", "a f", "b a", "a 9", "b b", "a 1", "a z", "b 2"};
    Versioning obj(versions);
    vector<string> result = obj.gen_lexicographical_order();
    for(auto ele: result){
        cout<<ele<<"\n";
    }
}