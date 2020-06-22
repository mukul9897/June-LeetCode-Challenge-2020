class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int r=d.size(),c=d[0].size();
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(i==r-1 && j==c-1) 
                    d[i][j]=max(1-d[i][j],1);
                else if(j==c-1) 
                    d[i][j]=max(d[i+1][j]-d[i][j],1);
                else if(i==r-1) 
                    d[i][j]=max(d[i][j+1]-d[i][j],1);
                else 
                    d[i][j]=max(min(d[i+1][j],d[i][j+1])-d[i][j],1);
            }
        }
        return d[0][0];
    }
};
