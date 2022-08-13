class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> mp;
        
        for(string word : words) {
            mp[word]++;
        }
        
        int j = 0;
        int k = words[0].size();
        vector<int> ans;
        int target = words.size();
        if(s.size() < target*k) return ans;
        
        while(j <= s.length() - k*words.size()) {
            int t = j;
            int count = 0;
            bool flag = true;
            map<string,int> e = mp;
            while(count < target) {
                int r = 0;
                string temp = "";
                while(t < s.length() && r < k) {
                    temp += s[t++];
                    r++;
                }
                // cout<<temp<<" "<<e[temp]<<endl;
                if(e.find(temp) != e.end()) {
                    e[temp]--;
                    if(e[temp]==0)
                        e.erase(temp);
                } else {
                    flag = false;
                    break;
                    
                }
                count++;
            }
            if(flag) {
                ans.push_back(j);
            }
            j++;
        }
        
        return ans;
    }
};