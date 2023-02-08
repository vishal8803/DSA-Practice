//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<long long int> ans;
      int row = 0, col = 0;
      
      vector<bool> t1(n+1, false);
      vector<bool> t2(n+1, false);
      
      for(auto a : arr) {
          if(t1[a[0]-1] == false) row++;
          if(t2[a[1]-1] == false) col++;
          
          long long int temp = (long long int)(n - row)*(long long int)n - ((long long int)col*(long long int)n - (long long int)row*(long long int)col);
          ans.push_back(temp);
          t1[a[0]-1] =  true;
          t2[a[1]-1] = true;
      }
      
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends