class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        if(n == 1) return votes[0];
        
        vector<pair< char, vector<int>>> v;
        
        for(char ch : votes[0]) {
            vector<int> freq(votes[0].size(), 0);
            for(int i = 0; i < n; i++) {
                int  pos;
                for(int j = 0; j < votes[0].size(); j++) {
                    if(ch == votes[i][j]) {
                        pos = j;
                        break;
                    }
                }
                freq[pos]++;
            }
            v.push_back({ch, freq});
        }
        
        sort(v.begin(), v.end(), [&](pair< char, vector<int>> &p1, pair< char, vector<int>> &p2) {
            if(p1.second == p2.second) return p1.first <= p2.first;
            return p1.second >= p2.second;
        });
        
        string ans = "";
        for(auto it : v) {
            ans += it.first;
        }
        return ans;
    }
};