class Solution
{
    public:
    int dp[4001];
    vector<vector < long long>> hash;
    int p = 11;
    int MOD = 1000000007;

    void computeHash(string s)
    {
        int n = s.length();
        hash = vector<vector < long long>> (n, vector < long long > (n,-1));
        long long P = p;
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                {
                    hash[i][j] = ((s[j] - 'a') *(P)) % MOD;
                }
                else
                {
                    hash[i][j] = (hash[i][j - 1] + (s[j] - 'a') *(P)) % MOD;
                }
            }
            P *= p;
            P %= MOD;
        }
    }

    int calc(string &s, int i)
    {
        if (i >= s.length()) return 0;

        if (dp[i] != -1) return dp[i];

        int mx = 1;

        for (int j = 0; j < s.length(); j++)
        {
            int l1 = i;
            int r1 = l1 + j;
            
            int l2 = r1 + 1;
            int r2 = l2 + j;
            if(r1 >= s.length() || r2 >= s.length()) break;
            
            if (hash[l1][r1] == hash[l2][r2])
            {
                mx = max(mx, 1 + calc(s, r1 + 1));
            }
        }

        return dp[i] = mx;
    }

    int deleteString(string s)
    {
        computeHash(s);
        memset(dp, -1, sizeof(dp));
        return calc(s, 0);
    }
};