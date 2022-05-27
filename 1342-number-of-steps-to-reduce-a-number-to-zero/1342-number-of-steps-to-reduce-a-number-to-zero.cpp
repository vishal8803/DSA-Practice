class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num>0){
            if(num&1){
                num -= 1;
            }else{
                num = num>>1;
            }
            count++;
        }
        return count;
    }
};