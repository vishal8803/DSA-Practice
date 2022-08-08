class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int size = 0;
        
        for(int i : nums) {
            if(size==0 || temp[size-1] < i) {
                temp.push_back(i);
                size++;
            } else {
                int idx = lower_bound(temp.begin(), temp.end(), i) - temp.begin();
                temp[idx] = i;
            }
        }
        
        return temp.size();
    }
};