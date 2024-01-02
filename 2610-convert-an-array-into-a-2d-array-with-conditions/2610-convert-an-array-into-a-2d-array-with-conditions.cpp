class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int,int> mp;
        for(int i : nums) mp[i]++;
        
        while(mp.size() > 0) {
            vector<int> temp;
            for(auto it : mp) {
                int num = it.first;
                temp.push_back(num);
            }
            for(int i : temp) {
                mp[i]--;
                if(mp[i] == 0) mp.erase(i);
            }
            ans.push_back(temp);
        }
        
        return ans; 
    }
};