class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(target<=startFuel)
            return 0;
        
        if(stations.size()==0)
            return -1;
        
        int pos = startFuel;
        
        priority_queue<int> pq;
        
        int i = 0;
        int count = 0;
        
        while(pos<target){
            
            while(i<stations.size() && pos>=stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())
                return -1;
            
            int t = pq.top();
            pq.pop();
            count++;
            pos += t;
            
            if(pos >= target){
                return count;
            }
            
            
        }
        return -1;
    }
};