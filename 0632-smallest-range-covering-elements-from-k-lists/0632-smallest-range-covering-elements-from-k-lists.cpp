class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        
        int mx = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i][0],{i,0}});
            mx = max(mx, nums[i][0]);
        }
        
        int mn = pq.top().first;
        vector<int> ans = {mn,mx};
        
        while(!pq.empty()){
            pair<int,pair<int,int>> t = pq.top();
            pq.pop();
            if(ans[1]-ans[0] > mx-mn){
                ans[0] = mn;
                ans[1] = mx;
            }
            
            int row = t.second.first;
            int col = t.second.second;
            
            if(col+1>=nums[row].size()){
                break;
            }
            
            pq.push({nums[row][col+1],{row,col+1}});
            mx = max(mx,nums[row][col+1]);
            mn = pq.top().first;
        }
        return ans;
    }
};