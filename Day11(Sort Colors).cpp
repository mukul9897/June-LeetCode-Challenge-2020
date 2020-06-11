class Solution {
public:
    void sortColors(vector<int>& n) {
        //sort(nums.begin(),nums.end());
        int l=n.size();
        
        map<int,int>mp;
        
        for(int i=0;i<l;i++) mp[n[i]]++;
        
        for(int i=0;i<l;i++){
            if(mp[0]!=0){ 
                n[i]=0; 
                mp[0]--;
            }
            else if(mp[1]!=0){ 
                n[i]=1; 
                mp[1]--;
            }
            else 
                n[i]=2;
        }
    }
};
