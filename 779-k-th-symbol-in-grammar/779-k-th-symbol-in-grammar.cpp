class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1) return 0;
        
        if(k%2==0) {
            int res = kthGrammar(n-1,k/2);
            if(res==0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            int res = kthGrammar(n-1,(k+1)/2);
            if(res==0) {
                return 0;
            } else {
                return 1;
            }
        }
        
        return -1;
    }
};