class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int idx = 0;
        
        priority_queue<int,vector<int>, greater<int>> pq;
        
        while(idx < heights.size() - 1){
            int diff = heights[idx+1] - heights[idx];
            pq.push(diff);
            
            if(pq.size() > ladders)
            {
                int t = pq.top();
                pq.pop();
                
                if(t<=0)
                {
                    idx++;
                    continue;
                }
                
                if(t > bricks){
                    break;
                }else{
                    bricks-=t;
                }
            }
            idx++;
        }
        
        return idx;
    }
};