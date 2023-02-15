class Solution {
public:
    int MOD = 1e9 + 7;
    int calc(vector<int> &v, int start, int finish, int fuel, vector<vector<int>> &dp) {
        int count = 0;
        
        if(start == finish) {
            count++;
        }
        
        if(fuel < 0) return 0;
        // cout<<start<<" "<<fuel<<endl;
        if(dp[start][fuel] != -1) return dp[start][fuel];
        
        for(int i = 0; i < v.size(); i++) {
            if(i == start) continue;
            if(abs(v[i] - v[start]) <= fuel) {
                count = (count%MOD + calc(v, i, finish, fuel - abs(v[i] - v[start]), dp)%MOD)%MOD;
            }
        }
        return dp[start][fuel] = count;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size()+1, vector<int>(fuel+1, -1));
        return calc(locations, start, finish, fuel, dp);
    }
};