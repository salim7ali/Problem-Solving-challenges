#include <bits/stdc++.h>

using namespace std;

vector<int> stockSpan(vector<int> stocks){
    //           {{value, index}, span} 
    stack<pair<pair<int, int>, int>> S;
    vector<int> result_spans((int)stocks.size());
    
    for(int i=0; i<stocks.size(); i++){
        if(S.empty()){
            S.push({{stocks[0], 0}, 1});
            continue;
        }
        int curr_span =1;
        while(S.top().first.first < stocks[i] && !S.empty()){
            curr_span += S.top().second;
            result_spans[S.top().first.second] = S.top().second;
            
            S.pop();
        }
        S.push({{stocks[i], i}, curr_span});
    }
    
    while(!S.empty()){
        result_spans[S.top().first.second] = S.top().second;
        S.pop();
    }
    
    return result_spans;
}

void display(vector<int> nums){
    for(auto ele: nums){
        cout<<ele<<" ";
    }
    cout<<"\n";
}

int main()
{
     std::vector<int> stocks = {100, 80, 60, 70, 60, 75, 85};
     vector<int> stock_spans = stockSpan(stocks);
     
     display(stock_spans);
     
     
}
