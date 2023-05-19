class RandomizedCollection {
public:
    map<int, set<int>> mp;
    vector<int> v;
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        mp[val].insert(v.size());
        v.push_back(val);
        return (mp[val].size() == 1);
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end() or mp[val].size()==0) return false;
        
        int idxOfVal = *(mp[val].begin());
        mp[val].erase(idxOfVal);
        
        int newNum = v[v.size()-1];
        swap(v[idxOfVal], v[v.size() - 1]);
        v.pop_back();
        mp[newNum].erase(v.size());
        
        if(idxOfVal != v.size())
            mp[newNum].insert(idxOfVal);
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        int r = rand()%n;
        return v[r];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */