class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        int n = arr.size();
        vector<bool> visited(n,false);
        visited[start] = true;
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                int idx = q.front();
                q.pop();
                
                if(arr[idx]==0) return true;
                
                int dest1 = idx + arr[idx];
                int dest2 = idx - arr[idx];
                
                if(dest1 < arr.size() && !visited[dest1]) {
                    q.push(dest1);
                    visited[dest1] = true;
                }
                
                if(dest2 >= 0 && !visited[dest2]) {
                    q.push(dest2);
                    visited[dest2] = true;
                }
            }
        }
        return false;
    }
};