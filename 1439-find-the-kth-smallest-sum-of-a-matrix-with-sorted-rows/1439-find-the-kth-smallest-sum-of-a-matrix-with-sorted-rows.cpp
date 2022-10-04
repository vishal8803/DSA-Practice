class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        set<pair<int, vector<int>>> st;
        
        int sum = 0;
        vector<int> temp;
        for(int i = 0; i < mat.size(); i++) {
            sum += mat[i][0];
            temp.push_back(0);
        }
        
        st.insert({sum, temp});
        
        while(k > 1) {
            auto it = *st.begin();
            st.erase(st.begin());
            int tempSum = it.first;
            
            vector<int> t = it.second;
            
            for(int i = 0; i < t.size(); i++) {
                vector<int> r = t;
                if(r[i] + 1 < mat[i].size()) {
                    r[i] = r[i] + 1;
                    st.insert({tempSum - mat[i][r[i] - 1] + mat[i][r[i]], r});
                }
            }
            
            k--;
        }
        
        return (*st.begin()).first;
    }
};