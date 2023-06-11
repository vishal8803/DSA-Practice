class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        map<pair<int,int>,int> m;
        for(int i = 0 ; i < roads.size() ; i++){
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
            pair<int,int> p = {roads[i][0],roads[i][1]};
            pair<int,int> q = {roads[i][1],roads[i][0]};
            m[p]++;
            m[q]++;
        }
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n  ; j++){
                if(i != j){
                    pair<int,int> temp = {i,j};
                    int x = indegree[i]+indegree[j];
                    if(m[temp]==1){
                        x--;
                    }
                    ans = max(ans,x);
                }
            }
        }
        return ans;
    }
};