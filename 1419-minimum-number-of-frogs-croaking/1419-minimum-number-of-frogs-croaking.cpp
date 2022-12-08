class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> v = {0,0,0,0,0};
        int ans = -1;
        int active = 0;
        
        for(char ch : croakOfFrogs) {
            if(ch == 'c') {
                v[0]++;
                active++;
            } else if(ch == 'r') {
                v[1]++;
            } else if(ch == 'o') {
                v[2]++;
            } else if(ch == 'a') {
                v[3]++;
            } else if(ch == 'k') {
                v[4]++;
                active--;
            }
            ans = max(ans, active);
            if(v[0] < v[1] || v[1] < v[2] || v[2] < v[3] || v[3] < v[4]) return -1;
        }
        if(v[0] != v[1] or v[1] != v[2] or v[2] != v[3] or v[3] != v[4]) return -1;
        return ans;
    }
};