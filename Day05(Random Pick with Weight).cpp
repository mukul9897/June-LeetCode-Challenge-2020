#include<bits/stdc++.h>
class Solution {
    vector<int>m;
    int sum;
public:
    Solution(vector<int>& w){
        sum=0;
        for(auto i:w){
            sum+=i;
            m.push_back(sum);
        } 
    }
    
    int pickIndex() {
        int ans=rand()%sum;
        return bs(ans+1);
    }
    int bs(int val){
        int l=0;
        int r=m.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(m[mid]<val) 
                l=mid+1;
            else 
                r=mid;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
