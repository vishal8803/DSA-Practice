class Solution {
public:
    int calc(vector<int> adj[], int node, vector<int>& informTime){
        int time = informTime[node];
        int mx = 0;
        
        for(auto it : adj[node]){
            int cst = time + calc(adj,it,informTime);
            mx = max(mx,cst);
        }
        return mx;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i = 0; i < manager.size(); i++){
            int mng = manager[i];
            if(mng==-1)
                continue;
            adj[mng].push_back(i);
        }
        
        return calc(adj,headID,informTime);
    }
};