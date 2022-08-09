class Solution
{
    public:
        int dp[16385][16][16];
        int calc(vector<int> &tasks, int sessionTime, int visited, int currentSession, int count)
        {
            int n = tasks.size();
            int d = (1 << (n)) - 1;
            if (d == visited)
            {
                return count;
            }
            if(dp[visited][currentSession][count] != -1) return dp[visited][currentSession][count];
            int ans = INT_MAX;
            
            for (int i = 0; i < tasks.size(); i++)
            {
                if (((visited >> i) &1) == 0)
                {
                    int t = visited;
                    t = (1 << i) | t;
                    if (currentSession + tasks[i] <= sessionTime)
                    {
                        ans = min(ans, calc(tasks, sessionTime, t, currentSession + tasks[i], count));
                    }
                    else
                    {
                        ans = min(ans, calc(tasks, sessionTime, t, tasks[i], count + 1));
                    }
                }
            }
            return dp[visited][currentSession][count] = ans;
        }

    int minSessions(vector<int> &tasks, int sessionTime)
    {
        int n = tasks.size();
        
        memset(dp, -1, sizeof(dp));
        return calc(tasks, sessionTime, 0, 0, 1);
    }
};