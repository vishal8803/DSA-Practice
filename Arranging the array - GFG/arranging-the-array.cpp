//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            vector<int> v1, v2;
            for(int i = 0; i < n; i++) {
                if(arr[i] < 0) v1.push_back(arr[i]);
                else v2.push_back(arr[i]);
            }
            
            int i = 0;
            while(i < v1.size()) {
                arr[i] = v1[i];
                i++;
            }
            int j = 0;
            while(j < v2.size()) {
                arr[i++] = v2[j++];
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends