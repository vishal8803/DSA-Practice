
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        map<pair<int,int>, vector<vector<int>>> mp;
        
        int n = grid.size();
        int  m = grid[0].size();
        map<pair<int,int>, int> dist;
        
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                int num = grid[i][j];
                dist[{i,j}] = INT_MAX;
                for(int k = 0; k < 4; k++) {
                    
                    int ni = i + directions[k][0];
                    int nj = j + directions[k][1];
                    
                    if(ni < 0 or nj < 0 or ni >= n or nj >= m) continue;
                    
                    if(k + 1 == num) {
                        mp[{i,j}].push_back({ni,nj,0});
                    } else {
                        mp[{i,j}].push_back({ni,nj,1});
                    }
                }
            }
        }
        
        dist[{0, 0}] = 0;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0, 0}});
        
        while(pq.size() > 0) {
            auto it = pq.top();
            pq.pop();
            int dst = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            // cout<<x<<" "<<y<<" "<<dst<<endl;
            
            for(auto node : mp[{x, y}]) {
                // cout<<"heelo ";
                int nx = node[0];
                int ny = node[1];
                int d = node[2];
                // cout<<nx<<" "<<ny<<" "<<d<<endl;
                if(dist[{nx, ny}] > d + dst) {
                    dist[{nx, ny}] = d + dst;
                    pq.push({dist[{nx, ny}], {nx, ny}});
                }
            }
        }
        
        return dist[{n-1,m-1}];
    }
};