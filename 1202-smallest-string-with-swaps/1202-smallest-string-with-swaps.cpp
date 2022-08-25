class Solution {
public:
    int parent[100002];
    int rnk[100002];
    
    void makeSet(int n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rnk[i] = 1;
        }
    }
    
    int findParent(int node) {
        if(parent[node] == node) {
            return node;
        }
        
        return parent[node] = findParent(parent[node]);
    }
    
    void makeUnion(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        
        if(rnk[u] > rnk[v]) {
            parent[v] = u;
        } else if(rnk[v] > rnk[u]) {
            parent[u] = v;
        } else {
            parent[u] = v;
            rnk[v]++;
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        makeSet(n);
        
        for(auto it : pairs) {
            makeUnion(it[0], it[1]);
        }
        
        map<int,vector<int>> mp;
        for(int i = 0; i < s.length(); i++) {
            int parent = findParent(i);
            if(mp.find(parent) == mp.end())
                mp[parent] =  vector<int>(26,0);
            mp[parent][s[i]-'a']++;
        }
        
        
        
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            int parent = findParent(i);
            for(int j = 0; j < mp[parent].size(); j++) {
                if(mp[parent][j] > 0) {
                    ans += ('a' + j);
                    mp[parent][j]--;
                    break;
                }
            }
        }
        return ans;
        
    }
};