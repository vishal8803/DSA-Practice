//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int i = 0;
        int j = 0;
        int len = 0;
        int count = 0;
        
        while(j < n) {
            if(arr[j] == 'O') count++;
            
            if(count <= m) {
                len = max(len, j - i + 1);
                j++;
            } else if(count > m) {
                while(i <= j and count > m){
                    if(arr[i] == 'O') count--;
                    i++;
                }
                len = max(len, j - i + 1);
                j++;
            }
        }
        return len;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends