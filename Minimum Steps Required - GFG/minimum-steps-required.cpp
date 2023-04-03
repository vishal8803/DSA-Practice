//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int ac = 0,  bc = 0;
    int i = 0;
    while(i < str.size()) {
        char ch = str[i];
        while(i < str.size() and str[i] == ch) {
            i++;
        }
        if(ch == 'a') ac++;
        else bc++;
    }
    
    if(ac == 0 or bc == 0) return 1;
    if(str[0] == str[str.size() - 1])
    return max(ac, bc);
    
    return 1 + max(ac,bc);
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends