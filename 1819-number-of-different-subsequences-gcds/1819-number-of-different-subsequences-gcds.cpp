class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        vector<int> v(200003, 0);
        for(int i : nums) {
            v[i]++;
        }
        
        int cnt = 0;
        for(int i = 1; i <= 200000; i++) {
            if(v[i]) cnt++;
            else {
                int t = -1;
                for(int j = i; j <= 200000; j += i) {
                    if(v[j]) {
                        if(t == -1) t = j;
                        else t = __gcd(t, j);
                    }
                }
                if(t == i) cnt++;
            }
        }
        return cnt;
    }
};