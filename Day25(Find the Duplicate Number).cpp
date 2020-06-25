class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int first=nums[0],second=nums[0];
        
        while(1){
            first=nums[first];
            second=nums[nums[second]];
            if(first==second) break;
        }
        first=nums[0];
        
        while(first!=second){
            first=nums[first];
            second=nums[second];
        }
        return first;
    }
};
