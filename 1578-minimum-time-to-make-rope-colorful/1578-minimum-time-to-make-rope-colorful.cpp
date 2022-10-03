class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        int i = 0;
        int n = colors.size();
        
        while(i < n) {
            int count = 0;
            char ch = colors[i];
            int sum = 0;
            int mx = 0;
            while(i < n && colors[i]==ch) {
                count++;
                sum += neededTime[i];
                mx = max(mx, neededTime[i]);
                i++;
            }
            if(count > 1) {
                cost += sum - mx;
            }
        }
        return cost;
    }
};