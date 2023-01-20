class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<long long>> v(n, vector<long long>(3, INT_MAX));
        v[0][0] = INT_MAX;
        v[0][1] = 0;
        v[0][2] = INT_MAX;
        
        for(int i = 1; i < n; i++) 
        {
            if(obstacles[i] == 0) {
                if(obstacles[i-1] == 0) {
                    v[i][0] = min(v[i-1][0], 1 + min(v[i-1][1], v[i-1][2]));
                    v[i][1] = min(v[i-1][1], 1 + min(v[i-1][0], v[i-1][2]));
                    v[i][2] = min(v[i-1][2], 1 + min(v[i-1][0], v[i-1][1]));
                } 
                else if(obstacles[i-1] == 1) 
                {
                    v[i][0] = 1 + min(v[i-1][1], v[i-1][2]);
                    v[i][1] = min(v[i-1][1], 1 + v[i-1][2]);
                    v[i][2] = min(1 + v[i-1][1], v[i-1][2]);
                } 
                else if(obstacles[i-1] == 2) 
                {
                    v[i][0] = min(v[i-1][0], 1 + v[i-1][2]);
                    v[i][1] = 1 + min(v[i-1][0], v[i-1][2]);
                    v[i][2] = min(v[i-1][2], 1 + v[i-1][0]);
                }
                else if(obstacles[i-1] == 3) 
                {
                    v[i][0] = min(v[i-1][0], 1 + v[i-1][1]);
                    v[i][1] = min(v[i-1][1], 1 + v[i-1][0]);
                    v[i][2] = 1 + min(v[i-1][1], v[i-1][0]);
                }
            } 
            else if(obstacles[i] == 1) 
            {
                if(obstacles[i-1] == 0) {
                    v[i][1] = min(v[i-1][1], 1 + min(v[i-1][0], v[i-1][2]));
                    v[i][2] = min(v[i-1][2], 1 + min(v[i-1][0], v[i-1][1]));
                } 
                else if(obstacles[i-1] == 1) {
                    v[i][2] = min(v[i-1][2], 1 + v[i-1][1]);
                    v[i][1] = min(v[i-1][1], v[i-1][2] + 1);
                } 
                else if(obstacles[i-1] == 2) {
                    v[i][1] = min(v[i-1][0] + 1, v[i-1][2]) + 1;
                    v[i][2] = v[i-1][2];
                } 
                else if(obstacles[i-1] == 3) {
                    v[i][1] = min(v[i-1][1], v[i-1][0] + 1);
                    v[i][2] = v[i][1] + 1;
                } 
            } 
            else if(obstacles[i] == 2) 
            {
                if(obstacles[i-1] == 0) {
                    v[i][0] = min(v[i-1][0], 1 + min(v[i-1][1], v[i-1][2]));
                    v[i][2] = min(v[i-1][2], 1 + min(v[i-1][0], v[i-1][1]));
                } 
                else if(obstacles[i-1] == 1) {
                    v[i][2] = min(v[i-1][2], 1 + v[i-1][1]);
                    v[i][0] = 1 + v[i][2];
                } 
                else if(obstacles[i-1] == 2) {
                    v[i][0] = min(v[i-1][0], v[i-1][2] + 1);
                    v[i][2] = min(v[i-1][2], 1 + v[i-1][0]);
                } 
                else if(obstacles[i-1] == 3) {
                    v[i][0] = min(v[i-1][0], v[i-1][1] + 1);
                    v[i][2] = v[i][0] + 1;
                } 
            } 
            else if(obstacles[i] == 3) {
                if(obstacles[i-1] == 0) {
                    v[i][0] = min(v[i-1][0], 1 + min(v[i-1][1], v[i-1][2]));
                    v[i][1] = min(v[i-1][1], 1 + min(v[i-1][0], v[i-1][1]));
                } 
                else if(obstacles[i-1] == 1) {
                    v[i][0] = 1 + min(v[i-1][1], 1 + v[i-1][2]);
                    v[i][1] = min(v[i-1][1], v[i-1][2] + 1);
                } 
                else if(obstacles[i-1] == 2) {
                    v[i][0] = min(v[i-1][0], v[i-1][2] + 1);
                    v[i][1] = 1 + v[i][0];
                } 
                else if(obstacles[i-1] == 3) {
                    v[i][0] = min(v[i-1][0], v[i-1][1] + 1);
                    v[i][1] = min(v[i-1][0] + 1, v[i-1][1]);
                } 
            }
            
        }
        
        // for(auto it : v) {
        //     cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        // }
        
        return min(v[n-1][0], min(v[n-1][1], v[n-1][2]));
    }
};