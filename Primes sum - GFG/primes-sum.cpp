//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string isSumOfTwo(int N){
        vector<bool> prime(N+1, true);
        
        prime[0] = false;
        prime[1] = false;
        
        for(int i = 2; i*i <= N; i++) {
            for(int j = 2*i; j <= N; j+=i) {
                prime[j] = false;
            }
        }
        
        vector<int> temp;
        for(int i = 0; i <= N; i++) {
            if(prime[i]) temp.push_back(i);
        }
        
        for(int i : temp) {
            if(prime[N-i]) return "Yes";
        }
        
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends