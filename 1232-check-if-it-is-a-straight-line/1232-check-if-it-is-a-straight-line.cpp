class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        set<double> st;
        
        for(int i = 0; i < c.size(); i++) {
            for(int j = i + 1; j < c.size(); j++) {
                if(c[j][0] == c[i][0]) {
                    st.insert(1);
                } else {
                    double m = (double)(c[j][1] - c[i][1])/(double)(c[j][0] - c[i][0]);
                    st.insert(m);
                }
                
            }
        }
        
        return (st.size() == 1);
    }
};