// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPossible(int capacity, int arr[], int N, int D){
        int days = 1;
        int temp = capacity;
        for(int i = 0; i < N; i++){
            if(temp >= arr[i]){
                temp -= arr[i];
            }else{
                temp = capacity;
                days++;
                i--;
            }
            if(days>D)
                return false;
        }
        return true;
    }
    
    int leastWeightCapacity(int arr[], int N, int D) {
        int st = *max_element(arr,arr+N);
        
        int end = 0;
        for(int i = 0; i < N; i++){
            end += arr[i];
        }
        int res =-1;
        while(st<=end){
            int mid = (st+end)/2;
            if(isPossible(mid,arr,N,D)){
                res = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends