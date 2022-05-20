// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    void calc(vector<int> &a, int target, int k, bool &ans, int save, vector<bool> &used){
        if(target==0){
            k--;
            target = save;
            if(k==0)
            {
                ans = true;
                return;
            }
        }else if(target<0)
            return;
        
        if(a.size()==0)
            return;
        
        // cout<<k<<endl;
        
        for(int j = 0; j < a.size(); j++){
            
            if(a[j]>target || used[j])
                continue;
                
            used[j] = true;
            calc(a,target-a[j],k,ans,save,used);
            used[j] = false;
        }
    }
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
         int sum = 0;
         vector<int> v;
         for(int i = 0; i < n; i++){
             sum += a[i];
             v.push_back(a[i]);
         }
         vector<bool> used(n,0);
         if(sum%k!=0)
            return false;
        
        
        int target = sum/k;
        bool ans = false;
        calc(v,target,k,ans,target,used);
        
        return ans;
    }
    
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends