class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 10001));
        
        for(auto edge : edges) {
            matrix[edge[0]][edge[1]] = edge[2];
            matrix[edge[1]][edge[0]] = edge[2];
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
        vector<vector<int>> v;
        for(int i = 0; i < n; i++) {
            int total = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(matrix[i][j] <= distanceThreshold) total++;
            }
            v.push_back({i,total});
        }
        
        sort(v.begin(), v.end(), [&](vector<int> &v1, vector<int> &v2){
            if(v1[1] == v2[1]) return v1[0] < v2[0];
            return v1[1] > v2[1];
        });
        
        return v[v.size()-1][0];
    }
};