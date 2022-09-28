class Solution {
public:
    int maximumSeatAllocate(vector<int> temp) {
        vector<bool> visited(10,true);
        for(int i : temp) {
            visited[i-1] = false;
        }
        
        int count = 0;
        if(visited[1] && visited[2] && visited[3] && visited[4]) {
            count++;
            if(visited[5] && visited[6] && visited[7] && visited[8]) count++;
        }
        else if(visited[5] && visited[6] && visited[7] && visited[8]) {
            count++;
            if(visited[1] && visited[2] && visited[3] && visited[4]) count++;
        }
        else if(visited[3] && visited[4] && visited[5] && visited[6]) count++;
        
        return count;
    }
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>> mp;
        
        for(vector<int> seat : reservedSeats) {
            mp[seat[0]].push_back(seat[1]);
        }
        
        int ans = (n - mp.size()) * 2;
        
        for(auto it : mp) {
            ans += maximumSeatAllocate(it.second);
        }
        
        return ans;
    }
};