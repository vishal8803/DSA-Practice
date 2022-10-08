class Solution {
public:
    
    
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int> mp;
        int mx = 2;
        
        for(int i : arr) mp[i]++;
        
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                int prev = arr[j];
                int sprev = arr[i];
                int ans = 2;
                while(mp.find(prev+sprev) != mp.end()) {
                    int t = sprev;
                    sprev = prev;
                    prev = t + prev;
                    ans++;
                }
                mx = max(mx, ans);
            }
        }
        
        if(mx <= 2) return 0;
        
        return mx;
    }
};