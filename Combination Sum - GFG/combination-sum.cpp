// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void calc(int i, int sum, vector<int> &a, vector<vector<int>> &ans, vector<int> temp){
        if(sum<0)
            return;
            
        if(sum==0){
            ans.push_back(temp);
            return;
        }
        
        if(i==a.size()){
            return;
        }
        
        
        if(sum>=a[i]){
            temp.push_back(a[i]);
            calc(i,sum-a[i],a,ans,temp);
            temp.pop_back();
        }
        
        calc(i+1,sum,a,ans,temp);
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(), A.end());
        vector<int> na;
        
        for(int i = 0; i < A.size(); i++){
            if(i==0){
                na.push_back(A[i]);
            }else if(A[i] != A[i-1]){
                na.push_back(A[i]);
            }
        }
        
        vector<vector<int>> ans;
        calc(0,B,na,ans,{});
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends