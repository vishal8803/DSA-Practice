//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int numberOfSubsequences(string S, string W){
        int n = S.size();
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            if(!visited[i] and S[i] == W[0]) {
                int j = i;
                int k = 0;
                while(j < n and k < W.size()) {
                    if(S[j] == W[k] and  !visited[j]) {
                        j++;
                        k++;
                    } else j++;
                }
                if(k == W.size()) {
                    count++;
                    j = i;
                    k = 0;
                    while(j < n and k < W.size()) {
                        if(S[j] == W[k] and  !visited[j]) {
                            visited[j] = true;
                            j++;
                            k++;
                        } else j++;
                    }
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends