class Solution
{
    public:
        bool isPossible(vector<int> &dist, double hour, int speed)
        {
            double totalTime = 0;

            for (int i = 0; i < dist.size(); i++)
            {

                if (i == dist.size() - 1)
                {
                    totalTime += dist[i] *1.0 / speed;
                    break;
                }

                if (dist[i] *1.0 / speed > dist[i] / speed)
                {

                    totalTime += dist[i] / speed + 1;
                }
                else
                {
                    totalTime += dist[i] / speed;
                }
            }

            return totalTime <= hour;
        }

    int minSpeedOnTime(vector<int> &dist, double hour)
    {

        int st = 1;
        int end = 1e9;

        

        int ans = -1;

        while (st <= end)
        {
            int mid = (st + end) / 2;

            if (isPossible(dist, hour, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }

        return ans;
    }
};