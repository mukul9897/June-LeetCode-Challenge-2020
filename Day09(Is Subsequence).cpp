class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=t.length();
        int s1=s.length();
        int j=0;
        
        for(int i=0;i<l;i++)
            if(j<s1 && s[j]==t[i]) 
                j++;
        if(j!=s1) 
            return false;
        return true;
    }
};
