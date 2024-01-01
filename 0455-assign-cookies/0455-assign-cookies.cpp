class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        
        int i = 0;
        int j = 0;
        int cnt = 0;
        
        while(i < g.size() and j < s.size()) {
            if(s[j] >= g[i]) {
                cnt++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        
        return cnt;
    }
};