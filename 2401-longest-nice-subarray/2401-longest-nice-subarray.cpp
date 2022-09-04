class Solution {
public:
    bool check(int n, vector<int> &temp) {
        for(int i = 0; i < 32; i++) {
            int bit = ((n>>i)&1);
            if(bit==1 && temp[31-i]>=1) return false;
        }
        
        return true;
    }
    
    void put(int n, vector<int> &temp) {
        for(int i = 0; i < 32; i++) {
            int bit = ((n>>i)&1);
            if(bit==1) {
                temp[31-i]++;
            }
        }
    }
    
    void remove(int n, vector<int> &temp) {
        for(int i = 0; i < 32; i++) {
            int bit = ((n>>i)&1);
            if(bit==1) {
                temp[31-i]--;
            }
        }
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        vector<int> temp(32, 0);
        int ans = 1;
        
        int n = nums.size();
        
        while(j < n) {
            if(check(nums[j], temp)) {
                
                put(nums[j], temp);
                ans = max(ans, j - i + 1);
                j++;
            } else {
                
                while(i <= j && check(nums[j], temp) == false) {
                    remove(nums[i], temp);
                    i++;
                }
                if(i<=j && check(nums[j], temp)==true) {
                    put(nums[j], temp);
                }
                ans = max(ans, j-i+1);
                j++;
            }
        }
        
        return ans;
    }
};