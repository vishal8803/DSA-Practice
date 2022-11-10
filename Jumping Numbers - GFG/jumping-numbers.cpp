//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> nums;
    
    void calc(long long num, long long x) {
        if(num > x) return;
        
        nums.push_back(num);
        
        int r = num%10;
        if(r==0) {
            num = num*10 + (r+1);
            calc(num, x);
        } else if(r==9) {
            num = num*10 + (r-1);
            calc(num, x);
        } else {
            num = num*10 + (r+1);
            calc(num,x);
            num/=10;
            num = num*10 + (r-1);
            calc(num,x);
        }
    }
    
    long long jumpingNums(long long X) {
        if(X<=9) return X;
        
        for(int i = 0; i <= 9; i++) calc(i, X);
        
        sort(nums.begin(), nums.end());
        
        int ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]==X) return X;
            if(nums[i] < X) ans = nums[i];
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends