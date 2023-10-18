class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n+1,0);
        vector<int> adj[n+1];
        for(int i=0; i<relations.size(); i++)
        {
            adj[relations[i][0]].push_back(relations[i][1]);
            indegree[relations[i][1]]+=1;
        }
        queue<int> q ;
        vector<int> dist(n+1,0);
        for(int i=1; i<=n; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                dist[i]=time[i-1];
            }
        }
        
        while(!q.empty())
        {
            int size = q.size();
            int t = INT_MIN ;
            while(size--)
            {
                int node = q.front();
                q.pop();
                for(int j : adj[node])
                {
                    if(indegree[j] != 0)
                    {
                        dist[j] = max(dist[j],dist[node]+time[j-1]);
                        indegree[j]-- ;
                        if(indegree[j]==0)
                        q.push(j);    
                    }
                }
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};