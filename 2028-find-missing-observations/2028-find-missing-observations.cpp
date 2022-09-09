class Solution {
public:
    
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(),0);
        
        int m = rolls.size();
        
        int target = (m+n)*mean - sum;
        
        if(target < n || target > 6*n) return {};
        
        int t = target/n;
        int extra = target%n;
        
        // cout<<t<<" "<<extra;
        vector<int> ans(n,t);
        int i = 0;
        
        while(extra>0){ 
            ans[i++] += 1;
            extra--;
        }
        
        return ans;
    }
};