class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,int> mp;
        for(auto it : rectangles) {
            double val = (double)it[0]/(double)it[1];
            mp[val]++;
        }
        
        long long cnt = 0;
        for(auto it : mp) {
            int f= it.second;
            cnt += ((long long)f*(long long)(f-1))/2ll;
        }
        
        return cnt;
    }
};