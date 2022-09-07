class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j = 0;
        int i = 1;
        vector<string> ans;
        
        while(i <= n && j < target.size()) {
            if(target[j]==i) {
                ans.push_back("Push");
                j++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            i++;
        }
        
        return ans;
    }
};