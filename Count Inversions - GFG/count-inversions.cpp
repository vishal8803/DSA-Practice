// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long  arr[], long long  st, long long  mid, long long  end){
        long long  n1 = mid-st+1;
        long long  n2 = end-mid;
        
        long long  a1[n1],a2[n2];
        for(long long  i = 0; i < n1; i++){
            a1[i] = arr[st+i];
        }
        
        for(long long  i = 0; i < n2; i++){
            a2[i] = arr[mid+1+i];
        }
        
        long long  i = 0, j = 0, k = st;
        long long int count = 0;
        
        while(i<n1 && j < n2){
            if(a1[i] <= a2[j]){
                arr[k] = a1[i];
                k++;
                i++;
            }else{
                count += n1-i;
                arr[k] = a2[j];
                j++;
                k++;
            }
        }
        
        while(i<n1){
            arr[k] = a1[i];
            k++;
            i++;
        }
        
        while(j<n2){
            arr[k] = a2[j];
            j++;
            k++;
        }
        
        return count;
    }
    
    long long int mergeSort(long long arr[], long long st, long long end){
        if(st>=end)
            return 0;
        
        long long int count  = 0;
        long long mid = (st) + (end-st)/2;
        
        count += mergeSort(arr,st,mid);
        count += mergeSort(arr,mid+1,end);
        count += merge(arr,st,mid,end);
        
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends