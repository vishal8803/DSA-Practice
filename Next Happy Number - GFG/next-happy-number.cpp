//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool isHappy(int N, set<int> &st) {
        while(N != 1) {
            
            if(st.find(N) != st.end()) return false;
            st.insert(N);
            int sum = 0;
            while(N> 0) {
                int r = N%10;
                sum += r*r;
                N/=10;
            }
            if(sum == 1) return true;
            N = sum;
        }
        return false;
    }
    
    int nextHappy(int N){
        set<int> st;
        N++;
        while(true) {
            if(isHappy(N, st)) return N;
            N++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends