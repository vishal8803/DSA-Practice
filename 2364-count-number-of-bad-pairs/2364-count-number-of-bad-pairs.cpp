class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]-i]++;
        }
        
        vector<int> temp;
        for(auto it : mp) {
            temp.push_back(it.second);
        }
        
        vector<long long> sum(temp.size(),0);
        sum[temp.size()-1] = temp[temp.size()-1];
        
        for(int i = temp.size()-2; i >= 0; i--) {
            sum[i] = sum[i+1] + temp[i];
        }
        
        long long count = 0;
        for(int i = 0; i < sum.size()-1; i++) {
            count+= (long long)temp[i]*sum[i+1];
        }
        
        return count;
    }
};