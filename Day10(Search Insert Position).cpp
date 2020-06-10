class Solution {
public:
    int searchInsert(vector<int>& n, int target) {
    
        int l=n.size();
        
        for(int i=0;i<l;i++){
        
            if(n[i]==target) 
                return i;
                
            else if(n[i]>target) 
                return i;
        }
        
        return l;
    }
};
