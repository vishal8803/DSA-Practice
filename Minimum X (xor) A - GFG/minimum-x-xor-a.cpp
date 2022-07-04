// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSetBits(int n){
        int count = 0;
        while(n>0){
            count++;
            n = (n&(n-1));
        }
        return count;
    }
    
    int minVal(int a, int b) {
        int countA = countSetBits(a);
        int countB = countSetBits(b);
        
        if(countA == countB){
            return a;
        }
        
        if(countA > countB){
            
            int diff = countA - countB;
            for(int i = 0; i<=31 && diff>0; ++i){
                if((a>>i)&1){
                    a=(a&(~(1<<i)));
                    diff--;
                    if(diff==0)
                        break;
                }
            }
            return a;
        }else if(countB > countA){
            int diff = countB - countA;
            for(int i = 0; i<=31 && diff>0; ++i){
                if(((a>>i)&1)==0){
                    a=(a|(1<<i));
                    diff--;
                    if(diff==0)
                        break;
                }
            }
            return a;
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends