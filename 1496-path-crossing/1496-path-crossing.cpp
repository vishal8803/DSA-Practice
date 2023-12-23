class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int,int>> st;
        
        st.insert({x,y});
        
        for(char ch : path) {
            if(ch == 'N') {
                x = x - 1;
            } else if(ch == 'S') {
                x = x + 1;
            } else if(ch == 'E') {
                y = y + 1;
            } else {
                y = y - 1;
            }
            if(st.find({x,y}) != st.end()) return true;
            st.insert({x, y});
        }
        
        return false;
    }
};