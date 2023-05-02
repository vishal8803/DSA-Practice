class Solution {
public:
    int arraySign(vector<int>& nums) {
        int nn = 0;
        for(int i : nums){
            if(i==0)
                return 0;
            if(i<0)
                nn++;
        }
        if(nn%2==1)
            return -1;
        return 1;
    }
};