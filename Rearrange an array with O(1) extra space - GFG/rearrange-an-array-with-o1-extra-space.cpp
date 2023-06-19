//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        long long mx = *max_element(arr, arr + n);
        mx++;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] != i) {
                int val = arr[i];
                arr[i] = arr[i]*mx;
                if(arr[val] < 0) {
                    arr[i] += abs(arr[val]/mx);
                } else {
                    arr[i] += arr[val];
                }
                arr[i] = -1*arr[i];
            }
            
        }
        
        for(int i = 0; i < n; i++) {
            arr[i] = abs(arr[i]);
            if(arr[i] != i) arr[i]%=mx;
        }
        
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends