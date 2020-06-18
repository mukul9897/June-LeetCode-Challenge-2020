class Solution {
public:
    int hIndex(vector<int>& c) {
       int l=c.size();
       int lb=0,ub=l-1,max1=0; 
       while(lb<=ub){
           int mid=(lb+ub)/2;
            if(c[mid]<l-mid) 
                lb=mid+1;
            else 
                ub=mid-1;
            }
        return l-lb;
    }
};
