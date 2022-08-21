class Solution {
public:
    bool canReplace(string stamp, string target, int idx) {
        for(int i = 0; i < stamp.length(); i++) {
            if(target[idx + i] != '?' && target[idx+i] != stamp[i]) return false;
        }
        return true;
    }
    
    void replace(string stamp, string &target, int idx, int &count) {
        for(int i = 0; i < stamp.length() ; i++) {
            if(target[idx + i] != '?') {
                target[idx+i] = '?';
                count++;
            }
        }
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        
        int count = 0;
        vector<bool> visited(target.size());
        
        while(count != target.length()) {
            bool flag = false;
            
            for(int i = 0; i <= target.length() - stamp.length(); i++) {
                if(!visited[i] && canReplace(stamp, target, i)) {
                    replace(stamp, target, i, count);
                    flag = true;
                    ans.push_back(i);
                    visited[i] = true;
                    if(count == target.length()) break;
                }
                
            }
            
            if(flag==false) {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};