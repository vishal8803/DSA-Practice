class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> mat(n,vector<int>(n,1));
        
        for(auto mine : mines){
            mat[mine[0]][mine[1]] = 0;
        }
        
        vector<vector<int>> left(n,vector<int>(n,0));
        vector<vector<int>> right(n,vector<int>(n,0));
        vector<vector<int>> up(n,vector<int>(n,0));
        vector<vector<int>> down(n,vector<int>(n,0));
        
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    sum+=1;
                    left[i][j] = sum;
                }else{
                    sum = 0;
                    left[i][j] = 0; 
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = n-1; j >= 0; j--){
                if(mat[i][j]){
                    sum+=1;
                    right[i][j] = sum;
                }else{
                    sum = 0;
                    right[i][j] = 0; 
                }
            }
        }
        
        for(int j = 0; j < n; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                if(mat[i][j]){
                    sum += 1;
                    up[i][j] = sum;
                }else{
                    sum = 0;
                    up[i][j] = 0;
                }
            }
        }
        
        for(int j = 0; j < n; j++){
            int sum = 0;
            for(int i = n-1; i >= 0; i--){
                if(mat[i][j]){
                    sum += 1;
                    down[i][j] = sum;
                }else{
                    sum = 0;
                    down[i][j] = 0;
                }
            }
        }
        
        int mx = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int t = min(min(up[i][j],down[i][j]), min(left[i][j], right[i][j]));
                mx = max(mx,t);
            }
        }
        
        return mx;
    }
};