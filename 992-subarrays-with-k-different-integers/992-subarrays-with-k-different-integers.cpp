class Solution {
public:
    int calc(vector<int> &nums) {
        int count = 0;
        int i = -1;
        int j = -1;
        int n = nums.size();
        map<int,int> mp;
        
        while(true){
            bool f1 = false;
            bool f2 = false;
            
            while(i < n - 1) {
                f1 = true;
                i++;
                mp[nums[i]]++;
                if(mp.size()==2){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)mp.erase(nums[i]);
                    i--;
                    break;
                }
            }
            
            while(j < i) {
                f2 = true;
                if(mp.size()==1){
                    count += i-j;
                }
                j++;
                mp[nums[j]]--;
                if(mp[nums[j]]==0) mp.erase(nums[j]);
                if(mp.size()==0) break;
            }
            if(!f1 && !f2) break;
        }
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if(k==1) return calc(nums);
        map<int,int> mpb;
        map<int,int> mps;
        
        int j = -1;
        int ib = -1;
        int is = -1;
        
        int n = nums.size();
        
        int count = 0;
        
        while(true) {
            bool flag1 = false;
            bool flag2 = false;
            bool flag3 = false;
            
            while(ib < n-1) {
                flag1 = true;
                ib++;
                mpb[nums[ib]]++;
                
                if(mpb.size() == k + 1) {
                    mpb[nums[ib]]--;
                    if(mpb[nums[ib]]==0)
                        mpb.erase(nums[ib]);
                    ib--;
                    break;
                }
            }
            
            while(is < ib) {
                flag2 = true;
                is++;
                mps[nums[is]]++;
                
                if(mps.size() == k) {
                    mps[nums[is]]--;
                    if(mps[nums[is]]==0)
                        mps.erase(nums[is]);
                    is--;
                    break;
                }
            }
            
            while(j < is) {
                flag3 = true;
                
                if(mps.size()==k-1 && mpb.size()==k) {
                    count += ib-is;
                }
                
                j++;
                
                mps[nums[j]]--;
                if(mps[nums[j]]==0){
                    mps.erase(nums[j]);
                }
                
                mpb[nums[j]]--;
                if(mpb[nums[j]]==0)
                    mpb.erase(nums[j]);
                
                
                if(mps.size() < k - 1 || mpb.size() < k) break;
            }
            
            if(!flag1 && !flag2 && !flag3) break;
        }
        
        return count;
    }
};