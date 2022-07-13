class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n,0);
        
        for(int i = 0; i < n; i++){
            ans[i] = i + 1;
        }
        
        int i = 0;
        while(k--){
            reverse(ans.begin()+i,ans.end());
            i++;
        }
        return ans;
    }
};