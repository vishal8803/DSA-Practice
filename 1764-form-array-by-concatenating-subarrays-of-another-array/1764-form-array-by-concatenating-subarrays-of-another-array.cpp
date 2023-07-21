class Solution {
public:
    int calc(vector<int> &v, int target) {
        int res = -1;
        int st = 0;
        int end = v.size() - 1;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            if(v[mid] > target) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return res;
    }
    
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        set<int> st;
        
        for(auto group : groups) {
            st.insert(group.size());
        }
        
        map<vector<int>, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) {
            vector<int> temp;
            for(int j = i; j < nums.size(); j++) {
                temp.push_back(nums[j]);
                if(st.find(j - i + 1) != st.end()) {
                    mp[temp].push_back(i);
                }
            }
        }
        
        int i = 0;
        if(mp.find(groups[i]) == mp.end()) return false;
        
        int idx = mp[groups[i]][0] + groups[i].size() - 1;
        i++;
        
        while(i < groups.size()) {
            vector<int> temp = groups[i];
            if(mp.find(temp) == mp.end()) return false;
            vector<int> v = mp[temp];
            int res = calc(v, idx);
            
            if(res != -1) {
                idx = res + v.size();
            } else {
                return false;
            }
            i++;
        }
        
        return true;
        
    }
};