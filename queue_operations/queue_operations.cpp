#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<pair<int, int>> Q;
    Q.push({1, 2});
    Q.push({3, 4});
    Q.push({5, 6});
    cout<<Q.front().first<<" "<<Q.front().second<<"\n";
    cout<<Q.back().first<<" "<<Q.back().second<<"\n";
    Q.pop();
    cout<<Q.front().first<<" "<<Q.front().second<<"\n";
    cout<<Q.back().first<<" "<<Q.back().second<<"\n";
}