class Solution {
public:
    string findMaximum(vector<int> &cost, int target, vector<string> &dp) {
        if(target < 0) return "#";
        if(target == 0) {
            return "";
        }
        
        if(dp[target] != "") return dp[target];
        
        string ans = "";
        
        for(int i = 0; i < 9; i++){
            string temp = findMaximum(cost, target - cost[i], dp);
            // cout<<temp<<endl;
            if(temp == "#") continue;
            
            string res = to_string(i+1) + temp;
            if(ans == "" or ans.size() < res.size()) ans = res;
            else if(ans.size() == res.size() and ans < res) ans = res; 
        }
        if(ans == "") return dp[target] = "#";
        return dp[target] = ans;
    }
    
    string largestNumber(vector<int>& cost, int target) {
        
        vector<string> dp(target + 1);
        string ans = findMaximum(cost, target, dp);
        
        if(ans == "#") return "0";
        
        return ans;
        
    }
};