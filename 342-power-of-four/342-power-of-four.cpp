class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;
        int t = abs(n);
        
        if(t&(t-1)!=0) {
            return false;
        }
        
        int count = 0;
        long long p = 1;
        
        while(p<=t) {
            if(p==t) {
                return true;
            } 
            p = p*4;
            count++;
            
        }
        return false;
    }
};