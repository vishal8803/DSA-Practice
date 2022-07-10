class Solution {
public:
    
    set<pair<int,int>> st;
    int x,y;
    
    Solution(int m, int n) {
        x = m;
        y = n;
    }
    
    vector<int> flip() {
        int i = rand()%x;
        int j = rand()%y;
        
        if(st.find({i,j})==st.end()){
            st.insert({i,j});
            return {i,j};
        }
        
        return flip();
    }
    
    void reset() {
        st.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */