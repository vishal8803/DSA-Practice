class Solution {
public:
    void calc(int n, int i, int k, vector<vector<int>> &ans, vector<int> temp){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        for(int j = i; j <= n; j++){
            temp.push_back(j);
            calc(n,j+1,k,ans,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        calc(n,1,k,ans,{});
        return ans;
    }
};