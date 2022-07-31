class Solution {
public:
    void calc(vector<int> adj[], map<int,int> &mp, int node, int n) {
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(node);
        visited[node] = true;
        int dist = 1;
        mp[node] = 0;
        
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            for(auto it : adj[t]) {
                
                if(!visited[it]) {
                    q.push(it);
                    mp[it] = 1 + mp[t];
                    visited[it] = true;
                }
            }
        }
        
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        map<int,int> mp1;
        map<int,int> mp2;
        
        int n = edges.size();
        
        vector<int> adj[n];
        
        for(int i = 0; i < n; i++) {
            if(edges[i]==-1) continue;
            adj[i].push_back(edges[i]);
        }
        
        calc(adj, mp1, node1, n);
        calc(adj, mp2, node2, n);
        
        int node = -1;
        int dist = INT_MAX;
        
        for(auto it : mp1) {
            int elem = it.first;
            int currDist = it.second;
            
            if(mp2.find(elem) != mp2.end()) {
                currDist = max(currDist, mp2[elem]);
                if(dist > currDist) {
                    dist = currDist;
                    node = elem;
                }
            }
        }
        
        return node;
    }
};