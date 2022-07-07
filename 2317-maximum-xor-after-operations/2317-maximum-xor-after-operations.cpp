class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int a = 0;
        for(int i : nums){
            a = a|i;
        }
        return a;
    }
};