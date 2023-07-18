class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 1 and n == 1) return 1;
        
        vector<set<int>> rem_col(m);
        vector<set<int>> rem_row(n);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rem_col[i].insert(j);
                rem_row[j].insert(i);
            }
        }
            
        queue<pair<int,int>> q;
        q.push({0,0});
        
        vector<vector<int>> dist(m, vector<int>(n, -1));
        dist[0][0] = 1;
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                
                int x = it.first;
                int y = it.second;
                vector<int> vis_cols, vis_rows;

                for(auto it = rem_col[x].lower_bound(y + 1); it != rem_col[x].end() && *it <= (y + grid[x][y]); it++) {
                    vis_cols.push_back(*it);
                    dist[x][*it] = 1 + dist[x][y];
                    q.push({x, *it});
                }
                
                for(auto col : vis_cols) {
                    rem_col[x].erase(col);
                    rem_row[col].erase(x);
                }
                
                for(auto it = rem_row[y].lower_bound(x + 1); it != rem_row[y].end() && *it <= (x + grid[x][y]); it++) {
                    vis_rows.push_back(*it);
                    dist[*it][y] = 1 + dist[x][y];
                    q.push({*it, y});
                }
                
                for(auto row : vis_rows) {
                    rem_row[y].erase(row);
                    rem_col[row].erase(y);
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};