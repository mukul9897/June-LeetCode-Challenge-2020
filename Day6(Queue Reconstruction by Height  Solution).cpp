#include<bits/stdc++.h>
class Solution {
public:
   
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) {
    
        vector<vector<int>>result;
        
        sort(v.begin(), v.end(), [](const vector<int>& a,const vector<int> &b){
           return(a[0]>b[0] ||(a[0]==b[0] && a[1]<b[1])); 
        });
        
        for(vector<int>& x:v)
            result.insert(result.begin()+x[1],x);
            
        return result;
    }
     
};
