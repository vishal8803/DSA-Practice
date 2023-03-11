//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        int mx = *max_element(A.begin(), A.end());
        vector<int> ans;
        set<int> st;
        for(int i : A) st.insert(i);
        
        map<int, vector<int>> mp;
        
        for(auto it : st) {
            int elem = it;
            vector<int> freq(N, 0);
            if(A[N-1] == elem) freq[N-1]++;
            for(int i = N - 2; i >= 0; i--) {
                freq[i] = freq[i+1];
                if(A[i] == elem) freq[i]++;
            }
            mp[elem] = freq;
        }
        for(auto q : Q) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int count = 0;
            for(int i = l; i<= r; i++) {
                int elem = A[i];
                int freq = mp[elem][i];
                
                if(freq == k) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends