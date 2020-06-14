class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& n){
        int n1=n.size();
        if(n1<=1) return n;
        sort(n.begin(),n.end());
        vector<int> next_idx(n1,-1);
        vector<int> sizes(n1,1);
        int max_len=1;
        int max_idx=0;
        
        for(int i=n1-1;i>=0;i--){
            int j=i+1;
            int max1=0;
            int max1_idx=i;
            while(j<n1){
                if(n[j]%n[i]==0 && sizes[j]>max1){
                    max1=sizes[j];
                    max1_idx=j;
                }
                j++;
            }
            if(max1_idx!=i){
                sizes[i]+=sizes[max1_idx];
                next_idx[i]=max1_idx;
                if(max1+1>max_len){
                    max_len=max1+1;
                    max_idx=i;
                }
            }
        }
        vector<int>result;
        int curr=max_idx;
        while(curr>=0){
            result.push_back(n[curr]);
            curr=next_idx[curr];
        }
        return result;
    
    }
};
