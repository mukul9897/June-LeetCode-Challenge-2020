class Solution {
    void dfs(unordered_map<string,multiset<string>>& adj,vector<string>& result,string s){
        while(adj[s].size()){
            string v=*(adj[s].begin());
            
            adj[s].erase(adj[s].begin());
            
            dfs(adj,result,v);
        }
        result.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& t) {
        unordered_map<string,multiset<string>>adj;
        for(vector<string>& t1:t) 
            adj[t1[0]].insert(t1[1]);
            
        vector<string> result;
        dfs(adj,result,"JFK");
        
        reverse(result.begin(),result.end());
        return result;
    }
};
