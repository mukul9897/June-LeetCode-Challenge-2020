class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>fact(n,1);
        vector<int>digits(n,1);
        for(int i=1;i<n;i++){
            fact[i]=fact[i-1]*(i+1);
            digits[i]=i+1;   
        }
        string result="";
        while(result.size()<n-1){
            int repeat=fact[fact.size()-2];
            int next=(k-1)/repeat;
            result+=to_string(digits[next]);
            digits.erase(digits.begin()+next);
            fact.pop_back();
            k=k%repeat;
            if(k==0){
                for(int i=digits.size()-1;i>=0;i--) 
                    result+=to_string(digits[i]);
            }
        }
        if(result.size()<n) 
            result+=to_string(digits[0]);
        return result;
    }
};
