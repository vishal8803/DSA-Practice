class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int val1 = 0, val2 = 0, val3 = 0;
        
        for(auto triplet : triplets) {
            if(triplet[0] > target[0] or triplet[1] > target[1] or triplet[2] > target[2]) continue;
            
            val1 = max(val1, triplet[0]);
            val2 = max(val2, triplet[1]);
            val3 = max(val3, triplet[2]);
        }
        
        if(val1 == target[0] and val2 == target[1] and val3 == target[2]) return true;
        return false;
    }
};