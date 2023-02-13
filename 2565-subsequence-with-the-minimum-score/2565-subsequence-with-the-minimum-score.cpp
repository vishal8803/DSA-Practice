class Solution {
public:
    int minimumScore(string s, string t) {
        vector<int> v;
        int p1 = s.size() - 1;
        int p2 = t.size() - 1;
        int m = t.size();
        while(p1 >= 0 and p2 >= 0) {
            while(p1 >= 0 and s[p1] != t[p2]) {
                p1--;
            }
            if(p1 == -1) {
                break;
            }
            v.push_back(p1);
            p1--;
            p2--;
        }
        
        reverse(v.begin(), v.end());
        
        int ans = m -  v.size();
        p1 =  0;
        for(int i = 0; i < t.size(); i++) {
            while(p1 < s.size() and s[p1] != t[i]) {
                p1++;
            }
            int x = upper_bound(v.begin(), v.end(), p1) - v.begin();
        if(x == v.size()) {
            if(p1 == s.size()) break;
            ans = min(ans, m - 1 -i);
            p1++;
            continue;
        }
        int sz = v.size() - x;
        int prev = ans;
        ans = min(ans, m - sz - 1 - i);
        if(ans < 0) return prev;
        p1++;
        }
        
        return ans;
    }
    
};