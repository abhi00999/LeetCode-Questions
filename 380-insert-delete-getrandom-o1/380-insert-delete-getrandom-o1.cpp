class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> m;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val)) return false;
        
        v.push_back(val);
        m[val]=v.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
        if(m.count(val)){
            int pos= m[val];
            m[v[v.size()-1]]= pos;
            swap(v[pos], v[v.size()-1]);
            v.pop_back();
            m.erase(val);
            
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */