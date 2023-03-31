class Solution {
public:
    int dp[51][51][11];
    int MOD = 1000000007;
    int calc(vector<string>& pizza, int si, int sj, int ei, int ej, int k, vector<vector<int>> &m1, vector<vector<int>> &m2) {
        
        if(k<=0) return 0;
        if(k == 1) {
            int count = 0;
            for(int i = si; i <= ei; i++) {
                for(int j = sj; j <= ej; j++) {
                    if(pizza[i][j] == 'A') return 1;
                }
            }
            
            return 0;
        }
        if(dp[si][sj][k] != -1) return dp[si][sj][k];
        long long ways = 0;
        int total1=0;
        for(int i = si; i <= ei; i++){
            
            total1 += (m2[i][ej] - (sj>0?m2[i][sj-1]:0));
            if(total1>0) {
                ways = (ways%MOD + calc(pizza, i+1, sj, ei, ej, k - 1, m1, m2)%MOD)%MOD;
            }
        }
        int total2 = 0;
        for(int j = sj; j <= ej; j++) {
            
            total2 += (m1[ei][j] - (si>0?m1[si-1][j]:0));
            if(total2>0) {
                ways = (ways%MOD + calc(pizza, si, j+1,ei, ej,k-1,m1,m2)%MOD)%MOD;
            }
        }
        
        
        return dp[si][sj][k] = ways%MOD;
    }
    
    int ways(vector<string>& pizza, int k) {
        memset(dp, -1, sizeof(dp));
        int n = pizza.size();
        int m = pizza[0].size();
        vector<vector<int>> m1(n, vector<int>(m, 0));
        vector<vector<int>> m2(n, vector<int>(m, 0));
        
        for(int j = 0; j < m; j++) {
            if(pizza[0][j] == 'A') {
                m1[0][j] = 1;
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pizza[i][j] == 'A') {
                    m1[i][j] = 1 + m1[i-1][j];
                } else {
                    m1[i][j] = m1[i-1][j];
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(pizza[i][0] == 'A') {
                m2[i][0] = 1;
            }
        }
        
        for(int j = 1; j < m; j++) {
            for(int i = 0; i < n; i++) {
                if(pizza[i][j] == 'A') {
                    m2[i][j] = 1 + m2[i][j-1];
                } else {
                    m2[i][j] = m2[i][j-1];
                }
            }
        }
        vector<vector<int>> v;
        return calc(pizza, 0, 0, n - 1, m - 1, k, m1, m2);
    }
};