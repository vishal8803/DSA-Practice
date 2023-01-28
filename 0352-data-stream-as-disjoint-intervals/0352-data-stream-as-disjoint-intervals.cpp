class SummaryRanges {
public:
    set<int> st;
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(st.size() == 0) return {};
        
        vector<vector<int>> v;
        int lt = -1, rt = -1;
        
        for(int i : st) {
            if(lt < 0) {
                lt = rt = i;
            } else if(i == rt + 1) {
                rt = i; 
            } else {
                v.push_back({lt, rt});
                lt = rt = i;
            }
        }
        
        v.push_back({lt, rt});
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */