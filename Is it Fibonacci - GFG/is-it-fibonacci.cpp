//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        deque<long long> dq;
        long long sum = 0;
        for(long long num : GeekNum) {
            dq.push_back(num);
            sum += num;
        }
        
        int count = K;
        while(count < N) {
            dq.push_back(sum);
            sum += sum - dq.front();
            dq.pop_front();
            count++;
        }
        
        return dq.back();
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends