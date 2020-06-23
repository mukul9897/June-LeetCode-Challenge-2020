class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++) 
            mp[nums[i]]++;
        for(auto i:mp) 
            if(i.second!=3) 
                return i.first;
        return 0;
    }
};
