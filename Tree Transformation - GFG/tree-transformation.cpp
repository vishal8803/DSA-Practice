//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        vector<int> indegree(N, 0);
        for(int i = 0; i < N; i++) {
            if(p[i] != -1) {
                indegree[p[i]]++;
                indegree[i]++;
            }
        }
        int cnt = 0;
        for(int i : indegree) {
            if(i == 1)
                cnt++;
        }
        
        return N - cnt - 1;
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends