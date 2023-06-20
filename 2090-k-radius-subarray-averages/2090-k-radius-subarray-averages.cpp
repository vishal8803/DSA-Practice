class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0; i<=k-1&& i<n; i++){
            ans[i]=-1;
        }
        
        for(int i=n-1; i>n-k-1 && i>=0; i--){
            ans[i]=-1;
        }
        
        int pt = k;
        int i=0,j=2*k;
        long long s =0 ;
        for(int g=i; g<=j && g<n; g++){
            s=s+nums[g];
        }
        while(j<n){
            ans[pt]=s/(2*k+1);
            pt++;
            s=s-nums[i];
            i++;
            j++;
            if(j<n)
            s=s+nums[j];
        }
        
        return ans;
        
    }
};