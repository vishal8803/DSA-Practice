class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> temp;
        
        for(int i = 0; i < buildings.size(); i++) {
            int left = buildings[i][0];
            int right = buildings[i][1];
            int height = buildings[i][2];
            
            temp.push_back({left, -height});
            temp.push_back({right, height});
        }
        
        sort(temp.begin(), temp.end());
        
        vector<vector<int>> ans;
        multiset<int> st;
        int ch = 0;
        st.insert(0);
        for(int i = 0; i < temp.size(); i++) {
            int x = temp[i][0];
            int height = temp[i][1];
            
            if(height < 0) {
                st.insert(-height);
            } else {
                st.erase(st.find(height));
            }
            
            int elem = *st.rbegin();
            
            if(ch != elem) {
                ans.push_back({x, elem});
                ch = elem;
            }
        }
        
        return ans;
    }
};