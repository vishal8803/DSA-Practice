class Solution {
public:
    int isPossibleToDivide(vector<int> adj[], vector<int> &nums, vector<int> &visited, int target, int node) {
        visited[node] = nums[node];
        int sum = 0;
        for(auto it : adj[node]) {
            if(visited[it]==0) {
                visited[node] += isPossibleToDivide(adj, nums, visited, target, it);
                
                if(visited[node] > target) return 1e9 + 7;
            }
        }
        if(visited[node] == target) return 0;
        return visited[node];
    }
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum = 0;
        int n = nums.size();
        
        for(int i : nums) sum += i;
        
        vector<int> adj[n];
        
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            
            adj[y].push_back(x);
            adj[x].push_back(y);
        }
        
        
        for(int i = n; i > 1; i--) {
            if(sum % i != 0) continue;
            
            vector<int> visited(n, 0);
            if(isPossibleToDivide(adj, nums, visited, sum/i, 0) == 0) return i - 1;
        }
        
        return 0;
    }
};