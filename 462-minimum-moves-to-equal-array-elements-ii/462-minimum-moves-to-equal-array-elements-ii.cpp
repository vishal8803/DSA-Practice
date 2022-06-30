class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        if(n==1)
            return 0;
        
        vector<long long> pref(n),suff(n);
        long long s = 0;
        
        for(int i = 0; i < n; i++){
            s = s + nums[i];
            pref[i] = s;
        }
        s=0;
        for(int i = n-1; i >= 0; i--){
            s = s + nums[i];
            suff[i] = s;
        }
        
        long long mn = INT_MAX;
        
        for(int i = 0; i < n; i++){
            if(i==0){
                long long moves = abs(suff[i+1] - (long long)(nums[i])*(long long)(n-i-1));
                if(moves < mn ){
                    mn = moves;
                }
            }else if(i==n-1){
                long long moves = abs(pref[i-1] - (long long)nums[i]*(long long)i);
                if(moves < mn ){
                    mn = moves;
                }
            }else{
                long long moves = abs(pref[i-1] - (long long)nums[i]*(long long)i) + abs(suff[i+1] - (long long)(nums[i])*(long long)(n-i-1));
                if(moves < mn ){
                    mn = moves;
                }
            }
        }
        return mn;
    }
};