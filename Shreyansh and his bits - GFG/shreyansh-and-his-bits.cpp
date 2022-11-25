//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include <bits/stdc++.h>

class Solution{
public:
    long long ncr(long long n, long long r)
    {
     
        long long p = 1, k = 1;
     
        if (n - r < r)
            r = n - r;
     
        if (r != 0) {
            while (r) {
                p *= n;
                k *= r;
     
                // gcd of p, k
                long long m = __gcd(p, k);
     
                // dividing by gcd, to simplify
                // product division by their gcd
                // saves from the overflow
                p /= m;
                k /= m;
     
                n--;
                r--;
            }
     
            // k should be simplified to 1
            // as C(n, r) is a natural number
            // (denominator should be 1 ) .
        }
     
        else
            p = 1;
     
        return p;
    }
    // 10010
    long long count(long long x) {
        int total = 0;
        int ones = 0;
        long long ans = 0;
        while(x > 0) {
            int bit = (x&1);
            if(bit) {
                ones++;
            }
            // cout<<total<<" "<<ones<<endl;
            if(ones <= total and bit){
                ans += ncr(total, ones);
            }
            
            total++;
            x = x>>1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends