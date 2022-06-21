// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadane(vector<int> temp){
        int n = temp.size();
        int sum = temp[0];
        
        int curr = 0;
        for(int i = 0; i < n; i++){
            curr += temp[i];
            
            sum = max(sum,curr);
            if(curr<0){
                curr = 0;
            }
        }
        return sum;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        vector<int> temp = M[0];
        int ans = kadane(temp);
        
        for(int i = 0; i < R; i++){
            vector<int> temp(C);
            for(int j = i; j < R; j++){
                for(int k = 0; k < C; k++){
                    temp[k] += M[j][k];
                }
                ans = max(ans,kadane(temp));
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends