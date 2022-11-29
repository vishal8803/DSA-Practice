class RandomizedSet {
public:
    set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) != st.end())
            return false;
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(st.find(val) == st.end())
            return false;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        auto it = st.cbegin();
        int t = rand()%st.size();
        std::advance(it, t);
 
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */