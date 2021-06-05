// https://www.geeksforgeeks.org/amazon-interview-experience-set-394-campus-full-time/

#include<bits/stdc++.h>
using namespace std;

class IncDecList{
    vector<int> inc_dec_list;
public: 
    IncDecList(vector<int> inc_dec_list){
        this->inc_dec_list = inc_dec_list; 
    }

    int get_peak_index(int L, int R){
        while(L<=R){
            int mid_index = L + floor((R-L)/2);
            
            if(L==0 && mid_index==0)
                return L;
            else if(R==inc_dec_list.size()-1 && mid_index==inc_dec_list.size()-1)
                return R;
            else if(inc_dec_list[mid_index-1] < inc_dec_list[mid_index] 
            && inc_dec_list[mid_index] > inc_dec_list[mid_index+1]){
                return mid_index;
            }
            else if(inc_dec_list[mid_index-1] < inc_dec_list[mid_index] 
            && inc_dec_list[mid_index] < inc_dec_list[mid_index+1]){ // mid on increasing side
                L = mid_index + 1;
            }
            else if(inc_dec_list[mid_index-1] > inc_dec_list[mid_index] 
            && inc_dec_list[mid_index] > inc_dec_list[mid_index+1]){  // mid on decreasing side
                R = mid_index -1;
            }
        }
    }

    int bin_search(int L, int R, int ele){
        while(L<=R){
            int mid_index = L + floor((R-L)/2);
            
            if(inc_dec_list[mid_index] == ele){
                return mid_index;
            }else if(ele < inc_dec_list[mid_index]){
                R = mid_index-1;
            }else{ //inc_dec_list[mid_index] < ele
                L = mid_index+1;
            }
        }
        return INT_MIN;
    }

    int get_element_index(int ele){
        int L = 0;
        int R = inc_dec_list.size()-1;

        int peak_index = get_peak_index(L, R);

        int ele_index;
        if(inc_dec_list[0]<=ele && ele<inc_dec_list[peak_index]){
            ele_index = bin_search(0, peak_index-1, ele);
        }else if(inc_dec_list[peak_index]<=ele && ele<=inc_dec_list[inc_dec_list.size()-1]){
            // ele_index = rev_bin_search(peak_index, inc_dec_list.size()-1, ele);
        }else
            return INT_MIN;
    }
};

int main(){
    IncDecList obj({1, 4, 23, 45, 50, 49, 48, 40, 21, 4, 2});
    obj.get_element_index(23);
}