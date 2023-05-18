using ll = long long;

#define all(a) a.begin(),a.end()
#define loop(i,a,b) for (int i = a; i < b; i++)
#define len(a) a.size()
#define vi vector<int> 
#define ll long long
#define pb push_back
#define p push
#define i insert
#define e erase
#define f first
#define s second
#define fr front;


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        
        int n = len(grid);
        int m = len(grid[0]);
        
        vector<vi> visited(n, vi(m, 0));
        vector<vi> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        loop(i, 0, n) {
            loop(j, 0, m) {
                if(grid[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        int count = 0;
        
        while(len(q) > 0) {
            int x = q.front().f;
            int y = q.front().s;
            q.pop();
            
            loop(i, 0, 4) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                if(nx < 0 or ny < 0 or nx >= n or ny >= m) {count++; continue;}
                if(grid[nx][ny] == 0) count++;
                else if(!visited[nx][ny]) {
                    q.p({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        
        return count;
    }
};