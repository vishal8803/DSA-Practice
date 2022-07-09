class Solution {
public:
    int calc(vector<vector<int>> &temp, int target){
        int ans = -1;
        int st = 0;
        int end = temp.size()-1;
        while(st<=end){
            int mid = (st+end)/2;
            if(temp[mid][0]>=target){
                ans = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1){
            return {-1};
        }
        vector<vector<int>> temp = intervals;
        
        sort(temp.begin(), temp.end());
        vector<int> dp(n);
        
        dp[n-1] = -1;
        
        for(int i = n - 2; i >= 0; i--){
            dp[i] = calc(temp, temp[i][1]);
        }
        
        map<pair<int,int>, int> mp;
        map<pair<int,int>, int> mp2;
        
        for(int i = 0; i < n; i++){
            mp[{temp[i][0],temp[i][1]}] = dp[i];
            mp2[{intervals[i][0],intervals[i][1]}] = i;
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            pair<int,int> p = {intervals[i][0],intervals[i][1]};
            if(mp[p]==-1){
                ans.push_back(-1);
            }else{
                vector<int> t = temp[mp[p]];
                ans.push_back(mp2[{t[0],t[1]}]);
            }
        }
        return ans;
    }
};