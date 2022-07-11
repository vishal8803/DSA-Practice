class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        long long totalSum = 0;
        
        for(int i = 0; i < wall[0].size(); i++){
            totalSum += wall[0][i];
        }
        
        // How many bricks will end on particular ith position
        map<long long,int> mp;
        
        for(int i = 0; i < wall.size(); i++){
            int s = 0;
            for(int j = 0; j < wall[i].size(); j++){
                s += wall[i][j];
                
                mp[s]++;
            }
        }
        
        int height = wall.size();
        int mn = INT_MAX;
        mp.erase(totalSum);
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            
            mn = min(mn, height-it->second);
        }
        if(mn==INT_MAX)
            return height;
        
        return mn;
    }
};