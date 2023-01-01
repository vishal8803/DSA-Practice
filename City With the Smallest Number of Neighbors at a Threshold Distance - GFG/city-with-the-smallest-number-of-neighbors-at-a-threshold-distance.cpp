//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 10001));
        
        for(auto edge : edges) {
            matrix[edge[0]][edge[1]] = edge[2];
            matrix[edge[1]][edge[0]] = edge[2];
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
        vector<vector<int>> v;
        for(int i = 0; i < n; i++) {
            int total = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(matrix[i][j] <= distanceThreshold) total++;
            }
            v.push_back({i,total});
        }
        
        sort(v.begin(), v.end(), [&](vector<int> &v1, vector<int> &v2){
            if(v1[1] == v2[1]) return v1[0] < v2[0];
            return v1[1] > v2[1];
        });
        
        return v[v.size()-1][0];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends