class RandomizedSet {
public:
    set<int>s;
    /** Initialize your data structure here. */
    RandomizedSet() {
       
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val)==s.end()){ s.insert(val); return true;}
        return false;
   }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        int count=0;
        if(s.find(val)!=s.end()){
            for (auto i = s.begin(); i != s.end();i++) { 
                if (*i== val){ i=s.erase(i); return true;}
            }
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int random=rand()%s.size(),count=0;
        for(auto i:s){
            if(count==random) return i;
            count++;
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
