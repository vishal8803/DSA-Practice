//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        long long mx = *max_element(query.begin(), query.end());
        int sv = sqrt(mx) + 1;
        
        vector<int> isPrime(sv, true);
        isPrime[0] = 0;
        isPrime[1] = 0;
        
        for(int i = 2; i * i <= sv; i++) {
            for(int j = 2*i; j <= sv; j+=i) {
                isPrime[j] = false;
            }
        }
        
        vector<int> ans;
        
        for(int i = 0; i < q; i++) {
            long long num = query[i];
            int count = 0;
            for(long long j = 0; j * j <= num; j++) {
                if(isPrime[j] and j*j <= num) {
                    count++;
                }
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends