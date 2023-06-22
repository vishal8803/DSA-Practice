//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        vector<int> cnt(3,0); // 5 10 20
        for(int bill : bills) {
            if(bill == 5) {
                cnt[0]++;
            } else if(bill == 10) {
                if(cnt[0] > 0) {
                    cnt[1]++;
                    cnt[0]--;
                } else return false;
            } else if(bill == 20) {
                if(cnt[0] > 0 and cnt[1] > 0) {
                    cnt[0]--;
                    cnt[1]--;
                    cnt[2]++;
                } else if(cnt[0] > 2) {
                    cnt[0] -= 3;
                    cnt[2]++;
                } else return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends