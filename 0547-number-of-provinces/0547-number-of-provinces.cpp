class Solution {
public:
    void dfs(vector<int> a[], vector<bool> &visited, int i) {
        visited[i]=true;
        for(int it : a[i]){
            if(!visited[it]){
                dfs(a,visited,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> adj[n+1];
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<a[0].size(); j++){
                if(i!=j && a[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int cnt=0;
        vector<bool> visited(a.size()+1);
        for(int i=1; i<a.size()+1; i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
};