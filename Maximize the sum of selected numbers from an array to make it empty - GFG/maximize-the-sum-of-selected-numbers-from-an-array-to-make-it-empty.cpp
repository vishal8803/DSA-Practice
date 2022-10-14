//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends

class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        
        int ans = 0;
        
        while(mp.size() > 0) {
            int num = mp.rbegin()->first;
            if(mp.find(num-1) != mp.end()) {
                mp[num-1]--;
                if(mp[num-1]==0) mp.erase(num-1);
            }
            mp[num]--;
            if(mp[num]==0) mp.erase(num);
            ans += num;
        }
        
        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends