
using ll = long long;
#define all(a) a.begin(),a.end()
#define loop(i,a,b) for (int i = a; i < b; i++)
#define len(a) a.size()
#define vi vector<int> 
#define vvi vector<vector<int>>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define p(a,b) pair<a,b>


class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& q) {
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        unordered_map<int,int> p_col;
        unordered_map<int,int> s_col;
        set<pair<int,int>> st; 
        
        vi ans;
        
        loop(i, 0, len(lamps)) {
            if(st.find({lamps[i][0], lamps[i][1]}) == st.end()) {
                row[lamps[i][0]]++;
                col[lamps[i][1]]++;
                p_col[lamps[i][0] + lamps[i][1]]++;
                s_col[lamps[i][0] - lamps[i][1]]++;
                st.insert({lamps[i][0], lamps[i][1]});
            }
        }
        
        vvi directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        loop(i, 0, len(q)) {
            auto it = q[i];
            if(row[it[0]] > 0 or col[it[1]] > 0 or p_col[it[0] + it[1]] > 0 or s_col[it[0] - it[1]] > 0) {
                ans.pb(1);
                loop(j, 0, 9) {
                    int nx = it[0] + directions[j][0];
                    int ny = it[1] + directions[j][1];
                    if(nx >= 0 and ny >= 0 and nx < n and ny < n and st.count({nx, ny}) > 0) {
                        row[nx]--;
                        col[ny]--;
                        p_col[nx+ny]--;
                        s_col[nx-ny]--;
                        st.erase(st.find({nx, ny}));
                    }
                }
            } else {
                ans.pb(0);
            }
        }
        
        return ans;
    }
};