class Solution {
public:
    int calc(vector<int> &v) {
        // for(int i : v) cout<<i<<" "; 
        int n = v.size();
        vector<int> dp(n,0);
        dp[n-1] = v[n-1];
        
        for(int i = n - 2; i >= 0; i--) {
            int num = v[i];
            int idx = -1;
            for(int j = i + 1; j < n; j++) {
                if(v[j] >= num) {
                    if(idx==-1) idx = j;
                    else if(dp[j] >= dp[idx]) idx = j;  
                }
            }
            if(idx==-1) {
                dp[i] = num;
            } else {
                dp[i] = num + dp[idx];
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // 1->5 1->5 2->4 2->6
        vector<pair<int,int>> v;
        
        for(int i = 0; i < scores.size(); i++) {
            v.push_back({ages[i],scores[i]});
        }
        
        sort(v.begin(), v.end(), [&](pair<int,int> &p1, pair<int,int> &p2) {
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        });
        
        // 1->5 8->1 9->2 10->3
        int n = scores.size();
        
        vector<int> arr;
        for(int i = 0; i < n; i++) arr.push_back(v[i].second);
        
        return calc(arr);
    }
};