//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        vector<int> points;
        queue<pair<int,int>> q;
        q.push({start_x, start_y});
        points.push_back(arr[start_x][start_y]);
        visited[start_x][start_y] = true;
        vector<vector<int>> directions = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
        
        while(q.size() > 0) {
            int size = q.size();
            int coins = 0;
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(auto &direction : directions) {
                    int nx = x + direction[0];
                    int ny = y + direction[1];
                    
                    if(nx < 0 or ny < 0 or nx >= n or ny >= m or visited[nx][ny]) continue;
                    coins += arr[nx][ny];
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            points.push_back(coins);
        }
        points.pop_back();
        
        for(int i = points.size() - 1; i >= 0; i--) {
            if(i + points[i] < points.size()) {
                points[i] = points[i] + points[i + points[i]];
            }
        }
        
        int idx = -1;
        int elem = INT_MIN;
        
        for(int i = 0; i < points.size(); i++) {
            if(points[i] > elem) {
                elem = points[i];
                idx = i;
            }
        }
        
        return idx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends