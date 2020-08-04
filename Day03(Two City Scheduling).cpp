class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& c) {
        int n=c.size()
        int sum=0,a=0,b=0;
        
        vector<tuple <int,int,int>>v;
        
        for(int i=0;i<n;i++) 
            v.push_back(make_tuple(abs(c[i][1]-c[i][0]),c[i][0],c[i][1]));
        
        sort(v.begin(), v.end());
        
        for(int i=n-1;i>=0;i--){
            if(get<1>(v[i])<=get<2>(v[i]) && a<n/2){
                a++;
                sum+=get<1>(v[i]);
            }
            else if(b<n/2){
                b++;
                sum+=get<2>(v[i]);
            } 
            else{
                a++;
                sum+=get<1>(v[i]);
            }
        }
        return sum;
    }
    
};
