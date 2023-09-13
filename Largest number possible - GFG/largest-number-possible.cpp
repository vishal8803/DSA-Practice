//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int no, int s){
        if (s == 0 && no > 1) return "-1";
        string ans =  "";
        int n = 9;
        while (ans.size() < no){
                
                if (s > 9){
                   ans.push_back('9');
                    s = s - 9;
                }
                else {
                    if (s > 0) {
                        ans.push_back(48+s);
                        s-=s;
                    }
                    else ans.push_back('0');
                }
        }
        if (s == 0)
            return ans;
        else if (s!=0) return "-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends