
#define all(a) a.begin(),a.end()
#define loop(i,a,b) for (int i = a; i < b; i++)
#define len(a) a.size()
#define vi vector<int> 
#define ll long long

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        
        loop(i, 0, len(nums)) {
            sum += nums[i];
            count += mp[sum-k];
            mp[sum]++;
        }
        
        return count;
    }
};