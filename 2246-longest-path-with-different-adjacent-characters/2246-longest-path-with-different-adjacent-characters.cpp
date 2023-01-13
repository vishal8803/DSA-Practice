class Solution {
public:
    int res = 1;
    pair<char,int> calc(vector<int> adj[], int node, string &s) {
        char ch = s[node];
        
        vector<pair<char,int>> possible;
        int mx1 = INT_MIN, mx2 = INT_MIN;
        for(int child : adj[node]) {
            auto it = calc(adj, child, s);
            if(it.first != ch) {
                possible.push_back(it);
                if(it.second > mx1) {
                    mx2 = mx1;
                    mx1 = it.second;
                } else if(it.second > mx2) {
                    mx2 = it.second;
                }
            }
        }
        
        if(possible.size() == 0) {
            return {ch, 1};
        }
        else if(possible.size() == 1) {
            res = max(res, 1 + possible[0].second);
            return {ch, 1 + possible[0].second};
        }
        
        
        res = max(res, 1 + mx1 + mx2);
        return {ch, 1 + mx1};
    }
        
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> adj[n];
        
        for(int i = 0; i < n; i++) {
            if(parent[i] != -1) {
                adj[parent[i]].push_back(i);
            }
        }
        calc(adj, 0, s);
        return res;
    }
};