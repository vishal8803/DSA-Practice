class Solution {
public:
    int getPath(vector<pair<int,int>> adj[], int target) {
        if(target == 0) return 0;
        
        queue<pair<int,int>> q;
        q.push({0, -1});
        int count = 0;
        set<pair<int, pair<int,int>>> st;
        
        while(q.size() > 0) {
            int size = q.size();
            
            while(size--) {
                auto node = q.front();
                q.pop();
                
                if(node.first == target) return count;
                
                for(auto it : adj[node.first]) {
                    if(node.second == -1) {
                        q.push({it.first, it.second});
                    } else if(node.second != it.second and st.find({it.first, {node.first, it.second}}) == st.end()) {
                        q.push({it.first, it.second});
                        st.insert({it.first, {node.first, it.second}});
                    }
                }
            }
            count++;
        }
        
        return -1;
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> adj[n];
        
        for(auto edge : redEdges) {
            adj[edge[0]].push_back({edge[1], 0});
        }
        
        for(auto edge : blueEdges) {
            adj[edge[0]].push_back({edge[1], 1});
        }
        
        vector<int> ans(n, INT_MAX);
        
        for(int i = 0; i < n; i++) {
            int res = getPath(adj, i);
            ans[i] = res;
        }
        
        return ans;
    }
};

