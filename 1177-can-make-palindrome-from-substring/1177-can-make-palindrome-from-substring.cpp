class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> mp;
        
        vector<int> temp(26,0);
        for(int i = 0; i < s.length(); i++) {
            temp[s[i]-'a']++;
            mp[i] = temp;
        }
        
        vector<bool> ans;
        
        for(auto q : queries) {
            int left = q[0];
            int right = q[1];
            int k = q[2];
            vector<int> lt, rt;
            if(left-1>=0) {
                lt = mp[left-1];
                rt = mp[right];
            } else {
                lt = vector<int>(26,0);
                rt = mp[right];
            }
            
            vector<int> diff(26,0);
            for(int i = 0; i < 26; i++) {
                int d = rt[i] - lt[i];
                diff[i] = d;
            }
            int count = 0;
            for(auto it : diff) {
                count += ((it)%2);
            }
            if(count==0 || count==1) ans.push_back(true);
            else {
                count = count/2;
                if(count <= k) ans.push_back(true);
                else ans.push_back(false);
            }
        }
        
        return ans;
    }
};