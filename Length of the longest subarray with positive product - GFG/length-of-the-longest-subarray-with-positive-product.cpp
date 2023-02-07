//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int getMaxLen(vector<int>& a) {
        if(a.size()==1)
        {
            if(a[0]>0)
                return 1;
            return 0;
        }
         int ans = 0;
        int i=0;
        while(i<a.size()){
            if(a[i]==0){
                i++;
                continue;
            }
            
            int j=i;
            int count = 0;
            while(j<a.size() && a[j]!=0){
                if(a[j]<0)
                    count++;
                j++;
                
            }
            if(j!=i){
                // j=j-1;
                if((count%2)==0){
                    ans = max(ans,j-i);
                }else{
                    int fn=i,ln=i;
                    for(int k=i; k<j; k++){
                        if(a[k]<0){
                            fn=k;
                            break;
                        }
                            
                    }
                    for(int k=j-1; k>=i; k--){
                        if(a[k]<0){
                            ln=k;
                            break;
                        }
                            
                    }
                    ans = max(ans,max(ln-i,j-fn-1));
                }
                i=j;
            }else{
                ans = max(ans,1);
                i=i+1;
            }
            
            
        }
        return ans;
    }
        int maxLength(vector<int> &arr,int n){
           return getMaxLen(arr);
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends