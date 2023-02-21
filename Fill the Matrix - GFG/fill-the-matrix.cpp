//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        int count = 0;
        vector<vector<int>> mat(N, vector<int>(M, 0));
        mat[x-1][y-1] = 1;
        queue<pair<int,int>> q;
        q.push({x-1,y-1});
        
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int nx = x + directions[i][0];
                    int ny = y + directions[i][1];
                    
                    if(nx >= 0 and ny >= 0 and nx < N and ny < M and mat[nx][ny] == 0) {
                        q.push({nx,ny});
                        mat[nx][ny] = 1;
                    }
                }
            }
            count++;
        }
        
        return count-1;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends