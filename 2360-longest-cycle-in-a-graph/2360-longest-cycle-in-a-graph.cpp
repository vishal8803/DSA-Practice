class Solution {
public:
    bool checkCyleInDirectedGraph(vector<int> a[] , vector<bool> &visited , vector<bool> &dfsVisited, int i, int &count, map<int,int>& mp)
{
    visited[i]=true ;
    dfsVisited[i] = true ;
    mp[i] = count;
    
    for(int j:a[i])
    {
        count++;
        if(!visited[j])
        {
            
            if(checkCyleInDirectedGraph(a,visited,dfsVisited,j, count,mp)){
                return true ;
            }
            
        }else if(dfsVisited[j]){
            count = count - mp[j];
            return true ;
        }
         count--;   
    }
    dfsVisited[i] = false ;
    mp.erase(count);
    return false ;
}

    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> adj[n];
        
        
        
        for(int i = 0; i < n; i++) {
            if(edges[i]==-1) continue;
            adj[i].push_back(edges[i]);
        }
        
        int len = -1;
        vector<bool> visited(n, false);
        vector<bool> dfsVisited(n,false);
        map<int,int> mp;
        
        for(int i = 0; i < edges.size(); i++) {
            int count = 0;
            if(!visited[i] && checkCyleInDirectedGraph(adj, visited, dfsVisited, i, count, mp)) {
                len = max(len, count);
            }
        }
        
        return len;
    }
};