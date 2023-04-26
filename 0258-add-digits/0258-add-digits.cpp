class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n>0){
            int r = n%10;
            sum+=r;
            n=n/10;
        }
        return sum;
    }
    int addDigits(int num) {
        int ans = 0;
        while(num>0){
            ans = digitSum(num);
            if(ans>=0 && ans<=9){
                return ans;
            }else{
                num = ans;
            }
        }
        return ans;
    }
};