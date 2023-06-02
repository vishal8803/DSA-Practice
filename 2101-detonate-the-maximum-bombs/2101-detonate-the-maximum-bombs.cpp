using ll = long long;
class Solution {
public:
    void dfs(map<int, vector<int>> &mp, int &bomb, set<int> &st, int &count, map<int, int> &cnt) {
        st.insert(bomb);
        count += cnt[bomb];
        
        for(auto it : mp[bomb]) {
            if(st.find(it) == st.end()) {
                dfs(mp, it, st, count, cnt);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        map<int, vector<int>> mp;
        map<int, int> cnt;
        
        
        for(int i = 0; i < bombs.size(); i++) {
            cnt[i]++;
            for(int j = 0; j < bombs.size(); j++) {
                
                if(i == j) continue;
                
                auto p1 = bombs[i];
                auto p2 = bombs[j];
                
                ll dist = (ll)((ll)pow(p1[0] - (ll)p2[0], 2) + (ll)pow((ll)p1[1] - (ll)p2[1], 2));
                
                if((ll)pow(p1[2], 2) >= dist) {
                    mp[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < bombs.size(); i++) {
            set<int> st;
            
                int count = 0;
                dfs(mp, i, st, count, cnt);
                ans = max(ans, count);
            
        }
        
        return ans;
    }
};