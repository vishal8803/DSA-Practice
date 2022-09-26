class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int total = n/2;
        map<int,int> mp;
        for(int i : candyType) {
            mp[i]++;
        }
        
        if(mp.size() >= total) return total;
        return mp.size();
    }
};