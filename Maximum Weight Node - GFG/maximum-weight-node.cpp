//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      vector<int> indegree(N, 0);
      
      for(int i = 0; i < Edge.size(); i++) {
          int x = Edge[i];
          if(x != -1) {
              indegree[x] += i;
          }
      }
      
      int ans = -1;
      int mx = INT_MIN;
      
      for(int i = 0; i < N; i++) {
          if(indegree[i] > mx) {
              mx = indegree[i];
              ans = i;
          } else if(indegree[i] == mx) {
              ans = max(ans, i);
          }
      }
      
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends