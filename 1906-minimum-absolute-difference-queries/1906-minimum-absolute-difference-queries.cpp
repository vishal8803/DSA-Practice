class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> mp(n+1,vector<int>(26));
        vector<int> f(mx + 1, 0);
        
        for(int i = 0; i < n; i++) {
            f[nums[i]]++;
            mp[i+1] = f;
        }
        
        vector<int> ans;
        // return ans;
        for(auto q : queries) {
            int lt = q[0];
            int rt = q[1];
            vector<int> freq(mx + 1, 0);
            vector<int> t;
            // cout<<n<<" "<<rt + 1<<" "<<lt<<endl;
            for(int i = 0; i < mx + 1; i++) {
                if(lt==0)
                freq[i] = abs(mp[rt + 1][i]);
                else freq[i] = abs(mp[rt + 1][i] - mp[lt][i]);
                if(freq[i] > 0) t.push_back(i);
            }
            // cout<<"h"<<endl;
            int mn = INT_MAX;
            for(int i = 0; i < t.size() - 1; i++) {
                mn = min(mn, abs(t[i] - t[i+1]));
            }
            // cout<<mn<<endl;
            if(mn == INT_MAX)
                ans.push_back(-1);
            else ans.push_back(mn);
            
        }
        
        return ans;
    }
};