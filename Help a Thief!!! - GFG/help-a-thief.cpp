// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        vector<pair<int,int>> v;
        
        for(int i = 0; i < N; i++){
            v.push_back({A[i],B[i]});
        }
        
        sort(v.begin(), v.end(), [&](pair<int,int> p1, pair<int,int> p2){
            return p1.second > p2.second;
        });
        
        int count = T;
        int profit = 0;
        
        for(int i = 0; i < N; i++){
            int price = v[i].second;
            int plates = v[i].first;
            // cout<<price<<" "<<plates<<endl;
            
            if(count >= plates){
                count -= plates;
                profit += price*plates;
            }else{
                profit += price*count;
                count = 0;
            }
            
            if(count==0)
                break;
        }
        
        return profit;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends