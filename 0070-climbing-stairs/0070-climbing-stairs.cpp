class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2 || n==3){
            return n;
        }
        
        
        long long one = 1;
        long long two = 1;
        n=n-2;
        while(n>=0){
            long long temp =(long long)one + (long long)two;
            one = two;
            two = temp;
            n-=1;
        }
        
        return two;
    }
};