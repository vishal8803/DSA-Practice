//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool calc(int arr[], int st, int end, int target) {
    while(st <= end) {
        int mid = (st + end) / 2;
        if(arr[mid] == target) return true;
        else if(arr[mid] > target) end = mid - 1;
        else st = mid + 1;
    }
    
    return false;
}

bool findPair(int arr[], int size, int n){
    sort(arr, arr + size);
    
    for(int i = 0; i < size; i++) {
        int target = arr[i] + n;
        if(calc(arr, i+1, size - 1, target)) return true;
    }
    
    return false;
    
}