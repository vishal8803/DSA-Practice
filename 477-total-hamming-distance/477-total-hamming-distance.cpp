class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int count = 0;
        
        for(int i = 0; i < 32; i++){
            int set = 0;
            int unset = 0;
            for(int j : nums){
                if(j>>i & (1))
                    set++;
                else
                    unset++;
            }
            count += set*unset;
        }
        return count;
    }
};