//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<unsigned long long> temp;
    void precompute()
    {
        for(int i = 0; i <= 63; i++) {
            unsigned long long num =pow(2,i);
            for(int j = i + 1; j <= 63; j++) {
                unsigned long long t = num + (long long)pow(2,j);
                for(int k = j + 1; k <= 63; k++) {
                    unsigned long long r = t + (long long)pow(2,k); 
                    if(r <= 1e18)
                    temp.push_back(r);
                }
            }
        }
        
        sort(temp.begin(), temp.end());
    }
    
    long long solve(long long l, long long r){
        // precompute();
        long long left, right;
        
        int st =  0;
        int end = temp.size() - 1;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            if(temp[mid] >= l) {
                left = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        st = 0;
        end = temp.size() - 1;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            if(temp[mid] <= r) {
                right = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return (right - left + 1);
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends