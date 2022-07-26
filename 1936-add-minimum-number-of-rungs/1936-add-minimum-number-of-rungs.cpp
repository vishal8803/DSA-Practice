class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int count = 0;
        if(rungs[0] > dist) {
            int diff = rungs[0];
            if(diff%dist==0) {
                count += diff/dist - 1;
            }else{
                count += diff/dist;
            }
        }
        
        for(int i = 0; i < rungs.size()-1; i++) {
            if(rungs[i+1] - rungs[i] > dist) {
                int diff = rungs[i+1] - rungs[i];
                if(diff%dist==0) {
                    count += diff/dist - 1;
                }else{
                    count += diff/dist;
                }
                
            }
        }
        
        return count;
    }
};