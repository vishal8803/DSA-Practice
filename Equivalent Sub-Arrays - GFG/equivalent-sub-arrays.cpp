// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        map<int,int> mp2;
        int i = 0;
        int j = 0;
        int count = 0;
        
        while(j<n){
            mp2[arr[j]]++;
            if(mp2.size()<mp.size()){
                j++;
            }else if(mp.size()==mp2.size()){
                count += (n-j);
                while(i<=j && mp2.size()==mp.size()){
                    mp2[arr[i]]--;
                    if(mp2[arr[i]]==0)
                    {
                        mp2.erase(arr[i]);
                    }
                    i++;
                    if(mp2.size()==mp.size()){
                        count+=n-j;
                    }
                }
                j++;
            }
            
        }
        return count;
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
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends