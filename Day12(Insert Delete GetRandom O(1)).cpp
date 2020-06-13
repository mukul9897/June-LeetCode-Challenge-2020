class RandomizedSet {
public:
    map<int,int>mp;
    vector<int>v;
    int c=0;
    /** Initialize your data structure here. */
    RandomizedSet() {
       
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val)==mp.end()){ 
            
            mp.insert({val,c});
            
            v.push_back(val);
            
            c++;
            
            return true;
        }
        return false;
   }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            int temp=v[mp[val]];
            v[mp[val]]=v[v.size()-1];
            v[v.size()-1]=temp;
            
            v.pop_back();
            
            mp[v[mp[val]]]=mp[val];
            mp.erase(val);
            c--;
            
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(v.size()!=0){
            int random=rand()%(v.size());
            
            return v[random]; 
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
