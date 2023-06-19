class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0;
        int alt = 0;
        
        for(int i : gain) {
            alt = i + alt;
            mx = max(mx, alt);
        }
        
        return mx;
    }
};