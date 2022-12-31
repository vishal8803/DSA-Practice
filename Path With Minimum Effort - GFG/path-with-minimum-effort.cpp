//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        
        vector<vector<int>> directions = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
        
        while(pq.size() > 0) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            for(int i = 0; i < 4; i++) {
                int nx = directions[i][0] + x;
                int ny = directions[i][1] + y;
                
                if(nx >= 0 and ny >= 0 and nx < n and ny < m and dist[nx][ny] > max(d, abs(heights[x][y] - heights[nx][ny]))) {
                    dist[nx][ny] = max(d, abs(heights[x][y] - heights[nx][ny]));
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends