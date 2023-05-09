class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector<bool> busStop(1000000, 0);
        vector<bool> busNumber(1000000, 0);
        
        map<int, vector<int>> mp;
        
        for(int i = 0; i < routes.size(); i++) {
            for(int j : routes[i]) {
                mp[j].push_back(i);
            }
        }
        
        queue<int> q;
        q.push(source);
        busStop[source] = 1;
        
        int level = 0;
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                q.pop();
                
                if(node == target) return level;
                
                for(auto &bus : mp[node]) {
                    if(busNumber[bus]) continue;
                    
                    for(auto &it : routes[bus]) {
                        if(busStop[it]) continue;
                        q.push(it);
                        busStop[it] = true;
                    }
                    busNumber[bus] = 1;
                }
            }
            level++;
        }
        return -1;
    }
};