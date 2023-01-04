class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        unordered_set<int> st;
        
        for(auto pair : adjacentPairs) {
            mp[pair[0]].push_back(pair[1]);
            mp[pair[1]].push_back(pair[0]);
        }
        
        vector<int> ans;
        int start;
        for(auto it : mp) {
            if(it.second.size() == 1) start = it.first;
        }
        
        queue<int> q;
        q.push(start);
        st.insert(start);
        
        while(q.size() > 0) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : mp[node]) {
                if(st.find(it) == st.end()) {
                    q.push(it);
                    st.insert(it);
                }
            }
        }
        
        return ans;
    }
};