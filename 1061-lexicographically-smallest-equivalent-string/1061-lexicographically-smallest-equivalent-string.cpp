class Solution {
public:
    void dfs(vector<int> adj[], char ch, char &sm, vector<bool> &visited) {
        if(ch < sm) sm = ch;
        visited[ch - 'a'] = true;
        
        for(auto it : adj[ch - 'a']) {
            if(!visited[it]) {
                dfs(adj, (char)('a' + it), sm, visited);
            }
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans = "";
        vector<int> adj[26];
        
        for(int i = 0; i < s1.size(); i++) {
            adj[s1[i] - 'a'].push_back(s2[i] - 'a');
            adj[s2[i] - 'a'].push_back(s1[i] - 'a');
        }
        
        // for(int i = 0; i < 26; i++) {
        //     cout<<(char)('a' + i)<<"-> ";
        //     for(int j : adj[i]) {
        //         cout<<(char)('a' + j)<<" ";
        //     }cout<<endl;
        // }
        
        for(char ch : baseStr) {
            if(adj[ch-'a'].size() == 0) {
                ans += ch;
            } else {
                vector<bool> visited(26, false);
                char cha = ch;
                // cout<<cha<<"->";
                dfs(adj, ch, cha, visited);
                // cout<<endl;
                ans += cha;
            }
            
        }
        
        return ans;
    }
};