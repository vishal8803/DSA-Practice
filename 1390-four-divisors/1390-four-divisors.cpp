class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) {
            int count = 0;
            int temp = 0;
            for(int j = 1; j * j <= i; j++) {
                if(i%j==0) {
                    if(i/j == j) {temp += j; count++;}
                    else {
                        temp += j;
                        temp += i/j;
                        count+=2;
                    }
                }
            }
            if(count == 4) sum += temp;
        }
        
        return sum;
    }
};